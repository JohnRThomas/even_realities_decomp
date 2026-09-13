# SPDX-License-Identifier: Apache-2.0
#
# Directory and file order is the link order of the image; see LAYOUT.md.

target_sources(app PRIVATE main.c)

add_subdirectory(button)
add_subdirectory(ble)
add_subdirectory(storage)
add_subdirectory(nfc)
add_subdirectory(ipc)
add_subdirectory(imu)
add_subdirectory(spim_spis)
add_subdirectory(ahrs)
add_subdirectory(threads)
add_subdirectory(sensors_audio)
add_subdirectory(aw9320x)
add_subdirectory(production_test)
add_subdirectory(notify)
add_subdirectory(dashboard)
add_subdirectory(ui)
add_subdirectory(gui)
add_subdirectory(panel_display)
add_subdirectory(fonts)
add_subdirectory(display)
add_subdirectory(utils)
