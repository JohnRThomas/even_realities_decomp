/*
 * Function: FUN_00080a3a
 * Entry:    00080a3a
 * Prototype: undefined2 __stdcall FUN_00080a3a(void)
 */


undefined2 FUN_00080a3a(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  if (((pGVar1->field2783_0x108a == 0) &&
      (pGVar1 = __get_dashboard_state(), pGVar1->field2784_0x108c == 0)) ||
     (pGVar1 = __get_dashboard_state(), 0x40 < (ushort)pGVar1->field2784_0x108c)) {
    pGVar1 = __get_dashboard_state();
    pGVar1->field2784_0x108c = 0x20;
  }
  pGVar1 = __get_dashboard_state();
  if ((ushort)pGVar1->field2784_0x108c < 4) {
    pGVar1 = __get_dashboard_state();
    pGVar1->field2784_0x108c = 4;
  }
  pGVar1 = __get_dashboard_state();
  return pGVar1->field2784_0x108c;
}


