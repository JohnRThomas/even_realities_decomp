/*
 * Function: FUN_00080732
 * Entry:    00080732
 * Prototype: undefined4 __stdcall FUN_00080732(void)
 */


undefined4 FUN_00080732(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  return *(undefined4 *)(pGVar1->field20_0xc8 + 8);
}


