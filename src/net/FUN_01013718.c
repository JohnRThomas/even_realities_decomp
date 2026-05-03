/*
 * Function: FUN_01013718
 * Entry:    01013718
 * Prototype: undefined * __stdcall FUN_01013718(undefined4 * param_1, uint param_2, int param_3, int param_4, undefined2 * param_5)
 */


/* WARNING: Removing unreachable block (ram,0x0101413c) */

undefined *
FUN_01013718(undefined4 *param_1,uint param_2,int param_3,int param_4,undefined2 *param_5)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  longlong lVar5;
  short sVar6;
  char cVar7;
  bool bVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  ushort *puVar13;
  int iVar14;
  undefined *puVar15;
  undefined4 *puVar16;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar17;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint extraout_r2_03;
  uint extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  uint extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r3;
  uint uVar18;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  int iVar19;
  int iVar20;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  uint extraout_r3_04;
  uint extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 extraout_r3_09;
  undefined4 extraout_r3_10;
  uint uVar21;
  undefined *puVar22;
  int iVar23;
  int iVar24;
  undefined4 uVar25;
  int iVar26;
  undefined4 uVar27;
  int iVar28;
  undefined8 uVar29;
  uint local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int iStack_2c;
  
  local_3c = (uint)*(byte *)((int)param_1 + 0x6f);
  local_38 = 0;
  uVar9 = FUN_01024ecc();
  uVar29 = CONCAT44(extraout_r1,(uint)uVar9);
  uVar17 = (uint)*(byte *)(param_1 + 0xb6);
  uVar25 = extraout_r3;
  if (uVar17 < 0xc) {
    cVar1 = *(char *)((int)param_1 + 0xc6);
    uVar21 = (uint)uVar9 + (uint)*(ushort *)(&DAT_0103c1b8 + uVar17 * 2) & 0xffff;
    if ((((param_3 == 0) && (*(char *)(param_1 + 199) == '\x03')) && (cVar1 == '\x0e')) &&
       (*(ushort *)(param_1 + 0xef) == param_2)) {
      param_1[0xc6] =
           (uint)*(ushort *)((int)param_1 + 0x362) + (uint)*(ushort *)((int)param_1 + 0x2f6);
      param_1[0xc4] = param_1[0xc9];
      param_1[0xc5] = param_1[5];
      FUN_0101698c(param_1);
      param_1[9] = param_1[0xf0];
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)((int)param_1 + 0x3be);
      param_1[5] = param_1[0xf1];
      param_1[7] = param_1[0xf2];
      *(undefined1 *)(param_1 + 199) = 2;
    }
    sVar6 = (short)param_2;
    iVar28 = (int)(short)(sVar6 - *(short *)(param_1 + 0xd8));
    iVar26 = (int)(short)(sVar6 - *(short *)(param_1 + 0x2f));
    iVar14 = param_4;
    cVar7 = DAT_21000f54;
    if (iVar28 < 0) goto LAB_01013b12;
