/*
 * Function: ext_flash_write
 * Entry:    0002f8c8
 * Prototype: int __stdcall ext_flash_write(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int ext_flash_write(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  k_timeout_t timeout;
  
  iVar1 = (uint)*(ushort *)(param_1 + 0x1070) << 0x1b;
  if (-1 < iVar1) {
    FUN_0007f328();
    iVar1 = extraout_r1;
  }
  if (DAT_20008548 == 0) {
    if (-1 < (int)((uint)*(ushort *)(param_1 + 0x1070) << 0x1b)) {
      FUN_0007f32a();
    }
  }
  else {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = iVar1;
    z_impl_k_mutex_lock((k_mutex *)&DAT_20008534,timeout);
    iVar1 = (**(code **)(*(int *)(DAT_20008548 + 8) + 4))(DAT_20008548,param_2,param_3,param_4);
    z_impl_k_mutex_unlock((k_mutex *)&DAT_20008534);
    uVar2 = extraout_r2;
    if (-1 < (int)((uint)*(ushort *)(param_1 + 0x1070) << 0x1b)) {
      FUN_0007f32a();
      uVar2 = extraout_r2_00;
    }
    if (iVar1 != 0) {
      if (LOG_LEVEL < 1) {
        return iVar1;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): flash write fail!\n","ext_flash_write",uVar2,BLE_DEBUG);
        return iVar1;
      }
      printk("%s(): flash write fail!\n");
      return iVar1;
    }
  }
  return 0;
}


