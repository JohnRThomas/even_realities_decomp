/*
 * Function: FUN_0007ff16
 * Entry:    0007ff16
 * Prototype: GlassesState * __stdcall FUN_0007ff16(void)
 */


GlassesState * FUN_0007ff16(void)

{
  bool bVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r2;
  undefined1 local_9;
  
  pGVar2 = __get_dashboard_state();
  if (((*(char *)pGVar2 != '\x01') ||
      (pGVar2 = __get_dashboard_state(), *(char *)(*(int *)&pGVar2->field_0x1018 + 1) == '\0')) ||
     (bVar1 = __is_idle(), !bVar1)) {
    pGVar2 = __get_dashboard_state();
    if (*(char *)pGVar2 != '\x02') {
      return pGVar2;
    }
    pGVar2 = __get_dashboard_state();
    if (*(char *)(*(int *)&pGVar2->field_0x1018 + 1) == '\0') {
      return (GlassesState *)&pGVar2->field_0x1000;
    }
  }
  __get_dashboard_state();
  pGVar2 = __get_dashboard_state();
  if (*(char *)(*(int *)&pGVar2->field_0x1018 + 1) != '\0') {
    pGVar2 = (GlassesState *)not_disturb_sync_data(&local_9,1,extraout_r2);
    if (pGVar2 != (GlassesState *)0x0) {
      return pGVar2;
    }
    pGVar2 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar2->field_0x1018 + 1) = 0;
    pGVar2 = __get_dashboard_state();
    if (*(char *)pGVar2 == '\x01') {
      FUN_0003f1bc();
    }
  }
  return (GlassesState *)0x0;
}


