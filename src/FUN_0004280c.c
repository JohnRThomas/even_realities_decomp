/*
 * Function: FUN_0004280c
 * Entry:    0004280c
 * Prototype: undefined4 __stdcall FUN_0004280c(void)
 */


undefined4 FUN_0004280c(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  memset(*(void **)&pGVar1->field_0x101c,0,0x21);
  DAT_2001db45 = 1;
  return 0;
}


