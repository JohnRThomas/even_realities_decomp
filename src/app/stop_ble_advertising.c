/*
 * Function: ?_stop_ble_advertising
 * Entry:    0007f3b0
 * Prototype: int __stdcall ?_stop_ble_advertising(void)
 */


int __stop_ble_advertising(void)

{
  GlassesState *pGVar1;
  int iVar2;
  
  pGVar1 = __get_dashboard_state();
  if (pGVar1->field_0x106c == 2) {
    iVar2 = bt_le_adv_stop();
    if (iVar2 != 0) {
      return iVar2;
    }
    pGVar1 = __get_dashboard_state();
    pGVar1->field_0x106c = 3;
  }
  return 0;
}


