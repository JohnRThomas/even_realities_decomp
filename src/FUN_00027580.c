/*
 * Function: FUN_00027580
 * Entry:    00027580
 * Prototype: undefined4 __stdcall FUN_00027580(void)
 */


undefined4 FUN_00027580(void)

{
  GlassesState *pGVar1;
  undefined4 uVar2;
  
  if (DAT_20008404 < 0x13ed) {
    uVar2 = 2;
  }
  else {
    pGVar1 = __get_dashboard_state();
    if ((byte)pGVar1->field_0xfc4 < 100) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}


