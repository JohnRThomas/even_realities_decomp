/*
 * Function: display_close
 * Entry:    0004c890
 * Prototype: undefined4 __stdcall display_close(void * param_1, uint param_2)
 */


undefined4 display_close(void *param_1,uint param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined1 local_28 [2];
  undefined2 local_26;
  undefined1 auStack_24 [24];
  
  memset(local_28,0,0x18);
  if (param_2 < 0xb) {
    local_28[0] = 3;
    if (param_1 != (void *)0x0) {
      memcpy(auStack_24,param_1,param_2);
      local_26 = (undefined2)param_2;
    }
    iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20003a64,local_28,(k_timeout_t)0x0);
    if (iVar1 == 0) {
      if (LOG_LEVEL < 1) {
        return 0;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): send display close command.......\n","display_close",extraout_r2,BLE_DEBUG
                  );
        return 0;
      }
      printk("%s(): send display close command.......\n");
      return 0;
    }
    printk("message queue send failed %s\r\n","display_close");
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): send data length more than %d,can\'t load it,exit ...\n");
    }
    else {
      ble_printk("%s(): send data length more than %d,can\'t load it,exit ...\n","display_close",10,
                 BLE_DEBUG);
    }
  }
  return 0xffffffff;
}


