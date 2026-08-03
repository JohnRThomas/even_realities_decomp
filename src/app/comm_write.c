/*
 * Function: comm_write
 * Entry:    00032170
 * Prototype: undefined4 __stdcall comm_write(int param_1, st25dv_context * param_2, undefined1 * param_3, size_t param_4)
 */


undefined4 comm_write(int param_1,st25dv_context *param_2,undefined1 *param_3,size_t param_4)

{
  undefined4 uVar1;
  
  if ((((param_2 == (st25dv_context *)0x0) || (param_3 == (undefined1 *)0x0)) || (param_4 == 0)) ||
     (param_1 == 2)) {
    printk("comm_write para is error\n");
    uVar1 = 0xffffffff;
  }
  else {
    if (param_1 == 0) {
      uVar1 = eeprom_st25dv_write_i2c_mb_mailbox_ram(param_2,param_3,param_4);
      return uVar1;
    }
    if (param_1 == 1) {
      uVar1 = __lpuart_async_b((int)param_2,param_3,param_4);
      return uVar1;
    }
    uVar1 = 0;
  }
  return uVar1;
}


