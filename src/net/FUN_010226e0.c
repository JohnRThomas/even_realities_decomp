/*
 * Function: FUN_010226e0
 * Entry:    010226e0
 * Prototype: undefined1 * __stdcall FUN_010226e0(undefined1 * param_1, int param_2, int param_3, int param_4)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_010226e0(undefined1 *param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  char cVar2;
  byte bVar3;
  longlong lVar4;
  byte bVar5;
  bool bVar6;
  ushort uVar7;
  short sVar8;
  ushort uVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined2 *puVar12;
  uint uVar13;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 uVar14;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  uint uVar15;
  int iVar16;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined1 *extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 uVar17;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined1 *extraout_r2_13;
  int extraout_r2_14;
  int extraout_r2_15;
  undefined4 extraout_r2_16;
  undefined4 extraout_r2_17;
  undefined1 *extraout_r2_18;
  undefined4 extraout_r2_19;
  undefined1 *extraout_r2_20;
  undefined1 *extraout_r2_21;
  char *extraout_r2_22;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined4 extraout_r3;
  undefined1 *extraout_r3_00;
  undefined1 *extraout_r3_01;
  undefined1 *extraout_r3_02;
  undefined4 extraout_r3_03;
  uint extraout_r3_04;
  undefined4 extraout_r3_05;
  uint extraout_r3_06;
  undefined1 *extraout_r3_07;
  uint *extraout_r3_08;
  int iVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *unaff_r10;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *extraout_r12;
  longlong lVar27;
  longlong lVar28;
  char cStack_e5;
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  undefined1 *puStack_d4;
  undefined4 *puStack_d0;
  undefined4 uStack_cc;
  undefined1 *puStack_c8;
  undefined1 *puStack_c4;
  undefined4 uStack_c0;
  undefined1 *puStack_bc;
  undefined1 *puStack_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  uint local_a8;
  undefined1 *local_a4;
  undefined1 *local_a0;
  undefined1 *local_9c;
  undefined1 *local_98;
  undefined1 *local_94;
  uint local_90;
  undefined1 *local_8c;
  uint local_88;
  undefined1 *local_84;
  undefined1 *local_80;
  int local_7c;
  int local_78;
  uint local_74;
  undefined1 *local_70;
  int local_6c;
  uint uStack_68;
  undefined1 *local_64;
  char cStack_5d;
  int local_5c [2];
  undefined4 uStack_54;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  local_94 = param_1;
  local_7c = param_2;
  local_78 = param_3;
  lVar27 = FUN_0102581c();
  uVar11 = (uint)((ulonglong)lVar27 >> 0x20);
  puVar19 = (undefined1 *)lVar27;
  uVar7 = FUN_01024e44();
  puVar22 = (undefined1 *)(uint)uVar7;
  iVar16 = param_4 * 0x20;
  iVar20 = param_4 * 0x20;
  *DAT_21001bc4 = 1;
  puVar21 = *(undefined1 **)(&DAT_210017c8 + iVar20);
  puVar23 = (undefined1 *)(uint)(byte)(&DAT_210017d4)[iVar20];
  local_a8 = *(uint *)(&DAT_210017cc + iVar20);
  uVar7 = *(ushort *)(&DAT_210017d6 + iVar20);
  puVar26 = (undefined1 *)(uint)uVar7;
  local_8c = *(undefined1 **)(&DAT_210017d0 + iVar20);
  local_48 = *(undefined4 *)(&DAT_210017c8 + iVar16);
  local_44 = *(undefined4 *)(&DAT_210017cc + iVar16);
  local_40 = *(undefined4 *)(&DAT_210017d0 + iVar16);
  local_3c = *(undefined4 *)(&DAT_210017d4 + iVar16);
  local_38 = *(undefined4 *)(&DAT_210017d8 + iVar16);
  uStack_34 = *(undefined4 *)(&DAT_210017dc + iVar16);
  local_84 = puVar22;
  local_70 = puVar23;
  puVar10 = (undefined1 *)FUN_01024c40((uint)puVar21 & 0xffffff);
  puVar18 = puVar23 + (int)(puVar10 + (int)(puVar26 + 1));
  if (&DAT_1e847fff < puVar10) {
LAB_01022d50:
    FUN_01025edc(0x70,0x5a0,&DAT_1e847fff,puVar18);
    iVar16 = extraout_r2_14;
    puVar25 = extraout_r3_00;
LAB_01022d5a:
    FUN_01025edc(0x70,0xa04,iVar16,puVar25);
    iVar16 = extraout_r2_15;
    puVar25 = extraout_r3_01;
LAB_01022d64:
    FUN_01025edc(0x70,0xa08,iVar16,puVar25);
    uVar14 = extraout_r2_16;
    puVar19 = extraout_r3_02;
LAB_01022d6e:
    FUN_01025edc(0x70,0xa7a,uVar14,puVar19);
    uVar14 = extraout_r2_17;
    uVar17 = extraout_r3_03;
LAB_01022d78:
    FUN_01025edc(0x70,0x2fa,uVar14,uVar17);
    puVar19 = extraout_r2_18;
    uVar11 = extraout_r3_04;
LAB_01022d82:
    FUN_01025edc(0x70,0xacc,puVar19,uVar11);
    uVar17 = extraout_r2_19;
    uVar14 = extraout_r3_05;
LAB_01022d8c:
    FUN_01025edc(0x70,0x907,uVar17,uVar14);
    puVar19 = extraout_r2_20;
    uVar11 = extraout_r3_06;
    lVar28 = lVar27;
  }
  else {
    if ((int)puVar18 < 512000000) {
      local_80 = puVar18;
      if ((int)puVar18 < 0) {
        local_80 = puVar18 + 512000000;
      }
    }
    else {
      local_80 = puVar18 + -512000000;
    }
    local_9c = (undefined1 *)(_DAT_21001718 & 0xff);
    local_74 = _DAT_21001718 >> 8 & 0xff;
    bVar5 = FUN_010252d0();
    local_88 = (uint)bVar5;
    if (puVar26 == (undefined1 *)0x0) {
      local_a4 = puVar26;
      sVar8 = FUN_01024ed8();
      if (sVar8 == 0x356) goto LAB_01022968;
LAB_01022796:
      if (sVar8 == 0x5f5) {
        puVar10 = &UNK_00000032;
        puVar23 = &UNK_00000035;
        puVar18 = &UNK_00000032;
        local_90 = 0x32;
        local_a0 = &UNK_00000035;
      }
      else if (sVar8 == 0x18c) {
        puVar10 = (undefined1 *)0xd;
        puVar18 = (undefined1 *)0xd;
        puVar23 = &MemManage;
        local_90 = 0xd;
        local_a0 = &MemManage;
      }
      else {
        puVar10 = (undefined1 *)0x0;
        puVar23 = &LAB_00000002_1;
        puVar18 = (undefined1 *)0x0;
        local_90 = 0;
        local_a0 = &LAB_00000002_1;
      }
      puVar25 = puVar18;
      puVar24 = puVar23;
      unaff_r10 = puVar10;
      if (puVar26 < puVar22) goto LAB_01022980;
LAB_010227c0:
      puVar18 = (undefined1 *)0x0;
      puVar23 = puVar24;
      unaff_r10 = puVar10;
    }
    else {
      uVar13 = local_88;
      if ((DAT_21001734 & (uint)DAT_21001730) != 0xffffffff) {
        uVar13 = local_88 | 1;
      }
      local_a4 = (undefined1 *)(uVar13 ^ 1);
      sVar8 = FUN_01024ed8();
      if (sVar8 != 0x356) goto LAB_01022796;
LAB_01022968:
      puVar10 = &Reserved1;
      puVar25 = &Reserved1;
      puVar24 = &LAB_0000001e_1;
      puVar23 = &LAB_0000001e_1;
      puVar18 = &Reserved1;
      local_90 = 0x1c;
      local_a0 = &LAB_0000001e_1;
      unaff_r10 = puVar25;
      if (puVar22 <= puVar26) goto LAB_010227c0;
LAB_01022980:
      puVar22 = local_80 + -(int)(puVar22 + 1);
      if (&DAT_1e847fff < local_80) goto LAB_01022d50;
      if ((int)puVar22 < 512000000) {
        puVar10 = puVar22;
        if ((int)puVar22 < 0) {
          puVar10 = puVar22 + 512000000;
        }
      }
      else {
        puVar10 = puVar22 + -512000000;
      }
      local_98 = puVar18;
      FUN_01024ccc((uint)puVar10,local_5c,&cStack_5d);
      puVar18 = (undefined1 *)((int)puVar21 - local_5c[0] & 0xffffff);
      puVar25 = local_98;
    }
    if (local_a4 == (undefined1 *)0x0) {
      if (local_9c == (undefined1 *)0x0) {
        puVar23 = &LAB_00000002_1;
        local_a0 = &LAB_00000002_1;
        puVar25 = local_9c;
        unaff_r10 = local_9c;
      }
      else {
        puVar23 = &Reset_1;
        local_a0 = &Reset_1;
        puVar25 = &LAB_00000002;
        unaff_r10 = &LAB_00000002;
      }
    }
    puVar10 = local_94;
    if (lVar27 != -1) {
      if (local_a8 < uVar11 || uVar11 - local_a8 < (uint)(puVar21 <= puVar19)) {
        lVar28 = lVar27 - CONCAT44(local_a8,puVar21);
        uVar13 = (uint)((ulonglong)lVar28 >> 0x20);
        bVar6 = 0x7fffff < (uint)lVar28;
        iVar16 = uVar13 - !bVar6;
        if (uVar13 != 0 || uVar13 < bVar6) goto LAB_01022d64;
        uVar13 = (int)puVar21 - (int)puVar19;
      }
      else {
        uVar13 = (int)puVar21 - (int)puVar19;
        uVar15 = (local_a8 - uVar11) - (uint)(puVar21 < puVar19);
        iVar16 = uVar15 - (0x7fffff >= uVar13);
        if (uVar15 != 0 || uVar15 < (0x7fffff < uVar13)) goto LAB_01022d5a;
      }
      if ((((0 < (int)uVar13) &&
           (puVar10 = puVar19, puVar23 = unaff_r10, local_a0 = puVar25,
           local_a4 != (undefined1 *)0x0)) && (DAT_21001738 != 0)) &&
         (puVar23 = local_9c, local_a0 = local_9c, local_9c != (undefined1 *)0x0)) {
        puVar23 = &LAB_00000002;
        local_a0 = puVar23;
      }
    }
    puVar22 = puVar21 + -(int)puVar18;
    uVar13 = local_a8 - (puVar21 < puVar18);
    unaff_r10 = puVar22 + -1;
    iVar16 = (int)unaff_r10 - (int)puVar10;
    local_98 = (undefined1 *)((uVar13 - 1) + (uint)(puVar22 != (undefined1 *)0x0));
    if (iVar16 < (int)puVar23) {
      if ((puVar18 == (undefined1 *)0x0) ||
         ((local_74 == 0 &&
          (local_6c = iVar16, uStack_68 = uVar13, local_64 = puVar10, bVar6 = FUN_01024e64(),
          iVar16 = local_6c, puVar10 = local_64, uVar13 = uStack_68, bVar6)))) {
        if (local_a4 != (undefined1 *)0x0) {
          return (undefined *)0x0;
        }
        if (local_9c == (undefined1 *)0x0) {
          return (undefined *)0x0;
        }
        puVar23 = local_a0 + -2;
      }
      else {
        if ((local_a4 == (undefined1 *)0x0) && (local_9c != (undefined1 *)0x0)) {
          puVar23 = local_a0 + -2;
        }
        unaff_r10 = puVar21 + -1;
        iVar16 = (int)unaff_r10 - (int)puVar10;
        local_98 = (undefined1 *)((local_a8 - 1) + (uint)(puVar21 != (undefined1 *)0x0));
        local_84 = (undefined1 *)0x0;
        uVar13 = local_a8;
        puVar22 = puVar21;
      }
      if (iVar16 < (int)puVar23) {
        return (undefined *)0x0;
      }
      local_9c = (undefined1 *)0x0;
    }
    else if (puVar18 != (undefined1 *)0x0) {
      local_8c = local_8c + (int)puVar18;
      puVar21 = puVar22;
      local_a8 = uVar13;
    }
    if ((((local_88 == 0) &&
         (DAT_21001734 != 0xffffffff || DAT_21001730 != (undefined1 *)0xffffffff)) &&
        (uVar13 - DAT_21001734 == (uint)(puVar22 < DAT_21001730) &&
         (uint)(local_90 <= (uint)((int)puVar22 - (int)DAT_21001730)) <=
         (uVar13 - DAT_21001734) - (uint)(puVar22 < DAT_21001730))) &&
       (puVar26 != (undefined1 *)0x0)) {
      return (undefined *)0x0;
    }
    puVar23 = unaff_r10 + -(int)local_94;
    puVar22 = local_98 + (-(uint)(unaff_r10 < local_94) - local_7c);
    sVar8 = FUN_01024ed8();
    if (sVar8 == 0x356) {
      puVar10 = &UNK_00000027;
LAB_0102289c:
      if (puVar22 != (undefined1 *)0x0 || puVar22 < (undefined1 *)(uint)(puVar10 <= puVar23))
      goto LAB_01022adc;
LAB_010228a6:
      lVar28 = lVar27;
      if (local_78 != 1) {
        uVar13 = (uint)local_a4 & 1;
        if (lVar27 == -1) {
          uVar13 = 1;
        }
        if (uVar13 == 0) {
          lVar4 = lVar27 - CONCAT44(local_98,unaff_r10);
          iVar16 = (int)((ulonglong)lVar4 >> 0x20);
          puVar22 = (undefined1 *)0x0;
          if (iVar16 < (int)(uint)((uint)lVar4 < 5)) {
            if ((int)(uint)(puVar19 == unaff_r10) <= iVar16) {
              return (undefined *)0x0;
            }
            goto LAB_010228e4;
          }
          FUN_0102546c((uint)unaff_r10,(int)local_98);
          uVar14 = extraout_r2_12;
        }
        else {
          puVar22 = (undefined1 *)0x0;
          FUN_0102546c((uint)unaff_r10,(int)local_98);
          uVar14 = extraout_r2_00;
        }
        goto LAB_010228d4;
      }
      uVar14 = 1;
      uVar17 = extraout_r2;
      if (lVar27 != -1) {
        puVar22 = (undefined1 *)0x0;
        goto LAB_010228e4;
      }
      goto LAB_01022d8c;
    }
    if (sVar8 != 0x5f5) {
      if (sVar8 == 0x18c) {
        puVar10 = &UsageFault;
      }
      else {
        puVar10 = (undefined1 *)0xb;
      }
      goto LAB_0102289c;
    }
    if (puVar22 == (undefined1 *)0x0 && (undefined1 *)(uint)(&SysTick < puVar23) <= puVar22)
    goto LAB_010228a6;
LAB_01022adc:
    puVar22 = (undefined1 *)(uint)(puVar26 != (undefined1 *)0x0);
    FUN_0102546c((uint)unaff_r10,(int)local_98);
    uVar14 = extraout_r2_01;
LAB_010228d4:
    puVar19 = local_98;
    lVar28 = CONCAT44(local_98,unaff_r10);
    if (local_98 == (undefined1 *)0xffffffff && unaff_r10 == (undefined1 *)0xffffffff)
    goto LAB_01022d6e;
LAB_010228e4:
    local_98 = (undefined1 *)((ulonglong)lVar28 >> 0x20);
    unaff_r10 = (undefined1 *)lVar28;
    uVar15 = (uint)unaff_r10 & 0xffffff;
    uVar13 = (uint)(puVar21 + ((int)local_8c - uVar15)) & 0xffffff;
    if (((uint)(puVar21 + ((int)local_8c - uVar15)) & 0xffffff) < 0x800001) {
      uVar13 = ((int)puVar21 - uVar15 & 0xffffff) - 1;
    }
    lVar28 = CONCAT44(uVar11,(uint)(0x7fffff >= uVar13));
    if (0x7fffff < uVar13) {
      return (undefined *)0x0;
    }
    iVar16 = FUN_01024c40(uVar15);
    puVar23 = local_80 + -iVar16;
    if (puVar23 < (undefined1 *)0xf424000) {
LAB_01022b28:
      if (DAT_2100171a == '\0') {
        puVar19 = local_84;
        if (local_84 < puVar26) {
          puVar19 = puVar26;
        }
        puVar19 = puVar19 + 0x1e;
        if ((int)puVar23 <= (int)puVar19) {
LAB_01022cde:
          puVar12 = (undefined2 *)FUN_01025edc(0x70,0xa8e,local_80,puVar19);
          *puVar12 = (short)puVar12;
          if ((uint)puVar21 >> 0x1c != 0) {
            bVar5 = puVar23[0x21001721];
            puVar23[0x21001721] = (&DAT_21001741)[(int)(extraout_r12 + 0x20) * 2];
            puVar22 = (undefined1 *)(uint)bVar5;
            do {
              puVar21 = puVar22;
              bVar3 = (&DAT_21001741)[(int)(puVar21 + 0x20) * 2];
              (&DAT_21001740)[(int)(puVar21 + 0x20) * 2] = 4;
              puVar22 = (undefined1 *)(uint)bVar3;
            } while (extraout_r12 != puVar21);
            if (puVar23[0x21001723] == 0x20) {
              puVar23[0x21001722] = bVar5;
            }
            else {
              (&DAT_21001741)[((byte)puVar23[0x21001723] + 0x20) * 2] = bVar5;
            }
            (&DAT_21001741)[(int)(puVar21 + 0x20) * 2] = 0x20;
            puVar23[0x21001723] = (char)puVar21;
            return (undefined1 *)(uint)bVar3;
          }
          return puVar21;
        }
      }
    }
    else {
      uVar11 = iVar16 - (int)local_80;
      if (255999999 < uVar11) {
        puVar19 = &DAT_1e847fff;
        if (&DAT_1e847fff < puVar23) {
          puVar23 = puVar23 + 512000000;
        }
        else {
          puVar10 = local_80;
          if (uVar11 < 512000000) goto LAB_01022da0;
          puVar23 = (undefined1 *)(-512000000 - uVar11);
        }
        goto LAB_01022b28;
      }
      puVar23 = (undefined1 *)-uVar11;
      puVar19 = (undefined1 *)0x0;
      if (DAT_2100171a == '\0') goto LAB_01022cde;
    }
    lVar27 = CONCAT44(puVar23,1);
    uVar14 = extraout_r1;
    puVar19 = local_80;
    if (local_78 != 1) {
      FUN_01025a4c(2,extraout_r1,local_80);
      FUN_01025a4c(1,extraout_r1_00,extraout_r2_02);
      uVar14 = extraout_r1_01;
      puVar19 = extraout_r2_03;
    }
    if (puVar26 < local_84) {
      local_b0 = 1;
      uVar11 = FUN_010258d0(2,1,(int)puVar23 - (int)local_84);
      uVar14 = extraout_r1_04;
      uVar17 = extraout_r2_06;
      if (puVar26 != (undefined1 *)0x0) {
        if (uVar11 == 0) goto LAB_01022c00;
        local_b0 = 1;
        uVar11 = FUN_010258d0(1,1,(int)puVar23 - (int)puVar26);
        uVar14 = extraout_r1_05;
        uVar17 = extraout_r2_07;
      }
LAB_01022c3e:
      if (uVar11 == 0) {
LAB_01022c00:
        FUN_01025a4c(2,uVar14,uVar17);
        FUN_01025a4c(1,extraout_r1_03,extraout_r2_05);
        return (undefined *)0x0;
      }
      local_b0 = 1;
      uVar11 = FUN_010258d0(0,uVar14,(uint)puVar23);
      uVar14 = extraout_r1_06;
      uVar17 = extraout_r2_08;
      if (uVar11 == 0) goto LAB_01022c00;
      if (puVar26 == (undefined1 *)0x0) goto LAB_01022b72;
LAB_01022c5a:
      lVar28 = CONCAT44(uVar14,DAT_21001730);
      if (puVar22 == (undefined1 *)0x0) {
        puVar19 = DAT_21001730;
        if (DAT_21001734 == 0xffffffff && DAT_21001730 == (undefined1 *)0xffffffff) {
          FUN_01024ee4();
          lVar28 = FUN_01025884();
          DAT_21001734 = (uint)((ulonglong)lVar28 >> 0x20);
          puVar19 = extraout_r2_13;
        }
LAB_01022c6c:
        DAT_21001730 = (undefined1 *)lVar28;
        uVar11 = 0;
        if (DAT_21001738 != 0) {
          FUN_01025a4c(5,(int)((ulonglong)lVar28 >> 0x20),puVar19);
          lVar28 = CONCAT44(extraout_r1_07,DAT_21001730);
          uVar11 = 0;
          DAT_21001738 = 0;
        }
      }
      else {
        if (DAT_21001734 != 0xffffffff || DAT_21001730 != (undefined1 *)0xffffffff) {
          FUN_01024f78();
          DAT_21001730 = (undefined1 *)0xffffffff;
          DAT_21001734 = 0xffffffff;
        }
LAB_01022ca2:
        local_b0 = 0;
        uVar11 = FUN_010258d0(5,0,(int)unaff_r10 - local_90);
        uVar14 = extraout_r2_09;
        uVar17 = extraout_r3;
        if (uVar11 == 0) goto LAB_01022d78;
        uVar11 = (uint)DAT_21001738;
        lVar28 = CONCAT44(extraout_r1_08,DAT_21001730);
        if (uVar11 == 0) {
          uVar11 = 1;
          DAT_21001738 = 1;
          lVar28 = CONCAT44(extraout_r1_08,DAT_21001730);
        }
      }
LAB_01022b92:
      DAT_21001730 = (undefined1 *)lVar28;
      puVar19 = puVar26 + 0x19;
      lVar27 = CONCAT44(puVar23,1);
      if ((int)puVar19 < (int)puVar23) {
        local_b0 = 1;
        uVar11 = FUN_010258d0(3,(int)((ulonglong)lVar28 >> 0x20),(int)puVar23 - (int)puVar19);
        if (uVar11 != 0) {
          *DAT_21001bc4 = 0;
        }
        local_3c = CONCAT22(uVar7,(undefined2)local_3c);
        local_3c = CONCAT31(local_3c._1_3_,(char)local_70);
        local_30._0_3_ = (uint3)CONCAT11((char)local_74,(char)local_9c);
        DAT_210016f0 = 0;
        DAT_210016f4 = uStack_54;
        DAT_210016f8 = 0xffffffff;
        DAT_210016fc = 0xffffffff;
        DAT_21001700 = puVar21;
        DAT_21001704 = local_a8;
        DAT_21001708 = local_8c;
        _DAT_2100170c = local_3c;
        _DAT_21001710 = local_38;
        DAT_21001714 = uStack_34;
        _DAT_21001718 = local_30;
        DAT_2100171c = uStack_2c;
        return &DAT_00000001;
      }
      goto LAB_01022d82;
    }
    if (local_84 < puVar26) {
      local_b0 = 1;
      uVar11 = FUN_010258d0(1,1,(int)puVar23 - (int)puVar26);
      uVar14 = extraout_r1_09;
      uVar17 = extraout_r2_10;
      if (local_84 != (undefined1 *)0x0) {
        if (uVar11 == 0) goto LAB_01022c00;
        local_b0 = 1;
        uVar11 = FUN_010258d0(2,1,(int)puVar23 - (int)local_84);
        uVar14 = extraout_r1_10;
        uVar17 = extraout_r2_11;
      }
      goto LAB_01022c3e;
    }
    uVar11 = (uint)puVar26 | (uint)local_84;
    lVar28 = CONCAT44(puVar23,1);
    if (uVar11 == 0) {
      local_b0 = 1;
      uVar11 = FUN_010258d0(0,uVar14,(uint)puVar23);
      uVar14 = extraout_r1_02;
      uVar17 = extraout_r2_04;
      if (uVar11 == 0) goto LAB_01022c00;
LAB_01022b72:
      if (DAT_21001738 != 0) goto LAB_01022c5a;
      if (DAT_21001734 == 0xffffffff && DAT_21001730 == (undefined1 *)0xffffffff) {
        uVar11 = DAT_21001734;
        lVar28 = CONCAT44(uVar14,DAT_21001730);
        if (puVar22 == (undefined1 *)0x0) goto LAB_01022b92;
      }
      else {
        FUN_01024f78();
        DAT_21001730 = (undefined1 *)0xffffffff;
        lVar28 = CONCAT44(extraout_r1_11,0xffffffff);
        DAT_21001734 = 0xffffffff;
        puVar19 = (undefined1 *)0xffffffff;
        if (puVar22 == (undefined1 *)0x0) goto LAB_01022c6c;
      }
      goto LAB_01022ca2;
    }
  }
  FUN_01025edc(0x70,0x9a3,puVar19,uVar11);
  puVar10 = extraout_r2_21;
  puVar19 = extraout_r3_07;
LAB_01022da0:
  uVar17 = (undefined4)((ulonglong)lVar28 >> 0x20);
  lVar27 = FUN_01025edc(0x70,0xb76,puVar10,puVar19);
  uVar14 = local_b0;
  uVar11 = (uint)((ulonglong)lVar27 >> 0x20);
  uStack_b4 = 0x1022dab;
  puStack_d0 = &DAT_210016f0;
  uVar7 = *(ushort *)(extraout_r2_22 + 8);
  uVar1 = *(undefined2 *)(extraout_r2_22 + 10);
  cVar2 = *extraout_r2_22;
  extraout_r3_08[4] = 0;
  extraout_r3_08[3] = 0;
  *(undefined2 *)(extraout_r3_08 + 4) = uVar1;
  extraout_r3_08[2] = 0;
  extraout_r3_08[5] = 0;
  *(ushort *)((int)extraout_r3_08 + 0xe) = uVar7;
  *(char *)((int)extraout_r3_08 + 0x12) = cVar2;
  *extraout_r3_08 = 0;
  extraout_r3_08[1] = 0;
  puStack_d4 = puVar21;
  uStack_cc = (int)lVar28;
  puStack_c8 = puVar22;
  puStack_c4 = puVar23;
  uStack_c0 = uVar17;
  puStack_bc = unaff_r10;
  puStack_b8 = puVar26;
  if (cVar2 != '\0') {
    FUN_01024ccc((int)&DAT_1e847fff - (uint)uVar7,(int *)&uStack_e4,(char *)(extraout_r3_08 + 3));
    uVar7 = *(ushort *)((int)extraout_r3_08 + 0xe);
    FUN_01024ccc((uint)uVar7,(int *)&uStack_e0,&cStack_e5);
    uVar9 = FUN_01024e44();
    uVar13 = FUN_01024dd8((uint)uVar9);
    if (DAT_2100173a == ' ') {
      lVar28 = lVar27 + 0xb;
      if ((uVar7 != 0) && (bVar5 = FUN_010252d0(), bVar5 == 0)) {
        sVar8 = FUN_01024ed8();
        if (sVar8 == 0x356) {
          lVar28 = lVar27 + 0x27;
        }
        else if (sVar8 == 0x5f5) {
          lVar28 = lVar27 + 0x3d;
        }
        else if (sVar8 == 0x18c) {
          lVar28 = lVar27 + 0x18;
        }
      }
      if (uStack_e0 < uVar13) {
        lVar28 = lVar28 + (ulonglong)(uVar13 - uStack_e0);
      }
    }
    else {
      lVar28 = CONCAT44(DAT_21001704 + ((undefined1 *)0xfffffff8 < DAT_21001700) +
                        (uint)CARRY4((uint)(DAT_21001700 + 7),(uint)DAT_21001708),
                        DAT_21001700 + 7 + (int)DAT_21001708);
    }
    iVar16 = *(int *)(extraout_r2_22 + 4);
    if (extraout_r2_22[0xb] == '\0') {
      iVar20 = 0x7a;
    }
    else {
      iVar20 = 0x60;
    }
    *(longlong *)extraout_r3_08 = lVar28;
    uVar13 = FUN_01024dd8(iVar20 + (uint)*(ushort *)((int)extraout_r3_08 + 0xe) +
                                   (uint)(byte)extraout_r3_08[3] + iVar16 + 2);
    extraout_r3_08[2] = uVar13;
    puVar23 = (undefined1 *)
              FUN_010225f0(*(uint *)(extraout_r2_22 + 0x10),extraout_r3_08,(uint)lVar27,uVar11,
                           (byte)uVar14);
    if (puVar23 == (undefined1 *)0x0) {
      *(longlong *)extraout_r3_08 = lVar27;
    }
    return puVar23;
  }
  lVar28 = FUN_01024c5c((uint)lVar27,uVar11);
  puVar23 = (undefined1 *)lVar28;
  puVar22 = *(undefined1 **)(extraout_r2_22 + 0x10);
  uVar11 = *(uint *)(extraout_r2_22 + 0x14);
  uVar13 = (uint)((ulonglong)(lVar28 + 256000000) >> 0x20);
  if ((uVar11 <= uVar13 && (uint)((undefined1 *)(lVar28 + 256000000) <= puVar22) <= uVar11 - uVar13)
     && (puVar23 = (undefined1 *)(lVar28 + 0x2f),
        uVar13 = (uint)((ulonglong)(lVar28 + 0x2f) >> 0x20),
        uVar13 < uVar11 || uVar11 - uVar13 < (uint)(puVar23 <= puVar22))) {
    puVar23 = (undefined1 *)(*(ushort *)(extraout_r2_22 + 8) + 1);
    if (uVar11 == 0 && (puVar23 <= puVar22) <= uVar11) {
      uVar13 = 0;
      uVar11 = 0;
    }
    else {
      uVar13 = (int)puVar22 - (int)puVar23;
      uVar11 = uVar11 - (puVar22 < puVar23);
    }
    FUN_01024d24(uVar13,uVar11,&uStack_e4,(int *)&uStack_e0,(char *)(extraout_r3_08 + 3));
    if (extraout_r2_22[0xb] == '\0') {
      iVar16 = 0x7a;
    }
    else {
      iVar16 = 0x60;
    }
    iVar16 = FUN_01024dd8(iVar16 + uStack_e4 + 2 + *(int *)(extraout_r2_22 + 4) +
                                   (uint)*(ushort *)(extraout_r2_22 + 8));
    puVar23 = (undefined1 *)(iVar16 - uStack_e0 & 0xffffff);
    *extraout_r3_08 = uStack_e0;
    extraout_r3_08[1] = uStack_dc;
    extraout_r3_08[2] = (uint)puVar23;
    return puVar23;
  }
  *(longlong *)extraout_r3_08 = lVar27 + -1;
  extraout_r3_08[2] = 1000;
  return puVar23;
}


