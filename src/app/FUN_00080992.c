/*
 * Function: FUN_00080992
 * Entry:    00080992
 * Prototype: undefined __stdcall FUN_00080992(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_00080992(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  if (**(char **)&pGVar1->field_0x101c != '\0') {
    pGVar1 = __get_dashboard_state();
    **(undefined1 **)&pGVar1->field_0x101c = 0;
  }
  return;
}


