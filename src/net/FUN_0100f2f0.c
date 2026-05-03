/*
 * Function: FUN_0100f2f0
 * Entry:    0100f2f0
 * Prototype: undefined __stdcall FUN_0100f2f0(ushort param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0100f2f0(ushort param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short *psVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar7;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 uVar8;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 extraout_r3_09;
  undefined4 extraout_r3_10;
  undefined4 extraout_r3_11;
  byte *local_14 [2];
  
  if (param_2 == (undefined4 *)0x0) goto LAB_0100f3a8;
  *(ushort *)(param_2 + 1) = param_1;
  *(undefined1 *)((int)param_2 + 9) = 0;
  psVar4 = (short *)FUN_0100a918(param_1,param_2,0);
  puVar5 = (undefined2 *)FUN_01027844((int)psVar4);
  uVar7 = extraout_r2;
  uVar8 = extraout_r3;
  if (puVar5 != (undefined2 *)0x0) {
    uVar2 = FUN_0102789e((int)psVar4,puVar5,(int *)local_14);
    *(ushort *)((int)param_2 + 6) = uVar2;
    uVar7 = extraout_r2_00;
    uVar8 = extraout_r3_00;
    if (uVar2 != 0) {
      if (uVar2 < 0xfc) {
        bVar1 = FUN_0100edec(local_14[0]);
        if ((bVar1 == 1) || (bVar1 == 2)) {
          *(byte *)(param_2 + 2) = bVar1;
          uVar7 = extraout_r2_01;
          uVar8 = extraout_r3_01;
          if ((undefined4 *)*param_2 == (undefined4 *)0x0) goto LAB_0100f36c;
          FUN_01026198((undefined4 *)*param_2,(undefined4 *)(local_14[0] + 3),
                       (uint)*(ushort *)((int)param_2 + 6));
          iVar6 = FUN_010278e8(psVar4);
          uVar7 = extraout_r2_02;
          uVar8 = extraout_r3_02;
          if (iVar6 != 0) {
            sVar3 = FUN_01027494(psVar4,(undefined4 *)0x0);
            uVar7 = extraout_r2_03;
            uVar8 = extraout_r3_03;
            if (sVar3 != 0) {
              if (DAT_21000ec2._1_1_ != '\0') {
                DAT_21000ec4 = DAT_21000ec4 + -1;
              }
              return;
            }
            goto LAB_0100f376;
          }
        }
        else {
          FUN_01009500(0x10,0x130,extraout_r2_01,extraout_r3_01);
          uVar7 = extraout_r2_04;
          uVar8 = extraout_r3_04;
LAB_0100f36c:
          FUN_01009500(0x10,0x137,uVar7,uVar8);
          uVar7 = extraout_r2_05;
          uVar8 = extraout_r3_05;
LAB_0100f376:
          FUN_01009500(0x10,0x141,uVar7,uVar8);
          uVar7 = extraout_r2_06;
          uVar8 = extraout_r3_06;
        }
        FUN_01009500(0x10,0x13c,uVar7,uVar8);
        uVar7 = extraout_r2_07;
        uVar8 = extraout_r3_07;
      }
      FUN_01009500(0x10,0x120,uVar7,uVar8);
      uVar7 = extraout_r2_08;
      uVar8 = extraout_r3_08;
    }
    FUN_01009500(0x10,0x11e,uVar7,uVar8);
    uVar7 = extraout_r2_09;
    uVar8 = extraout_r3_09;
  }
  FUN_01009500(0x10,0x119,uVar7,uVar8);
  param_3 = extraout_r2_10;
  param_4 = extraout_r3_10;
LAB_0100f3a8:
  FUN_01009500(0x10,0x110,param_3,param_4);
  DAT_21000ec8 = FUN_01009500(0x10,0x2bf,extraout_r2_11,extraout_r3_11);
  DAT_21000ee0 = 0;
  DAT_21000ee4 = 0;
  DAT_21000ef0 = 0;
  DAT_21000ed4 = 0;
  DAT_21000edc = 0;
  DAT_21000ee8 = 0;
  DAT_21000eec = 0;
  DAT_21000ed8 = 1;
  DAT_21000ecc = &DAT_21000ed0;
  DAT_21000ed0 = &DAT_21000ed0;
  return;
}


