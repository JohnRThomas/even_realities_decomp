/*
 * Function: ?_set_date
 * Entry:    0008073e
 * Prototype: undefined4 __stdcall ?_set_date(undefined4 param_1)
 */


undefined4 __set_date(undefined4 param_1)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  *(undefined4 *)(pGVar1->field20_0xc8 + 8) = param_1;
  return param_1;
}


