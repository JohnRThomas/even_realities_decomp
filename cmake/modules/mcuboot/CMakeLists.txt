# SPDX-License-Identifier: Apache-2.0
#
# net_core/ as the network core child image, added the way nrf/samples/CMakeLists.txt
# adds hci_rpmsg to Bluetooth applications.
#
# NCS's MCUboot glue (included below) creates net_core_app_update.bin and puts it in
# dfu_application.zip only if the CPUNET child image exists when the glue runs.  Zephyr
# runs the CMake code of the application's own modules after all west modules, i.e.
# too late, so the child image is added here, right before the glue.

if(CONFIG_BOARD_ENABLE_CPUNET)
  if(CONFIG_NRF53_UPGRADE_NETWORK_CORE)
    # b0n validates the network core image; MCUboot hands updates to it over PCD.
    add_overlay_config(net_core ${ZEPHYR_NRF_MODULE_DIR}/subsys/bootloader/image/secure_boot.conf)
    add_overlay_config(mcuboot ${ZEPHYR_NRF_MODULE_DIR}/subsys/pcd/pcd.conf)
  endif()

  add_child_image(
    NAME net_core
    SOURCE_DIR ${APPLICATION_SOURCE_DIR}/net_core
    DOMAIN CPUNET
    BOARD ${CONFIG_DOMAIN_CPUNET_BOARD}
  )
endif()

include(${ZEPHYR_NRF_MODULE_DIR}/modules/mcuboot/CMakeLists.txt)
