/*
 * Function: ?_eeprom_st25dv_write_sys
 * Entry:    00027a5c
 * Prototype: int __stdcall ?_eeprom_st25dv_write_sys(int param_1, undefined4 param_2, void * param_3, size_t param_4)
 */


int __eeprom_st25dv_write_sys(int param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  int iVar1;
  uint cycles_to_wait;
  undefined4 uVar2;
  undefined4 extraout_r1;
  int iVar3;
  undefined4 *puVar4;
  k_mutex *mutex;
  k_timeout_t timeout;
  
  if (param_4 != 0) {
    iVar3 = 0x14;
    puVar4 = *(undefined4 **)(param_1 + 4);
    mutex = *(k_mutex **)(param_1 + 0x10);
    uVar2 = param_2;
    while( true ) {
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar2;
      z_impl_k_mutex_lock(mutex,timeout);
      iVar1 = FUN_0007fbea(puVar4,param_2,param_3,param_4);
      cycles_to_wait = z_impl_k_mutex_unlock(mutex);
      if (iVar1 == 0) break;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        printk("eeprom_st25dv_write_sys addr %04X offset %04X failed %d\r\n",
               *(ushort *)(puVar4 + 2) | 4,param_2,iVar1);
        return iVar1;
      }
      i2c_delay(cycles_to_wait);
      uVar2 = extraout_r1;
    }
  }
  return 0;
}


