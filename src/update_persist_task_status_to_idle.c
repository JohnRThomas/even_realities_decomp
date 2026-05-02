/*
 * Function: update_persist_task_status_to_idle
 * Entry:    0002dc6c
 * Prototype: undefined __stdcall update_persist_task_status_to_idle(int param_1, undefined4 param_2)
 */


void update_persist_task_status_to_idle(int param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  
  while (DAT_20019a6a != '\0') {
    sleep_33_seconds();
    param_2 = extraout_r1;
  }
  DAT_20019a6a = 1;
  if ((*(char *)(param_1 + 0xd5) != '\0') || (*(char *)(*(int *)(param_1 + 0x1068) + 4) != '\x01'))
  {
    if ((*(char *)(param_1 + 0xd5) != '\0') && (*(char *)(param_1 + 0xd5) != '\x01')) {
      display_close_screen((uint)*(byte *)(param_1 + 0xd5),param_2);
    }
    if (*(char *)(param_1 + 0xd5) == '\x10') {
      *(undefined1 *)(param_1 + 0xf9c) = DAT_20019a6b;
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): persist task [stop]: %d\n","update_persist_task_status_to_idle");
      }
      else {
        ble_printk("%s(): persist task [stop]: %d\n","update_persist_task_status_to_idle",0,
                   &BLE_DEBUG);
      }
    }
    *(undefined1 *)(param_1 + 0xd5) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x1068) + 4) = 1;
  }
  DAT_20019a6a = 0;
  return;
}


