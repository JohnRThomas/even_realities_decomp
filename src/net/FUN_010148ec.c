/*
 * Function: FUN_010148ec
 * Entry:    010148ec
 * Prototype: undefined * __stdcall FUN_010148ec(undefined1 * param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


undefined * FUN_010148ec(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  
  if (param_2 != 0) {
    if (param_2 == 1) {
      param_1[0x108] = 0;
      FUN_01020e34();
      puVar1 = FUN_01023284();
      return puVar1;
    }
    FUN_01009500(0x30,0x7dd,param_3,param_4);
    uVar4 = extraout_r2_00;
    uVar5 = extraout_r3_00;
LAB_010149c8:
    iVar3 = FUN_01009500(0x30,0x737,uVar4,uVar5);
    return (undefined *)(uint)*(byte *)(iVar3 + 0x120);
  }
  iVar3 = 0;
  if (*(short *)(param_1 + 0x22) != 0) {
    uVar7 = FUN_0100fe3c();
    iVar3 = uVar7 - (uVar7 / *(ushort *)(param_1 + 0x22)) * (uint)*(ushort *)(param_1 + 0x22);
  }
  uVar7 = *(uint *)(param_1 + 0x118);
  iVar6 = *(int *)(param_1 + 0x11c);
  iVar2 = FUN_01012b2c((int)param_1);
  *(undefined2 *)(param_1 + 0x132) = 0x102;
  *(uint *)(param_1 + 0x138) = iVar2 + iVar3 + uVar7;
  param_1[0x128] = 0;
  *(uint *)(param_1 + 0x13c) = iVar6 + (uint)CARRY4(iVar2 + iVar3,uVar7);
  iVar3 = FUN_01013414((int)param_1);
  *(short *)(param_1 + 0x130) = (short)iVar3;
  uVar7 = *(uint *)(param_1 + 0x138);
  iVar3 = *(int *)(param_1 + 0x13c);
  *(uint *)(param_1 + 0x118) = uVar7;
  *(int *)(param_1 + 0x11c) = iVar3;
  if (param_1[0x148] == '\0') {
    if ((*(int *)(param_1 + 0x144) == 0x7fffffff && *(int *)(param_1 + 0x140) == -1) ||
       (uVar8 = FUN_01012ab4((int)param_1,0),
       -1 < (int)(((*(int *)(param_1 + 0x144) - iVar3) - (uint)(*(uint *)(param_1 + 0x140) < uVar7))
                 - (uint)(*(uint *)(param_1 + 0x140) - uVar7 < (int)uVar8 + 0x152U)))) {
      uVar7 = FUN_010239c8((uint)(byte)param_1[0x100],param_1 + 0x128);
      uVar4 = extraout_r2;
      uVar5 = extraout_r3;
      if (uVar7 == 0) goto LAB_010149c8;
    }
    else {
      FUN_010130bc(param_1);
    }
  }
  *(undefined2 *)(param_1 + 0x122) = 0;
  FUN_01020e34();
  puVar1 = FUN_01023284();
  return puVar1;
}


