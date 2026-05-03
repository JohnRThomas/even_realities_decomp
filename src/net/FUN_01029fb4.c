/*
 * Function: FUN_01029fb4
 * Entry:    01029fb4
 * Prototype: bool __stdcall FUN_01029fb4(int param_1, int param_2, undefined1 * param_3)
 */


bool FUN_01029fb4(int param_1,int param_2,undefined1 *param_3)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar8;
  uint uVar9;
  uint extraout_r2;
  undefined1 uVar10;
  undefined1 uVar11;
  bool bVar12;
  
  bVar1 = FUN_0100f0b0(param_2);
  bVar2 = FUN_0100f0b8(param_2);
  uVar4 = FUN_01029f1e((uint)bVar2);
  uVar5 = FUN_01029f1e((uint)bVar1);
  uVar11 = (undefined1)(uVar4 | uVar5);
  if (((uVar4 | uVar5) & 0xff) != 0) {
    uVar11 = 1;
  }
  uVar6 = FUN_010200d8();
  if ((uVar6 & bVar2) == 0) {
    uVar4 = 0;
  }
  uVar6 = FUN_010200d8();
  if ((uVar6 & bVar1) == 0) {
    uVar5 = 0;
  }
  uVar6 = uVar4;
  if (*(byte *)(param_1 + 0x6e) == uVar4) {
    uVar6 = 0;
  }
  *param_3 = (char)uVar6;
  uVar9 = (uint)*(byte *)(param_1 + 0x6f);
  if (uVar9 == uVar5) {
    uVar5 = 0;
  }
  param_3[1] = (char)uVar5;
  uVar8 = extraout_r1;
  if ((uVar6 == 0 && uVar5 == 0) &&
     (sVar3 = FUN_0100f0c4(param_2), uVar8 = extraout_r1_00, uVar9 = extraout_r2,
     0x7ffd < (ushort)(sVar3 + ~*(ushort *)(param_1 + 0xbc)))) {
    uVar11 = 0;
  }
  if (uVar4 == 0) {
    iVar7 = FUN_01028c86((uint)*(byte *)(param_1 + 0x6e),uVar8,uVar9);
    bVar12 = iVar7 == 3;
  }
  else {
    bVar12 = uVar4 == 8;
  }
  if (!bVar12) {
    return (bool)uVar11;
  }
  if (*(char *)(param_1 + 0x16c) != '\x01') {
    return (bool)uVar11;
  }
  if (*(short *)(param_1 + 0x170) == 1) {
    if (*(char *)(param_1 + 0x6e) != '\x04') {
      uVar10 = 4;
      goto LAB_0102a06c;
    }
  }
  else if (*(char *)(param_1 + 0x6e) == '\b') {
    return (bool)uVar11;
  }
  uVar10 = 8;
LAB_0102a06c:
  *param_3 = uVar10;
  return (bool)uVar11;
}


