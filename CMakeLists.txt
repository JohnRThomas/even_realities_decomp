# SPDX-License-Identifier: Apache-2.0
#
# Even Realities G1 application core firmware (reproduction of v1.63).

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ar_glasses)

target_include_directories(app PRIVATE src/include)

# keep relocations in zephyr.elf (analysis only; the image is unchanged)
zephyr_ld_options(-Wl,--emit-relocs)

# struct ncs_mem at 0x2007fc00 (shared with bootloader / net core)
zephyr_linker_sources(SECTIONS linker/ncs_mem.ld)

target_sources(app PRIVATE
  src/main.c
  src/button/button.c
  src/ble/ble_nus.c
  src/ble/ble_ancs.c
  src/ble_proto/ble_proto.c
  src/storage/smp_bt.c
  src/storage/local_settings.c
  src/storage/flash_settings.c
  src/storage/file_storage.c
  src/storage/setting_store.c
  src/storage/quicknote_store.c
  src/nfc/nfc_wlc.c
  src/nfc/eeprom_st25dv.c
  src/nfc/st25dv.c
  src/ipc/ipc_host.c
  src/imu/imu_fusion.c
  src/spim_spis/spim.c
  src/imu/ahrs.c
  src/threads/threads.c
  src/threads/watchdog.c
  src/threads/ble_req.c
  src/threads/system_state.c
  src/threads/task_status.c
  src/threads/message_task.c
  src/sensors_audio/ext_flash.c
  src/sensors_audio/opt3007.c
  src/sensors_audio/fuel_gauge.c
  src/sensors_audio/dmic_audio.c
  src/sensors_audio/audio_stream.c
  src/aw9320x/aw9320x.c
  src/aw9320x/aw93203_port.c
  src/production_test/comm.c
  src/production_test/production_test.c
  src/production_test/serial_thread.c
  src/production_test/serial_port.c
  src/notify/notification.c
  src/notify/ncs_notification.c
  src/notify/whitelist.c
  src/notify/ui_notification.c
  src/notify/ui_template.c
  src/notify/ui_countdown.c
  src/notify/demo_image.c
  src/dashboard/dashboard.c
  src/ui/ui_quicknote.c
  src/ui/ui_even_ai.c
  src/ui/ui_bitmap.c
  src/ui/ui_teleprompter.c
  src/ui/ui_navigation_map.c
  src/ui/ui_translate.c
  src/ui/ui_onboarding.c
  src/ui/ui_raster_height.c
  src/gui/gui.c
  src/gui/gui_strings.c
  src/gui/resource_manager.c
  src/gui/ui_set_imu_pitch.c
  src/gui/ui_prompt_info.c
  src/gui/ui_transcribe_info.c
  src/gui/ui_even_ai_v2_info.c
  src/panel_display/jbd_panel.c
  src/panel_display/panel_fb.c
  src/panel_display/jbd_panel_flush.c
  src/panel_display/jbd013_api.c
  src/panel_display/hal_driver.c
  src/panel_display/font_bitmap.c
  src/panel_display/font_ascii.c
  src/gui/fonts/gui_fonts.c
  src/panel_display/proxy_thread.c
  src/panel_display/display_thread.c
  src/panel_display/md5.c
  src/panel_display/common_utils.c
  src/panel_display/burial_point.c
  ${ZEPHYR_BASE}/lib/crc/crc8_sw.c
)
