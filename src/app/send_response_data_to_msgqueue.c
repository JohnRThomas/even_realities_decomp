/*
 * Function: send_response_data_to_msgqueue
 * Entry:    0004b3a4
 * Prototype: undefined4 __stdcall send_response_data_to_msgqueue(void * param_1, uint param_2)
 */


undefined4 send_response_data_to_msgqueue(void *param_1,uint param_2)

{
  GlassesState *pGVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_28 [2];
  undefined2 local_26;
  undefined1 auStack_24 [24];
  
  pGVar1 = __get_dashboard_state();
  if (*(char *)pGVar1 == '\x02') {
LAB_0004b3b6:
    uVar2 = 0;
  }
  else {
    memset(auStack_28,0,0x18);
    if (param_2 < 0x15) {
      if (param_1 != (void *)0x0) {
        memcpy(auStack_24,param_1,param_2);
        local_26 = (undefined2)param_2;
      }
      iVar3 = z_impl_k_msgq_put((k_msgq *)&DAT_20003acc,auStack_28,(k_timeout_t)0x0);
      if (iVar3 == 0) goto LAB_0004b3b6;
      printk("message queue send failed %s\r\n","send_response_data_to_msgqueue");
    }
    else if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): send data length more than %d,can\'t load it,exit ...\n");
      }
      else {
        ble_printk("%s(): send data length more than %d,can\'t load it,exit ...\n",
                   "send_response_data_to_msgqueue",0x14,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


