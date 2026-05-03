/*
 * Function: FUN_01029d16
 * Entry:    01029d16
 * Prototype: undefined __stdcall FUN_01029d16(void)
 */


void FUN_01029d16(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined8 uVar2;
  
  FUN_01027d4c(1);
  uVar2 = FUN_01027d4c(0);
  FUN_0100a8dc((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  FUN_0100b0c4();
  iVar1 = FUN_0100b958();
  if (iVar1 != 0) {
    FUN_01009500(1,0xf9,extraout_r2,extraout_r3);
  }
  return;
}


