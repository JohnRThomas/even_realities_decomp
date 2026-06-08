/*
 * Function: FUN_00080732
 * Entry:    00080732
 * Prototype: undefined4 __stdcall FUN_00080732(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_00080732(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  return *(undefined4 *)&pGVar1->field_0xd0;
}