joined_r0x01013788:
    uVar17 = 0;
    iVar23 = 0;
    if (cVar7 != '\0') {
      bVar8 = FUN_01024fcc();
      iVar23 = 0;
      uVar17 = extraout_r2_00;
      if (bVar8) {
        uVar17 = (uint)*(ushort *)(param_1 + 0xc2);
        if (((uVar17 < 2) || (uVar17 = (uint)*(byte *)(param_1 + 199), uVar17 == 2)) ||
           (uVar17 = (uint)*(byte *)((int)param_1 + 0x332), uVar17 != 0)) {
          iVar23 = 0;
        }
        else {
          puVar15 = (undefined *)param_1[5];
          uVar29 = CONCAT44(extraout_r1_00,puVar15);
          if (puVar15 < &DAT_00001d4c) {
            iVar23 = 0;
          }
          else {
            uVar17 = (uint)*(byte *)(param_1 + 0xb6);
            uVar25 = extraout_r3_01;
            if (0xb < uVar17) goto LAB_01013e30;
            uVar21 = (uint)(ushort)(*(short *)(&DAT_0103c1b8 + uVar17 * 2) + 0x640);
            if (*(char *)(param_1 + 199) == '\x01') {
              if (*(byte *)((int)param_1 + 0xc9) == 3) {
                uVar17 = param_1[0xc5];
                uVar18 = param_1[9] + uVar17;
              }
              else {
                iVar10 = param_1[9];
                iVar23 = FUN_0100dd8c((uint)*(byte *)((int)param_1 + 0x2ef),
                                      (uint)*(byte *)((int)param_1 + 0x6f),uVar17,
                                      (uint)*(byte *)((int)param_1 + 0xc9));
                uVar18 = iVar10 + iVar23;
                uVar17 = param_1[0xc5];
              }
              iVar23 = FUN_01024e78(uVar17,uVar21);
              iVar19 = param_1[0xc4];
              iVar24 = param_1[0xc6];
              param_1[0xc4] = iVar23;
              iVar10 = FUN_01024e78(uVar18,uVar21);
              iVar20 = param_1[200];
              param_1[200] = iVar10;
              iVar11 = FUN_01024e78(param_1[5],uVar21);
              if ((undefined *)param_1[5] < &DAT_00001d4c) {
                iVar11 = iVar11 + 2;
              }
              uVar17 = param_1[0xc9];
              param_1[0xc9] = iVar11;
              iVar23 = (iVar11 - uVar17) *
                       ((((uint)*(ushort *)((int)param_1 + 0x2f6) + iVar26) - iVar28) +
                       ~param_1[0xc6]) + (iVar23 - iVar19) * iVar24 + (iVar10 - iVar20);
            }
            else {
              iVar23 = FUN_01024e78((uint)puVar15,uVar21);
              iVar10 = param_1[0xc9];
              if ((undefined *)param_1[5] < &DAT_00001d4c) {
                iVar23 = iVar23 + 2;
              }
              param_1[0xc9] = iVar23;
              iVar23 = (iVar23 - iVar10) *
                       (((uint)*(ushort *)((int)param_1 + 0x2f6) + iVar26) - iVar28);
              uVar17 = extraout_r2_01;
            }
            *(undefined1 *)((int)param_1 + 0x332) = 1;
          }
        }
      }
    }
    uVar18 = (uint)*(byte *)(param_1 + 199);
    switch(uVar18) {
    case 0:
      iVar28 = FUN_0100dd8c((uint)*(byte *)((int)param_1 + 0x2ef),
                            (uint)*(byte *)((int)param_1 + 0x6f),uVar17,uVar18);
      iVar26 = FUN_01024e78(param_1[9] + iVar28,uVar21);
      param_1[200] = iVar26;
      iVar26 = FUN_01024e78(param_1[5],uVar21);
      if ((undefined *)param_1[5] < &DAT_00001d4c) {
        iVar26 = iVar26 + 2;
      }
      param_1[0xc9] = iVar26;
      FUN_010211c8(&local_30,&local_34);
      iVar14 = FUN_01024bc0(param_1[0xd6],param_1[0xd7],local_30,iStack_2c,local_34);
      bVar2 = *(byte *)((int)param_1 + 0x6f);
      iVar26 = FUN_010211f0((uint)bVar2);
      if ((bVar2 & 0xc) == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = 0x28;
      }
      FUN_0100fc8c((uint)param_1,iVar10 + (uint)(&DAT_0000df41 + iVar26) / 1000 + 0xc5);
      local_38 = param_1[0xda];
      local_3c = param_1[9];
      iVar10 = FUN_010211f0((uint)*(byte *)((int)param_1 + 0x6f));
      iVar11 = param_1[200];
      iVar26 = *(ushort *)(param_1 + 10) + 0x22;
      local_38 = (((((local_38 - 0x20) + local_3c) - iVar11) + iVar28) - iVar14) -
                 (uint)(&DAT_0000a3a1 + iVar10) / 1000;
      uVar17 = (uint)*(byte *)((int)param_1 + 0x6f);
      if ((*(byte *)((int)param_1 + 0x6f) & 0xc) == 0) {
        iVar28 = FUN_010211f0(uVar17);
        uVar21 = (uint)(&DAT_0000a3a1 + iVar28) / 1000;
        local_3c = uVar17;
      }
      else {
        uVar21 = 0x65;
      }
      iVar28 = FUN_010211e0(uVar17);
      uVar21 = (iVar11 + 0x30) * 2 + iVar26 + uVar21;
      DAT_21000f58 = (undefined *)(iVar28 + uVar21);
      if (0x243 < local_38 - param_1[0xda]) goto LAB_010139f4;
      FUN_01009500(0x30,0x51f,local_38,local_38 - param_1[0xda]);
LAB_01013b12:
      *(undefined1 *)((int)param_1 + 0x333) = 0;
      cVar7 = DAT_21000f54;
      param_1[0xd6] = param_1[0xd4];
      param_1[0xd7] = param_1[0xd5];
      iVar28 = iVar26;
      iVar14 = 1;
      goto joined_r0x01013788;
    case 1:
      goto switchD_01013796_caseD_1;
    case 2:
      iVar28 = FUN_01024e78(param_1[0xc5] + param_1[9],uVar21);
      param_1[200] = iVar28;
      iVar28 = FUN_01024e78(param_1[5],uVar21);
      bVar2 = *(byte *)((int)param_1 + 0x6f);
      if ((undefined *)param_1[5] < &DAT_00001d4c) {
        iVar28 = iVar28 + 2;
      }
      param_1[0xc9] = iVar28;
      iVar28 = FUN_010211f0((uint)bVar2);
      if ((bVar2 & 0xc) == 0) {
        iVar26 = 0;
      }
      else {
        iVar26 = 0x28;
      }
      FUN_0100fc8c((uint)param_1,iVar26 + (uint)(&DAT_0000df41 + iVar28) / 1000 + 0xc5);
      if ((*(short *)((int)param_1 + 0x2f6) == 0) && (param_4 != 0)) {
        iVar11 = param_1[0xc5];
        iVar14 = param_1[9];
        bVar2 = *(byte *)((int)param_1 + 0x6f);
        iVar28 = FUN_010211f0((uint)bVar2);
        iVar10 = param_1[0xdb];
        iVar19 = param_1[200];
        iVar26 = FUN_010211e0((uint)bVar2);
        local_38 = (((iVar11 + iVar14 + -0x20 + iVar10) - iVar19) - iVar26) -
                   (uint)(&DAT_0000a3a1 + iVar28) / 1000;
        iVar28 = param_1[200];
      }
      else {
        iVar28 = param_1[200];
        local_38 = (param_1[0xc5] + param_1[9]) - iVar28;
      }
      iVar14 = param_1[0xc4];
      iVar26 = param_1[0xc6];
      bVar2 = *(byte *)((int)param_1 + 0x6f);
      uVar9 = *(ushort *)(param_1 + 10);
      if ((bVar2 & 0xc) == 0) {
        iVar10 = FUN_010211f0((uint)bVar2);
        uVar17 = (uint)(&DAT_0000a3a1 + iVar10) / 1000;
      }
      else {
        uVar17 = 0x65;
      }
      iVar10 = FUN_010211e0((uint)bVar2);
      puVar12 = (undefined *)(iVar10 + (uint)uVar9 + (iVar26 * iVar14 + iVar28 + 0x30) * 2 + uVar17)
      ;
      puVar15 = (undefined *)param_1[5];
      DAT_21000f58 = puVar12;
      *(undefined1 *)(param_1 + 199) = 1;
      goto LAB_01013814;
    case 3:
      puVar15 = (undefined *)param_1[5];
      local_38 = (int)puVar15 * iVar28;
      if ((param_4 == 0) || (*(short *)((int)param_1 + 0x2f6) != 0)) {
        puVar12 = DAT_21000f58;
        if (*(char *)((int)param_1 + 0x333) != '\0') goto LAB_01013814;
        uVar17 = (uint)*(ushort *)((int)param_1 + 0x2f6);
      }
      else {
        *(undefined1 *)((int)param_1 + 0x333) = 0;
        uVar17 = 0;
      }
      iVar10 = param_1[0xc9];
      uVar21 = local_38 - iVar10 * iVar28;
      if ((((*(char *)((int)param_1 + 0xc5) == '&') ||
           (uVar18 = (uint)*(byte *)((int)param_1 + 0xc6), uVar18 == 0x26)) &&
          (uVar18 = (param_2 - *(ushort *)(param_1 + 0xef)) * 0x10000, -1 < (int)uVar18)) &&
         (uVar18 = (uint)*(byte *)((int)param_1 + 0x3bf), uVar18 != 0)) {
        local_3c = uVar18;
      }
      local_38 = uVar21;
      if ((iVar14 != 0) && (uVar17 == 0)) {
        iVar28 = param_1[0xdb];
        uVar25 = 0;
        if (iVar28 == 0) goto LAB_01013e34;
        uVar17 = (uint)*(byte *)((int)param_1 + 0x6f);
        if ((*(byte *)((int)param_1 + 0x6f) & 0xc) == 0) {
          iVar14 = FUN_010211f0(uVar17);
          iVar28 = param_1[0xdb];
          uVar17 = (uint)*(byte *)((int)param_1 + 0x6f);
          iVar14 = (uint)(&DAT_0000a3a1 + iVar14) / 1000 + 0x10;
        }
        else {
          iVar14 = 0x75;
        }
        iVar11 = FUN_010211e0(uVar17);
        uVar17 = (uint)*(ushort *)((int)param_1 + 0x2f6);
        iVar10 = param_1[0xc9];
        local_38 = (((uVar21 - 0x10) + iVar28) - iVar14) - iVar11;
      }
      uVar17 = (iVar10 * (uVar17 + iVar26) + 0x30) * 2;
      if ((local_3c & 0xc) == 0) {
        iVar28 = FUN_010211f0(local_3c);
        uVar21 = (uint)(&DAT_0000a3a1 + iVar28) / 1000;
      }
      else {
        uVar21 = 0x65;
      }
      iVar28 = FUN_010211e0(local_3c);
      puVar12 = (undefined *)(uVar21 + iVar28 + uVar17);
      puVar15 = (undefined *)param_1[5];
      DAT_21000f58 = puVar12;
      if (puVar15 < &DAT_00001d4c) {
        bVar8 = FUN_0100dee8((int)puVar15,uVar17,(int *)&DAT_21000f58,(int *)&local_38);
        *(bool *)((int)param_1 + 0x333) = bVar8;
        puVar15 = (undefined *)param_1[5];
        puVar12 = DAT_21000f58;
      }
      goto LAB_01013814;
    default:
      goto switchD_01013796_default;
    }
  }
  goto LAB_01013e30;
