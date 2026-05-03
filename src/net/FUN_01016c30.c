/*
 * Function: FUN_01016c30
 * Entry:    01016c30
 * Prototype: uint __stdcall FUN_01016c30(int param_1, uint param_2)
 */


/* WARNING: Control flow encountered bad instruction data */

uint FUN_01016c30(int param_1,uint param_2)

{
  undefined1 uVar1;
  byte bVar2;
  bool bVar3;
  ushort *puVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  uint extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 uVar7;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 extraout_r2_14;
  undefined4 extraout_r2_15;
  undefined4 extraout_r2_16;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar8;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  uint extraout_r3_06;
  uint extraout_r3_07;
  uint extraout_r3_08;
  uint extraout_r3_09;
  uint extraout_r3_10;
  undefined4 *puVar9;
  
  uVar1 = *(undefined1 *)((int)&DAT_0103c20c + (uint)DAT_2100100a);
  FUN_01020cf4(uVar1);
  puVar9 = (undefined4 *)(uint)(byte)(&DAT_2100104d)[DAT_21001028];
  DAT_2100101f = uVar1;
  switch(puVar9) {
  case (undefined4 *)0x1:
  case (undefined4 *)0x4:
  case (undefined4 *)0x8:
    bVar2 = FUN_0100adb4();
    uVar5 = (uint)bVar2;
    uVar7 = extraout_r2_00;
    if (0x3f < uVar5) {
      uVar5 = 0x40;
    }
    break;
  case (undefined4 *)0x2:
    uVar5 = 0xd;
    uVar7 = extraout_r2;
    break;
  default:
    FUN_01009500(0x32,0x90f,extraout_r2,(int)puVar9 + -1);
    *(int *)extraout_r2_01 = extraout_r2_01;
    *(undefined4 *)(extraout_r2_01 + 4) = extraout_r3;
    puVar4 = (ushort *)FUN_0100ada0();
    bVar2 = FUN_0100adb4();
    uVar5 = FUN_01027648(puVar4,(ushort)bVar2);
    if (uVar5 != 0) {
      FUN_01020f64(uVar5);
      FUN_01021020(0);
      DAT_21001000 = 6;
                    /* WARNING: Could not recover jumptable at 0x01016cda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)0x1016ca7)();
      return uVar5;
    }
    FUN_01009500(0x32,0x61b,extraout_r2_02,extraout_r3_00);
    FUN_01020afc(0xff,(uint)DAT_21001049,extraout_r2_03);
    puVar4 = (ushort *)FUN_0100ada0();
    bVar2 = FUN_0100adb4();
    uVar5 = FUN_01027648(puVar4,(ushort)bVar2);
    if (uVar5 != 0) {
      FUN_01020f64(uVar5);
      uVar5 = DAT_21001049 & 0xc;
      if ((DAT_21001049 & 0xc) != 0) {
        uVar5 = 0x28;
      }
      FUN_01021020(uVar5);
      DAT_21001000 = 9;
                    /* WARNING: Could not recover jumptable at 0x01016d2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)0x1016ce7)();
      return uVar5;
    }
    FUN_01009500(0x32,0x646,extraout_r2_04,extraout_r3_01);
    puVar4 = (ushort *)FUN_0100ada0();
    bVar2 = FUN_0100adb4();
    pbVar6 = (byte *)FUN_01027648(puVar4,(ushort)bVar2);
    if (pbVar6 == (byte *)0x0) {
      FUN_01009500(0x32,&DAT_00001544,extraout_r2_06,extraout_r3_02);
      uVar7 = extraout_r2_11;
      uVar8 = extraout_r3_05;
LAB_01016de2:
      FUN_01009500(0x32,&DAT_0000155f,uVar7,uVar8);
      uVar7 = extraout_r2_12;
      uVar5 = extraout_r3_06;
LAB_01016dec:
      FUN_01009500(0x32,&DAT_0000154a,uVar7,uVar5);
      uVar7 = extraout_r2_13;
      uVar5 = extraout_r3_07;
LAB_01016df6:
      FUN_01009500(0x32,&DAT_0000153b,uVar7,uVar5);
      uVar7 = extraout_r2_14;
      uVar5 = extraout_r3_08;
LAB_01016e00:
      FUN_01009500(0x32,&DAT_0000153a,uVar7,uVar5);
      uVar7 = extraout_r2_15;
      uVar5 = extraout_r3_09;
    }
    else {
      uVar5 = DAT_21000fe4 - 1;
      uVar7 = extraout_r2_06;
      if (2 < uVar5) goto LAB_01016dec;
      if ((extraout_r2_05 >> 0x1e == 0) ||
         ((bVar3 = FUN_0100ec9c(pbVar6), uVar7 = extraout_r2_08, !bVar3 &&
          (bVar3 = FUN_0100ed3c(pbVar6), uVar7 = extraout_r2_09, !bVar3)))) {
        uVar5 = (uint)DAT_21001000;
        if (4 < uVar5) {
          uVar5 = (uint)DAT_21001000;
          if (uVar5 < 0xb) {
            uVar5 = (**(code **)(*(int *)(DAT_21001054 + 0x18) + (DAT_21001000 + 0x3ffffffb) * 4))()
            ;
            uVar7 = extraout_r2_07;
            uVar8 = extraout_r3_03;
            goto LAB_01016d8a;
          }
          goto LAB_01016df6;
        }
        goto LAB_01016e00;
      }
      uVar5 = (uint)DAT_21001000;
      if (4 < uVar5) {
        uVar5 = (uint)DAT_21001000;
        if (10 < uVar5) goto LAB_01016e14;
        uVar5 = (**(code **)(*(int *)(DAT_21001054 + 0x14) + (DAT_21001000 + 0x3ffffffb) * 4))
                          (pbVar6);
        uVar7 = extraout_r2_10;
        uVar8 = extraout_r3_04;
LAB_01016d8a:
        if (uVar5 < 0xf) {
                    /* WARNING: Could not recover jumptable at 0x01016d9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar5 = (**(code **)(*(int *)(DAT_21001054 + 0x10) + uVar5 * 4))();
          return uVar5;
        }
        goto LAB_01016de2;
      }
    }
    FUN_01009500(0x32,&DAT_000014c9,uVar7,uVar5);
    uVar7 = extraout_r2_16;
    uVar5 = extraout_r3_10;
LAB_01016e14:
    FUN_01009500(0x32,&DAT_000014ca,uVar7,uVar5);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_01020afc(uVar5,puVar9,uVar7);
  FUN_01020f64(param_2);
  if (param_1 != 0) {
    uVar5 = FUN_01021aec(1,puVar9);
    return (uint)(uVar5 != 0);
  }
  FUN_01021908(1,puVar9);
  return 1;
}


