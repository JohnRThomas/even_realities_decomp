/*
 * Function: FUN_010175c8
 * Entry:    010175c8
 * Prototype: undefined4 __stdcall FUN_010175c8(undefined4 param_1, undefined1 * param_2)
 */


undefined4 FUN_010175c8(undefined4 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  uint extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 *puVar8;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar9;
  undefined4 *puVar10;
  
  iVar3 = DAT_21000fe0;
  if (DAT_21000f99 != '\0') {
    puVar2 = (ushort *)FUN_0100a518(DAT_21000f9a,0);
    uVar1 = extraout_r2;
    uVar6 = extraout_r3;
    if (puVar2 != (ushort *)0x0) {
      FUN_0100b0dc((uint)*puVar2);
      iVar3 = FUN_0100a564(*puVar2,0);
      if (iVar3 == 0) goto LAB_010175f2;
      FUN_01009500(0x32,0x3f5,extraout_r2_00,extraout_r3_00);
      uVar1 = extraout_r2_01;
      uVar6 = extraout_r3_01;
    }
    FUN_01009500(0x32,0x3f1,uVar1,uVar6);
    if (0x5f < DAT_2100104c) goto LAB_010176e2;
    puVar10 = (undefined4 *)(uint)*(byte *)((int)&DAT_0103c210 + (uint)(DAT_2100104c >> 5));
    while( true ) {
      uVar4 = (uint)(byte)DAT_2100104a;
      FUN_01020cf4((byte)DAT_2100104a & 0x3f);
      DAT_2100101f = (byte)((uVar4 << 0x1a) >> 0x1a);
      if (extraout_r2_02 >> 0x1e != 0) break;
      puVar5 = FUN_0102126c(&DAT_00000001,DAT_21001004,puVar10);
      uVar6 = extraout_r2_04;
      if (puVar5 != (undefined4 *)0x0) goto LAB_010176a6;
      FUN_01009500(0x32,0x93e,extraout_r2_04,extraout_r3_02);
LAB_010176e2:
      puVar10 = (undefined4 *)0x0;
    }
    uVar4 = FUN_01021aec(1,puVar10);
    uVar1 = 0;
    uVar6 = extraout_r2_03;
    if (uVar4 != 0) {
LAB_010176a6:
      if (DAT_21001018 == '\x02') {
        uVar4 = 0x40;
      }
      else {
        uVar4 = 0xff;
      }
      FUN_01020afc(uVar4,puVar10,uVar6);
      if ((DAT_21001038 == '\0') && (DAT_2100100c = FUN_0100d34c(5), DAT_2100100c != '\0')) {
        if (((uint)puVar10 & 0xc) == 0) {
          uVar4 = 0x50;
        }
        else {
          uVar4 = 0x55;
        }
        FUN_01020470();
        FUN_01021098(uVar4);
      }
      FUN_01020f64(0);
      uVar1 = 1;
    }
    return uVar1;
  }
  *(undefined4 *)(DAT_21000fe0 + 3) = DAT_21000f9e;
  *(undefined2 *)(iVar3 + 7) = DAT_21000fa2;
  *(bool *)(DAT_21000fe0 + 2) = (DAT_21000f9d & 0xfd) != 0;
LAB_010175f2:
  *param_2 = 0x13;
  puVar10 = (undefined4 *)(param_2 + 3);
  puVar5 = (undefined4 *)&DAT_21000f99;
  do {
    puVar8 = puVar5 + 4;
    uVar9 = puVar5[1];
    puVar7 = puVar10 + 4;
    uVar1 = puVar5[2];
    uVar6 = puVar5[3];
    *puVar10 = *puVar5;
    puVar10[1] = uVar9;
    puVar10[2] = uVar1;
    puVar10[3] = uVar6;
    puVar10 = puVar7;
    puVar5 = puVar8;
  } while (puVar8 != (undefined4 *)((int)&DAT_21000fb8 + 1));
  *(undefined1 *)puVar7 = DAT_21000fb8._1_1_;
  param_2[6] = 0;
  return uVar1;
}


