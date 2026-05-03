/*
 * Function: FUN_0101e660
 * Entry:    0101e660
 * Prototype: undefined __stdcall FUN_0101e660(int param_1, undefined4 param_2, uint param_3)
 */


void FUN_0101e660(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar3 = *(int *)(param_1 + 0x20);
  if (iVar3 != 0) {
    param_3 = *(uint *)(param_1 + 8);
    uVar4 = *(uint *)(iVar3 + 8);
    if (uVar4 <= param_3) {
      iVar2 = *(int *)(param_1 + 0x18);
      iVar5 = *(int *)(param_1 + 0x1c);
      uVar6 = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(iVar3 + 0x1c) = uVar6;
      iVar1 = iVar3;
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x18) = iVar3;
        iVar2 = *(int *)(iVar3 + 0x18);
        iVar1 = DAT_2100113c;
      }
      DAT_2100113c = iVar1;
      if (iVar2 == 0) {
        *(undefined4 *)(iVar3 + 0xc) = 0;
        return;
      }
      iVar1 = *(int *)(param_1 + 0xc);
      *(int *)(iVar2 + 0x1c) = iVar3;
      *(uint *)(iVar3 + 0xc) = (param_3 + iVar1) - uVar4;
      return;
    }
  }
  FUN_01009500(0x37,0xcd,param_3,iVar3);
  DAT_21001140._0_1_ = 1;
  return;
}


