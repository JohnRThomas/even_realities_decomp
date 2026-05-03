/*
 * Function: FUN_00030484
 * Entry:    00030484
 * Prototype: undefined4 __stdcall FUN_00030484(int param_1)
 */


undefined4 FUN_00030484(int param_1)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  if (*(char *)pGVar1 == '\x01') {
    if (param_1 == 0) {
      DAT_20003052 = 0;
    }
    else {
      DAT_20003052 = 2;
    }
  }
  return 0;
}


