/*
 * Function: update_persist_task_status_to_wait_blow_head
 * Entry:    0002dd04
 * Prototype: undefined __stdcall update_persist_task_status_to_wait_blow_head(int param_1, undefined4 param_2)
 */


void update_persist_task_status_to_wait_blow_head(int param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  undefined1 *puVar1;
  
  while (DAT_20019a6a != '\0') {
    sleep_33_seconds();
    param_2 = extraout_r1;
  }
  DAT_20019a6a = 1;
  if ((*(char *)(param_1 + 0xd5) != '\0') && (*(char *)(param_1 + 0xd5) != '\x01')) {
    display_close_screen((uint)*(byte *)(param_1 + 0xd5),param_2);
  }
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): persist task [stop]: %d\n");
    }
    else {
      ble_printk("%s(): persist task [stop]: %d\n","update_persist_task_status_to_wait_blow_head",1,
                 BLE_DEBUG);
    }
  }
  *(undefined1 *)(param_1 + 0xd5) = 1;
  puVar1 = *(undefined1 **)(param_1 + 0x1068);
  *puVar1 = 1;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  DAT_20019a6a = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1068) + 4) = 1;
  return;
}


