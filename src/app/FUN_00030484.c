/*
 * Function: FUN_00030484
 * Entry:    00030484
 * Prototype: undefined4 __stdcall FUN_00030484(int param_1)
 */


undefined4 FUN_00030484(int param_1)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  if (pGVar1->is_master == true) {
    if (param_1 == 0) {
      g_is_need_irq = 0;
    }
    else {
      g_is_need_irq = 2;
    }
  }
  return 0;
}


