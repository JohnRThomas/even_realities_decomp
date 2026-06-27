/*
 * Function: display_close_screen
 * Entry:    0004c938
 * Prototype: undefined4 __stdcall display_close_screen(int param_1, undefined4 param_2)
 */


undefined4 display_close_screen(int param_1,undefined4 param_2)

{
  GlassesState *pGVar1;
  undefined1 local_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  _local_c = CONCAT11((char)param_1,1);
  if (param_1 != 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): display_close_screen %d\n");
      }
      else {
        ble_printk("%s(): display_close_screen %d\n","display_close_screen",param_1,BLE_DEBUG);
      }
    }
    if (param_1 == 4) {
      FUN_00037824();
    }
    FUN_0004c41c();
    display_close(&local_c,2);
    z_impl_k_yield();
    pGVar1 = __get_dashboard_state();
    memset(&pGVar1->field_0xef,0,0x5dc);
  }
  return 0;
}


