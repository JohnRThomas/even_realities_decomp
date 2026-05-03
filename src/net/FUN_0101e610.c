/*
 * Function: FUN_0101e610
 * Entry:    0101e610
 * Prototype: ulonglong __stdcall FUN_0101e610(uint param_1, int param_2, uint param_3, undefined4 param_4, uint param_5, int param_6)
 */


ulonglong FUN_0101e610(uint param_1,int param_2,uint param_3,undefined4 param_4,uint param_5,
                      int param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint extraout_r2;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  
  uVar1 = param_1 - param_5;
  iVar4 = (param_2 - param_6) - (uint)(param_1 < param_5);
  iVar7 = iVar4 + (uint)(0x80000000 < uVar1);
  bVar9 = uVar1 + 0x7fffffff < 0xfffffffe;
  if ((uint)-iVar7 < (uint)bVar9) {
    if (iVar4 < 0) {
      iVar2 = -uVar1 - param_3 * (-uVar1 / param_3);
      iVar7 = 0;
      if (iVar2 != 0) {
        return CONCAT44(iVar4,param_3 - iVar2);
      }
    }
    else {
      iVar7 = uVar1 - param_3 * (uVar1 / param_3);
    }
    return CONCAT44(iVar4,iVar7);
  }
  uVar3 = FUN_01009500(0x37,0xbd,param_3,-(uint)!bVar9 - iVar7);
  iVar4 = *(int *)(uVar3 + 0x20);
  uVar1 = extraout_r2;
  if (iVar4 != 0) {
    uVar1 = *(uint *)(uVar3 + 8);
    uVar5 = *(uint *)(iVar4 + 8);
    if (uVar5 <= uVar1) {
      iVar7 = *(int *)(uVar3 + 0x18);
      iVar6 = *(int *)(uVar3 + 0x1c);
      uVar8 = *(undefined4 *)(uVar3 + 0x1c);
      *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(uVar3 + 0x18);
      *(undefined4 *)(iVar4 + 0x1c) = uVar8;
      iVar2 = iVar4;
      if (iVar6 != 0) {
        *(int *)(iVar6 + 0x18) = iVar4;
        iVar7 = *(int *)(iVar4 + 0x18);
        iVar2 = DAT_2100113c;
      }
      DAT_2100113c = iVar2;
      if (iVar7 == 0) {
        *(undefined4 *)(iVar4 + 0xc) = 0;
        return (ulonglong)uVar3;
      }
      iVar2 = *(int *)(uVar3 + 0xc);
      *(int *)(iVar7 + 0x1c) = iVar4;
      *(uint *)(iVar4 + 0xc) = (uVar1 + iVar2) - uVar5;
      return CONCAT44(iVar7,iVar2);
    }
  }
  uVar1 = FUN_01009500(0x37,0xcd,uVar1,iVar4);
  DAT_21001140._0_1_ = 1;
  return (ulonglong)uVar1;
}


