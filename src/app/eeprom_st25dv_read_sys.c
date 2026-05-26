/*
 * Function: ?_eeprom_st25dv_read_sys
 * Entry:    000279f8
 * Prototype: int __stdcall ?_eeprom_st25dv_read_sys(st25dv_context * context, uint offset, undefined4 param_3, int param_4)
 */


int __eeprom_st25dv_read_sys(st25dv_context *context,uint offset,undefined4 param_3,int param_4)

{
  int extraout_r0;
  uint uVar1;
  uint extraout_r1;
  int iVar2;
  device *pdVar3;
  k_mutex *mutex;
  k_timeout_t timeout;
  
  if (param_4 != 0) {
    iVar2 = 0x14;
    pdVar3 = context->device;
    mutex = context->mutex;
    uVar1 = offset;
    while( true ) {
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar1;
      z_impl_k_mutex_lock(mutex,timeout);
      FUN_0007fc00(pdVar3,offset,param_3,param_4);
      uVar1 = z_impl_k_mutex_unlock(mutex);
      if (extraout_r0 == 0) break;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        printk("eeprom_st25dv_read_sys addr %04X offset %04X failed %d\r\n",
               *(ushort *)&pdVar3->api | 4,offset,extraout_r0);
        return extraout_r0;
      }
      i2c_delay(uVar1);
      uVar1 = extraout_r1;
    }
  }
  return 0;
}


