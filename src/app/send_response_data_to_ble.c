/*
 * Function: send_response_data_to_ble
 * Entry:    0004b430
 * Prototype: undefined4 __stdcall send_response_data_to_ble(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4
send_response_data_to_ble
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GlassesState *pGVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  pGVar1 = __get_dashboard_state();
  if (*(char *)pGVar1 != '\x02') {
    memset((void *)((int)&local_20 + 1),0,0x17);
    local_20 = CONCAT31(local_20._1_3_,1);
    iVar2 = z_impl_k_msgq_put((k_msgq *)&DAT_20003acc,&local_20,(k_timeout_t)0x0);
    if (iVar2 != 0) {
      printk("message queue send failed %s\r\n","send_response_data_to_ble");
      return 0xffffffff;
    }
  }
  return 0;
}


