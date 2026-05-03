/*
 * Function: FUN_0102373c
 * Entry:    0102373c
 * Prototype: undefined1 __stdcall FUN_0102373c(char * param_1)
 */


/* WARNING: Removing unreachable block (ram,0x0102383c) */
/* WARNING: Removing unreachable block (ram,0x010237e0) */
/* WARNING: Removing unreachable block (ram,0x010237ec) */
/* WARNING: Removing unreachable block (ram,0x01023780) */
/* WARNING: Removing unreachable block (ram,0x01023768) */
/* WARNING: Removing unreachable block (ram,0x010237b6) */
/* WARNING: Removing unreachable block (ram,0x0102380a) */
/* WARNING: Removing unreachable block (ram,0x010238ca) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0102373c(char *param_1)

{
  int iVar1;
  undefined1 uVar2;
  bool bVar3;
  longlong lVar4;
  byte bVar5;
  ushort uVar6;
  short sVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  longlong lVar16;
  char cStack_45;
  uint local_44;
  undefined8 local_40;
  int local_38;
  byte local_34;
  ushort local_32;
  
  if (*param_1 != '\0') {
    return 0;
  }
  if ((_DAT_e000ed04 & 0x1ff) != 0) {
    uVar14 = (_DAT_e000ed04 & 0x1ff) - 0x10;
    iVar8 = (int)(char)uVar14;
    local_40 = CONCAT44(local_40._4_4_,(uint)local_40);
    if (iVar8 < 0) {
      if ((byte)(&DAT_e000ed14)[uVar14 & 0xf] >> 5 == 0) {
        return 0;
      }
    }
    else if ((byte)(&DAT_e000e400)[iVar8] >> 5 == 0) {
      return 0;
    }
  }
  do {
    uVar14 = (uint)DAT_21001739;
    DAT_21001729 = '\0';
    iVar8 = uVar14 * 0x40;
    uVar13 = uVar14 + 1 & 1;
    uVar9 = *(undefined4 *)(&DAT_21001744 + iVar8);
    uVar10 = *(undefined4 *)(&DAT_21001748 + iVar8);
    uVar12 = *(undefined4 *)(&DAT_2100174c + iVar8);
    iVar1 = uVar13 * 0x40;
    *(undefined4 *)(&DAT_21001740 + iVar1) = *(undefined4 *)(&DAT_21001740 + iVar8);
    *(undefined4 *)(&DAT_21001744 + iVar1) = uVar9;
    *(undefined4 *)(&DAT_21001748 + iVar1) = uVar10;
    *(undefined4 *)(&DAT_2100174c + iVar1) = uVar12;
    uVar9 = *(undefined4 *)(&DAT_21001754 + iVar8);
    uVar10 = *(undefined4 *)(&DAT_21001758 + iVar8);
    uVar12 = *(undefined4 *)(&DAT_2100175c + iVar8);
    *(undefined4 *)(&DAT_21001750 + iVar1) = *(undefined4 *)(&DAT_21001750 + iVar8);
    *(undefined4 *)(&DAT_21001754 + iVar1) = uVar9;
    *(undefined4 *)(&DAT_21001758 + iVar1) = uVar10;
    *(undefined4 *)(&DAT_2100175c + iVar1) = uVar12;
    uVar9 = *(undefined4 *)(&DAT_21001764 + iVar8);
    uVar10 = *(undefined4 *)(&DAT_21001768 + iVar8);
    uVar12 = *(undefined4 *)(&DAT_2100176c + iVar8);
    *(undefined4 *)(&DAT_21001760 + iVar1) = *(undefined4 *)(&DAT_21001760 + iVar8);
    *(undefined4 *)(&DAT_21001764 + iVar1) = uVar9;
    *(undefined4 *)(&DAT_21001768 + iVar1) = uVar10;
    *(undefined4 *)(&DAT_2100176c + iVar1) = uVar12;
    uVar9 = *(undefined4 *)(&DAT_21001774 + iVar8);
    uVar10 = *(undefined4 *)(&DAT_21001778 + iVar8);
    uVar12 = *(undefined4 *)(&DAT_2100177c + iVar8);
    *(undefined4 *)(&DAT_21001770 + iVar1) = *(undefined4 *)(&DAT_21001770 + iVar8);
    *(undefined4 *)(&DAT_21001774 + iVar1) = uVar9;
    *(undefined4 *)(&DAT_21001778 + iVar1) = uVar10;
    *(undefined4 *)(&DAT_2100177c + iVar1) = uVar12;
    uVar2 = (&DAT_21001722)[uVar14 * 3];
    *(undefined2 *)((int)&DAT_21001720 + uVar13 * 3) =
         *(undefined2 *)((int)&DAT_21001720 + uVar14 * 3);
    (&DAT_21001722)[uVar13 * 3] = uVar2;
    lVar16 = FUN_01025884();
    uVar15 = (uint)((ulonglong)lVar16 >> 0x20);
    uVar14 = (uint)lVar16;
    FUN_01022dac(uVar14,uVar15,param_1,(uint *)&local_40,(byte)uVar13);
    if (DAT_2100173a == ' ') {
LAB_010238e6:
      bVar3 = false;
    }
    else {
      uVar11 = DAT_21001704 + (uint)CARRY4(DAT_21001708,DAT_21001700);
      if (uVar11 < local_40._4_4_ ||
          local_40._4_4_ - uVar11 < (uint)(DAT_21001708 + DAT_21001700 <= (uint)local_40))
      goto LAB_010238e6;
      bVar3 = true;
      local_40 = CONCAT44(uVar11,DAT_21001708 + DAT_21001700);
    }
    if ((((local_38 + (uint)local_40) - (uVar14 & 0xffffff) & 0xffffff) < 0x800001) &&
       (((uint)local_40 - (uVar14 & 0xffffff) & 0xffffff) < 0x800001)) {
      iVar8 = FUN_010225f0(256000000,(uint *)&local_40,uVar14,uVar15,(byte)uVar13);
      if ((bVar3) || (iVar8 != 0)) goto LAB_010238a6;
    }
    else {
      uVar15 = (uint)local_32;
      FUN_01024ccc(uVar15,(int *)&local_44,&cStack_45);
      uVar6 = FUN_01024e44();
      uVar14 = FUN_01024dd8((uint)uVar6);
      if (DAT_2100173a == ' ') {
        lVar4 = lVar16 + 0xb;
        if (uVar15 != 0) {
          bVar5 = FUN_010252d0();
          if (bVar5 == 0) {
            sVar7 = FUN_01024ed8();
            if (sVar7 == 0x356) {
              lVar4 = lVar16 + 0x27;
            }
            else if (sVar7 == 0x5f5) {
              lVar4 = lVar16 + 0x3d;
            }
            else if (sVar7 == 0x18c) {
              lVar4 = lVar16 + 0x18;
            }
          }
        }
        if (local_44 < uVar14) {
          lVar4 = lVar4 + (ulonglong)(uVar14 - local_44);
        }
      }
      else {
        lVar4 = CONCAT44(DAT_21001704 + (uint)(0xfffffff8 < DAT_21001700) +
                         (uint)CARRY4(DAT_21001700 + 7,DAT_21001708),DAT_21001700 + 7 + DAT_21001708
                        );
      }
      local_34 = 0x1f;
      local_40 = lVar4;
LAB_010238a6:
      lVar16 = FUN_01024c5c((uint)local_40,(uint)((ulonglong)local_40 >> 0x20));
      *(ulonglong *)(param_1 + 0x10) =
           lVar16 + (ulonglong)
                    CONCAT14(CARRY4((uint)local_32,(uint)local_34),
                             (uint)local_32 + (uint)local_34 + 1);
    }
    if (DAT_21001729 == '\0') {
      return 1;
    }
  } while( true );
}


