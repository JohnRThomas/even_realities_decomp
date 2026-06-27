/*
 * Function: FUN_00080338
 * Entry:    00080338
 * Prototype: undefined __stdcall FUN_00080338(int param_1)
 */


void FUN_00080338(int param_1)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xe9 = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xea = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xcc = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xcd = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xce = 0;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xcf = 0;
  if (param_1 == 0) {
    pGVar1 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar1->field_0x1010 + 7) = 0xd;
  }
  else {
    pGVar1 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar1->field_0x1010 + 7) = 0;
    pGVar1 = __get_dashboard_state();
    **(undefined1 **)&pGVar1->field_0x1010 = 0;
  }
  pGVar1 = __get_dashboard_state();
  memset((void *)(*(int *)&pGVar1->field_0x1010 + 8),0,0x1df);
  return;
}


