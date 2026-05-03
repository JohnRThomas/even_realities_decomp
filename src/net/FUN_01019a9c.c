/*
 * Function: FUN_01019a9c
 * Entry:    01019a9c
 * Prototype: uint __stdcall FUN_01019a9c(undefined4 param_1, byte * param_2)
 */


uint FUN_01019a9c(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  ushort uVar7;
  short *psVar8;
  undefined2 *puVar9;
  int iVar10;
  ushort *puVar11;
  undefined4 uVar12;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar13;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar14;
  undefined4 extraout_r3_01;
  uint uVar15;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  uint extraout_r3_04;
  uint extraout_r3_05;
  undefined4 extraout_r3_06;
  uint extraout_r3_07;
  undefined4 uVar16;
  uint uVar17;
  ushort uStack_5e;
  int aiStack_5c [2];
  undefined4 uStack_54;
  byte *local_4c;
  byte local_48 [12];
  undefined4 *local_3c;
  byte local_38;
  
  psVar8 = (short *)FUN_0100ada0();
  puVar9 = (undefined2 *)FUN_01027844((int)psVar8);
  uVar12 = extraout_r2;
  uVar13 = extraout_r3;
  if (puVar9 == (undefined2 *)0x0) {
LAB_01019d1e:
    FUN_01009500(0x33,0x1ab,uVar12,uVar13);
    uVar13 = extraout_r2_05;
    uVar12 = extraout_r3_03;
LAB_01019d28:
    FUN_01009500(0x33,0x49,uVar13,uVar12);
    uVar12 = extraout_r2_06;
    uVar15 = extraout_r3_04;
LAB_01019d30:
    FUN_01009500(0x33,0x99,uVar12,uVar15);
    uVar13 = extraout_r2_07;
    uVar15 = extraout_r3_05;
LAB_01019d38:
    FUN_01009500(0x33,0x48,uVar13,uVar15);
    uVar12 = extraout_r2_08;
    uVar13 = extraout_r3_06;
  }
  else {
    uVar7 = FUN_0102789e((int)psVar8,puVar9,(int *)&local_4c);
    bVar4 = FUN_0100adb4();
    if (bVar4 != uVar7) {
      FUN_01009500(0x33,0x1b5,extraout_r2_00,extraout_r3_00);
      uVar12 = extraout_r2_04;
      uVar13 = extraout_r3_02;
      goto LAB_01019d1e;
    }
    FUN_0101a870(local_4c,local_48);
    iVar10 = FUN_010278d2((int)puVar9);
    uVar12 = *(undefined4 *)(iVar10 + 0x12);
    uVar13 = *(undefined4 *)(iVar10 + 0x16);
    uVar16 = *(undefined4 *)(iVar10 + 0x1e);
    *(undefined4 *)(param_2 + 0xb) = *(undefined4 *)(iVar10 + 0x1a);
    uVar14 = *(undefined4 *)(iVar10 + 0x2a);
    *(undefined4 *)(param_2 + 3) = uVar12;
    *(undefined4 *)(param_2 + 7) = uVar13;
    uVar12 = *(undefined4 *)(iVar10 + 0x22);
    uVar13 = *(undefined4 *)(iVar10 + 0x26);
    *(undefined4 *)(param_2 + 0x1b) = uVar14;
    bVar4 = *(byte *)(iVar10 + 0x1c);
    *(undefined4 *)(param_2 + 0x13) = uVar12;
    *(undefined4 *)(param_2 + 0xf) = uVar16;
    *(undefined4 *)(param_2 + 0x17) = uVar13;
    if (-1 < (int)((uint)bVar4 << 0x1b)) {
      if (DAT_21001058 == '\0') {
        if (*(byte *)(iVar10 + 0x2d) < 0x25) {
          DAT_21001058 = '\x01';
          goto LAB_01019c74;
        }
LAB_01019b66:
        cVar5 = '\x01';
        param_2[0xb] = 0;
      }
      else {
LAB_01019c74:
        if (local_48[0] == 2) goto LAB_01019b66;
        uVar15 = FUN_0100ec10((int)local_4c,(undefined4 *)(param_2 + 0x1f),0xe5,(uint)DAT_21001059);
        param_2[0xb] = (byte)uVar15;
        DAT_21001059 = (byte)uVar15 + DAT_21001059;
        cVar5 = FUN_0100ebfc((int)local_4c);
        if ((uint)DAT_21001059 == (int)cVar5) {
          cVar5 = '\x01';
        }
        else {
          cVar5 = '\0';
          param_2[0xd] = param_2[0xd] & 0x9f | 0x20;
        }
      }
      if ((param_2[0xd] & 0x60) == 0x20) {
        if (DAT_21001058 == '\x01') {
          if (-1 < (int)((uint)param_2[0xd] << 0x1e)) goto LAB_01019cf0;
          DAT_21001058 = '\x02';
        }
        else if (DAT_21001058 == '\x02') {
LAB_01019cf0:
          DAT_21001058 = '\x03';
        }
        else if (DAT_21001058 == '\0') {
          DAT_21001058 = '\x01';
        }
      }
      else {
        DAT_21001058 = '\0';
      }
      *param_2 = 4;
      cVar6 = FUN_01020088();
      uVar13 = extraout_r2_03;
      if (cVar6 != '\0') goto LAB_01019b94;
      uVar15 = 0;
      goto joined_r0x01019b8c;
    }
    if ((int)((uint)bVar4 << 0x1d) < 0) {
      param_2[0xb] = 0;
    }
    else {
      FUN_01026198((undefined4 *)(param_2 + 0x1f),local_3c,(uint)local_38);
      param_2[0xb] = local_38;
    }
    *param_2 = 4;
    cVar5 = FUN_01020088();
    uVar13 = extraout_r2_01;
    if (cVar5 != '\0') {
LAB_01019b94:
      uVar15 = (uint)*param_2;
      if (uVar15 == 4) {
        bVar4 = param_2[0xd];
        uVar12 = 4;
        if ((bVar4 & 0x10) == 0) goto LAB_01019d28;
        uVar12 = *(undefined4 *)(param_2 + 3);
        DAT_21001064 = *(undefined4 *)(param_2 + 0xb);
        DAT_21001068 = *(undefined4 *)(param_2 + 0xf);
        bVar1 = param_2[0xb];
        uVar17 = (uint)bVar1;
        DAT_2100105c._0_1_ = (byte)uVar12;
        DAT_2100105c._1_1_ = (byte)((uint)uVar12 >> 8);
        DAT_2100105c._2_2_ = (undefined2)((uint)uVar12 >> 0x10);
        DAT_21001060._0_2_ = (undefined2)*(undefined4 *)(param_2 + 7);
        DAT_21001060._2_2_ = (undefined2)((uint)*(undefined4 *)(param_2 + 7) >> 0x10);
        DAT_2100106c = *(undefined4 *)(param_2 + 0x13);
        DAT_21001070 = *(uint *)(param_2 + 0x17);
        DAT_21001074 = *(undefined4 *)(param_2 + 0x1b);
        FUN_01026198((undefined4 *)&DAT_21001078,(undefined4 *)(param_2 + 0x1f),uVar17);
        bVar2 = (byte)DAT_2100105c;
        if (((bVar4 & 4) != 0) && (DAT_2100106c._3_1_ == -2)) {
          param_2[0xc] = 0xfe;
          uVar15 = DAT_21001070;
          *(undefined2 *)(param_2 + 0x11) = (undefined2)DAT_21001074;
          uVar12 = CONCAT22((undefined2)DAT_21001060,DAT_2100105c._2_2_);
          param_2[0x13] = DAT_21001064._1_1_;
          *(uint *)(param_2 + 0xd) = uVar15;
          *param_2 = 0x11;
          bVar4 = (byte)DAT_2100105c;
          *(undefined4 *)(param_2 + 6) = uVar12;
          param_2[3] = bVar4;
          param_2[4] = 1;
          param_2[5] = DAT_2100105c._1_1_;
          *(undefined2 *)(param_2 + 10) = DAT_21001060._2_2_;
joined_r0x01019b8c:
          if (cVar5 == '\0') {
            return uVar15;
          }
          goto LAB_01019b32;
        }
        bVar3 = DAT_21001064._1_1_;
        param_2[3] = (byte)DAT_2100105c;
        uVar12 = 3;
        param_2[0xc] = bVar1;
        *param_2 = 3;
        param_2[1] = (bVar1 + 10) * bVar2 + 2;
        *(undefined2 *)(param_2 + 10) = DAT_21001060._2_2_;
        param_2[5] = DAT_2100105c._1_1_;
        *(uint *)(param_2 + 6) = CONCAT22((undefined2)DAT_21001060,DAT_2100105c._2_2_);
        param_2[uVar17 + 0xd] = bVar3;
        if ((bVar4 & 8) == 0) {
          uVar15 = bVar4 & 3;
          if (uVar15 == 3) {
            param_2[4] = bVar4 & 8;
          }
          else if ((bVar4 & 4) == 0) {
            if (uVar15 == 2) {
              param_2[4] = 2;
            }
            else {
              if ((bVar4 & 3) != 0) goto LAB_01019d4a;
              param_2[4] = 3;
            }
          }
          else {
            uVar15 = 1;
            param_2[4] = 1;
          }
        }
        else {
          uVar15 = 4;
          param_2[4] = 4;
        }
        if (uVar17 < 0x20) {
          uVar15 = FUN_01026198((undefined4 *)(param_2 + 0xd),(undefined4 *)&DAT_21001078,uVar17);
          goto joined_r0x01019b8c;
        }
        goto LAB_01019d30;
      }
      goto LAB_01019d38;
    }
LAB_01019b32:
    iVar10 = FUN_010278e8(psVar8);
    uVar12 = extraout_r2_02;
    uVar13 = extraout_r3_01;
    if (iVar10 != 0) {
      uVar7 = FUN_01027494(psVar8,(undefined4 *)0x0);
      DAT_21001059 = 0;
      return (uint)uVar7;
    }
  }
  FUN_01009500(0x33,0x1f9,uVar12,uVar13);
  uVar12 = extraout_r2_09;
  uVar15 = extraout_r3_07;
LAB_01019d4a:
  FUN_01009500(0x33,0x96,uVar12,uVar15);
  uStack_54 = 0x1019d53;
  puVar11 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar11,aiStack_5c,&uStack_5e);
  iVar10 = FUN_010278d2(aiStack_5c[0]);
  return (uint)(*(char *)(iVar10 + 0x25) != -1);
}


