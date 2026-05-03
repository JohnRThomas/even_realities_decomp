/*
 * Function: FUN_010121ac
 * Entry:    010121ac
 * Prototype: undefined __stdcall FUN_010121ac(undefined1 * param_1, int param_2, undefined4 param_3)
 */


void FUN_010121ac(undefined1 *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 extraout_r1;
  uint uVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int iVar6;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar7;
  undefined4 extraout_r3_02;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  int unaff_r6;
  byte *unaff_r7;
  byte *pbVar8;
  undefined4 *unaff_r8;
  undefined4 unaff_lr;
  
  do {
    *(undefined4 *)((int)register0x00000054 + -4) = unaff_lr;
    *(undefined4 **)((int)register0x00000054 + -8) = unaff_r8;
    *(byte **)((int)register0x00000054 + -0xc) = unaff_r7;
    *(int *)((int)register0x00000054 + -0x10) = unaff_r6;
    *(undefined4 *)((int)register0x00000054 + -0x14) = unaff_r5;
    *(undefined4 *)((int)register0x00000054 + -0x18) = unaff_r4;
    if (param_2 != 0) {
      pbVar8 = param_1 + 0x28;
      uVar5 = FUN_010132d4(pbVar8);
      if (uVar5 == 0) {
        iVar6 = (uint)*(ushort *)(param_1 + 2) << 0x1c;
        if (-1 < iVar6) {
          FUN_01011e64(param_1,extraout_r1,iVar6,(uint)*(ushort *)(param_1 + 2));
          return;
        }
        uVar5 = FUN_01013324(pbVar8);
        uVar2 = FUN_010132d4(pbVar8);
        iVar6 = FUN_01013398(uVar5 - uVar2 & 0xff);
        DAT_21000f28 = DAT_21000f28 + iVar6;
        FUN_010131e8((int)pbVar8);
      }
      uVar3 = FUN_010131f4((int)pbVar8);
      FUN_01020cf4((char)uVar3);
      FUN_01020afc(0x25,(uint)(byte)param_1[4],extraout_r2_01);
      param_3 = extraout_r2_02;
    }
    pbVar8 = DAT_21000f20;
    unaff_r7 = (byte *)(uint)(byte)param_1[0x6e];
    pbVar8[0] = 0;
    pbVar8[1] = 0;
    switch(*(ushort *)(param_1 + 2)) {
    case 0x10:
      FUN_0100e7bc(pbVar8,2);
      pbVar8 = DAT_21000f20;
      break;
    default:
      FUN_01009500(0x2d,0x64a,param_3,*(ushort *)(param_1 + 2) - 0x10);
      uVar3 = extraout_r2_04;
      iVar6 = extraout_r3_00;
      unaff_r6 = param_2;
      goto switchD_01012296_caseD_11;
    case 0x12:
      FUN_0100e7bc(pbVar8,6);
      pbVar8 = DAT_21000f20;
      break;
    case 0x13:
      FUN_0100e7bc(pbVar8,0);
      pbVar8 = DAT_21000f20;
      *DAT_21000f20 = *DAT_21000f20 & 0xdf | 0x20;
      break;
    case 0x15:
    case 0x1d:
      FUN_0100e7bc(pbVar8,1);
      pbVar8 = DAT_21000f20;
      *DAT_21000f20 = *DAT_21000f20 & 0xdf | 0x20;
      if (unaff_r7 == (byte *)0x0) {
        FUN_0100e828((int)pbVar8,(undefined4 *)(param_1 + 0x68));
        FUN_0100e854(DAT_21000f20,param_1[0x67]);
        pbVar8 = DAT_21000f20;
      }
      else {
        FUN_0100e828((int)pbVar8,(undefined4 *)(param_1 + 0x6f));
        FUN_0100e854(DAT_21000f20,'\x01');
        pbVar8 = DAT_21000f20;
      }
    }
    FUN_0100e808((int)pbVar8,(undefined4 *)(param_1 + 0x61));
    FUN_0100e838(DAT_21000f20,param_1[0x60]);
    if ((*(ushort *)(param_1 + 2) & 0xfff7) != 0x15) {
      FUN_0100e86c((int)DAT_21000f20,*(undefined4 **)(param_1 + 0x48),(uint)(byte)param_1[0x4c],
                   (uint)(*(ushort *)(param_1 + 2) & 0xfff7));
    }
    FUN_01020f64((uint)DAT_21000f20);
    iVar6 = DAT_21000f2c;
    DAT_21000f24 = 4;
    uVar3 = extraout_r2;
    if (param_2 == 0) {
LAB_0101228e:
      iVar6 = *(ushort *)(param_1 + 2) - 0x10;
      unaff_r6 = param_2;
      switch(*(ushort *)(param_1 + 2)) {
      case 0x10:
        return;
      case 0x12:
      case 0x13:
      case 0x15:
      case 0x1d:
        FUN_010210f0(0,1,(uint)(byte)param_1[4]);
        return;
      }
switchD_01012296_caseD_11:
      FUN_01009500(0x2d,0xd79,uVar3,iVar6);
      uVar3 = extraout_r2_05;
      uVar7 = extraout_r3_01;
    }
    else {
      if (*(short *)(param_1 + 2) == 0x10) {
        FUN_01021908(0,(undefined4 *)(uint)(byte)param_1[4]);
        uVar3 = extraout_r2_03;
        goto LAB_0101228e;
      }
      unaff_r7 = param_1 + 0x28;
      uVar5 = FUN_01013324(unaff_r7);
      unaff_r6 = uVar5 - 1;
      uVar5 = FUN_010132d4(unaff_r7);
      uVar5 = FUN_010133a4(unaff_r6 - uVar5 & 0xff,(uint)*(ushort *)(param_1 + 2),0x28);
      unaff_r8 = (undefined4 *)(iVar6 + uVar5);
      if ((int)((uint)*(ushort *)(param_1 + 2) << 0x1c) < 0) {
        unaff_r8 = (undefined4 *)((int)unaff_r8 + DAT_21000f28);
        iVar6 = FUN_01013348();
        *(int *)(param_1 + 0x110) = iVar6 + (int)unaff_r8;
      }
      puVar1 = FUN_0102126c((undefined *)0x0,unaff_r8,(undefined4 *)(uint)(byte)param_1[4]);
      uVar3 = extraout_r2_00;
      uVar7 = extraout_r3;
      param_2 = unaff_r6;
      if (puVar1 != (undefined4 *)0x0) goto LAB_0101228e;
    }
    FUN_01009500(0x2d,0xd65,uVar3,uVar7);
    puVar4 = (undefined1 *)((uint)param_1 >> 0x1c);
    puVar1 = (undefined4 *)((int)register0x00000054 + -0x1c);
    *puVar1 = 0x1012383;
    *(byte ***)((int)register0x00000054 + -0x20) = &DAT_21000f20;
    *(undefined4 *)((int)register0x00000054 + -0x24) = param_1;
    *(undefined4 *)((int)register0x00000054 + -0x28) = extraout_r3_02;
    if (*(short *)(puVar4 + 2) != 0x10) {
      if (DAT_21000f32 != '\0') {
        FUN_01020470();
        FUN_01021098(0x40);
      }
      FUN_01020f64((uint)DAT_21000f20);
      uVar5 = *(ushort *)(puVar4 + 2) & 4;
      if ((*(ushort *)(puVar4 + 2) & 4) != 0) {
        FUN_01021020(0);
        DAT_21000f24 = 2;
                    /* WARNING: Could not recover jumptable at 0x010123b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)*puVar1)();
        return;
      }
      FUN_010210f0((char)uVar5,uVar5,(uint)(byte)puVar4[4]);
      FUN_01021020(0);
      DAT_21000f24 = 2;
                    /* WARNING: Could not recover jumptable at 0x010123d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar1)();
      return;
    }
    param_2 = 1;
    unaff_r4 = *(undefined4 *)((int)register0x00000054 + -0x24);
    unaff_r5 = *(undefined4 *)((int)register0x00000054 + -0x20);
    unaff_lr = *puVar1;
    param_1 = puVar4;
    param_3 = extraout_r2_06;
    register0x00000054 = (BADSPACEBASE *)((int)register0x00000054 + -0x18);
  } while( true );
}


