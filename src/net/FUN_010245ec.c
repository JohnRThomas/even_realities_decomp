/*
 * Function: FUN_010245ec
 * Entry:    010245ec
 * Prototype: uint __stdcall FUN_010245ec(uint param_1)
 */


/* WARNING: Removing unreachable block (ram,0x01024a80) */
/* WARNING: Removing unreachable block (ram,0x01024b24) */
/* WARNING: Removing unreachable block (ram,0x01024af8) */
/* WARNING: Removing unreachable block (ram,0x0102499c) */
/* WARNING: Removing unreachable block (ram,0x01024944) */
/* WARNING: Removing unreachable block (ram,0x01024ac8) */
/* WARNING: Removing unreachable block (ram,0x01024ad2) */
/* WARNING: Removing unreachable block (ram,0x01024b98) */
/* WARNING: Removing unreachable block (ram,0x01024ad8) */
/* WARNING: Removing unreachable block (ram,0x01024ae6) */
/* WARNING: Removing unreachable block (ram,0x010249c0) */
/* WARNING: Removing unreachable block (ram,0x01024a04) */
/* WARNING: Removing unreachable block (ram,0x01024a32) */
/* WARNING: Removing unreachable block (ram,0x01024aba) */
/* WARNING: Removing unreachable block (ram,0x01024a46) */
/* WARNING: Removing unreachable block (ram,0x01024b4e) */
/* WARNING: Removing unreachable block (ram,0x01024b40) */
/* WARNING: Removing unreachable block (ram,0x01024b6a) */

