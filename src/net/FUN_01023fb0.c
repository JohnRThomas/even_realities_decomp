/*
 * Function: FUN_01023fb0
 * Entry:    01023fb0
 * Prototype: bool __stdcall FUN_01023fb0(uint param_1)
 */


/* WARNING: Removing unreachable block (ram,0x010241de) */
/* WARNING: Removing unreachable block (ram,0x0102428e) */
/* WARNING: Removing unreachable block (ram,0x0102417a) */
/* WARNING: Removing unreachable block (ram,0x01024140) */
/* WARNING: Removing unreachable block (ram,0x01024162) */
/* WARNING: Removing unreachable block (ram,0x01024166) */
/* WARNING: Removing unreachable block (ram,0x0102416a) */
/* WARNING: Removing unreachable block (ram,0x0102416e) */
/* WARNING: Removing unreachable block (ram,0x01023ff8) */
/* WARNING: Removing unreachable block (ram,0x01023fd0) */
/* WARNING: Removing unreachable block (ram,0x01024084) */
/* WARNING: Removing unreachable block (ram,0x0102421c) */
/* WARNING: Removing unreachable block (ram,0x01024110) */
/* WARNING: Removing unreachable block (ram,0x010241ba) */
/* WARNING: Removing unreachable block (ram,0x010240f6) */
/* WARNING: Removing unreachable block (ram,0x01024198) */
/* WARNING: Removing unreachable block (ram,0x01024038) */
/* WARNING: Removing unreachable block (ram,0x010240d4) */
/* WARNING: Removing unreachable block (ram,0x01024068) */

bool FUN_01023fb0(uint param_1)

