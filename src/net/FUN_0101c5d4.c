/*
 * Function: FUN_0101c5d4
 * Entry:    0101c5d4
 * Prototype: undefined __stdcall FUN_0101c5d4(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0101c5d4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 *extraout_r2_01;
  int iVar5;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 unaff_r6;
  byte abStack_28 [24];
  
  switch(param_2) {
  case 0:
    if (DAT_2100111c == '\0') {
      FUN_0101bfe4((char *)abStack_28,param_1,1,(undefined4 *)0x0);
      uVar3 = FUN_010239c8((uint)*(byte *)((int)param_1 + 0x301),abStack_28);
      if (uVar3 == 0) {
        FUN_01009500(0x35,0x2d4,extraout_r2,extraout_r3);
        param_3 = extraout_r2_00;
        param_4 = extraout_r3_00;
        goto switchD_0101c5de_default;
      }
      *(short *)(param_1 + 0x2f) = *(short *)(param_1 + 0x2f) + 1;
      goto LAB_0101c5ee;
    }
switchD_0101c5de_caseD_2:
    *(undefined1 *)(param_1 + 0xc0) = 4;
LAB_0101c5ee:
    FUN_01020e34();
    FUN_01023284();
    return;
  case 1:
    *(undefined1 *)(param_1 + 0xc0) = 3;
    return;
  case 2:
    goto switchD_0101c5de_caseD_2;
  case 3:
    param_1[9] = param_1[0xc9];
    bVar1 = *(byte *)((int)param_1 + 0x6f);
    param_1[0xc2] = param_1[5];
    *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 200);
    uVar2 = *(ushort *)(&DAT_0103c250 + (uint)*(byte *)((int)param_1 + 0x6e) * 2);
    param_1[5] = param_1[0xca];
    param_1[7] = param_1[0xcb];
    iVar4 = FUN_010211f0((uint)bVar1);
    if ((bVar1 & 0xc) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0x28;
    }
    FUN_0100fc8c((uint)param_1,iVar5 + (uVar2 + 0x79d + iVar4) / 1000 + 199);
    *(undefined1 *)(param_1 + 0xc0) = 2;
    return;
  case 4:
    bVar1 = *(byte *)((int)param_1 + 0x6f);
    uVar2 = *(ushort *)(&DAT_0103c250 + (uint)*(byte *)((int)param_1 + 0x6e) * 2);
    iVar4 = FUN_010211f0((uint)bVar1);
    if ((bVar1 & 0xc) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0x28;
    }
    FUN_0100fc8c((uint)param_1,iVar5 + (uVar2 + 0x79d + iVar4) / 1000 + 199);
    return;
  default:
switchD_0101c5de_default:
    iVar4 = FUN_01009500(0x35,0x329,param_3,param_4);
    *extraout_r2_01 = param_1;
    extraout_r2_01[1] = unaff_r6;
    iVar4 = *(int *)(iVar4 + 4);
    if (*(char *)(iVar4 + 0xc5) != '\x03') {
      *(undefined1 *)(iVar4 + 0x104) = 0;
      return;
    }
    *(undefined1 *)(iVar4 + 0x100) = 0;
    *(undefined1 *)(iVar4 + 0xc5) = 0;
    return;
  }
}


