/*
 * Function: FUN_00035e5c
 * Entry:    00035e5c
 * Prototype: undefined4 __stdcall FUN_00035e5c(void)
 */


undefined4 FUN_00035e5c(void)

{
  GlassesState *pGVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  pGVar1 = __get_dashboard_state();
  uVar3 = 0;
  if ((&DAT_2000878c)[((byte)pGVar1->field_0xdd - 1) * 0x6d] != 0) {
    uVar2 = FUN_00080732();
    pGVar1 = __get_dashboard_state();
    iVar4 = (&DAT_2000878c)[((byte)pGVar1->field_0xdd - 1) * 0x6d];
    pGVar1 = __get_dashboard_state();
    if ((uint)(byte)pGVar1->field_0x10d7 + iVar4 < uVar2) {
      uVar3 = 2;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}


