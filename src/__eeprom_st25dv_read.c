/*
 * Function: ?_eeprom_st25dv_read
 * Entry:    00027994
 * Prototype: uint __stdcall ?_eeprom_st25dv_read(st25dv_context * param_1, uint param_2, undefined4 param_3, int param_4)
 */


uint __eeprom_st25dv_read(st25dv_context *param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint cycles_to_wait;
  uint extraout_r1;
  device *pdVar2;
  int iVar3;
  k_mutex *mutex;
  k_timeout_t timeout;
  int iVar4;
  uint uVar5;
  
  if (param_4 != 0) {
    iVar3 = 0x14;
    pdVar2 = param_1->device;
    mutex = param_1->mutex;
    uVar1 = param_2;
    uVar5 = param_2;
    while( true ) {
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar1;
      z_impl_k_mutex_lock(mutex,timeout);
      iVar4 = param_4;
      uVar1 = __st25dv_read((device *)pdVar2->name,(uint)*(ushort *)&pdVar2->api,param_2,param_3,
                            param_4);
      cycles_to_wait = z_impl_k_mutex_unlock(mutex);
      if (uVar1 == 0) break;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        printk("eeprom_st25dv_read addr %04X offset %04X failed %d\r\n",
               (uint)*(ushort *)&pdVar2->api,param_2,uVar1,iVar4,uVar5);
        return uVar1;
      }
      i2c_delay(cycles_to_wait);
      uVar1 = extraout_r1;
    }
  }
  return 0;
}


