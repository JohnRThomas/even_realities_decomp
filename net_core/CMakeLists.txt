# SPDX-License-Identifier: Apache-2.0
#
# Even Realities G1 network core firmware (reproduction of v1.63).

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(net_core)

zephyr_ld_options(-Wl,--emit-relocs)

# Link order = target address order of the vendor code.
target_sources(app PRIVATE
  src/main.c
  src/ipc.c
  src/hci_rpmsg.c
  src/app_esb.c
  src/timeslot.c
)

# ---------------------------------------------------------------------------
# Update image in the shipped format (net_core_app_update.bin), as the NCS v2.5
# multi-image build produces it for the network core (nrf/cmake/... b0n
# validation + modules/mcuboot net_core_app_sign_target):
#   1. zephyr.hex + b0n validation block (validation_data.py, magic
#      0x281ee6de,0x86518483,79106: hash of the image, public key, signature)
#      -> signed_by_b0_app.hex
#   2. objcopy -O binary --gap-fill 0xff -> net_core_app_to_sign.bin
#   3. imgtool sign with the stock MCUboot key root-rsa-2048.pem (the shipped
#      image carries the same KEYHASH TLV), header 0x200, version 0.0.0+0.
# The b0n key of the vendor is unknown: like NCS without SB_SIGNING_KEY_FILE a
# private key is generated once in the build directory.  Its public key and
# signature (128 B of the validation block) and the MCUboot SHA256 / RSA-PSS
# TLVs (PSS uses a random salt) cannot match the shipped file.
# ---------------------------------------------------------------------------
set(NET_B0_DIR ${ZEPHYR_NRF_MODULE_DIR}/scripts/bootloader)
set(NET_SIGN_DIR ${ZEPHYR_BINARY_DIR}/net_sign)
set(NET_B0_KEY ${NET_SIGN_DIR}/GENERATED_NON_SECURE_SIGN_KEY_PRIVATE.pem)
file(MAKE_DIRECTORY ${NET_SIGN_DIR})
if(NOT EXISTS ${NET_B0_KEY})
  execute_process(COMMAND ${PYTHON_EXECUTABLE} ${NET_B0_DIR}/keygen.py --private --out ${NET_B0_KEY}
                  COMMAND_ERROR_IS_FATAL ANY)
endif()

add_custom_command(
  OUTPUT ${ZEPHYR_BINARY_DIR}/net_core_app_update.bin
  BYPRODUCTS ${ZEPHYR_BINARY_DIR}/signed_by_b0_app.hex ${ZEPHYR_BINARY_DIR}/net_core_app_to_sign.bin
  COMMAND ${PYTHON_EXECUTABLE} ${NET_B0_DIR}/keygen.py --public --in ${NET_B0_KEY} --out ${NET_SIGN_DIR}/public.pem
  COMMAND ${PYTHON_EXECUTABLE} ${NET_B0_DIR}/hash.py --in ${ZEPHYR_BINARY_DIR}/zephyr.hex > ${NET_SIGN_DIR}/app_firmware.sha256
  COMMAND ${PYTHON_EXECUTABLE} ${NET_B0_DIR}/do_sign.py --private-key ${NET_B0_KEY}
          --in ${NET_SIGN_DIR}/app_firmware.sha256 > ${NET_SIGN_DIR}/app_firmware.signature
  COMMAND ${PYTHON_EXECUTABLE} ${NET_B0_DIR}/validation_data.py --input ${ZEPHYR_BINARY_DIR}/zephyr.hex
          --output-hex ${ZEPHYR_BINARY_DIR}/signed_by_b0_app.hex --output-bin ${NET_SIGN_DIR}/signed_by_b0_app.bin
          --offset 0 --signature ${NET_SIGN_DIR}/app_firmware.signature --public-key ${NET_SIGN_DIR}/public.pem
          --magic-value 0x281ee6de,0x86518483,79106
  COMMAND ${CMAKE_OBJCOPY} --input-target=ihex --output-target=binary --gap-fill=0xff
          ${ZEPHYR_BINARY_DIR}/signed_by_b0_app.hex ${ZEPHYR_BINARY_DIR}/net_core_app_to_sign.bin
  COMMAND ${PYTHON_EXECUTABLE} ${ZEPHYR_MCUBOOT_MODULE_DIR}/scripts/imgtool.py sign
          --key ${ZEPHYR_MCUBOOT_MODULE_DIR}/root-rsa-2048.pem --header-size 0x200 --align 4
          --version 0.0.0+0 --pad-header --slot-size 0x40000
          ${ZEPHYR_BINARY_DIR}/net_core_app_to_sign.bin ${ZEPHYR_BINARY_DIR}/net_core_app_update.bin
  DEPENDS ${ZEPHYR_BINARY_DIR}/zephyr.hex
  COMMENT "Creating net_core_app_update.bin (b0n validation + MCUboot signature)"
)
add_custom_target(net_core_app_update ALL DEPENDS ${ZEPHYR_BINARY_DIR}/net_core_app_update.bin)
add_dependencies(net_core_app_update zephyr_final)
