# SPDX-License-Identifier: Apache-2.0
#
# Even Realities G1 application core firmware (reconstruction of v1.66).
#
#   west build -b nrf5340dk_nrf5340_cpuapp   MCUboot, this image and the network core
#                                            image (net_core/), packaged in
#                                            build/zephyr/dfu_application.zip

cmake_minimum_required(VERSION 3.20.0)

# Module glue that adds net_core/ as the network core child image
# (cmake/modules/mcuboot/CMakeLists.txt).
list(APPEND MODULE_EXT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ar_glasses)

target_include_directories(app PRIVATE src/include)

# struct ncs_mem at 0x2007fc00 (shared with bootloader / net core)
zephyr_linker_sources(SECTIONS linker/ncs_mem.ld)

add_subdirectory(src)

# Build identification in the boot log and the "#t" debug command: configure time and
# the git commit of this tree.
string(TIMESTAMP G1_BUILD_TIME "%Y-%m-%d %H:%M:%S")
execute_process(COMMAND git rev-parse --short=8 HEAD
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                OUTPUT_VARIABLE G1_GIT_COMMIT OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
if(NOT G1_GIT_COMMIT)
  set(G1_GIT_COMMIT unknown)
endif()
set_property(SOURCE src/main.c src/ble/ble_proto.c TARGET_DIRECTORY app APPEND PROPERTY
             COMPILE_DEFINITIONS G1_BUILD_TIME="${G1_BUILD_TIME}" G1_GIT_COMMIT="${G1_GIT_COMMIT}")
