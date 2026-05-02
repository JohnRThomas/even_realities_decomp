/*
 * Function: comm_write
 * Entry:    00032170
 * Prototype: undefined4 __stdcall comm_write(int param_1, st25dv_context * param_2, undefined1 * param_3, size_t param_4)
 */


undefined4 comm_write(int param_1,st25dv_context *param_2,undefined1 *param_3,size_t param_4)

{
  uint uVar1;
  char *fmt;
  undefined4 uVar2;
  undefined4 uStack_14;
  
  if ((((param_2 == (st25dv_context *)0x0) || (param_3 == (undefined1 *)0x0)) || (param_4 == 0)) ||
     (param_1 == 2)) {
    printk("comm_write para is error\n");
    return 0xffffffff;
  }
  if (param_1 != 0) {
    if (param_1 != 1) {
      return 0;
    }
    uVar2 = lpuart_async_b((int)param_2,param_3,param_4);
    return uVar2;
  }
  if (((param_2 == (st25dv_context *)0x0) || (param_3 == (undefined1 *)0x0)) || (param_4 == 0)) {
    return 0xffffffff;
  }
  uStack_14 = (uint)param_3 & 0xffffff;
  uVar1 = __eeprom_st25dv_read(param_2,0x2006,(int)&uStack_14 + 3,1);
  if (uVar1 == 0) {
    if ((uStack_14 & 0x6000000) == 0) {
      uVar1 = __eeprom_st25dv_write((int)param_2,0x2008,param_3,param_4);
      if (uVar1 == 0) {
        uVar1 = __eeprom_st25dv_read(param_2,0x2006,(int)&uStack_14 + 3,1);
        if (uVar1 == 0) {
          return 0;
        }
        goto LAB_00027b80;
      }
      fmt = "eeprom_st25dv_write ST25DV_REG_MAILBOX_DYN failed\n";
    }
    else {
      fmt = "eeprom_st25dv_write_i2c_mb_mailbox_ram no write\n";
    }
    printk(fmt);
    uVar2 = 0xfffffffd;
  }
  else {
LAB_00027b80:
    printk("eeprom_st25dv_read ST25DV_REG_MB_CTRL_DYN is failed\n");
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}