switchD_01013796_caseD_1:
  iVar14 = param_1[0xc9];
  uVar17 = param_1[0xc6];
  uVar4 = *(ushort *)((int)param_1 + 0x2f6);
  local_38 = iVar28 * (param_1[5] - iVar14);
  iVar10 = param_1[200];
  bVar2 = *(byte *)((int)param_1 + 0x6f);
  iVar28 = param_1[0xc4];
  uVar9 = *(ushort *)(param_1 + 10);
  if ((bVar2 & 0xc) == 0) {
    iVar11 = FUN_010211f0((uint)bVar2);
    uVar21 = (uint)(&DAT_0000a3a1 + iVar11) / 1000;
  }
  else {
    uVar21 = 0x65;
  }
  iVar11 = FUN_010211e0((uint)bVar2);
  DAT_21000f58 = (undefined *)
                 (iVar11 + (uint)uVar9 +
                           (iVar14 * (iVar26 + (uint)uVar4 + ~uVar17) +
                           iVar28 * uVar17 + iVar10 + 0x30) * 2 + uVar21);
LAB_010139f4:
  puVar15 = (undefined *)param_1[5];
  puVar12 = DAT_21000f58;
LAB_01013814:
  local_38 = local_38 - iVar23;
  puVar22 = puVar15 + (-0x1d8 - param_1[0xc9]);
  if (puVar12 <= puVar15 + (-0x1d8 - param_1[0xc9])) {
    puVar22 = puVar12;
  }
  param_1[0xbc] = puVar22;
  param_1[0xd2] = param_1[0xd6] + local_38;
  param_1[0xd3] = param_1[0xd7] + (uint)CARRY4(param_1[0xd6],local_38);
  *(undefined1 *)(param_1 + 0xce) = 0;
  *(undefined2 *)(param_1 + 0xd0) = 0x92;
  iVar28 = FUN_0100f8fc((int)(param_1 + 0xc));
  *(short *)(param_1 + 0xd8) = sVar6;
  param_1[0xcf] = puVar22 + iVar28;
  param_1[0xd6] = param_1[0xd2];
  param_1[0xd7] = param_1[0xd3];
  bVar8 = FUN_01016960();
  if (bVar8) {
    param_1[0xcf] = param_1[0xcf] + 0x1e;
  }
  *(undefined1 *)((int)param_1 + 0x342) = 0;
  if (0 < (short)(*(short *)(param_1 + 0xb8) - sVar6)) {
    *(undefined1 *)((int)param_1 + 0x342) = 2;
  }
  if (cVar1 == '\x0e') {
    if (param_4 != 0) goto LAB_01013d04;
  }
  else if (param_4 == 0) {
    if ((*(char *)(param_1 + 199) != '\0') &&
       (uVar17 = FUN_0100dcd0((char *)(param_1 + 0xce),param_1[5] - param_1[0xc9]),
       (uVar17 & 0xffff) != 0)) {
      if (param_5 == (undefined2 *)0x0) {
        return &DAT_00000001;
      }
      *param_5 = (short)uVar17;
      return &DAT_00000001;
    }
  }
  else {
LAB_01013d04:
    uVar9 = *(ushort *)(param_1 + 0xc2);
    if (uVar9 == 0) {
      *(ushort *)((int)param_1 + 0x30a) = uVar9;
    }
    else if (((uint)*(ushort *)((int)param_1 + 0x30a) * (uint)*(byte *)(param_1 + 0xc3) +
              (uint)*(byte *)(param_1 + 0xc3) < (uint)uVar9) &&
            (0 < (short)(*(short *)(param_1 + 0xb8) - sVar6))) {
      *(ushort *)((int)param_1 + 0x30a) = *(ushort *)((int)param_1 + 0x30a) + 1;
      *(undefined1 *)((int)param_1 + 0x342) = 0;
      iVar28 = FUN_0100fe3c();
      *(byte *)(param_1 + 0xc3) = ((byte)iVar28 & 7) + 1;
    }
  }
  uVar17 = FUN_010239c8((uint)*(byte *)(param_1 + 0xd9),(byte *)(param_1 + 0xce));
  if (uVar17 != 0) {
    *(byte *)(param_1 + 0xcc) = (byte)param_3 ^ 1;
    return (undefined *)0x0;
  }
  uVar29 = FUN_01009500(0x30,0x5cf,extraout_r2,extraout_r3_00);
  uVar17 = extraout_r2_02;
  uVar25 = extraout_r3_02;
