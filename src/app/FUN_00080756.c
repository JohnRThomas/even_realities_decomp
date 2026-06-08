/*
 * Function: FUN_00080756
 * Entry:    00080756
 * Prototype: undefined4 __stdcall FUN_00080756(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_00080756(void)

{
  GlassesState *pGVar1;
  undefined4 uVar2;
  
  pGVar1 = __get_dashboard_state();
  if ((byte)pGVar1->field_0xfc4 < 0x15) {
    uVar2 = 0;
  }
  else {
    pGVar1 = __get_dashboard_state();
    if ((byte)pGVar1->field_0xfc5 < 0x15) {
      pGVar1 = __get_dashboard_state();
      uVar2 = 0xffffffff;
      if (2 < (byte)pGVar1->field_0xfc5) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


