/*
 * Function: eeprom_st25dv_write_i2c_mb_mailbox_ram
 * Entry:    00027b5c
 * Prototype: undefined4 __stdcall eeprom_st25dv_write_i2c_mb_mailbox_ram(st25dv_context * param_1, void * param_2, size_t param_3)
 */


undefined4
eeprom_st25dv_write_i2c_mb_mailbox_ram(st25dv_context *param_1,void *param_2,size_t param_3)

{
  uint uVar1;
  undefined4 uVar2;
  char *fmt;
  undefined4 uStack_14;
  
  if (((param_1 == (st25dv_context *)0x0) || (param_2 == (void *)0x0)) || (param_3 == 0)) {
    return 0xffffffff;
  }
  uStack_14 = (uint)param_2 & 0xffffff;
  uVar1 = __eeprom_st25dv_read(param_1,ST25DV_MB_CTRL_DYN_REG,(int)&uStack_14 + 3,1);
  if (uVar1 == 0) {
    if ((uStack_14 & 0x6000000) == 0) {
      uVar1 = __eeprom_st25dv_write((int)param_1,ST25DV_MAILBOX_RAM_REG,param_2,param_3);
      if (uVar1 == 0) {
        uVar1 = __eeprom_st25dv_read(param_1,ST25DV_MB_CTRL_DYN_REG,(int)&uStack_14 + 3,1);
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