{
  int iVar1;
  undefined1 uVar2;
  bool bVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar7;
  int extraout_r3;
  undefined4 extraout_r3_00;
  int iVar8;
  uint uVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  longlong lVar14;
  ulonglong uVar15;
  
  bVar10 = false;
  iVar11 = 1;
  do {
    do {
      if (iVar11 == 0) {
        enableIRQinterrupts();
      }
      DAT_21001729 = '\0';
      uVar12 = (uint)DAT_21001739;
      iVar8 = (uint)DAT_21001739 * 0x40;
      uVar9 = DAT_21001739 + 1 & 1;
      uVar5 = *(undefined4 *)(&DAT_21001744 + iVar8);
      uVar6 = *(undefined4 *)(&DAT_21001748 + iVar8);
      uVar7 = *(undefined4 *)(&DAT_2100174c + iVar8);
      iVar1 = uVar9 * 0x40;
      *(undefined4 *)(&DAT_21001740 + iVar1) = *(undefined4 *)(&DAT_21001740 + iVar8);
      *(undefined4 *)(&DAT_21001744 + iVar1) = uVar5;
      *(undefined4 *)(&DAT_21001748 + iVar1) = uVar6;
      *(undefined4 *)(&DAT_2100174c + iVar1) = uVar7;
      uVar5 = *(undefined4 *)(&DAT_21001754 + iVar8);
      uVar6 = *(undefined4 *)(&DAT_21001758 + iVar8);
      uVar7 = *(undefined4 *)(&DAT_2100175c + iVar8);
      *(undefined4 *)(&DAT_21001750 + iVar1) = *(undefined4 *)(&DAT_21001750 + iVar8);
      *(undefined4 *)(&DAT_21001754 + iVar1) = uVar5;
      *(undefined4 *)(&DAT_21001758 + iVar1) = uVar6;
      *(undefined4 *)(&DAT_2100175c + iVar1) = uVar7;
      uVar5 = *(undefined4 *)(&DAT_21001764 + iVar8);
      uVar6 = *(undefined4 *)(&DAT_21001768 + iVar8);
      uVar7 = *(undefined4 *)(&DAT_2100176c + iVar8);
      *(undefined4 *)(&DAT_21001760 + iVar1) = *(undefined4 *)(&DAT_21001760 + iVar8);
      *(undefined4 *)(&DAT_21001764 + iVar1) = uVar5;
      *(undefined4 *)(&DAT_21001768 + iVar1) = uVar6;
      *(undefined4 *)(&DAT_2100176c + iVar1) = uVar7;
      uVar5 = *(undefined4 *)(&DAT_21001774 + iVar8);
      uVar6 = *(undefined4 *)(&DAT_21001778 + iVar8);
      uVar7 = *(undefined4 *)(&DAT_2100177c + iVar8);
      *(undefined4 *)(&DAT_21001770 + iVar1) = *(undefined4 *)(&DAT_21001770 + iVar8);
      *(undefined4 *)(&DAT_21001774 + iVar1) = uVar5;
      *(undefined4 *)(&DAT_21001778 + iVar1) = uVar6;
      *(undefined4 *)(&DAT_2100177c + iVar1) = uVar7;
      uVar2 = (&DAT_21001722)[uVar12 * 3];
      *(undefined2 *)((int)&DAT_21001720 + uVar9 * 3) =
           *(undefined2 *)((int)&DAT_21001720 + uVar12 * 3);
      (&DAT_21001722)[uVar9 * 3] = uVar2;
    } while (DAT_21001729 != '\0');
    iVar8 = uVar9 * 0x20;
    if ((&DAT_21001740)[(param_1 + uVar9 * 0x20) * 2] != '\x03') goto LAB_010240e0;
    uVar13 = (uint)*(byte *)((int)&DAT_21001720 + uVar9 * 3);
    uVar12 = uVar13;
    if (param_1 == uVar13) {
      if (uVar13 == 0x20) goto LAB_010240e0;
LAB_01024232:
      *(undefined *)((int)&DAT_21001720 + uVar9 * 3) = (&DAT_21001741)[(uVar12 + iVar8) * 2];
    }
    else {
      do {
        uVar4 = uVar12;
        if (uVar4 == 0x20) goto LAB_010240e0;
        uVar12 = (uint)(byte)(&DAT_21001741)[(iVar8 + uVar4) * 2];
      } while (param_1 != uVar12);
      if (uVar12 == 0x20) goto LAB_010240e0;
      if (uVar13 == uVar12) goto LAB_01024232;
      (&DAT_21001741)[(uVar4 + iVar8) * 2] = (&DAT_21001741)[(uVar12 + iVar8) * 2];
    }
    (&DAT_21001740)[(iVar8 + param_1) * 2] = 1;
    iVar11 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      iVar11 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
  } while (DAT_21001729 != '\0');
  iVar8 = 0;
  if (((param_1 != uVar13) || (DAT_2100173a != ' ')) || (iVar8 = FUN_0102306c(2,uVar9), iVar8 != 0))
  {
    DAT_21001739 = ~DAT_21001739 & 1;
    DAT_21001729 = -1;
    if (iVar8 == 2) {
      lVar14 = FUN_01025884();
      uVar12 = (uint)((ulonglong)lVar14 >> 0x20);
      uVar9 = (uint)lVar14;
      if (uVar12 < DAT_21001704 || DAT_21001704 - uVar12 < (uint)(uVar9 <= DAT_21001700)) {
        uVar13 = DAT_21001700 - uVar9;
        uVar9 = (DAT_21001704 - uVar12) - (uint)(DAT_21001700 < uVar9);
        iVar8 = uVar9 - (0x7fffff >= uVar13);
        if (uVar9 == 0 && (0x7fffff < uVar13) <= uVar9) {
          FUN_01024c40(uVar13);
          bVar10 = true;
          if (DAT_21001bc0 != (code *)0x0) {
            (*DAT_21001bc0)();
          }
          goto LAB_010240e0;
        }
      }
      else {
        FUN_01025edc(0x70,0x816,DAT_21001704,DAT_21001700);
        uVar9 = extraout_r2;
        iVar8 = extraout_r3;
      }
      FUN_01025edc(0x70,0x817,uVar9,iVar8);
      uVar15 = FUN_010259ec(0,0,extraout_r2_00,extraout_r3_00);
      return *(int *)uVar15 != 0;
    }
    if (iVar8 == 1) {
      bVar10 = true;
      if (DAT_21001bc0 != (code *)0x0) {
        (*DAT_21001bc0)(0xffffffff);
      }
    }
    else {
      bVar10 = true;
    }
  }
LAB_010240e0:
  if (iVar11 == 0) {
    enableIRQinterrupts();
  }
  return bVar10;
}


