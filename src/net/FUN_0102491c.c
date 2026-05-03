/*
 * Function: FUN_0102491c
 * Entry:    0102491c
 * Prototype: ulonglong __stdcall FUN_0102491c(uint param_1, undefined4 param_2, undefined4 param_3, int param_4)
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

ulonglong FUN_0102491c(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined1 uVar2;
  byte bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  uint extraout_r2;
  uint extraout_r2_00;
  undefined4 uVar9;
  int iVar10;
  int extraout_r3;
  undefined1 *puVar11;
  undefined1 *extraout_r3_00;
  char *unaff_r6;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  char cStack_45;
  uint uStack_44;
  int aiStack_40 [2];
  undefined4 *puStack_38;
  
  if ((&DAT_21001740)[(param_1 + (uint)DAT_21001739 * 0x20) * 2] != '\0') {
    uVar12 = (uint)DAT_21001739;
    iVar10 = (uVar12 * 0x20 + param_1) * 2;
    bVar3 = (&DAT_21001740)[iVar10];
    do {
      if (bVar3 == 1) {
LAB_01024992:
        iVar10 = 1;
        do {
          do {
            if (iVar10 == 0) {
              enableIRQinterrupts();
            }
            DAT_21001729 = '\0';
            uVar13 = (uint)DAT_21001739;
            iVar6 = (uint)DAT_21001739 * 0x40;
            uVar12 = DAT_21001739 + 1 & 1;
            uVar5 = *(undefined4 *)(&DAT_21001744 + iVar6);
            uVar8 = *(undefined4 *)(&DAT_21001748 + iVar6);
            uVar9 = *(undefined4 *)(&DAT_2100174c + iVar6);
            iVar1 = uVar12 * 0x40;
            *(undefined4 *)(&DAT_21001740 + iVar1) = *(undefined4 *)(&DAT_21001740 + iVar6);
            *(undefined4 *)(&DAT_21001744 + iVar1) = uVar5;
            *(undefined4 *)(&DAT_21001748 + iVar1) = uVar8;
            *(undefined4 *)(&DAT_2100174c + iVar1) = uVar9;
            uVar5 = *(undefined4 *)(&DAT_21001754 + iVar6);
            uVar8 = *(undefined4 *)(&DAT_21001758 + iVar6);
            uVar9 = *(undefined4 *)(&DAT_2100175c + iVar6);
            *(undefined4 *)(&DAT_21001750 + iVar1) = *(undefined4 *)(&DAT_21001750 + iVar6);
            *(undefined4 *)(&DAT_21001754 + iVar1) = uVar5;
            *(undefined4 *)(&DAT_21001758 + iVar1) = uVar8;
            *(undefined4 *)(&DAT_2100175c + iVar1) = uVar9;
            uVar5 = *(undefined4 *)(&DAT_21001764 + iVar6);
            uVar8 = *(undefined4 *)(&DAT_21001768 + iVar6);
            uVar9 = *(undefined4 *)(&DAT_2100176c + iVar6);
            *(undefined4 *)(&DAT_21001760 + iVar1) = *(undefined4 *)(&DAT_21001760 + iVar6);
            *(undefined4 *)(&DAT_21001764 + iVar1) = uVar5;
            *(undefined4 *)(&DAT_21001768 + iVar1) = uVar8;
            *(undefined4 *)(&DAT_2100176c + iVar1) = uVar9;
            uVar5 = *(undefined4 *)(&DAT_21001774 + iVar6);
            uVar8 = *(undefined4 *)(&DAT_21001778 + iVar6);
            uVar9 = *(undefined4 *)(&DAT_2100177c + iVar6);
            *(undefined4 *)(&DAT_21001770 + iVar1) = *(undefined4 *)(&DAT_21001770 + iVar6);
            *(undefined4 *)(&DAT_21001774 + iVar1) = uVar5;
            *(undefined4 *)(&DAT_21001778 + iVar1) = uVar8;
            *(undefined4 *)(&DAT_2100177c + iVar1) = uVar9;
            uVar2 = (&DAT_21001722)[uVar13 * 3];
            *(undefined2 *)((int)&DAT_21001720 + uVar12 * 3) =
                 *(undefined2 *)((int)&DAT_21001720 + uVar13 * 3);
            (&DAT_21001722)[uVar12 * 3] = uVar2;
          } while (DAT_21001729 != '\0');
          uVar13 = (uint)*(byte *)((int)&DAT_21001720 + uVar12 * 3 + 1);
          iVar6 = 0;
          if (uVar13 != 0x20) {
            if (param_1 == uVar13) {
              if (uVar13 != 0x20) {
                uVar15 = 0x20;
                iVar6 = uVar12 << 5;
                uVar14 = uVar13;
LAB_01024b82:
                iVar10 = (iVar6 + uVar13) * 2;
                *(undefined *)((int)&DAT_21001720 + uVar12 * 3 + 1) = (&DAT_21001741)[iVar10];
LAB_01024b22:
                iVar6 = (int)&DAT_210016f0 + iVar10;
                if (uVar14 == (byte)(&DAT_21001722)[uVar12 * 3]) {
                  (&DAT_21001722)[uVar12 * 3] = (char)uVar15;
                }
              }
            }
            else {
              iVar6 = uVar12 * 0x20;
              uVar15 = uVar13;
              do {
                uVar14 = (uint)(byte)(&DAT_21001741)[(iVar6 + uVar15) * 2];
                if (param_1 == uVar14) {
                  if (uVar14 != 0x20) {
                    if (uVar13 == uVar14) goto LAB_01024b82;
                    iVar10 = (iVar6 + uVar14) * 2;
                    (&DAT_21001741)[(uVar15 + iVar6) * 2] = (&DAT_21001741)[iVar10];
                    goto LAB_01024b22;
                  }
                  break;
                }
                uVar15 = uVar14;
              } while (uVar14 != 0x20);
            }
          }
          iVar10 = 0;
          bVar4 = (bool)isCurrentModePrivileged();
          if (bVar4) {
            iVar10 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          if (DAT_21001729 == '\0') {
            DAT_21001739 = (char)uVar12;
            DAT_21001729 = 0xff;
            if (iVar10 == 0) {
              enableIRQinterrupts();
            }
            return CONCAT44(iVar6,uVar13);
          }
        } while( true );
      }
      if (bVar3 - 4 < 3) {
        (&DAT_21001740)[(uVar12 * 0x20 + param_1) * 2] = 1;
        goto LAB_01024992;
      }
      FUN_0102aa1e();
      bVar3 = (&DAT_21001740)[iVar10];
    } while( true );
  }
  FUN_01025edc(0x70,0xbf1,param_3,0);
  uVar12 = (int)unaff_r6 >> 0x1f;
  puStack_38 = &DAT_210016f0;
  if (extraout_r3 != 0) {
    FUN_01025edc(0x70,0xc43,extraout_r2,extraout_r3);
    uStack_44 = extraout_r2_00;
    puVar11 = extraout_r3_00;
LAB_01024c28:
    uVar16 = FUN_01025edc(0x70,0xb76,uStack_44,puVar11);
    *(undefined2 *)uVar16 = (short)uVar16;
    *(char **)((undefined2 *)uVar16 + 3) = unaff_r6;
    return uVar16 & 0xffffffff00000000;
  }
  unaff_r6 = &cStack_45;
  iVar10 = FUN_01024c40(extraout_r2);
  FUN_01024d24(uVar12,0,&uStack_44,aiStack_40,unaff_r6);
  puVar7 = (undefined1 *)0xf424000;
  puVar11 = (undefined1 *)(iVar10 - uStack_44);
  if ((undefined1 *)0xf423fff < puVar11) {
    uStack_44 = uStack_44 - iVar10;
    if (uStack_44 < 256000000) {
      puVar11 = (undefined1 *)-uStack_44;
    }
    else {
      puVar7 = &DAT_1e847fff;
      if (&DAT_1e847fff < puVar11) {
        puVar11 = puVar11 + 512000000;
      }
      else {
        if (uStack_44 < 512000000) goto LAB_01024c28;
        puVar11 = (undefined1 *)(-512000000 - uStack_44);
      }
    }
  }
  return CONCAT44(puVar7,(param_4 + -0xf) - (int)puVar11);
}


