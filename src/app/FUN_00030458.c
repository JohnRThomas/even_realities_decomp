/*
 * Function: FUN_00030458
 * Entry:    00030458
 * Prototype: undefined4 __stdcall FUN_00030458(void)
 */


undefined4 FUN_00030458(void)

{
  char cVar1;
  GlassesState *pGVar2;
  
  if ((g_is_need_irq != '\x01') &&
     ((cVar1 = FUN_00033d5c(), cVar1 == '\x01' ||
      (pGVar2 = __get_dashboard_state(), pGVar2->is_master == true)))) {
    g_is_need_irq = '\x01';
  }
  return 0;
}


