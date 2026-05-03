/*
 * Function: FUN_0002715c
 * Entry:    0002715c
 * Prototype: undefined __stdcall FUN_0002715c(uint param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0002715c(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_r2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  iVar1 = FUN_0007fc38((int)global_st25dv_context_ptr,param_1 & 0xff,param_3);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_0007fc50(global_st25dv_context_ptr,(int)&uStack_14 + 3), iVar1 == 0)) {
    uVar2 = (param_1 << 0x16) >> 0x1e | 0xc;
    uStack_14 = CONCAT13((char)uVar2,(undefined3)uStack_14);
    FUN_0007fc62(global_st25dv_context_ptr,uVar2,extraout_r2);
  }
  return;
}


