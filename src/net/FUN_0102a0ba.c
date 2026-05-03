/*
 * Function: FUN_0102a0ba
 * Entry:    0102a0ba
 * Prototype: undefined __stdcall FUN_0102a0ba(int param_1, uint param_2, uint param_3)
 */


void FUN_0102a0ba(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 4);
  bVar1 = *(byte *)(iVar6 + 0x6e);
  bVar2 = *(byte *)(iVar6 + 0x6f);
  uVar4 = FUN_01029f38(param_2,param_3);
  uVar5 = (undefined1)uVar4;
  uVar3 = (undefined1)(uVar4 >> 8);
  if ((uint)bVar1 == (uVar4 & 0xff)) {
    uVar5 = 0;
  }
  if ((uint)bVar2 == (uVar4 << 0x10) >> 0x18) {
    uVar3 = 0;
  }
  *(undefined1 *)(iVar6 + 0x31a) = uVar5;
  *(undefined1 *)(iVar6 + 0x31b) = uVar3;
  return;
}


