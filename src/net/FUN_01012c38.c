/*
 * Function: FUN_01012c38
 * Entry:    01012c38
 * Prototype: uint __stdcall FUN_01012c38(undefined4 * param_1, byte * param_2)
 */


uint FUN_01012c38(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  undefined4 uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined *puVar12;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar13;
  undefined4 extraout_r3;
  undefined4 *puVar14;
  uint uVar15;
  uint unaff_r9;
  uint uVar16;
  undefined8 uVar17;
  undefined4 local_68;
  undefined2 uStack_64;
  byte *local_60;
  ushort local_5c;
  uint local_58;
  undefined1 local_54;
  undefined1 local_53;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  uVar15 = (uint)*(byte *)((int)param_1 + 5);
  cVar4 = *(char *)((int)param_1 + 0xe);
  local_50 = *param_1;
  local_4c = param_1[1];
  local_48 = param_1[2];
  local_44 = param_1[3];
  local_40 = param_1[4];
  uStack_3c = param_1[5];
  uStack_38 = param_1[6];
  uStack_34 = param_1[7];
  puVar14 = &local_30;
  local_30 = param_1[8];
  uStack_2c = param_1[9];
  FUN_010131a4((undefined2 *)&local_68);
  bVar1 = *param_2;
  puVar12 = (undefined *)(uint)bVar1;
  bVar5 = param_2[10];
  uVar13 = param_2[0x14] - 1 & 0xff;
  if (uVar13 < 3) {
    puVar12 = &DAT_0103c17c;
    puVar14 = (undefined4 *)(param_2[1] & 0x7f);
    unaff_r9 = (uint)(byte)(&DAT_0103c190)[uVar13];
    if (-1 < (int)((uint)param_2[1] << 0x1b)) {
      uVar13 = param_2[0x16] - 1 & 0xff;
      if (2 < uVar13) goto LAB_01012e32;
      uVar15 = (uint)(byte)(&DAT_0103c190)[uVar13];
    }
    if (cVar4 == '\x01') {
      if (unaff_r9 == 8) {
        unaff_r9 = 4;
      }
      if (uVar15 == 8) {
        uVar15 = 4;
      }
    }
    FUN_010131b4((int)&local_68,param_2[9]);
    if (param_2[0x14] == 2) {
      uVar13 = (uint)(byte)(param_2[0x15] + 1);
    }
    else {
      uVar13 = 1;
    }
  }
  else {
LAB_01012e32:
    uVar17 = FUN_01009500(6,0x2a6,puVar12,uVar13);
    puVar11 = (undefined4 *)((ulonglong)uVar17 >> 0x20);
    *puVar11 = extraout_r2_00;
    puVar11[1] = extraout_r3;
    puVar11[2] = param_2;
    puVar11[3] = param_1;
    puVar11[4] = &local_68;
    uVar13 = ((int)uVar17 << 4) >> 0x1d;
    if (uVar13 == 0) {
      uVar9 = *(ushort *)((int)uVar17 + 2);
      uVar15 = (uint)uVar9;
      uVar13 = uVar15 & 0x10;
      if ((uVar9 & 0x10) != 0) {
        if ((uVar9 & 4) == 0) {
          uVar13 = 0x1f;
        }
        else {
          uVar13 = 0;
        }
        return uVar13;
      }
      if (-1 < (int)(uVar15 << 0x1e)) {
        if (-1 < (int)(uVar15 << 0x1f)) {
          uVar9 = FUN_0100acd0();
          return (uint)uVar9;
        }
        uVar13 = 0xee;
      }
      return uVar13;
    }
  }
  FUN_010131b8((undefined1 *)&local_68,uVar13,(uint)(byte)(param_2[0x1a] + 1));
  uVar9 = (ushort)puVar14;
  if ((int)puVar14 << 0x1c < 0) {
    uVar13 = 0;
  }
  else {
    uVar13 = FUN_01013324((byte *)&local_68);
    if ((int)((uint)param_2[1] << 0x1b) < 0) {
      uVar17 = FUN_01013350(uVar13,(uint)puVar14,0x28,(uint)param_2[1] << 0x1b);
      iVar10 = (int)uVar17;
    }
    else {
      uVar7 = FUN_0100acd0();
      puVar12 = (undefined *)FUN_01011190(uVar13,unaff_r9);
      uVar17 = FUN_010111ec((uint)uVar7,puVar12,uVar15,1,uVar9);
      iVar10 = (int)uVar17;
    }
    uVar16 = ((iVar10 + 0x2f1U) / 0x271) * 0x271;
    uVar13 = (uint)*(uint3 *)(param_2 + 3) * 0x271;
    if ((uVar13 <= uVar16 && uVar16 + (uint)*(uint3 *)(param_2 + 3) * -0x271 != 0) &&
       (uVar13 = (uint)*(uint3 *)(param_2 + 6) * 0x271,
       uVar16 <= (uint)*(uint3 *)(param_2 + 6) * 0x271)) {
      uVar13 = uVar16;
    }
  }
  bVar2 = param_2[0x18];
  bVar3 = param_2[0x12];
  uVar7 = FUN_010288be(param_1[0x11]);
  uVar8 = FUN_010288d8(param_1[0x11]);
  uVar16 = (uint)uVar8;
  if ((uint)uVar8 < (uint)uVar7) {
    uVar16 = (uint)uVar7;
  }
  if (((uVar16 == 0) || (((uint)puVar14 & 0x18) != 0)) ||
     (local_60 = (byte *)&local_68, local_5c = uVar9, local_58 = uVar13, local_54 = (char)unaff_r9,
     local_53 = (char)uVar15, uVar16 = FUN_01012514(uVar16,&local_60,extraout_r2,uVar13),
     uVar16 != 0)) {
    uVar6 = local_40;
    local_50 = CONCAT22(uVar9,(undefined2)local_50);
    uVar16 = 0;
    local_40._3_1_ = SUB41(uVar6,3);
    local_40._0_3_ = CONCAT12(bVar5,CONCAT11(bVar3,(undefined1)local_40));
    local_50 = CONCAT31(local_50._1_3_,bVar1);
    local_4c._0_2_ = CONCAT11((char)uVar15,(char)unaff_r9);
    local_44 = CONCAT31(local_44._1_3_,bVar2 == 1);
    *param_1 = local_50;
    param_1[1] = local_4c;
    param_1[2] = uVar13;
    param_1[3] = local_44;
    param_1[4] = local_40;
    param_1[5] = uStack_3c;
    param_1[6] = uStack_38;
    param_1[7] = uStack_34;
    param_1[8] = local_30;
    param_1[9] = uStack_2c;
    param_1[10] = local_68;
    *(undefined2 *)(param_1 + 0xb) = uStack_64;
    *(bool *)((int)param_1 + 0x67) = (param_2[0xb] & 0xfd) != 0;
    param_1[0x1a] = *(undefined4 *)(param_2 + 0xc);
    *(undefined2 *)(param_1 + 0x1b) = *(undefined2 *)(param_2 + 0x10);
    *(byte *)((int)param_1 + 0x3e) = *(byte *)((int)param_1 + 0x3e) & 0xf | param_2[0x17] << 4;
  }
  else {
    uVar16 = 0x45;
  }
  return uVar16;
}


