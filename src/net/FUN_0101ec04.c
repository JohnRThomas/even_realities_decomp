/*
 * Function: FUN_0101ec04
 * Entry:    0101ec04
 * Prototype: undefined4 __stdcall FUN_0101ec04(uint param_1)
 */


undefined4 FUN_0101ec04(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_1 >> 0x10;
  if (uVar7 - 0x5554 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if ((undefined *)(uVar7 & 0xffff7fff) != &DAT_00002aaa) {
      uVar1 = 1;
    }
  }
  uVar3 = 0;
  iVar2 = 0x16;
  uVar6 = 0;
  uVar4 = param_1 >> 10 & 0x3fffe0;
  uVar5 = 0x1f;
  do {
    if ((uVar3 | ~(uVar7 ^ uVar6)) == 0xffffffff) {
      return 0;
    }
    iVar2 = iVar2 + -1;
    uVar6 = (uVar4 & 1) << 0xf | uVar6 >> 1;
    uVar3 = (uVar5 & 1) << 0xf | uVar3 >> 1;
    uVar4 = uVar4 >> 1;
    uVar5 = uVar5 >> 1;
  } while (iVar2 != 0);
  return uVar1;
}


