/*
 * Function: FUN_0101e0e8
 * Entry:    0101e0e8
 * Prototype: undefined4 __stdcall FUN_0101e0e8(ushort param_1, int param_2, undefined4 param_3)
 */


undefined4 FUN_0101e0e8(ushort param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int extraout_r3;
  undefined4 extraout_r3_00;
  
  FUN_0100a848(param_1,param_2,param_3);
  if (*(byte *)(param_2 + 0x301) != 0x20) {
    FUN_0102491c((uint)*(byte *)(param_2 + 0x301),extraout_r1,extraout_r2,extraout_r3);
    cVar1 = FUN_010236bc((uint)*(byte *)(param_2 + 0x301));
    if (cVar1 == '\0') {
      FUN_01009500(0x36,0x98c,extraout_r2_00,extraout_r3_00);
      return 0;
    }
  }
  bVar2 = FUN_0101e4ec(param_2 + 0x2d8);
  if (!bVar2) {
    return 0;
  }
  uVar3 = FUN_0101e50c(param_2 + 0x2d8);
  return uVar3;
}


