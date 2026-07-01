/*
 * Function: ?_is_idle
 * Entry:    000802b8
 * Prototype: bool __stdcall ?_is_idle(void)
 */


bool __is_idle(void)

{
  GlassesState *pGVar1;
  bool bVar2;
  
  pGVar1 = __get_dashboard_state();
  if (((*(int *)pGVar1->___glasses_state == 0) &&
      (pGVar1 = __get_dashboard_state(), *(char *)(pGVar1->___glasses_state + 4) == 0x1)) &&
     (pGVar1 = __get_dashboard_state(), pGVar1->field20_0xc8[0xd] == 0x0)) {
    pGVar1 = __get_dashboard_state();
    bVar2 = pGVar1->field_0xfea == '\x01';
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


