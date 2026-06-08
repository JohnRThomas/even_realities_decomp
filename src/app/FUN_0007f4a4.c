/*
 * Function: FUN_0007f4a4
 * Entry:    0007f4a4
 * Prototype: undefined4 __stdcall FUN_0007f4a4(undefined1 param_1, undefined1 param_2, int param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_0007f4a4(undefined1 param_1,undefined1 param_2,int param_3)

{
  GlassesState *pGVar1;
  
  if (param_3 == 0) {
    pGVar1 = __get_dashboard_state();
    pGVar1->field_0xcf = param_2;
    pGVar1 = __get_dashboard_state();
    pGVar1->field_0xcd = param_1;
  }
  else {
    FUN_0007f41e(param_1,param_2);
  }
  return 0;
}


