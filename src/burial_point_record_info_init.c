/*
 * Function: burial_point_record_info_init
 * Entry:    0004ddcc
 * Prototype: undefined __stdcall burial_point_record_info_init(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void burial_point_record_info_init(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  GlassesState *pGVar1;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): burial_point_record_info_init\n");
    }
    else {
      ble_printk("%s(): burial_point_record_info_init\n","burial_point_record_info_init",param_3,
                 BLE_DEBUG);
    }
  }
  pGVar1 = __get_dashboard_state();
  memset(&pGVar1->field_0x10da,0,0x1a);
  pGVar1 = __get_dashboard_state();
  memset(&pGVar1->field_0x10f4,0,0x1a);
  pGVar1 = __get_dashboard_state();
  memset(&pGVar1->field_0x110e,0,0x1a);
  return;
}


