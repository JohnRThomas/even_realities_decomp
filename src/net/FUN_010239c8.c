/*
 * Function: FUN_010239c8
 * Entry:    010239c8
 * Prototype: uint __stdcall FUN_010239c8(uint param_1, byte * param_2)
 */


/* WARNING: Removing unreachable block (ram,0x010239f4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_010239c8(uint param_1,byte *param_2)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  bool bVar4;
  char cVar5;
  longlong lVar6;
  byte bVar7;
  ushort uVar8;
  short sVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  undefined4 uVar13;
  undefined4 uVar14;
  uint extraout_r2;
  uint extraout_r2_00;
  undefined4 extraout_r2_01;
  uint extraout_r2_02;
  uint extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar15;
  uint uVar16;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint extraout_r3_01;
  undefined4 *unaff_r4;
  uint unaff_r5;
  char *unaff_r6;
  undefined4 *puVar17;
  undefined4 *unaff_r7;
  uint uVar18;
  uint uVar19;
  int unaff_r8;
  int iVar20;
  char *unaff_r9;
  int unaff_r10;
  char *pcVar21;
  uint unaff_r11;
  undefined4 *puVar22;
  undefined4 *extraout_r12;
  longlong lVar23;
  uint local_5c;
  uint local_54;
  undefined4 local_50;
  undefined4 *local_4c;
  undefined8 uStack_48;
  uint local_40;
  uint uStack_3c;
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  
  uVar14 = 0xe000ed00;
  cVar5 = (char)param_1;
  if ((_DAT_e000ed04 & 0x1ff) == 0) {
    local_5c = 8;
  }
  else {
    uVar18 = (_DAT_e000ed04 & 0x1ff) - 0x10;
    iVar20 = (int)(char)uVar18;
    if (iVar20 < 0) {
      bVar7 = (&DAT_e000ed14)[uVar18 & 0xf];
    }
    else {
      bVar7 = (&DAT_e000e400)[iVar20];
    }
    local_5c = (uint)(bVar7 >> 5);
    if (local_5c == 0) {
      unaff_r4 = &DAT_210016f0;
      uVar18 = (uint)DAT_2100173a;
      if (uVar18 != 0x20) {
        local_5c = (uint)*param_2;
        if (local_5c != 0) {
          FUN_01025edc(0x70,0x71d,0xe000ed00,local_5c);
          goto LAB_01023e3c;
        }
        goto LAB_010239f0;
      }
      goto LAB_01023f98;
    }
  }
  if (*param_2 < 2) {
LAB_010239f0:
    unaff_r5 = 0;
    uVar18 = 0;
    iVar20 = 1;
    local_50 = (uint *)(&DAT_210017c8 + param_1 * 0x20);
LAB_01023a1a:
    do {
      unaff_r4 = &DAT_210016f0;
      if (iVar20 == 0) {
        enableIRQinterrupts();
      }
      unaff_r6 = (char *)(uint)DAT_21001739;
      DAT_21001729 = '\0';
      if (local_5c != 0) {
        iVar11 = (int)unaff_r6 * 0x40;
        pcVar21 = (char *)((uint)(unaff_r6 + 1) & 1);
        iVar1 = (int)pcVar21 * 0x40;
        uVar14 = *(undefined4 *)(&DAT_21001744 + iVar11);
        uVar13 = *(undefined4 *)(&DAT_21001748 + iVar11);
        uVar15 = *(undefined4 *)(&DAT_2100174c + iVar11);
        *(undefined4 *)(&DAT_21001740 + iVar1) = *(undefined4 *)(&DAT_21001740 + iVar11);
        *(undefined4 *)(&DAT_21001744 + iVar1) = uVar14;
        *(undefined4 *)(&DAT_21001748 + iVar1) = uVar13;
        *(undefined4 *)(&DAT_2100174c + iVar1) = uVar15;
        uVar14 = *(undefined4 *)(&DAT_21001754 + iVar11);
        uVar13 = *(undefined4 *)(&DAT_21001758 + iVar11);
        uVar15 = *(undefined4 *)(&DAT_2100175c + iVar11);
        *(undefined4 *)(&DAT_21001750 + iVar1) = *(undefined4 *)(&DAT_21001750 + iVar11);
        *(undefined4 *)(&DAT_21001754 + iVar1) = uVar14;
        *(undefined4 *)(&DAT_21001758 + iVar1) = uVar13;
        *(undefined4 *)(&DAT_2100175c + iVar1) = uVar15;
        uVar14 = *(undefined4 *)(&DAT_21001764 + iVar11);
        uVar13 = *(undefined4 *)(&DAT_21001768 + iVar11);
        uVar15 = *(undefined4 *)(&DAT_2100176c + iVar11);
        *(undefined4 *)(&DAT_21001760 + iVar1) = *(undefined4 *)(&DAT_21001760 + iVar11);
        *(undefined4 *)(&DAT_21001764 + iVar1) = uVar14;
        *(undefined4 *)(&DAT_21001768 + iVar1) = uVar13;
        *(undefined4 *)(&DAT_2100176c + iVar1) = uVar15;
        uVar14 = *(undefined4 *)(&DAT_21001774 + iVar11);
        uVar13 = *(undefined4 *)(&DAT_21001778 + iVar11);
        uVar15 = *(undefined4 *)(&DAT_2100177c + iVar11);
        *(undefined4 *)(&DAT_21001770 + iVar1) = *(undefined4 *)(&DAT_21001770 + iVar11);
        *(undefined4 *)(&DAT_21001774 + iVar1) = uVar14;
        *(undefined4 *)(&DAT_21001778 + iVar1) = uVar13;
        *(undefined4 *)(&DAT_2100177c + iVar1) = uVar15;
        uVar2 = (&DAT_21001722)[(int)unaff_r6 * 3];
        *(undefined2 *)((int)&DAT_21001720 + (int)pcVar21 * 3) =
             *(undefined2 *)((int)&DAT_21001720 + (int)unaff_r6 * 3);
        (&DAT_21001722)[(int)pcVar21 * 3] = uVar2;
        unaff_r6 = pcVar21;
        if (DAT_21001729 != '\0') goto LAB_01023a1a;
      }
      lVar23 = FUN_01025884();
      local_54 = (uint)lVar23;
      FUN_01022dac(local_54,(uint)((ulonglong)lVar23 >> 0x20),(char *)param_2,&local_40,
                   (byte)unaff_r6);
      unaff_r8 = (int)unaff_r6 * 0x20;
      iVar20 = (param_1 + (int)unaff_r6 * 0x20) * 2;
      unaff_r10 = (int)&DAT_210016f0 + iVar20;
      if ((byte)(&DAT_21001740)[iVar20] - 1 < 2) {
        uVar18 = local_40 - (local_54 & 0xffffff);
        uVar19 = (uint)((uVar18 & 0xfffffe) != 0);
        if (0x800000 < (uVar18 & 0xffffff)) {
          uVar19 = 0;
        }
        if (0x800000 < ((local_38 + local_40) - (local_54 & 0xffffff) & 0xffffff)) {
          uVar19 = 0;
        }
        if (uVar19 == 0) {
          (&DAT_21001740)[iVar20] = 4;
          if ((&DAT_21001722)[(int)unaff_r6 * 3] == 0x20) {
            *(char *)((int)&DAT_21001720 + (int)unaff_r6 * 3 + 1) = cVar5;
          }
          else {
            (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[(int)unaff_r6 * 3] + unaff_r8) * 2] = cVar5
            ;
          }
          (&DAT_21001722)[(int)unaff_r6 * 3] = cVar5;
          (&DAT_21001741)[(unaff_r8 + param_1) * 2] = 0x20;
          uVar18 = uVar19;
          uVar19 = 1;
        }
        else {
          unaff_r11 = FUN_0102237c(&local_40,(int)unaff_r6,(byte *)((int)&uStack_48 + 6),
                                   (byte *)((int)&uStack_48 + 7));
          if (unaff_r11 == 0) {
            (&DAT_21001740)[iVar20] = 4;
            if ((&DAT_21001722)[(int)unaff_r6 * 3] == 0x20) {
              *(char *)((int)&DAT_21001720 + (int)unaff_r6 * 3 + 1) = cVar5;
            }
            else {
              (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[(int)unaff_r6 * 3] + unaff_r8) * 2] =
                   cVar5;
            }
            uVar18 = 0;
            (&DAT_21001722)[(int)unaff_r6 * 3] = cVar5;
            (&DAT_21001741)[(unaff_r8 + param_1) * 2] = 0x20;
          }
          else {
            unaff_r7 = (undefined4 *)(uStack_48._4_4_ >> 0x10 & 0xff);
            puVar10 = (undefined4 *)(uStack_48._4_4_ >> 0x18);
            unaff_r9 = unaff_r6;
            if (unaff_r7 == puVar10) {
LAB_01023e3c:
              if (unaff_r7 != (undefined4 *)&Reserved2) {
                *(undefined *)(unaff_r10 + 0x51) =
                     (&DAT_21001741)[(int)(unaff_r8 + (int)unaff_r7) * 2];
                goto LAB_01023e50;
              }
              iVar20 = (int)unaff_r9 << 1;
              *(undefined1 *)(unaff_r10 + 0x51) =
                   *(undefined1 *)((int)&DAT_21001720 + (int)unaff_r9 * 3);
              uVar18 = unaff_r11;
LAB_01023d26:
              unaff_r9[iVar20 + 0x21001720] = cVar5;
              uVar19 = uVar18;
            }
            else {
              uVar14 = extraout_r2_01;
              uVar13 = extraout_r3;
              if (puVar10 == (undefined4 *)&Reserved2) goto LAB_01023f8e;
              if (unaff_r7 == (undefined4 *)&Reserved2) {
                bVar7 = *(byte *)((int)&DAT_21001720 + (int)unaff_r6 * 3);
                *(undefined *)((int)&DAT_21001720 + (int)unaff_r6 * 3) =
                     (&DAT_21001741)[(int)(puVar10 + (int)unaff_r6 * 8) * 2];
              }
              else {
                bVar7 = (&DAT_21001741)[(int)(unaff_r7 + (int)unaff_r6 * 8) * 2];
                (&DAT_21001741)[(int)(unaff_r7 + (int)unaff_r6 * 8) * 2] =
                     (&DAT_21001741)[(int)(puVar10 + (int)unaff_r6 * 8) * 2];
              }
              local_4c = (undefined4 *)(uint)bVar7;
              iVar20 = (int)unaff_r6 * 2;
              puVar17 = local_4c;
              do {
                puVar22 = puVar17;
                bVar3 = (&DAT_21001741)[(int)(puVar22 + (int)unaff_r6 * 8) * 2];
                (&DAT_21001740)[(int)(puVar22 + (int)unaff_r6 * 8) * 2] = 5;
                puVar17 = (undefined4 *)(uint)bVar3;
              } while (puVar10 != puVar22);
              if ((&DAT_21001722)[(int)unaff_r6 * 3] == 0x20) {
                *(byte *)((int)&DAT_21001720 + (int)unaff_r6 * 3 + 1) = bVar7;
              }
              else {
                (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[(int)unaff_r6 * 3] + unaff_r8) * 2] =
                     bVar7;
              }
              (&DAT_21001722)[(int)unaff_r6 * 3] = (char)puVar22;
              (&DAT_21001741)[(int)(puVar22 + (int)unaff_r6 * 8) * 2] = 0x20;
              (&DAT_21001741)[(param_1 + unaff_r8) * 2] = bVar3;
              uVar18 = unaff_r11;
              if (unaff_r7 == (undefined4 *)&Reserved2) goto LAB_01023d26;
LAB_01023e50:
              (&DAT_21001741)[(int)((int)unaff_r7 + unaff_r8) * 2] = cVar5;
              uVar18 = 0;
              uVar19 = unaff_r11;
            }
            (&DAT_21001740)[(unaff_r8 + param_1) * 2] = 3;
          }
        }
      }
      else {
        uVar19 = 0;
      }
      iVar20 = 0;
      bVar4 = (bool)isCurrentModePrivileged();
      if (bVar4) {
        iVar20 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      if (DAT_21001729 == '\0') {
        *local_50 = local_40;
        local_50[1] = uStack_3c;
        local_50[2] = local_38;
        local_50[3] = uStack_34;
        local_50[4] = local_30;
        local_50[5] = uStack_2c;
        if (uVar19 == 0) {
LAB_01023f38:
          uVar12 = uStack_2c;
          if (unaff_r5 != 0) {
            uVar12 = 0;
          }
          goto LAB_01023bee;
        }
        uVar12 = uStack_2c;
        if (unaff_r5 != 0) {
          uVar12 = 0;
        }
        if (local_5c == 0) {
          if (unaff_r5 == 0) {
            DAT_21001729 = -1;
          }
          else {
            DAT_21001729 = -1;
            uVar12 = 0;
          }
          goto LAB_01023bee;
        }
        uVar16 = local_38;
        if ((uVar18 == 0) || (DAT_2100173a != 0x20)) goto LAB_01023ba8;
        iVar11 = FUN_0102306c(2,(int)unaff_r6);
        uVar12 = extraout_r1;
        uVar16 = extraout_r2;
        if (iVar11 != 0) goto joined_r0x01023f6e;
        uVar12 = (uint)*param_2;
        if (uVar12 == 0) {
          uVar19 = (uint)DAT_21001739;
          uVar12 = (uint)DAT_21001739;
          bVar7 = (&DAT_21001722)[uVar19 * 3];
          (&DAT_21001740)[(param_1 + uVar19 * 0x20) * 2] = 4;
          if (bVar7 == 0x20) {
            *(char *)((int)&DAT_21001720 + uVar19 * 3 + 1) = cVar5;
          }
          else {
            (&DAT_21001741)[((uint)bVar7 + uVar19 * 0x20) * 2] = cVar5;
          }
          iVar11 = (uVar19 * 0x20 + param_1) * 2;
          local_38 = (int)&DAT_210016f0 + iVar11;
          (&DAT_21001722)[uVar19 * 2 + uVar12] = cVar5;
          (&DAT_21001741)[iVar11] = 0x20;
          uStack_2c = param_1;
          uVar19 = uVar18;
          goto LAB_01023f38;
        }
        uVar16 = extraout_r2;
        if (uVar12 != 1) {
LAB_01023ba8:
          iVar11 = 0;
joined_r0x01023f6e:
          local_38 = uVar16;
          if (unaff_r5 != 0) {
            uVar12 = 0;
          }
          DAT_21001739 = ~DAT_21001739 & 1;
          DAT_21001729 = -1;
          if (unaff_r5 != 0) {
            uVar12 = 0;
          }
          if (iVar11 == 2) {
            FUN_01024c40(DAT_21001700 - local_54);
            uVar12 = extraout_r1_01;
            local_38 = extraout_r2_02;
            if (DAT_21001bc0 != (code *)0x0) {
              (*DAT_21001bc0)();
              uVar12 = extraout_r1_02;
              local_38 = extraout_r2_03;
            }
          }
          else if ((iVar11 == 1) && (DAT_21001bc0 != (code *)0x0)) {
            (*DAT_21001bc0)(0xffffffff);
            uVar12 = extraout_r1_00;
            local_38 = extraout_r2_00;
          }
LAB_01023bee:
          if (iVar20 == 0) {
            enableIRQinterrupts();
          }
          if (unaff_r5 != 0) {
            uVar12 = 0;
          }
          if ((uVar19 != 0) &&
             (uVar18 = (uint)*(byte *)((int)&DAT_21001720 + (uint)DAT_21001739 * 3 + 1),
             uVar18 != 0x20)) {
            if (unaff_r5 != 0) {
              uVar12 = 0;
            }
            FUN_0102603c((uint)DAT_21001bc9,uVar12,local_38,uVar18);
          }
          return uVar19;
        }
      }
    } while( true );
  }
  FUN_01025edc(0x70,0x721,0xe000ed00,(uint)*param_2);
  uVar14 = extraout_r2_04;
  uVar13 = extraout_r3_00;
LAB_01023f8e:
  FUN_01025edc(0x70,0x281,uVar14,uVar13);
  uVar14 = extraout_r2_05;
  uVar18 = extraout_r3_01;
LAB_01023f98:
  FUN_01025edc(0x70,0x71a,uVar14,uVar18);
  puVar10 = extraout_r12;
  do {
    uVar14 = puVar10[1];
    uVar13 = puVar10[2];
    uVar15 = puVar10[3];
    *unaff_r7 = *puVar10;
    unaff_r7[1] = uVar14;
    unaff_r7[2] = uVar13;
    unaff_r7[3] = uVar15;
    uVar2 = *(undefined1 *)((int)unaff_r4 + unaff_r11 * 3 + 0x32);
    *(undefined2 *)((int)unaff_r4 + unaff_r5 * 3 + 0x30) =
         *(undefined2 *)((int)unaff_r4 + unaff_r11 * 3 + 0x30);
    *(undefined1 *)((int)unaff_r4 + unaff_r5 * 3 + 0x32) = uVar2;
    lVar23 = FUN_01025884();
    uVar19 = (uint)((ulonglong)lVar23 >> 0x20);
    uVar18 = (uint)lVar23;
    FUN_01022dac(uVar18,uVar19,unaff_r9,(uint *)&uStack_48,(byte)unaff_r5);
    if (*(char *)((int)unaff_r4 + 0x4a) == ' ') {
LAB_010238e6:
      bVar4 = false;
    }
    else {
      uVar16 = unaff_r4[6] + unaff_r4[4];
      uVar12 = unaff_r4[5] + (uint)CARRY4(unaff_r4[6],unaff_r4[4]);
      if (uVar12 < uStack_48._4_4_ || uStack_48._4_4_ - uVar12 < (uint)(uVar16 <= (uint)uStack_48))
      goto LAB_010238e6;
      bVar4 = true;
      uStack_48 = CONCAT44(uVar12,uVar16);
    }
    if ((((local_40 + (uint)uStack_48) - (uVar18 & 0xffffff) & 0xffffff) < 0x800001) &&
       (((uint)uStack_48 - (uVar18 & 0xffffff) & 0xffffff) < 0x800001)) {
      iVar20 = FUN_010225f0(256000000,(uint *)&uStack_48,uVar18,uVar19,(byte)unaff_r5);
      if ((bVar4) || (iVar20 != 0)) goto LAB_010238a6;
    }
    else {
      uVar18 = uStack_3c >> 0x10;
      FUN_01024ccc(uVar18,(int *)&local_4c,(char *)((int)&local_50 + 3));
      uVar8 = FUN_01024e44();
      puVar10 = (undefined4 *)FUN_01024dd8((uint)uVar8);
      if (*(char *)((int)unaff_r4 + 0x4a) == ' ') {
        lVar6 = lVar23 + 0xb;
        if (uVar18 != 0) {
          bVar7 = FUN_010252d0();
          if (bVar7 == 0) {
            sVar9 = FUN_01024ed8();
            if (sVar9 == 0x356) {
              lVar6 = lVar23 + 0x27;
            }
            else if (sVar9 == 0x5f5) {
              lVar6 = lVar23 + 0x3d;
            }
            else if (sVar9 == 0x18c) {
              lVar6 = lVar23 + 0x18;
            }
          }
        }
        if (local_4c < puVar10) {
          lVar6 = lVar6 + (ulonglong)(uint)((int)puVar10 - (int)local_4c);
        }
      }
      else {
        uVar18 = unaff_r4[4] + 7;
        lVar6 = CONCAT44(unaff_r4[5] + (uint)(0xfffffff8 < (uint)unaff_r4[4]) +
                         (uint)CARRY4(uVar18,unaff_r4[6]),uVar18 + unaff_r4[6]);
      }
      uStack_3c = CONCAT31(uStack_3c._1_3_,0x1f);
      uStack_48 = lVar6;
LAB_010238a6:
      lVar23 = FUN_01024c5c((uint)uStack_48,(uint)((ulonglong)uStack_48 >> 0x20));
      *(longlong *)(unaff_r9 + 0x10) =
           lVar23 + CONCAT44(unaff_r10 * 2 + (uint)CARRY4(uStack_3c >> 0x10,uStack_3c & 0xff),
                             (uStack_3c >> 0x10) + (uStack_3c & 0xff) + 1);
    }
    if (*(char *)((int)unaff_r4 + 0x39) == '\0') {
      return 1;
    }
    unaff_r11 = (uint)*(byte *)((int)unaff_r4 + 0x49);
    *(char *)((int)unaff_r4 + 0x39) = (char)unaff_r10;
    puVar22 = (undefined4 *)(unaff_r8 + unaff_r11 * 0x40);
    unaff_r5 = unaff_r11 + 1 & 1;
    uVar14 = puVar22[1];
    uVar13 = puVar22[2];
    uVar15 = puVar22[3];
    puVar17 = (undefined4 *)(unaff_r8 + unaff_r5 * 0x40);
    *puVar17 = *puVar22;
    puVar17[1] = uVar14;
    puVar17[2] = uVar13;
    puVar17[3] = uVar15;
    uVar14 = puVar22[5];
    uVar13 = puVar22[6];
    uVar15 = puVar22[7];
    puVar17[4] = puVar22[4];
    puVar17[5] = uVar14;
    puVar17[6] = uVar13;
    puVar17[7] = uVar15;
    uVar14 = puVar22[9];
    uVar13 = puVar22[10];
    uVar15 = puVar22[0xb];
    puVar10 = puVar22 + 0xc;
    puVar17[8] = puVar22[8];
    puVar17[9] = uVar14;
    puVar17[10] = uVar13;
    puVar17[0xb] = uVar15;
    unaff_r7 = puVar17 + 0xc;
  } while( true );
}


