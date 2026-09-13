# SPDX-License-Identifier: Apache-2.0
#
# Zephyr module glue of the application (MODULE_EXT_ROOT, set in ../../CMakeLists.txt).
# Only the application image reads it; the child images keep the NCS glue.

# Wrap NCS's MCUboot glue (nrf/modules/modules.cmake points it at nrf/modules/mcuboot).
set(ZEPHYR_MCUBOOT_CMAKE_DIR ${CMAKE_CURRENT_LIST_DIR}/mcuboot)
