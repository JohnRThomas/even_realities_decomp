/*
 * Function: update_temp_task_status
 * Entry:    0002db74
 * Prototype: uint __stdcall update_temp_task_status(int param_1, uint param_2, uint param_3)
 */


uint update_temp_task_status(int param_1,uint param_2,uint param_3)

{
  char *fmt;
  uint uVar1;
  uint extraout_r1;
  uint uVar2;
  undefined1 *puVar3;
  
  uVar1 = param_2;
  while (DAT_20019a6a != '\0') {
    sleep_33_seconds();
    uVar1 = extraout_r1;
  }
  DAT_20019a6a = 1;
  if (**(uint **)(param_1 + 0x1068) == param_2) {
    uVar2 = (uint)(byte)(*(uint **)(param_1 + 0x1068))[1];
    if (uVar2 == 1) {
      DAT_20019a6a = 0;
      return param_3;
    }
    if (uVar2 == param_3) {
      DAT_20019a6a = 0;
      return param_3;
    }
  }
  if (*(byte *)(param_1 + 0xd5) == param_2) {
    DAT_20019a6a = 0;
    return param_3;
  }
  if ((*(char *)(param_1 + 0xd5) == '\0') || (*(char *)(param_1 + 0xd5) == '\x01')) {
    if (param_3 != 2) goto LAB_0002dc1a;
LAB_0002dbce:
    if (LOG_LEVEL < 1) goto LAB_0002dbe6;
    fmt = "%s(): persist task [running]: %d\n";
  }
  else {
    if (param_3 == 2) {
      if ((param_2 != 4) && (param_2 != 6)) {
        DAT_20019a6a = 0;
        return 2;
      }
      display_close_screen((uint)*(byte *)(param_1 + 0xd5),uVar1);
      goto LAB_0002dbce;
    }
    display_close_screen((uint)*(byte *)(param_1 + 0xd5),uVar1);
LAB_0002dc1a:
    if (param_3 == 3) {
      if (LOG_LEVEL < 1) goto LAB_0002dbe6;
      fmt = "%s(): persist task [pause]: %d\n";
    }
    else {
      if (LOG_LEVEL < 1) goto LAB_0002dbe6;
      fmt = "%s(): persist task [stop]: %d\n";
    }
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"update_temp_task_status",param_2,BLE_DEBUG);
  }
LAB_0002dbe6:
  *(char *)(param_1 + 0xd5) = (char)param_2;
  puVar3 = *(undefined1 **)(param_1 + 0x1068);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x1068) + 4) = 1;
  DAT_20019a6a = 0;
  return param_3;
}


