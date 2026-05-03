/*
 * Function: FUN_01023284
 * Entry:    01023284
 * Prototype: undefined * __stdcall FUN_01023284(void)
 */


undefined * FUN_01023284(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  ushort uVar7;
  short sVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  int iVar12;
  undefined4 extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 uVar13;
  uint uVar14;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  uint extraout_r2_03;
  uint uVar15;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 *puVar16;
  int unaff_r7;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  longlong lVar21;
  longlong lVar22;
  undefined8 uVar23;
  char cStack_2d;
  int aiStack_2c [2];
  
  puVar16 = &DAT_210016f0;
  lVar21 = FUN_01025884();
  uVar15 = (uint)((ulonglong)lVar21 >> 0x20);
  FUN_01025b44();
  if (DAT_210016fc != -1 || DAT_210016f8 != -1) {
    DAT_210016f8 = -1;
    DAT_210016fc = -1;
  }
  if ((DAT_2100171a == '\0') &&
     (uVar14 = FUN_01024e78(DAT_21001708,0x230),
     uVar20 = DAT_21001704 + CARRY4(DAT_21001708,DAT_21001700) +
              (uint)CARRY4(DAT_21001708 + DAT_21001700,uVar14),
     uVar20 < uVar15 ||
     uVar15 - uVar20 < (uint)(DAT_21001708 + DAT_21001700 + uVar14 <= (uint)lVar21))) {
    puVar16 = &DAT_210016f0 + (uint)DAT_2100173a * 8;
    (*(code *)(&DAT_210017c0)[(uint)DAT_2100173a * 8])((&DAT_210017c4)[(uint)DAT_2100173a * 8],8);
    FUN_01025edc(0x70,0x3cb,extraout_r2_02,extraout_r3);
LAB_01023548:
    puVar11 = (undefined *)FUN_01024e0c();
    *(undefined2 *)(puVar16 + 10) = 0;
LAB_010233da:
    if (unaff_r7 == 2) {
      puVar11 = (undefined *)FUN_01024c40(puVar16[4] - (uint)lVar21);
      if ((code *)puVar16[0x134] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x010233f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar11 = (undefined *)(*(code *)puVar16[0x134])();
        return puVar11;
      }
    }
    else if ((code *)puVar16[0x134] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0102355c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar11 = (undefined *)(*(code *)puVar16[0x134])(0xffffffff);
      return puVar11;
    }
    return puVar11;
  }
  if ((DAT_21001711 == '\0') || (DAT_21001727 == 0)) {
    FUN_0102546c((uint)(lVar21 + 3),(int)((ulonglong)(lVar21 + 3) >> 0x20));
    uVar13 = extraout_r2;
  }
  else {
    FUN_010256f0();
    uVar13 = extraout_r2_01;
  }
  bVar4 = DAT_2100173a;
  bVar6 = DAT_21001728;
  uVar15 = (uint)DAT_21001728;
  if (uVar15 == 0) {
    DAT_21001728 = 1;
    uVar14 = (uint)DAT_2100173a;
    uVar13 = 0;
    if (uVar14 != 0x20) {
      DAT_21001726 = bVar6;
      uVar20 = (uint)DAT_2100173a;
      DAT_2100173a = 0x20;
      DAT_2100173b = ' ';
      DAT_21001727 = bVar6;
      DAT_210016f0 = uVar15;
      DAT_21001718 = FUN_01024e50();
      uVar14 = (uint)DAT_21001739;
      iVar19 = (uint)DAT_21001739 * 2;
      uVar15 = (uint)*(byte *)((int)&DAT_21001720 + (uint)DAT_21001739 * 3);
      if (uVar15 != 0x20) {
        iVar17 = uVar15 * 0x20;
        if ((&DAT_210017da)[uVar15 * 0x20] == '\x01') {
          uVar3 = *(ushort *)(&DAT_210017d6 + uVar15 * 0x20);
          FUN_01024ccc((uint)uVar3,aiStack_2c,&cStack_2d);
          uVar7 = FUN_01024e44();
          FUN_01024dd8((uint)uVar7);
          if (DAT_2100173a == 0x20) {
            lVar22 = lVar21 + 0xb;
            if ((uVar3 != 0) && (bVar6 = FUN_010252d0(), bVar6 == 0)) {
              sVar8 = FUN_01024ed8();
              if (sVar8 == 0x356) {
                lVar22 = lVar21 + 0x27;
              }
              else if (sVar8 == 0x5f5) {
                lVar22 = lVar21 + 0x3d;
              }
              else if (sVar8 == 0x18c) {
                lVar22 = lVar21 + 0x18;
              }
            }
          }
          else {
            lVar22 = CONCAT44(DAT_21001704 + (0xfffffff8 < DAT_21001700) +
                              (uint)CARRY4(DAT_21001700 + 7,DAT_21001708),
                              DAT_21001700 + 7 + DAT_21001708);
          }
          uVar15 = (uint)((ulonglong)lVar22 >> 0x20);
          if (uVar15 < *(uint *)(&DAT_210017cc + iVar17) ||
              *(uint *)(&DAT_210017cc + iVar17) - uVar15 <
              (uint)((uint)lVar22 <= *(uint *)(&DAT_210017c8 + iVar17))) {
            *(longlong *)(&DAT_210017c8 + iVar17) = lVar22;
          }
          uVar15 = (uint)*(byte *)((int)&DAT_21001720 + iVar19 + uVar14);
        }
      }
      iVar18 = iVar19 + uVar14;
      iVar17 = uVar14 * 0x20;
      if (uVar15 == 0x20) goto LAB_01023366;
LAB_01023354:
      uVar9 = FUN_01022f74(uVar14);
      if (uVar9 == uVar15) goto LAB_01023366;
LAB_0102335e:
      do {
        uVar15 = (uint)*(byte *)((int)&DAT_21001720 + iVar18);
        if (uVar15 != 0x20) goto LAB_01023354;
LAB_01023366:
        lVar22 = FUN_01025884();
        iVar12 = (int)((ulonglong)lVar22 >> 0x20);
        if ((DAT_2100173b == ' ') ||
           (uVar9 = (uint)((ulonglong)(lVar22 + 2) >> 0x20),
           uVar9 < DAT_21001704 || DAT_21001704 - uVar9 < (uint)((uint)(lVar22 + 2) <= DAT_21001700)
           )) {
          if (uVar15 == 0x20) {
            if (DAT_21001734 != -1 || DAT_21001730 != -1) {
              FUN_01024f78();
              DAT_21001730 = -1;
              DAT_21001734 = -1;
              iVar12 = extraout_r1_00;
            }
            iVar18 = DAT_21001730;
            if (DAT_21001738 != '\0') {
              FUN_01025a4c(5,iVar12,DAT_21001730);
              DAT_21001738 = '\0';
              iVar12 = extraout_r1_01;
              iVar18 = extraout_r2_00;
            }
            unaff_r7 = 1;
            FUN_01025a4c(4,iVar12,iVar18);
            uVar23 = FUN_01025b44();
            DAT_2100173b = 0x20;
            *DAT_21001bc4 = 0;
            iVar18 = (iVar17 + uVar20) * 2;
            cVar1 = (&DAT_21001740)[iVar18];
          }
          else {
            puVar10 = FUN_010226e0((undefined1 *)lVar22,iVar12,1,uVar15);
            uVar23 = CONCAT44(extraout_r1,puVar10);
            if (puVar10 == (undefined1 *)0x0) {
              bVar6 = *(byte *)((int)&DAT_21001720 + iVar18);
              *(undefined *)((int)&DAT_21001720 + iVar18) = (&DAT_21001741)[(iVar17 + uVar15) * 2];
              bVar5 = bVar6;
              do {
                bVar2 = bVar5;
                uVar9 = (uint)bVar2;
                iVar12 = (iVar17 + uVar9) * 2;
                (&DAT_21001740)[iVar12] = 4;
                bVar5 = (&DAT_21001741)[iVar12];
              } while (uVar9 != uVar15);
              if ((&DAT_21001722)[iVar18] == 0x20) {
                *(byte *)((int)&DAT_21001720 + iVar18 + 1) = bVar6;
              }
              else {
                (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[iVar18] + iVar17) * 2] = bVar6;
              }
              (&DAT_21001722)[iVar18] = bVar2;
              (&DAT_21001741)[(uVar9 + iVar17) * 2] = 0x20;
              goto LAB_0102335e;
            }
            unaff_r7 = 2;
            DAT_2100173b = (char)uVar15;
            iVar18 = (iVar17 + uVar20) * 2;
            cVar1 = (&DAT_21001740)[iVar18];
          }
          uVar15 = (uint)((ulonglong)uVar23 >> 0x20);
          puVar11 = (undefined *)uVar23;
          if (cVar1 == '\x02') {
            (&DAT_21001740)[iVar18] = 6;
            uVar15 = (uint)(byte)(&DAT_21001722)[iVar19 + uVar14];
            if (uVar15 == 0x20) {
              *(byte *)((int)&DAT_21001720 + iVar19 + uVar14 + 1) = bVar4;
            }
            else {
              (&DAT_21001741)[((uint)(byte)(&DAT_21001722)[iVar19 + uVar14] + iVar17) * 2] = bVar4;
            }
            (&DAT_21001722)[iVar19 + uVar14] = bVar4;
            (&DAT_21001741)[(iVar17 + uVar20) * 2] = 0x20;
          }
          DAT_21001729 = 0xff;
          uVar14 = (uint)*(byte *)((int)&DAT_21001720 + iVar19 + uVar14 + 1);
          if (uVar14 != 0x20) {
            puVar11 = (undefined *)FUN_0102603c((uint)DAT_21001bc9,uVar15,0xff,uVar14);
          }
          if (DAT_21001718 == '\0') goto LAB_010233da;
          goto LAB_01023548;
        }
      } while( true );
    }
  }
  else {
    FUN_01025edc(0x70,0x3e4,uVar13,uVar15);
    uVar14 = extraout_r2_03;
    uVar13 = extraout_r3_00;
  }
  uVar23 = FUN_01025edc(0x70,999,uVar14,uVar13);
  FUN_010250d0();
  uVar14 = (uint)DAT_21001739;
  uVar15 = 0;
  do {
    if ((&DAT_21001740)[uVar15 * 2 + (uint)DAT_21001739 * 0x40] == '\0') {
      *(undefined8 *)(&DAT_210017c0 + uVar15 * 8) = uVar23;
      (&DAT_21001740)[(uVar15 + uVar14 * 0x20) * 2] = 1;
      return (undefined *)(uVar15 & 0xff);
    }
    uVar15 = uVar15 + 1;
  } while (uVar15 != 0x20);
  return &Reserved2;
}


