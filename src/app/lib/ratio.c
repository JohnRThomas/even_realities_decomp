/*
 * Function: ratio
 * Entry:    0008ad94
 * Prototype: undefined4 __stdcall ratio(int param_1, int param_2)
 */


/* exclude_from_export_ai */

undefined4 ratio(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_s1;
  uint extraout_s1_00;
  ulonglong uVar6;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  uVar4 = b2d(param_1);
  uVar5 = b2d(param_2);
  iVar1 = (local_30 - uStack_2c) + (*(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10)) * 0x20;
  if (iVar1 < 1) {
    uVar3 = extraout_s1_00 + iVar1 * -0x100000;
    uVar2 = extraout_s1;
  }
  else {
    uVar2 = extraout_s1 + iVar1 * 0x100000;
    uVar3 = extraout_s1_00;
  }
  uVar6 = __divdf3(uVar4,uVar2,uVar5,uVar3);
  return (int)uVar6;
}


