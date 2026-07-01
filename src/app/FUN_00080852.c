/*
 * Function: FUN_00080852
 * Entry:    00080852
 * Prototype: undefined __stdcall FUN_00080852(uint param_1)
 */


void FUN_00080852(uint param_1)

{
  GlassesState *pGVar1;
  
  if ((param_1 < 3) &&
     ((pGVar1 = __get_dashboard_state(), *(byte *)(*(int *)&pGVar1->field_0x1018 + 2) != param_1 ||
      (pGVar1 = __get_dashboard_state(), pGVar1->field20_0xc8[0xd] != '\a')))) {
    pGVar1 = __get_dashboard_state();
    *(char *)(*(int *)&pGVar1->field_0x1018 + 2) = (char)param_1;
    pGVar1 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar1->field_0x1018 + 1) = 1;
  }
  return;
}


