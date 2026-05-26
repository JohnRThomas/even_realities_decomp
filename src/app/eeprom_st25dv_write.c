/*
 * Function: ?_eeprom_st25dv_write
 * Entry:    000278e8
 * Prototype: uint __stdcall ?_eeprom_st25dv_write(int param_1, undefined4 param_2, void * param_3, size_t param_4)
 */


uint __eeprom_st25dv_write(int param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  uint uVar1;
  uint cycles_to_wait;
  undefined4 uVar2;
  undefined4 extraout_r1;
  undefined4 *puVar3;
  int iVar4;
  k_mutex *mutex;
  k_timeout_t timeout;
  size_t sVar5;
  undefined4 uVar6;
  
  if (param_4 != 0) {
    iVar4 = 0x14;
    puVar3 = *(undefined4 **)(param_1 + 4);
    mutex = *(k_mutex **)(param_1 + 0x10);
    uVar2 = param_2;
    uVar6 = param_2;
    while( true ) {
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar2;
      z_impl_k_mutex_lock(mutex,timeout);
      sVar5 = param_4;
      uVar1 = __st25dv_write(puVar3,(uint)*(ushort *)(puVar3 + 2),param_2,param_3,param_4);
      cycles_to_wait = z_impl_k_mutex_unlock(mutex);
      if (uVar1 == 0) break;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        printk("eeprom_st25dv_write addr %04X offset %04X failed %d\r\n",
               (uint)*(ushort *)(puVar3 + 2),param_2,uVar1,sVar5,uVar6);
        return uVar1;
      }
      i2c_delay(cycles_to_wait);
      uVar2 = extraout_r1;
    }
  }
  return 0;
}


