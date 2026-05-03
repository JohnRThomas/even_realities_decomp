/*
 * Function: FUN_0101b7a8
 * Entry:    0101b7a8
 * Prototype: uint __stdcall FUN_0101b7a8(byte * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Removing unreachable block (ram,0x0101b91a) */
/* WARNING: Removing unreachable block (ram,0x0101b94a) */

uint FUN_0101b7a8(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar8;
  undefined4 extraout_r2_03;
  uint uVar9;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar10;
  undefined4 extraout_r3_03;
  int unaff_r4;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte abStack_50 [28];
  undefined1 *puStack_34;
  code *UNRECOVERED_JUMPTABLE;
  int local_1c [4];
  
  local_1c[1] = (int)DAT_210010a0;
  if (local_1c[1] == 0) {
    bVar1 = *param_1;
    uVar11 = bVar1 & 1;
    if ((bVar1 & 1) == 0) {
      uVar9 = 1;
      uVar13 = 2;
      local_1c[0] = 0;
      DAT_210010a4 = uVar11;
      uVar2 = uVar11;
    }
    else {
      local_1c[0] = *(int *)(param_1 + 8);
      uVar13 = 3;
      uVar9 = 2;
      DAT_210010a4 = *(uint *)(param_1 + 4);
      uVar2 = 1;
    }
    uVar12 = uVar11;
    local_1c[2] = local_1c[1];
    if ((bVar1 & 2) != 0) {
      local_1c[uVar2] = *(int *)(param_1 + 0x10);
      DAT_210010a4 = *(uint *)(param_1 + 0xc);
      uVar11 = uVar9;
      uVar12 = uVar13;
    }
    if ((int)((uint)bVar1 << 0x1d) < 0) {
      uVar12 = uVar12 | 8;
      DAT_210010a4 = *(uint *)(param_1 + 0x14);
      local_1c[uVar11] = *(int *)(param_1 + 0x18);
    }
    else {
      uVar11 = uVar11 - 1 & 0xff;
    }
    DAT_210010cf = (byte)uVar11;
    DAT_21001104 = 0x271;
    DAT_21001100 = DAT_210010a4;
    iVar3 = FUN_0101a930();
    uVar11 = uVar12 & 1;
    if (uVar11 != 0) {
      DAT_210010a8 = local_1c[0] - iVar3;
    }
    uVar13 = uVar11;
    if ((int)(uVar12 << 0x1e) < 0) {
      uVar13 = uVar11 + 1;
      *(int *)(&DAT_210010a0 + (uVar11 + 2) * 4) = local_1c[uVar11] - iVar3;
    }
    if ((int)(uVar12 << 0x1c) < 0) {
      *(int *)(&DAT_210010a0 + (uVar13 + 2) * 4) = local_1c[uVar13] - iVar3;
    }
    return 0;
  }
  FUN_01009500(0x21,800,local_1c[1],param_4);
  bVar1 = DAT_210010a0;
  do {
    UNRECOVERED_JUMPTABLE = (code *)0x101b885;
  } while (DAT_210010a0 != 0);
  puStack_34 = &DAT_210010a0;
  pbVar4 = FUN_01019a04();
  DAT_210010a1 = bVar1;
  DAT_210010a0 = 4;
  DAT_210010ce = bVar1;
  DAT_21001114 = 0;
  iVar5 = FUN_0101a930();
  uVar11 = 0;
  iVar3 = 0;
  uVar13 = 0;
  do {
    iVar7 = uVar11 + 2;
    uVar13 = uVar13 + 1;
    uVar11 = uVar13 & 0xff;
    iVar3 = iVar3 + *(int *)(&DAT_210010a0 + iVar7 * 4) + iVar5;
  } while (uVar11 <= DAT_210010cf);
  DAT_210010f8 = iVar3;
  uVar11 = FUN_01023634(0x101b321,0);
  *pbVar4 = (byte)uVar11;
  uVar8 = extraout_r2;
  uVar10 = extraout_r3;
  if (uVar11 != 0x20) {
    pbVar6 = FUN_0101ab8c(abStack_50,1,(uint *)0x0,(uint *)(unaff_r4 >> 2));
    uVar8 = extraout_r2_00;
    uVar10 = extraout_r3_00;
    if (pbVar6 != (byte *)0x0) {
      uVar11 = FUN_010239c8((uint)*pbVar4,abStack_50);
      if (uVar11 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0101b90c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar11 = (*UNRECOVERED_JUMPTABLE)(0);
        return uVar11;
      }
      FUN_01009500(0x21,0x369,extraout_r2_01,extraout_r3_01);
      uVar8 = extraout_r2_02;
      uVar10 = extraout_r3_02;
    }
    FUN_01009500(0x21,0x368,uVar8,uVar10);
    uVar8 = extraout_r2_03;
    uVar10 = extraout_r3_03;
  }
  FUN_01009500(0x21,0x366,uVar8,uVar10);
  uVar11 = (iVar3 >> 2) - (unaff_r4 >> 2);
  if (uVar11 < *(int *)(pbVar4 + 0x38) - 0x11aU) {
    uVar13 = 1;
  }
  else {
    uVar13 = 0;
    iVar3 = FUN_0101aa18();
    if (iVar3 != 0) {
      return (uint)(uVar11 < *(int *)(pbVar4 + 0x38) - 0x11aU);
    }
  }
  return uVar13;
}


