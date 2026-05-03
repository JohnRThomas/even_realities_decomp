/*
 * Function: FUN_0101e9e4
 * Entry:    0101e9e4
 * Prototype: undefined __stdcall FUN_0101e9e4(int param_1, int param_2)
 */


void FUN_0101e9e4(int param_1,int param_2)

{
  undefined1 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined8 uVar6;
  
  iVar3 = FUN_01022120();
  iVar4 = FUN_01022120();
  bVar5 = param_2 == iVar4;
  if (param_2 == iVar3) {
    bVar5 = bVar5 | 2;
  }
  uVar6 = FUN_010200cc();
  iVar3 = (int)uVar6;
  if (iVar3 << 0x17 < 0) {
    if (iVar3 << 0x14 < 0) {
      iVar3 = 0xf;
      bVar2 = true;
    }
    else {
      iVar3 = 3;
      bVar2 = false;
    }
  }
  else if (iVar3 << 0x17 < 0 || iVar3 << 0x14 < 0) {
    iVar3 = 0xd;
    bVar2 = true;
  }
  else {
    iVar3 = 1;
    bVar2 = false;
  }
  uVar1 = (undefined1)param_2;
  *(undefined1 *)(param_1 + 0x8d) = uVar1;
  *(byte *)(param_1 + 0x8c) = bVar5;
  if (iVar3 << 0x1e < 0) {
    *(undefined1 *)(param_1 + 0x8f) = uVar1;
    *(byte *)(param_1 + 0x8e) = bVar5;
  }
  if (iVar3 << 0x1d < 0) {
    *(undefined1 *)(param_1 + 0x91) = uVar1;
    *(byte *)(param_1 + 0x90) = bVar5;
  }
  if (bVar2) {
    *(undefined1 *)(param_1 + 0x93) = uVar1;
    *(byte *)(param_1 + 0x92) = bVar5;
  }
  return;
}


