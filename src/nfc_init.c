/*
 * Function: nfc_init
 * Entry:    000274ac
 * Prototype: undefined4 __stdcall nfc_init(void)
 */


undefined4 nfc_init(void)

{
  byte local_12;
  byte local_11;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  local_c = 0;
  local_12 = 0;
  global_st25dv_context_ptr = __eeprom_st25dv_init();
  if ((((global_st25dv_context_ptr != (st25dv_context *)0x0) &&
       (global_st25dv_context_ptr->device != (device *)0x0)) &&
      (global_st25dv_context_ptr->mutex != (k_mutex *)0x0)) &&
     (global_st25dv_context_ptr->callbacks != (st25dv_callbacks *)0x0)) {
    z_impl_k_sleep((k_timeout_t)0x290);
    (*(code *)global_st25dv_context_ptr->callbacks->field2_0x8)();
    FUN_0007fc9a(global_st25dv_context_ptr,(int)&local_10);
    printk("UUID = %02X %02X %02X %02X %02X %02X %02X %02X.\n",local_10 & 0xff,local_10 >> 8 & 0xff,
           local_10 >> 0x10 & 0xff,local_10 >> 0x18,local_c & 0xff,local_c >> 8 & 0xff,
           local_c >> 0x10 & 0xff,local_c >> 0x18);
    if ((local_c >> 8 & 0xff) - 0x50 < 2) {
      DAT_20019937 = 1;
    }
    FUN_0007fcac(global_st25dv_context_ptr,(int)&local_12);
    printk("REV_IC = %02X.\n",(uint)local_12);
    FUN_0007fcbe(global_st25dv_context_ptr,(int)&local_11);
    printk("REF_IC = %02X.\n",(uint)local_11);
    adc_nfc_init();
    init_box_status();
  }
  return 0;
}


