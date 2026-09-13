# SPDX-License-Identifier: Apache-2.0
#
# Details of the shipped v1.66 build that do not follow from the source.  Nothing in the
# project's CMake files refers to this file: build_repro.sh makes CMake include it at
# the end of the project() call of the application and of the network core image
# (CMAKE_PROJECT_<name>_INCLUDE), i.e. after find_package(Zephyr), and passes
#   G1_EXACT_BUILD_TIME, G1_EXACT_GIT_COMMIT   build identification strings
#   G1_APP_PSS_SALT, G1_NET_PSS_SALT           MCUboot signature salts (application)
# What Zephyr and NCS read before project() are plain -D options of build_repro.sh: the
# Windows newlib (LIB_INCLUDE_DIR) and the b0n signature (net_core_CONFIG_SB_SIGNING_*).

set(G1_EXACT_DIR ${CMAKE_CURRENT_LIST_DIR})

# Build identification.  The CMakeLists.txt of both images define G1_BUILD_TIME (the
# application also G1_GIT_COMMIT) on the sources that print them, from the configure
# time and git HEAD.  Replace the values with those of v1.66.
function(g1_pin_build_strings)
  get_target_property(sources app SOURCES)
  foreach(src ${sources})
    if(src MATCHES "^\\$<")
      continue()
    endif()
    get_property(defs SOURCE ${src} TARGET_DIRECTORY app PROPERTY COMPILE_DEFINITIONS)
    if(NOT defs MATCHES "G1_BUILD_TIME=|G1_GIT_COMMIT=")
      continue()
    endif()
    if(DEFINED G1_EXACT_BUILD_TIME)
      string(REGEX REPLACE "G1_BUILD_TIME=\"[^\"]*\"" "G1_BUILD_TIME=\"${G1_EXACT_BUILD_TIME}\""
             defs "${defs}")
    endif()
    if(DEFINED G1_EXACT_GIT_COMMIT)
      string(REGEX REPLACE "G1_GIT_COMMIT=\"[^\"]*\"" "G1_GIT_COMMIT=\"${G1_EXACT_GIT_COMMIT}\""
             defs "${defs}")
    endif()
    set_property(SOURCE ${src} TARGET_DIRECTORY app PROPERTY COMPILE_DEFINITIONS ${defs})
  endforeach()
endfunction()
cmake_language(DEFER CALL g1_pin_build_strings)

if(NOT PROJECT_NAME STREQUAL "ar_glasses")
  return()
endif()

# ---- application image only ----

# MCUboot signs both update images with the stock root-rsa-2048.pem (the shipped images
# carry the same KEYHASH TLV) using RSA-PSS, whose 32-byte salt is random.  Re-signing
# with the salt of the shipped signature (pss_salt.py recover) reproduces the
# shipped TLV when the signed bytes are identical.  Only the .bin update images (and so
# dfu_application.zip) are re-signed; the signed .hex files keep a random salt.
function(g1_pin_pss_salt bin salt)
  add_custom_command(
    OUTPUT ${bin}.salt_pinned
    COMMAND ${PYTHON_EXECUTABLE} ${G1_EXACT_DIR}/pss_salt.py resign
            ${ZEPHYR_MCUBOOT_MODULE_DIR}/root-rsa-2048.pem ${bin} ${bin} ${salt}
    COMMAND ${CMAKE_COMMAND} -E touch ${bin}.salt_pinned
    DEPENDS ${bin}
    COMMENT "Re-signing ${bin} with the pinned RSA-PSS salt"
  )
endfunction()

function(g1_repro_after_sources)
  # crc8_ccitt: the vendor zephyr tree leaves lib/crc/crc8_sw.c out of libzephyr, the
  # application compiles it, last in link order (sdk_patches/zephyr).
  target_sources(app PRIVATE ${ZEPHYR_BASE}/lib/crc/crc8_sw.c)

  g1_pin_pss_salt(${ZEPHYR_BINARY_DIR}/app_update.bin ${G1_APP_PSS_SALT})
  g1_pin_pss_salt(${ZEPHYR_BINARY_DIR}/net_core_app_update.bin ${G1_NET_PSS_SALT})
  add_custom_target(g1_pinned_pss_salts ALL DEPENDS
    ${ZEPHYR_BINARY_DIR}/app_update.bin.salt_pinned
    ${ZEPHYR_BINARY_DIR}/net_core_app_update.bin.salt_pinned
  )
  add_dependencies(g1_pinned_pss_salts mcuboot_sign_target)
  add_dependencies(dfu_application_zip g1_pinned_pss_salts)
endfunction()
cmake_language(DEFER CALL g1_repro_after_sources)
