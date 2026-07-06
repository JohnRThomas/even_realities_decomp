/*
 * Function: FUN_00030440
 * Entry:    00030440
 * Prototype: undefined1 __stdcall FUN_00030440(void)
 */


undefined1 FUN_00030440(void)

{
  undefined1 uVar1;
  GlassesState *pGVar2;
  
  pGVar2 = __get_dashboard_state();
  uVar1 = g_is_need_irq;
  if (pGVar2->is_master != true) {
    uVar1 = 0;
  }
  return uVar1;
}


