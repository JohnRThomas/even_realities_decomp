/*
 * Function: FUN_0007ff16
 * Entry:    0007ff16
 * Prototype: GlassesState * __stdcall FUN_0007ff16(void)
 */


GlassesState * FUN_0007ff16(void)

{
  bool bVar1;
  GlassesState *pGVar2;
  GlassesState *pGVar3;
  
  pGVar2 = __get_dashboard_state();
  if (((*(char *)pGVar2 == '\x01') &&
      (pGVar2 = __get_dashboard_state(), *(char *)(*(int *)&pGVar2->field_0x1018 + 1) != '\0')) &&
     (bVar1 = __is_idle(), bVar1)) {
LAB_0007ff36:
    __get_dashboard_state();
    pGVar2 = (GlassesState *)FUN_00080806();
    return pGVar2;
  }
  pGVar2 = __get_dashboard_state();
  if (*(char *)pGVar2 == '\x02') {
    pGVar3 = __get_dashboard_state();
    pGVar2 = (GlassesState *)&pGVar3->field_0x1000;
    if (*(char *)(*(int *)&pGVar3->field_0x1018 + 1) != '\0') goto LAB_0007ff36;
  }
  return pGVar2;
}


