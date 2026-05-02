/*
 * Function: ?_get_something_from_glasses_state
 * Entry:    00080bb4
 * Prototype: undefined1 * __stdcall ?_get_something_from_glasses_state(void)
 */


undefined1 * __get_something_from_glasses_state(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  return &pGVar1->field_0xb6c;
}


