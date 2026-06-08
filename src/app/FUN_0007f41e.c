/*
 * Function: FUN_0007f41e
 * Entry:    0007f41e
 * Prototype: undefined __stdcall FUN_0007f41e(undefined1 param_1, undefined1 param_2)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_0007f41e(undefined1 param_1,undefined1 param_2)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xce = param_2;
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0xcc = param_1;
  return;
}


