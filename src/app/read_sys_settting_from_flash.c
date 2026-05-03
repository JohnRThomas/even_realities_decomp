/*
 * Function: read_sys_settting_from_flash
 * Entry:    00025380
 * Prototype: undefined4 __stdcall read_sys_settting_from_flash(undefined4 * param_1)
 */


undefined4 read_sys_settting_from_flash(undefined4 *param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 *puVar2;
  undefined4 extraout_r3;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 local_94;
  char local_93 [16];
  char acStack_83 [16];
  char local_73 [16];
  char acStack_63 [16];
  undefined1 local_53;
  undefined2 local_52;
  undefined1 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 uStack_14;
  
  memset(&local_a8,0,0x98);
  iVar1 = flash_settings_read(0x130000,&local_a8,0x98,extraout_r3);
  if (iVar1 == 0) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): read sys settings success!\n");
      }
      else {
        ble_printk("%s(): read sys settings success!\n","read_sys_settting_from_flash",extraout_r2,
                   BLE_DEBUG);
      }
    }
    *param_1 = local_a8;
    param_1[1] = local_a4;
    *(undefined1 *)(param_1 + 2) = local_a0;
    param_1[3] = local_9c;
    param_1[4] = local_98;
    *(undefined1 *)(param_1 + 5) = local_94;
    if (local_93[0] != -1) {
      puVar2 = (undefined4 *)((int)param_1 + 0x15);
      pcVar4 = local_93;
      do {
        pcVar3 = pcVar4 + 4;
        *puVar2 = *(undefined4 *)pcVar4;
        puVar2 = puVar2 + 1;
        pcVar4 = pcVar3;
      } while (pcVar3 != acStack_83);
    }
    if (local_73[0] != -1) {
      puVar2 = (undefined4 *)((int)param_1 + 0x35);
      pcVar4 = local_73;
      do {
        pcVar3 = pcVar4 + 4;
        *puVar2 = *(undefined4 *)pcVar4;
        puVar2 = puVar2 + 1;
        pcVar4 = pcVar3;
      } while (pcVar3 != acStack_63);
    }
    *(undefined1 *)((int)param_1 + 0x55) = local_53;
    *(undefined1 *)(param_1 + 0x16) = local_50;
    *(undefined2 *)((int)param_1 + 0x56) = local_52;
    param_1[0x17] = local_4c;
    param_1[0x1f] = local_2c;
    param_1[0x18] = local_48;
    param_1[0x19] = local_44;
    param_1[0x20] = local_28;
    param_1[0x1a] = local_40;
    param_1[0x1b] = local_3c;
    *(undefined2 *)(param_1 + 0x1e) = local_30;
    param_1[0x1c] = local_38;
    param_1[0x21] = local_24;
    param_1[0x22] = uStack_20;
    param_1[0x1d] = local_34;
    param_1[0x23] = local_1c;
    param_1[0x24] = local_18;
    *(undefined2 *)(param_1 + 0x25) = uStack_14;
    uVar5 = 0;
  }
  else {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sys_flash_settings_read error!\n");
      }
      else {
        ble_printk("%s(): sys_flash_settings_read error!\n","read_sys_settting_from_flash",
                   extraout_r2,BLE_DEBUG);
      }
    }
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


