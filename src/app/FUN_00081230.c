/*
 * Function: FUN_00081230
 * Entry:    00081230
 * Prototype: undefined __stdcall FUN_00081230(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_00081230(void)

{
  byte bVar1;
  GlassesState *pGVar2;
  
  pGVar2 = __get_dashboard_state();
  if ((pGVar2->field_0x10f4 != '\0') && (bVar1 = FUN_00081216(), bVar1 < 7)) {
    pGVar2 = __get_dashboard_state();
    pGVar2->field_0x10f4 = 0;
  }
  return;
}


