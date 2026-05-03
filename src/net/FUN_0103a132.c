/*
 * Function: FUN_0103a132
 * Entry:    0103a132
 * Prototype: undefined __stdcall FUN_0103a132(int param_1, int param_2)
 */


void FUN_0103a132(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 uVar3;
  undefined4 extraout_r3_00;
  uint uVar4;
  int iVar5;
  
  uVar4 = *(uint *)(param_1 + 8);
  uVar1 = FUN_01039f28(param_1,param_2);
  if ((0x7fff < uVar4) && (uVar1 == 1)) {
    return;
  }
  uVar1 = FUN_01039f92(uVar4);
  iVar2 = param_1 + uVar1 * 4;
  iVar5 = *(int *)(iVar2 + 0x10);
  if (iVar5 == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1 << (uVar1 & 0xff);
    *(int *)(iVar2 + 0x10) = param_2;
    FUN_01039f12(param_1,param_2,2,param_2);
    iVar2 = 3;
    iVar5 = param_2;
    uVar3 = extraout_r3;
  }
  else {
    uVar1 = FUN_01039efc(param_1,iVar5,2);
    FUN_01039f12(param_1,param_2,extraout_r2,uVar1);
    FUN_01039f12(param_1,param_2,3,iVar5);
    FUN_01039f12(param_1,uVar1,extraout_r2_00,param_2);
    iVar2 = 2;
    uVar3 = extraout_r3_00;
  }
  FUN_01039f12(param_1,iVar5,iVar2,uVar3);
  return;
}


