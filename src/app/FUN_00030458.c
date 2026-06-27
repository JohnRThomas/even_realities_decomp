/*
 * Function: FUN_00030458
 * Entry:    00030458
 * Prototype: undefined4 __stdcall FUN_00030458(void)
 */


undefined4 FUN_00030458(void)

{
  char cVar1;
  GlassesState *pGVar2;
  
  if ((DAT_20003052 != '\x01') &&
     ((cVar1 = FUN_00033d5c(), cVar1 == '\x01' ||
      (pGVar2 = __get_dashboard_state(), *(char *)pGVar2 == '\x01')))) {
    DAT_20003052 = '\x01';
  }
  return 0;
}


