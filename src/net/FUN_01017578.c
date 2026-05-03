/*
 * Function: FUN_01017578
 * Entry:    01017578
 * Prototype: uint __stdcall FUN_01017578(undefined4 param_1, undefined1 * param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01017578(undefined4 param_1,undefined1 *param_2)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 extraout_r2;
  undefined4 *puVar9;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  uint extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r3;
  undefined4 *puVar10;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar11;
  undefined4 *puVar12;
  
  *param_2 = 0x18;
  bVar2 = DAT_21000fd0._1_1_;
  uVar3 = (uint)DAT_21000fd0._1_1_;
  *(undefined2 *)(param_2 + 3) = _DAT_21000fcf;
  param_2[5] = bVar2;
  if (param_2[3] != '\x01') {
    return uVar3;
  }
  uVar1 = *(ushort *)(param_2 + 4);
  iVar4 = FUN_0100a518(uVar1,0);
  if (iVar4 != 0) {
    FUN_0100b0dc((uint)uVar1);
    iVar4 = FUN_0100a564(uVar1,0);
    if (iVar4 != 0) {
      FUN_01009500(0x32,0x411,extraout_r2,extraout_r3);
      iVar4 = DAT_21000fe0;
      if (DAT_21000f99 != '\0') {
        puVar5 = (ushort *)FUN_0100a518(DAT_21000f9a,0);
        uVar8 = extraout_r2_00;
        uVar11 = extraout_r3_00;
        if (puVar5 != (ushort *)0x0) {
          FUN_0100b0dc((uint)*puVar5);
          iVar4 = FUN_0100a564(*puVar5,0);
          if (iVar4 == 0) goto LAB_010175f2;
          FUN_01009500(0x32,0x3f5,extraout_r2_01,extraout_r3_01);
          uVar8 = extraout_r2_02;
          uVar11 = extraout_r3_02;
        }
        FUN_01009500(0x32,0x3f1,uVar8,uVar11);
        if (0x5f < DAT_2100104c) goto LAB_010176e2;
        puVar12 = (undefined4 *)(uint)*(byte *)((int)&DAT_0103c210 + (uint)(DAT_2100104c >> 5));
        while( true ) {
          uVar3 = (uint)(byte)DAT_2100104a;
          FUN_01020cf4((byte)DAT_2100104a & 0x3f);
          DAT_2100101f = (byte)((uVar3 << 0x1a) >> 0x1a);
          if (extraout_r2_03 >> 0x1e != 0) break;
          puVar7 = FUN_0102126c(&DAT_00000001,DAT_21001004,puVar12);
          uVar8 = extraout_r2_05;
          if (puVar7 != (undefined4 *)0x0) goto LAB_010176a6;
          FUN_01009500(0x32,0x93e,extraout_r2_05,extraout_r3_03);
LAB_010176e2:
          puVar12 = (undefined4 *)0x0;
        }
        uVar6 = FUN_01021aec(1,puVar12);
        uVar3 = 0;
        uVar8 = extraout_r2_04;
        if (uVar6 != 0) {
LAB_010176a6:
          if (DAT_21001018 == '\x02') {
            uVar3 = 0x40;
          }
          else {
            uVar3 = 0xff;
          }
          FUN_01020afc(uVar3,puVar12,uVar8);
          if ((DAT_21001038 == '\0') && (DAT_2100100c = FUN_0100d34c(5), DAT_2100100c != '\0')) {
            if (((uint)puVar12 & 0xc) == 0) {
              uVar3 = 0x50;
            }
            else {
              uVar3 = 0x55;
            }
            FUN_01020470();
            FUN_01021098(uVar3);
          }
          FUN_01020f64(0);
          uVar3 = 1;
        }
        return uVar3;
      }
      *(undefined4 *)(DAT_21000fe0 + 3) = DAT_21000f9e;
      *(undefined2 *)(iVar4 + 7) = DAT_21000fa2;
      *(bool *)(DAT_21000fe0 + 2) = (DAT_21000f9d & 0xfd) != 0;
LAB_010175f2:
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      MasterStackPointer = 0x13;
      puVar12 = (undefined4 *)&LAB_00000002_1;
      puVar7 = (undefined4 *)&DAT_21000f99;
      do {
        puVar10 = puVar7 + 4;
        uVar11 = puVar7[1];
        puVar9 = puVar12 + 4;
        uVar3 = puVar7[2];
        uVar8 = puVar7[3];
        *puVar12 = *puVar7;
        puVar12[1] = uVar11;
        puVar12[2] = uVar3;
        puVar12[3] = uVar8;
        puVar12 = puVar9;
        puVar7 = puVar10;
      } while (puVar10 != (undefined4 *)((int)&DAT_21000fb8 + 1));
      *(undefined1 *)puVar9 = DAT_21000fb8._1_1_;
      LAB_00000006 = 0;
      return uVar3;
    }
  }
  return 0;
}


