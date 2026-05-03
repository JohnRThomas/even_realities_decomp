/*
 * Function: update_persist_task_status
 * Entry:    0002da34
 * Prototype: uint __stdcall update_persist_task_status(int param_1, uint param_2, uint param_3)
 */


uint update_persist_task_status(int param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  char *fmt;
  uint uVar2;
  uint extraout_r1;
  uint uVar3;
  
  uVar2 = param_2;
  while (DAT_20019a6a != '\0') {
    sleep_33_seconds();
    uVar2 = extraout_r1;
  }
  DAT_20019a6a = 1;
  if (**(uint **)(param_1 + 0x1068) == param_2) {
    uVar3 = (uint)(byte)(*(uint **)(param_1 + 0x1068))[1];
    if (uVar3 == 1) {
      DAT_20019a6a = 0;
      return param_3;
    }
    if (uVar3 == param_3) {
      DAT_20019a6a = 0;
      return param_3;
    }
  }
  uVar1 = (undefined1)param_2;
  if ((*(char *)(param_1 + 0xd5) == '\0') || (*(char *)(param_1 + 0xd5) == '\x01')) {
    *(undefined1 *)(param_1 + 0xd5) = uVar1;
LAB_0002db2e:
    if (param_3 != 2) {
LAB_0002db0a:
      if (param_3 == 3) {
        if (LOG_LEVEL < 1) goto LAB_0002dae2;
        fmt = "%s(): persist task [pause]: %d\n";
      }
      else {
        if (LOG_LEVEL < 1) goto LAB_0002dae2;
        fmt = "%s(): persist task [stop]: %d\n";
      }
      if (BLE_DEBUG == 0) {
        printk(fmt);
      }
      else {
        ble_printk(fmt,"update_persist_task_status",param_2,BLE_DEBUG);
      }
      goto LAB_0002dae2;
    }
  }
  else {
    if ((*(char *)(*(int *)(param_1 + 0xff0) + 0x74) != '\0') &&
       (*(char *)(param_1 + 0xd5) == '\x06')) goto LAB_0002db2e;
    if (param_3 != 2) {
      display_close_screen((uint)*(byte *)(param_1 + 0xd5),uVar2);
      *(undefined1 *)(param_1 + 0xd5) = uVar1;
      goto LAB_0002db0a;
    }
    if (0x14 < param_2) {
      DAT_20019a6a = 0;
      return 2;
    }
    if (-1 < (int)((0x1100d0U >> (param_2 & 0xff)) << 0x1f)) {
      DAT_20019a6a = 0;
      return 2;
    }
    display_close_screen((uint)*(byte *)(param_1 + 0xd5),uVar2);
    *(undefined1 *)(param_1 + 0xd5) = uVar1;
  }
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): persist task [running]: %d\n");
    }
    else {
      ble_printk("%s(): persist task [running]: %d\n","update_persist_task_status",param_2,BLE_DEBUG
                );
    }
  }
  if ((param_2 == 0x10) && (DAT_20019a6b = *(char *)(param_1 + 0xf9c), DAT_20019a6b == '\x01')) {
    *(undefined1 *)(param_1 + 0xf9c) = 0;
  }
  if (1 < **(byte **)(param_1 + 0x1014)) {
    **(byte **)(param_1 + 0x1014) = 0;
  }
LAB_0002dae2:
  **(uint **)(param_1 + 0x1068) = param_2;
  *(char *)(*(int *)(param_1 + 0x1068) + 4) = (char)param_3;
  DAT_20019a6a = 0;
  return param_3;
}


