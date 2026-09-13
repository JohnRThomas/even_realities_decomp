# SPDX-License-Identifier: Apache-2.0

target_sources(app PRIVATE
  threads.c
  watchdog.c
  ble_req.c
  system_state.c
  task_status.c
  message_task.c
)
