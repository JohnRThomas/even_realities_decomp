/*
 * Function: ?_eeprom_st25dv_read
 * Entry:    00027994
 * Prototype: uint __stdcall ?_eeprom_st25dv_read(st25dv_context * param_1, st25dv_register param_2, undefined4 param_3, int param_4)
 */


uint __eeprom_st25dv_read
               (st25dv_context *param_1,st25dv_register param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint cycles_to_wait;
  st25dv_register sVar2;
  st25dv_register extraout_r1;
  device *pdVar3;
  int iVar4;
  k_mutex *mutex;
  k_timeout_t timeout;
  int iVar5;
  st25dv_register sVar6;
  
  if (param_4 != 0) {
    iVar4 = 0x14;
    pdVar3 = param_1->device;
    mutex = param_1->mutex;
    sVar2 = param_2;
    sVar6 = param_2;
    while( true ) {
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = sVar2;
      z_impl_k_mutex_lock(mutex,timeout);
      iVar5 = param_4;
      uVar1 = __st25dv_read((device *)pdVar3->name,(uint)*(ushort *)&pdVar3->api,param_2,param_3,
                            param_4);
      cycles_to_wait = z_impl_k_mutex_unlock(mutex);
      if (uVar1 == 0) break;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        printk("eeprom_st25dv_read addr %04X offset %04X failed %d\r\n",
               (uint)*(ushort *)&pdVar3->api,param_2,uVar1,iVar5,sVar6);
        return uVar1;
      }
      i2c_delay(cycles_to_wait);
      sVar2 = extraout_r1;
    }
  }
  return 0;
}


