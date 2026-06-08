/*
 * Function: FUN_00080724
 * Entry:    00080724
 * Prototype: undefined4 __stdcall FUN_00080724(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_00080724(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  return *(undefined4 *)pGVar1->glasses_state_struct_0FF0;
}


