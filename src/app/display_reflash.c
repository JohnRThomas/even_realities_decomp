/*
 * Function: display_reflash
 * Entry:    0004c7f0
 * Prototype: undefined4 __stdcall display_reflash(void * param_1, uint param_2)
 */


undefined4 display_reflash(void *param_1,uint param_2)

{
  int iVar1;
  undefined1 local_28;
  undefined1 uStack_27;
  undefined2 local_26;
  undefined1 auStack_24 [24];
  
  memset(&local_28,0,0x18);
  if (param_2 < 0xb) {
    sys_clock_tick_get();
    memset(&uStack_27,0,0x17);
    local_28 = 2;
    if (param_1 != (void *)0x0) {
      memcpy(auStack_24,param_1,param_2);
      local_26 = (undefined2)param_2;
    }
    iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a64,&local_28,(k_timeout_t)0x0);
    if (iVar1 == 0) {
      sys_clock_tick_get();
      FUN_0004c41c();
      return 0;
    }
    printk("message queue send failed %s\r\n","display_reflash");
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): send data length more than %d,can\'t load it,exit ...\n");
    }
    else {
      ble_printk("%s(): send data length more than %d,can\'t load it,exit ...\n","display_reflash",
                 10,BLE_DEBUG);
    }
  }
  return 0xffffffff;
}


