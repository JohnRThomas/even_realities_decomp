/*
 * Function: load_burial_point
 * Entry:    0002515c
 * Prototype: undefined4 __stdcall load_burial_point(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 load_burial_point(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint32_t uVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  
  iVar1 = flash_settings_read(0x135000,(void *)(param_1 + 0x1128),0x11c,param_4);
  if (iVar1 == 0) {
    uVar3 = 0;
    if ((*(short *)(param_1 + 0x113c) == -1) || (*(char *)(param_1 + 0x113e) == '\0')) {
      uVar2 = z_impl_sys_rand32_get();
      memset((void *)(param_1 + 0x1128),0,0x11c);
      *(undefined1 *)(param_1 + 0x113c) = 7;
      *(uint32_t *)(param_1 + 0x1128) = uVar2;
      *(undefined1 *)(param_1 + 0x113e) = 1;
    }
  }
  else {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): burial_point read error!\n");
      }
      else {
        ble_printk("%s(): burial_point read error!\n","load_burial_point",extraout_r2,BLE_DEBUG,
                   param_4);
      }
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


