/*
 * Function: FUN_000809e2
 * Entry:    000809e2
 * Prototype: int __stdcall FUN_000809e2(void)
 */


int FUN_000809e2(void)

{
  ushort uVar1;
  GlassesState *pGVar2;
  
  pGVar2 = __get_dashboard_state();
  if (((pGVar2->field2783_0x108a == 0) &&
      (pGVar2 = __get_dashboard_state(), pGVar2->field2784_0x108c == 0)) ||
     (pGVar2 = __get_dashboard_state(), 0x40 < (ushort)pGVar2->field2783_0x108a)) {
    pGVar2 = __get_dashboard_state();
    pGVar2->field2783_0x108a = 0x20;
  }
  pGVar2 = __get_dashboard_state();
  uVar1 = pGVar2->field2783_0x108a;
  pGVar2 = __get_dashboard_state();
  return *(int *)&(pGVar2->jdb_panel_context).field_0x358 + (uint)uVar1;
}