uint FUN_010245ec(uint param_1)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  short sVar6;
  uint uVar7;
  undefined2 *puVar8;
  uint extraout_r1;
  uint extraout_r1_00;
  byte bVar9;
  undefined4 extraout_r2;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 extraout_r2_00;
  undefined4 uVar13;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint extraout_r3;
  int extraout_r3_00;
  undefined4 uVar17;
  int extraout_r3_01;
  undefined1 *puVar18;
  undefined1 *extraout_r3_02;
  uint uVar19;
  char *unaff_r6;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  char cStack_95;
  uint uStack_94;
  int aiStack_90 [2];
  undefined4 *puStack_88;
  char cStack_3d;
  int aiStack_3c [2];
  
  iVar12 = DAT_210016f0;
  if (DAT_2100173a != 0x20) {
    uVar14 = (uint)*(byte *)((int)&DAT_21001720 + (uint)DAT_21001739 * 3);
    if (uVar14 != 0x20) {
      do {
        iVar16 = uVar14 * 0x20;
        if ((byte)(&DAT_210017d8)[iVar16] <= param_1) {
          iVar1 = (uint)DAT_2100173a * 0x20;
          uVar14 = *(uint *)(&DAT_210017d0 + iVar1) + *(uint *)(&DAT_210017c8 + iVar1);
          uVar15 = *(int *)(&DAT_210017cc + iVar1) +
                   (uint)CARRY4(*(uint *)(&DAT_210017d0 + iVar1),*(uint *)(&DAT_210017c8 + iVar1));
          if ((uVar15 < *(uint *)(&DAT_210017cc + iVar16) ||
               *(uint *)(&DAT_210017cc + iVar16) - uVar15 <
               (uint)(uVar14 <= *(uint *)(&DAT_210017c8 + iVar16))) &&
             (uVar14 = FUN_01024c40(*(uint *)(&DAT_210017c8 + iVar16) - uVar14),
             iVar12 + 0x76U <= uVar14)) {
            return uVar14 - iVar12;
          }
          return 0;
        }
        uVar14 = (uint)(byte)(&DAT_21001741)[(uVar14 + (uint)DAT_21001739 * 0x20) * 2];
      } while (uVar14 != 0x20);
    }
    return 0xffffffff;
  }
  FUN_01025edc(0x70,0xb86,&DAT_210016f0,0x20);
  if (DAT_2100173a != 0x20) {
    return (uint)DAT_21001710;
  }
  FUN_01025edc(0x70,0xbad,0x20,&DAT_210016f0);
  iVar12 = DAT_21001708;
  uVar14 = DAT_21001700;
  uVar15 = (int)unaff_r6 >> 0x1b;
  if (DAT_2100173a != 0x20) {
    uVar19 = (uint)DAT_2100173a;
    uVar21 = (uint)*(byte *)((int)&DAT_21001720 + (uint)DAT_21001739 * 3);
    FUN_01024ccc(DAT_210016f0 + uVar15,aiStack_3c,&cStack_3d);
    if (uVar15 - 0x76 < 0xf423f8b) {
      iVar16 = uVar19 * 0x20;
      uVar7 = (aiStack_3c[0] + *(int *)(&DAT_210017c8 + iVar16) + *(int *)(&DAT_210017d0 + iVar16))
              - DAT_21001700;
      if ((uVar7 & 0xffffff) < 0x800001) {
        uVar23 = (uint)DAT_21001739;
        DAT_21001710 = 0;
        DAT_21001708 = uVar7;
        if (uVar21 == 0x20) {
          FUN_01025a4c(5,&DAT_210016f0 + uVar19 * 8,(uint)DAT_21001739);
          uVar14 = (uint)DAT_21001739;
LAB_01024778:
          DAT_210016fc = 0xffffffff;
          DAT_210016f8 = 0xffffffff;
          uVar7 = 0x20;
          bVar9 = *(byte *)((int)&DAT_21001720 + uVar14 * 3);
        }
        else {
          uVar19 = 0;
          uVar7 = 0x20;
          do {
            uVar22 = uVar21;
            uVar21 = DAT_21001700;
            iVar16 = uVar22 * 0x20;
            uVar20 = DAT_21001704 + (uint)CARRY4(DAT_21001708,DAT_21001700);
            uVar10 = *(uint *)(&DAT_210017c8 + iVar16);
            if (uVar20 < *(uint *)(&DAT_210017cc + iVar16) ||
                *(uint *)(&DAT_210017cc + iVar16) - uVar20 <
                (uint)(DAT_21001708 + DAT_21001700 <= uVar10)) {
              if ((*(short *)(&DAT_210017d6 + iVar16) != 0) && (DAT_2100170e == 0)) {
                sVar6 = FUN_01024ed8();
                if (sVar6 == 0x356) {
                  iVar16 = 0x1d;
                }
                else if (sVar6 == 0x5f5) {
                  iVar16 = 0x33;
                }
                else if (sVar6 == 0x18c) {
                  iVar16 = 0xe;
                }
                else {
                  iVar16 = 1;
                }
                uVar10 = uVar10 - uVar21;
                uVar19 = extraout_r1;
                if ((int)uVar10 < iVar16) {
                  uVar19 = (uint)DAT_21001710;
                  goto LAB_010247fa;
                }
              }
              FUN_01025a4c(5,uVar19,uVar10);
              uVar14 = (uint)DAT_21001739;
              if (uVar7 == 0x20) goto LAB_01024778;
              goto LAB_0102485c;
            }
LAB_010247fa:
            if ((byte)(&DAT_210017d8)[uVar22 * 0x20] <= uVar19) {
              DAT_21001708 = (iVar12 + uVar14) - DAT_21001700;
              return 2;
            }
            uVar21 = (uint)(byte)(&DAT_21001741)[(uVar22 + uVar23 * 0x20) * 2];
            uVar7 = uVar22;
          } while ((byte)(&DAT_21001741)[(uVar22 + uVar23 * 0x20) * 2] != 0x20);
          FUN_01025a4c(5,uVar19,uVar10);
          uVar14 = (uint)DAT_21001739;
LAB_0102485c:
          DAT_210016fc = 0xffffffff;
          DAT_210016f8 = 0xffffffff;
          bVar3 = *(byte *)((int)&DAT_21001720 + uVar14 * 3);
          iVar12 = uVar14 * 0x20;
          *(undefined *)((int)&DAT_21001720 + uVar14 * 3) =
               (&DAT_21001741)[(uVar7 + uVar14 * 0x20) * 2];
          bVar9 = bVar3;
          do {
            bVar4 = bVar9;
            uVar21 = (uint)bVar4;
            iVar16 = (iVar12 + uVar21) * 2;
            bVar9 = (&DAT_21001741)[iVar16];
            (&DAT_21001740)[iVar16] = 5;
          } while (uVar7 != uVar21);
          if ((&DAT_21001722)[uVar14 * 3] == 0x20) {
            *(byte *)((int)&DAT_21001720 + uVar14 * 3 + 1) = bVar3;
          }
          else {
            (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[uVar14 * 3] + iVar12) * 2] = bVar3;
          }
          (&DAT_21001741)[(uVar21 + iVar12) * 2] = 0x20;
          (&DAT_21001722)[uVar14 * 3] = bVar4;
        }
        uVar21 = (uint)DAT_21001739;
        (&DAT_21001741)[((uint)DAT_2100173a + uVar21 * 0x20) * 2] = bVar9;
        DAT_210016f0 = DAT_210016f0 + uVar15;
        uVar11 = 0xff;
        DAT_21001729 = 0xff;
        uVar14 = 0;
        if ((DAT_21001727 != '\0') && (uVar14 = (uint)DAT_21001711, uVar14 == 1)) {
          iVar12 = DAT_21001704 + -1 + (uint)(DAT_21001700 != 0);
          FUN_0102561c((DAT_21001700 - 1) + DAT_21001708,
                       iVar12 + (uint)CARRY4(DAT_21001700 - 1,DAT_21001708),iVar12);
          uVar21 = extraout_r1_00;
          uVar11 = extraout_r2_00;
          uVar14 = extraout_r3;
        }
        if (uVar7 == 0x20) {
          return 0;
        }
        FUN_0102603c((uint)DAT_21001bc9,uVar21,uVar11,uVar14);
        return 0;
      }
    }
    return 1;
  }
  FUN_01025edc(0x70,0xbb3,extraout_r2,0x20);
  if ((&DAT_21001740)[(uVar15 + (uint)DAT_21001739 * 0x20) * 2] != '\0') {
    uVar14 = (uint)DAT_21001739;
    iVar12 = (uVar14 * 0x20 + uVar15) * 2;
    bVar9 = (&DAT_21001740)[iVar12];
    do {
      if (bVar9 == 1) {
LAB_01024992:
        iVar12 = 1;
        do {
          do {
            if (iVar12 == 0) {
              enableIRQinterrupts();
            }
            DAT_21001729 = '\0';
            uVar21 = (uint)DAT_21001739;
            iVar16 = (uint)DAT_21001739 * 0x40;
            uVar14 = DAT_21001739 + 1 & 1;
            uVar11 = *(undefined4 *)(&DAT_21001744 + iVar16);
            uVar13 = *(undefined4 *)(&DAT_21001748 + iVar16);
            uVar17 = *(undefined4 *)(&DAT_2100174c + iVar16);
            iVar1 = uVar14 * 0x40;
            *(undefined4 *)(&DAT_21001740 + iVar1) = *(undefined4 *)(&DAT_21001740 + iVar16);
            *(undefined4 *)(&DAT_21001744 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001748 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100174c + iVar1) = uVar17;
            uVar11 = *(undefined4 *)(&DAT_21001754 + iVar16);
            uVar13 = *(undefined4 *)(&DAT_21001758 + iVar16);
            uVar17 = *(undefined4 *)(&DAT_2100175c + iVar16);
            *(undefined4 *)(&DAT_21001750 + iVar1) = *(undefined4 *)(&DAT_21001750 + iVar16);
            *(undefined4 *)(&DAT_21001754 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001758 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100175c + iVar1) = uVar17;
            uVar11 = *(undefined4 *)(&DAT_21001764 + iVar16);
            uVar13 = *(undefined4 *)(&DAT_21001768 + iVar16);
            uVar17 = *(undefined4 *)(&DAT_2100176c + iVar16);
            *(undefined4 *)(&DAT_21001760 + iVar1) = *(undefined4 *)(&DAT_21001760 + iVar16);
            *(undefined4 *)(&DAT_21001764 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001768 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100176c + iVar1) = uVar17;
            uVar11 = *(undefined4 *)(&DAT_21001774 + iVar16);
            uVar13 = *(undefined4 *)(&DAT_21001778 + iVar16);
            uVar17 = *(undefined4 *)(&DAT_2100177c + iVar16);
            *(undefined4 *)(&DAT_21001770 + iVar1) = *(undefined4 *)(&DAT_21001770 + iVar16);
            *(undefined4 *)(&DAT_21001774 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001778 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100177c + iVar1) = uVar17;
            uVar2 = (&DAT_21001722)[uVar21 * 3];
            *(undefined2 *)((int)&DAT_21001720 + uVar14 * 3) =
                 *(undefined2 *)((int)&DAT_21001720 + uVar21 * 3);
            (&DAT_21001722)[uVar14 * 3] = uVar2;
          } while (DAT_21001729 != '\0');
          uVar21 = (uint)*(byte *)((int)&DAT_21001720 + uVar14 * 3 + 1);
          if (uVar21 != 0x20) {
            if (uVar15 == uVar21) {
              if (uVar21 != 0x20) {
                uVar19 = 0x20;
                iVar12 = uVar14 << 5;
                uVar7 = uVar21;
LAB_01024b82:
                *(undefined *)((int)&DAT_21001720 + uVar14 * 3 + 1) =
                     (&DAT_21001741)[(iVar12 + uVar21) * 2];
LAB_01024b22:
                if (uVar7 == (byte)(&DAT_21001722)[uVar14 * 3]) {
                  (&DAT_21001722)[uVar14 * 3] = (char)uVar19;
                }
              }
            }
            else {
              iVar12 = uVar14 * 0x20;
              uVar19 = uVar21;
              do {
                uVar7 = (uint)(byte)(&DAT_21001741)[(iVar12 + uVar19) * 2];
                if (uVar15 == uVar7) {
                  if (uVar7 != 0x20) {
                    if (uVar21 == uVar7) goto LAB_01024b82;
                    (&DAT_21001741)[(uVar19 + iVar12) * 2] = (&DAT_21001741)[(iVar12 + uVar7) * 2];
                    goto LAB_01024b22;
                  }
                  break;
                }
                uVar19 = uVar7;
              } while (uVar7 != 0x20);
            }
          }
          iVar12 = 0;
          bVar5 = (bool)isCurrentModePrivileged();
          if (bVar5) {
            iVar12 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          if (DAT_21001729 == '\0') {
            DAT_21001739 = (char)uVar14;
            DAT_21001729 = 0xff;
            if (iVar12 == 0) {
              enableIRQinterrupts();
            }
            return uVar21;
          }
        } while( true );
      }
      if (bVar9 - 4 < 3) {
        (&DAT_21001740)[(uVar14 * 0x20 + uVar15) * 2] = 1;
        goto LAB_01024992;
      }
      FUN_0102aa1e();
      bVar9 = (&DAT_21001740)[iVar12];
    } while( true );
  }
  FUN_01025edc(0x70,0xbf1,uVar15 >> 0x1d,0);
  uVar14 = (int)unaff_r6 >> 0x1f;
  puStack_88 = &DAT_210016f0;
  if (extraout_r3_01 != 0) {
    FUN_01025edc(0x70,0xc43,extraout_r2_01,extraout_r3_01);
    uStack_94 = extraout_r2_02;
    puVar18 = extraout_r3_02;
LAB_01024c28:
    puVar8 = (undefined2 *)FUN_01025edc(0x70,0xb76,uStack_94,puVar18);
    *puVar8 = (short)puVar8;
    *(char **)(puVar8 + 3) = unaff_r6;
    return 0;
  }
  unaff_r6 = &cStack_95;
  iVar12 = FUN_01024c40(extraout_r2_01);
  FUN_01024d24(uVar14,0,&uStack_94,aiStack_90,unaff_r6);
  puVar18 = (undefined1 *)(iVar12 - uStack_94);
  if ((undefined1 *)0xf423fff < puVar18) {
    uStack_94 = uStack_94 - iVar12;
    if (uStack_94 < 256000000) {
      puVar18 = (undefined1 *)-uStack_94;
    }
    else if (&DAT_1e847fff < puVar18) {
      puVar18 = puVar18 + 512000000;
    }
    else {
      if (uStack_94 < 512000000) goto LAB_01024c28;
      puVar18 = (undefined1 *)(-512000000 - uStack_94);
    }
  }
  return (extraout_r3_00 + -0xf) - (int)puVar18;
}


