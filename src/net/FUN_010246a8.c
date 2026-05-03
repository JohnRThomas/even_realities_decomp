/*
 * Function: FUN_010246a8
 * Entry:    010246a8
 * Prototype: uint __stdcall FUN_010246a8(int param_1, uint param_2, undefined4 param_3)
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

uint FUN_010246a8(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  undefined2 *puVar9;
  uint extraout_r1;
  uint extraout_r1_00;
  byte bVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 extraout_r2;
  undefined4 uVar13;
  uint extraout_r2_00;
  uint extraout_r2_01;
  int iVar14;
  uint extraout_r3;
  int extraout_r3_00;
  undefined4 uVar15;
  int extraout_r3_01;
  undefined1 *puVar16;
  undefined1 *extraout_r3_02;
  uint uVar17;
  char *unaff_r6;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  char cStack_85;
  uint uStack_84;
  int aiStack_80 [2];
  undefined4 *puStack_78;
  char cStack_2d;
  int local_2c [2];
  
  iVar12 = DAT_21001708;
  uVar8 = DAT_21001700;
  if (DAT_2100173a != 0x20) {
    uVar17 = (uint)DAT_2100173a;
    uVar19 = (uint)*(byte *)((int)&DAT_21001720 + (uint)DAT_21001739 * 3);
    FUN_01024ccc(DAT_210016f0 + param_1,local_2c,&cStack_2d);
    if (param_1 - 0x76U < 0xf423f8b) {
      iVar14 = uVar17 * 0x20;
      uVar7 = (local_2c[0] + *(int *)(&DAT_210017c8 + iVar14) + *(int *)(&DAT_210017d0 + iVar14)) -
              DAT_21001700;
      if ((uVar7 & 0xffffff) < 0x800001) {
        uVar21 = (uint)DAT_21001739;
        DAT_21001710 = (byte)param_2;
        DAT_21001708 = uVar7;
        if (uVar19 == 0x20) {
          FUN_01025a4c(5,&DAT_210016f0 + uVar17 * 8,(uint)DAT_21001739);
          uVar8 = (uint)DAT_21001739;
LAB_01024778:
          DAT_210016fc = 0xffffffff;
          DAT_210016f8 = 0xffffffff;
          uVar17 = 0x20;
          bVar10 = *(byte *)((int)&DAT_21001720 + uVar8 * 3);
        }
        else {
          uVar17 = 0x20;
          do {
            uVar20 = uVar19;
            uVar19 = DAT_21001700;
            iVar14 = uVar20 * 0x20;
            uVar18 = DAT_21001704 + (uint)CARRY4(DAT_21001708,DAT_21001700);
            uVar7 = *(uint *)(&DAT_210017c8 + iVar14);
            if (uVar18 < *(uint *)(&DAT_210017cc + iVar14) ||
                *(uint *)(&DAT_210017cc + iVar14) - uVar18 <
                (uint)(DAT_21001708 + DAT_21001700 <= uVar7)) {
              if ((*(short *)(&DAT_210017d6 + iVar14) != 0) && (DAT_2100170e == 0)) {
                sVar6 = FUN_01024ed8();
                if (sVar6 == 0x356) {
                  iVar14 = 0x1d;
                }
                else if (sVar6 == 0x5f5) {
                  iVar14 = 0x33;
                }
                else if (sVar6 == 0x18c) {
                  iVar14 = 0xe;
                }
                else {
                  iVar14 = 1;
                }
                uVar7 = uVar7 - uVar19;
                param_2 = extraout_r1;
                if ((int)uVar7 < iVar14) {
                  param_2 = (uint)DAT_21001710;
                  goto LAB_010247fa;
                }
              }
              FUN_01025a4c(5,param_2,uVar7);
              uVar8 = (uint)DAT_21001739;
              if (uVar17 == 0x20) goto LAB_01024778;
              goto LAB_0102485c;
            }
LAB_010247fa:
            if ((byte)(&DAT_210017d8)[uVar20 * 0x20] <= param_2) {
              DAT_21001708 = (iVar12 + uVar8) - DAT_21001700;
              return 2;
            }
            uVar19 = (uint)(byte)(&DAT_21001741)[(uVar20 + uVar21 * 0x20) * 2];
            uVar17 = uVar20;
          } while ((byte)(&DAT_21001741)[(uVar20 + uVar21 * 0x20) * 2] != 0x20);
          FUN_01025a4c(5,param_2,uVar7);
          uVar8 = (uint)DAT_21001739;
LAB_0102485c:
          DAT_210016fc = 0xffffffff;
          DAT_210016f8 = 0xffffffff;
          bVar3 = *(byte *)((int)&DAT_21001720 + uVar8 * 3);
          iVar12 = uVar8 * 0x20;
          *(undefined *)((int)&DAT_21001720 + uVar8 * 3) =
               (&DAT_21001741)[(uVar17 + uVar8 * 0x20) * 2];
          bVar10 = bVar3;
          do {
            bVar4 = bVar10;
            uVar19 = (uint)bVar4;
            iVar14 = (iVar12 + uVar19) * 2;
            bVar10 = (&DAT_21001741)[iVar14];
            (&DAT_21001740)[iVar14] = 5;
          } while (uVar17 != uVar19);
          if ((&DAT_21001722)[uVar8 * 3] == 0x20) {
            *(byte *)((int)&DAT_21001720 + uVar8 * 3 + 1) = bVar3;
          }
          else {
            (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[uVar8 * 3] + iVar12) * 2] = bVar3;
          }
          (&DAT_21001741)[(uVar19 + iVar12) * 2] = 0x20;
          (&DAT_21001722)[uVar8 * 3] = bVar4;
        }
        uVar19 = (uint)DAT_21001739;
        (&DAT_21001741)[((uint)DAT_2100173a + uVar19 * 0x20) * 2] = bVar10;
        DAT_210016f0 = DAT_210016f0 + param_1;
        uVar11 = 0xff;
        DAT_21001729 = 0xff;
        uVar8 = 0;
        if ((DAT_21001727 != '\0') && (uVar8 = (uint)DAT_21001711, uVar8 == 1)) {
          iVar12 = DAT_21001704 + -1 + (uint)(DAT_21001700 != 0);
          FUN_0102561c((DAT_21001700 - 1) + DAT_21001708,
                       iVar12 + (uint)CARRY4(DAT_21001700 - 1,DAT_21001708),iVar12);
          uVar19 = extraout_r1_00;
          uVar11 = extraout_r2;
          uVar8 = extraout_r3;
        }
        if (uVar17 == 0x20) {
          return 0;
        }
        FUN_0102603c((uint)DAT_21001bc9,uVar19,uVar11,uVar8);
        return 0;
      }
    }
    return 1;
  }
  FUN_01025edc(0x70,0xbb3,param_3,0x20);
  uVar8 = (int)unaff_r6 >> 0x1b;
  if ((&DAT_21001740)[(uVar8 + (uint)DAT_21001739 * 0x20) * 2] != '\0') {
    uVar19 = (uint)DAT_21001739;
    iVar12 = (uVar19 * 0x20 + uVar8) * 2;
    bVar10 = (&DAT_21001740)[iVar12];
    do {
      if (bVar10 == 1) {
LAB_01024992:
        iVar12 = 1;
        do {
          do {
            if (iVar12 == 0) {
              enableIRQinterrupts();
            }
            DAT_21001729 = '\0';
            uVar17 = (uint)DAT_21001739;
            iVar14 = (uint)DAT_21001739 * 0x40;
            uVar19 = DAT_21001739 + 1 & 1;
            uVar11 = *(undefined4 *)(&DAT_21001744 + iVar14);
            uVar13 = *(undefined4 *)(&DAT_21001748 + iVar14);
            uVar15 = *(undefined4 *)(&DAT_2100174c + iVar14);
            iVar1 = uVar19 * 0x40;
            *(undefined4 *)(&DAT_21001740 + iVar1) = *(undefined4 *)(&DAT_21001740 + iVar14);
            *(undefined4 *)(&DAT_21001744 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001748 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100174c + iVar1) = uVar15;
            uVar11 = *(undefined4 *)(&DAT_21001754 + iVar14);
            uVar13 = *(undefined4 *)(&DAT_21001758 + iVar14);
            uVar15 = *(undefined4 *)(&DAT_2100175c + iVar14);
            *(undefined4 *)(&DAT_21001750 + iVar1) = *(undefined4 *)(&DAT_21001750 + iVar14);
            *(undefined4 *)(&DAT_21001754 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001758 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100175c + iVar1) = uVar15;
            uVar11 = *(undefined4 *)(&DAT_21001764 + iVar14);
            uVar13 = *(undefined4 *)(&DAT_21001768 + iVar14);
            uVar15 = *(undefined4 *)(&DAT_2100176c + iVar14);
            *(undefined4 *)(&DAT_21001760 + iVar1) = *(undefined4 *)(&DAT_21001760 + iVar14);
            *(undefined4 *)(&DAT_21001764 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001768 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100176c + iVar1) = uVar15;
            uVar11 = *(undefined4 *)(&DAT_21001774 + iVar14);
            uVar13 = *(undefined4 *)(&DAT_21001778 + iVar14);
            uVar15 = *(undefined4 *)(&DAT_2100177c + iVar14);
            *(undefined4 *)(&DAT_21001770 + iVar1) = *(undefined4 *)(&DAT_21001770 + iVar14);
            *(undefined4 *)(&DAT_21001774 + iVar1) = uVar11;
            *(undefined4 *)(&DAT_21001778 + iVar1) = uVar13;
            *(undefined4 *)(&DAT_2100177c + iVar1) = uVar15;
            uVar2 = (&DAT_21001722)[uVar17 * 3];
            *(undefined2 *)((int)&DAT_21001720 + uVar19 * 3) =
                 *(undefined2 *)((int)&DAT_21001720 + uVar17 * 3);
            (&DAT_21001722)[uVar19 * 3] = uVar2;
          } while (DAT_21001729 != '\0');
          uVar17 = (uint)*(byte *)((int)&DAT_21001720 + uVar19 * 3 + 1);
          if (uVar17 != 0x20) {
            if (uVar8 == uVar17) {
              if (uVar17 != 0x20) {
                uVar7 = 0x20;
                iVar12 = uVar19 << 5;
                uVar21 = uVar17;
LAB_01024b82:
                *(undefined *)((int)&DAT_21001720 + uVar19 * 3 + 1) =
                     (&DAT_21001741)[(iVar12 + uVar17) * 2];
LAB_01024b22:
                if (uVar21 == (byte)(&DAT_21001722)[uVar19 * 3]) {
                  (&DAT_21001722)[uVar19 * 3] = (char)uVar7;
                }
              }
            }
            else {
              iVar12 = uVar19 * 0x20;
              uVar7 = uVar17;
              do {
                uVar21 = (uint)(byte)(&DAT_21001741)[(iVar12 + uVar7) * 2];
                if (uVar8 == uVar21) {
                  if (uVar21 != 0x20) {
                    if (uVar17 == uVar21) goto LAB_01024b82;
                    (&DAT_21001741)[(uVar7 + iVar12) * 2] = (&DAT_21001741)[(iVar12 + uVar21) * 2];
                    goto LAB_01024b22;
                  }
                  break;
                }
                uVar7 = uVar21;
              } while (uVar21 != 0x20);
            }
          }
          iVar12 = 0;
          bVar5 = (bool)isCurrentModePrivileged();
          if (bVar5) {
            iVar12 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          if (DAT_21001729 == '\0') {
            DAT_21001739 = (char)uVar19;
            DAT_21001729 = 0xff;
            if (iVar12 == 0) {
              enableIRQinterrupts();
            }
            return uVar17;
          }
        } while( true );
      }
      if (bVar10 - 4 < 3) {
        (&DAT_21001740)[(uVar19 * 0x20 + uVar8) * 2] = 1;
        goto LAB_01024992;
      }
      FUN_0102aa1e();
      bVar10 = (&DAT_21001740)[iVar12];
    } while( true );
  }
  FUN_01025edc(0x70,0xbf1,uVar8 >> 0x1d,0);
  uVar8 = (int)unaff_r6 >> 0x1f;
  puStack_78 = &DAT_210016f0;
  if (extraout_r3_01 != 0) {
    FUN_01025edc(0x70,0xc43,extraout_r2_00,extraout_r3_01);
    uStack_84 = extraout_r2_01;
    puVar16 = extraout_r3_02;
LAB_01024c28:
    puVar9 = (undefined2 *)FUN_01025edc(0x70,0xb76,uStack_84,puVar16);
    *puVar9 = (short)puVar9;
    *(char **)(puVar9 + 3) = unaff_r6;
    return 0;
  }
  unaff_r6 = &cStack_85;
  iVar12 = FUN_01024c40(extraout_r2_00);
  FUN_01024d24(uVar8,0,&uStack_84,aiStack_80,unaff_r6);
  puVar16 = (undefined1 *)(iVar12 - uStack_84);
  if ((undefined1 *)0xf423fff < puVar16) {
    uStack_84 = uStack_84 - iVar12;
    if (uStack_84 < 256000000) {
      puVar16 = (undefined1 *)-uStack_84;
    }
    else if (&DAT_1e847fff < puVar16) {
      puVar16 = puVar16 + 512000000;
    }
    else {
      if (uStack_84 < 512000000) goto LAB_01024c28;
      puVar16 = (undefined1 *)(-512000000 - uStack_84);
    }
  }
  return (extraout_r3_00 + -0xf) - (int)puVar16;
}


