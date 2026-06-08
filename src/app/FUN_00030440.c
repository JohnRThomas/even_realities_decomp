/*
 * Function: FUN_00030440
 * Entry:    00030440
 * Prototype: undefined1 __stdcall FUN_00030440(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined1 FUN_00030440(void)

{
  undefined1 uVar1;
  GlassesState *pGVar2;
  
  pGVar2 = __get_dashboard_state();
  uVar1 = DAT_20003052;
  if (*(char *)pGVar2 != '\x01') {
    uVar1 = 0;
  }
  return uVar1;
}