LAB_01013e30:
  FUN_01013408((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),uVar17,uVar25);
  uVar18 = extraout_r2_03;
  uVar25 = extraout_r3_03;
LAB_01013e34:
  FUN_01009500(0x30,0x571,uVar18,uVar25);
  uVar17 = extraout_r2_04;
  uVar18 = extraout_r3_04;
switchD_01013796_default:
  FUN_01009500(0x30,0x586,uVar17,uVar18);
  puVar13 = (ushort *)(extraout_r3_05 >> 0x1d);
  uVar17 = 0;
  if (puVar13 == (ushort *)0x0) {
    FUN_01009500(0x30,0x97,extraout_r2_05,extraout_r3_05);
    FUN_01009500(0x30,0x68c,extraout_r2_07,extraout_r3_06);
    FUN_01009500(0x30,0xbb,extraout_r2_08,extraout_r3_07);
    FUN_01009500(0x30,0x64d,extraout_r2_09,extraout_r3_08);
    iVar28 = FUN_01009500(0x30,0x64c,extraout_r2_10,extraout_r3_09);
    *(undefined1 *)(iVar28 + 0x108) = 0;
    puVar16 = *(undefined4 **)(iVar28 + 0x104);
    uVar25 = *(undefined4 *)(iVar28 + 0x138);
    uVar27 = *(undefined4 *)(iVar28 + 0x13c);
    *(char *)((int)puVar16 + 0x2ef) = (char)((int)(extraout_r2_11 >> 0x1d) >> 1);
    *(undefined1 *)(iVar28 + 0x120) = 0;
    *(undefined1 *)(iVar28 + 0x121) = 1;
    FUN_0100d7f4(puVar16,1);
    puVar16 = *(undefined4 **)(iVar28 + 0x104);
    puVar16[0xd4] = uVar25;
    puVar16[0xd5] = uVar27;
    uVar3 = *(undefined1 *)(iVar28 + 0x100);
    puVar16[0xda] = iVar28 << 4;
    *(undefined1 *)(puVar16 + 0xd9) = uVar3;
    *(undefined1 *)(puVar16 + 199) = 0;
    *(undefined2 *)(puVar16 + 0xd8) = 0;
    puVar16[0xd6] = uVar25;
    puVar16[0xd7] = uVar27;
    puVar15 = FUN_01013718(puVar16,0,0,0,(undefined2 *)0x0);
    if (puVar15 == (undefined *)0x0) {
      *(undefined1 *)(puVar16 + 199) = 1;
      puVar16[0xc6] = 0;
      puVar16[0xc4] = 0;
      *(undefined2 *)((int)puVar16 + 0x32e) = 0;
      *(undefined2 *)(puVar16 + 0xcb) = 0;
      *(undefined1 *)((int)puVar16 + 0x331) = 0;
      *(undefined2 *)((int)puVar16 + 0x362) = 0;
      *(short *)(puVar16 + 0x2f) = *(short *)(puVar16 + 0x2f) + -1;
      FUN_01020e34();
      puVar15 = FUN_01023284();
      return puVar15;
    }
    iVar28 = FUN_01009500(0x30,0x21e,extraout_r2_12,extraout_r3_10);
    return *(undefined **)(iVar28 + 0x104);
  }
  puVar13[0x1b6] = 0;
  puVar13[0x1b7] = 0;
  if ((char)puVar13[0x198] == '\0') {
    uVar9 = puVar13[0x5e];
    uVar17 = (uint)uVar9;
    puVar13[0x5e] = puVar13[0x196];
    puVar13[0x173] = puVar13[0x196] - uVar9;
  }
  else {
    uVar9 = puVar13[0x197];
    uVar4 = puVar13[0x5e];
    if (uVar9 == uVar4) {
      puVar13[0x5e] = puVar13[0x172];
      puVar13[0x173] = puVar13[0x172] - uVar9;
    }
    else {
      puVar13[0x5e] = uVar9;
      puVar13[0x173] = uVar9 - uVar4;
    }
  }
  *(undefined4 *)(puVar13 + 0x1a8) = *(undefined4 *)(puVar13 + 0x1a4);
  *(undefined4 *)(puVar13 + 0x1aa) = *(undefined4 *)(puVar13 + 0x1a6);
  puVar15 = (undefined *)FUN_010166cc(puVar13,uVar17);
  if (*(char *)((int)puVar13 + 0x2eb) == '\0') {
    return puVar15;
  }
  iVar28 = 0x25e;
  if ((*(byte *)((int)puVar13 + 0x6f) & 0xc) == 0) {
    iVar28 = 0x236;
  }
  uVar17 = FUN_010236a8();
  if (uVar17 < 0x92) {
    uVar17 = 0x92;
  }
  if (*(int *)(puVar13 + 0x192) + -0x92 + uVar17 < *(uint *)(puVar13 + 10)) {
    uVar17 = ((*(uint *)(puVar13 + 10) + 0x92) - *(int *)(puVar13 + 0x192)) - uVar17;
  }
  else {
    uVar17 = 0;
  }
  if ((DAT_21000f5c == '\0') && (*(uint *)(puVar13 + 0x18) <= uVar17)) {
    uVar17 = *(uint *)(puVar13 + 0x18);
  }
  iVar26 = FUN_0100f8fc((int)(puVar13 + 0x18));
  bVar2 = *(byte *)((int)puVar13 + 0x6f);
  iVar14 = FUN_010211f0((uint)bVar2);
  if ((bVar2 & 0xc) == 0) {
    iVar23 = 0;
  }
  else {
    iVar23 = 0x28;
  }
  uVar18 = iVar23 + *(int *)(puVar13 + 0x178) + 0xc5 + iVar26 +
                    (uint)(&DAT_0000df41 + iVar14) / 1000;
  uVar21 = FUN_010245ec(2);
  uVar17 = uVar17 - uVar18 & ~((int)(uVar17 - uVar18) >> 0x1f);
  if (uVar21 <= uVar17) {
    uVar17 = uVar21;
  }
  uVar21 = FUN_010246a8(uVar17,2,extraout_r2_06);
  if (uVar21 == 0) {
    uVar18 = uVar18 + uVar17;
  }
  DAT_21000f60 = FUN_0100fb68((int)puVar13,uVar18,iVar28);
  bVar2 = *(byte *)((int)puVar13 + 0x6f);
  iVar28 = FUN_010211f0((uint)bVar2);
  if ((bVar2 & 0xc) == 0) {
    iVar26 = 0;
  }
  else {
    iVar26 = 0x28;
  }
  lVar5 = ZEXT48(&DAT_0000df41 + iVar28) * 0x10624dd3;
  puVar15 = (undefined *)
            FUN_01024538(((uVar18 - 0x17a) - (uint)(&DAT_0000df41 + iVar28) / 1000) - iVar26,
                         extraout_r1_01,(int)lVar5,(int)((ulonglong)lVar5 >> 0x20));
  return puVar15;
}


