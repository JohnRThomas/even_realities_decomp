/*
 * Function: FUN_0102a34e
 * Entry:    0102a34e
 * Prototype: uint __stdcall FUN_0102a34e(int param_1)
 */


uint FUN_0102a34e(int param_1)

{
  bool bVar1;
  uint uVar2;
  int extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  int extraout_r3;
  ulonglong uVar3;
  
  bVar1 = FUN_0102a338(param_1);
  uVar2 = 0;
  if (bVar1) {
    bVar1 = FUN_0102a312(param_1);
    uVar2 = (uint)bVar1;
    if (extraout_r1 == 1) {
      *(undefined1 *)(param_1 + 0x10) = 7;
      FUN_01023fb0((uint)*(byte *)(param_1 + 4));
      uVar3 = FUN_0102491c((uint)*(byte *)(param_1 + 4),extraout_r1_00,extraout_r2,extraout_r3);
      uVar2 = (uint)uVar3;
    }
    *(undefined1 *)(param_1 + 0x10) = 1;
    if (bVar1 != 0) {
      uVar2 = FUN_0101e50c(param_1 + 0x20);
      return uVar2;
    }
  }
  return uVar2;
}


