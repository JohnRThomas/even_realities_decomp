/*
 * Function: FUN_0100afcc
 * Entry:    0100afcc
 * Prototype: undefined __stdcall FUN_0100afcc(void)
 */


void FUN_0100afcc(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  iVar2 = FUN_0102a9e2(&DAT_21000bf4);
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = FUN_01009500(0x1d,0x30,extraout_r2,extraout_r3);
  }
  DAT_21000bf5 = uVar1;
  return;
}


