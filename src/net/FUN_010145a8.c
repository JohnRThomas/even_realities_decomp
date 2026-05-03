/*
 * Function: FUN_010145a8
 * Entry:    010145a8
 * Prototype: undefined4 * __stdcall FUN_010145a8(undefined4 * param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_010145a8(undefined4 *param_1)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  ushort uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined *puVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  uint extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  int iVar15;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  uint extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 extraout_r3_09;
  undefined4 extraout_r3_10;
  undefined4 extraout_r3_11;
  undefined4 uVar16;
  int iVar17;
  uint unaff_r7;
  uint uVar18;
  longlong lVar19;
  undefined8 uVar20;
  short local_12;
  
  if (*(char *)((int)param_1 + 0x2eb) != '\0') {
    _MasterStackPointer = 0x96f3b83d;
    _NMI = (undefined1 *)0x200;
    _HardFault = &UNK_00036f94;
    return param_1;
  }
  if (*(char *)(param_1 + 199) != '\x03') {
    _HardFault = (undefined *)0x36f94;
    _NMI = (undefined1 *)0x200;
                    /* WARNING: Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000008) is written */
                    /* WARNING: Read-only address (ram,0x0000000c) is written */
    _MasterStackPointer = 0x96f3b83d;
    return param_1;
  }
  lVar19 = thunk_FUN_01025834();
  lVar19 = lVar19 - *(longlong *)(param_1 + 0xd4);
  puVar5 = (undefined4 *)lVar19;
  iVar14 = (int)((ulonglong)lVar19 >> 0x20);
  if (iVar14 < (int)(uint)(puVar5 == (undefined4 *)0x0)) {
    return puVar5;
  }
  iVar15 = -(uint)((undefined4 *)0xfffffffe < puVar5) - iVar14;
  if (iVar15 < 0 ==
      (SBORROW4(0,iVar14) != SBORROW4(-iVar14,(uint)((undefined4 *)0xfffffffe < puVar5)))) {
    if (param_1[5] == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (uint)puVar5 / (uint)param_1[5] & 0xffff;
    }
    uVar6 = uVar6 + *(ushort *)(param_1 + 0x2f) + 1;
    *(short *)(param_1 + 0xcb) = (short)uVar6;
    if ((short)(*(short *)(param_1 + 0xb9) - *(short *)(param_1 + 0xcb)) < 1) {
      return (undefined4 *)(uVar6 & 0xffff);
    }
    bVar3 = FUN_01023fb0((uint)*(byte *)(param_1 + 0xd9));
    if ((undefined4 *)(uint)bVar3 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    *(undefined1 *)((int)param_1 + 0x331) = 0xff;
    uVar6 = ((uint)*(ushort *)(param_1 + 0x2f) + (uint)*(ushort *)(param_1 + 0x3e) + -1) -
            (uint)*(ushort *)((int)param_1 + 0xf6) & 0xffff;
    if ((int)((uVar6 - *(ushort *)(param_1 + 0xcb)) * 0x10000) < 0) {
      return (undefined4 *)(uint)bVar3;
    }
    while( true ) {
      puVar5 = (undefined4 *)FUN_01013718(param_1,(uint)*(ushort *)(param_1 + 0xcb),1,0,&local_12);
      if (puVar5 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      uVar11 = extraout_r2;
      uVar16 = extraout_r3;
      if (puVar5 != (undefined4 *)&DAT_00000001) break;
      *(short *)(param_1 + 0xcb) = *(short *)(param_1 + 0xcb) + local_12;
      if ((int)((uVar6 - *(ushort *)(param_1 + 0xcb)) * 0x10000) < 0) {
        return puVar5;
      }
    }
  }
  else {
    FUN_01009500(0x30,0x603,(int)*(longlong *)(param_1 + 0xd4),iVar15);
    uVar11 = extraout_r2_00;
    uVar16 = extraout_r3_00;
  }
  uVar20 = FUN_01009500(0x30,0x63c,uVar11,uVar16);
  puVar7 = (undefined4 *)uVar20;
  puVar5 = puVar7;
  uVar11 = extraout_r2_01;
  uVar16 = extraout_r3_01;
  switch((int)((ulonglong)uVar20 >> 0x20)) {
  case 0:
    if (puVar7[0xdb] != 0) goto LAB_01014778;
    while (DAT_21000f64 == '\0') {
      puVar9 = FUN_01013718(puVar7,(uint)*(ushort *)(puVar7 + 0xb9),0,1,(undefined2 *)0x0);
      if (puVar9 == (undefined *)0x0) goto LAB_010146b6;
      puVar5 = (undefined4 *)FUN_01009500(0x30,0x717,extraout_r2_03,extraout_r3_03);
LAB_01014778:
      if ((*(char *)((int)puVar5 + 0x332) != '\0') && (*(char *)(puVar5 + 199) == '\x03')) {
        bVar1 = *(byte *)((int)puVar5 + 0x6f);
        uVar8 = (uint)bVar1;
        uVar4 = thunk_FUN_01024ecc();
        uVar20 = CONCAT44(extraout_r1,(uint)uVar4);
        uVar6 = (uint)*(byte *)(puVar7 + 0xb6);
        uVar11 = extraout_r2_04;
        if (0xb < uVar6) goto LAB_01014858;
        iVar15 = puVar7[0xdb];
        uVar2 = *(ushort *)(&DAT_0103c1b8 + uVar6 * 2);
        unaff_r7 = uVar2 + 0x640 & 0xffff;
        iVar14 = FUN_010211e0(uVar8);
        uVar6 = (uint)uVar4 + (uint)uVar2 & 0xffff;
        if ((bVar1 & 0xc) == 0) {
          iVar12 = FUN_010211f0(uVar8);
          iVar17 = puVar7[0xbc];
          iVar12 = -((iVar12 + 999U) / 1000);
          iVar10 = FUN_010211e0(uVar8);
          iVar17 = iVar17 - iVar10;
          iVar10 = FUN_010211f0(uVar8);
          uVar8 = (uint)(&DAT_0000a3a1 + iVar10) / 1000;
        }
        else {
          iVar17 = puVar7[0xbc];
          iVar12 = -0x3c;
          iVar10 = FUN_010211e0(uVar8);
          uVar8 = 0x65;
          iVar17 = iVar17 - iVar10;
        }
        uVar18 = (iVar15 - iVar14) + iVar12;
        iVar14 = (iVar17 - uVar8 >> 1) + 0x29;
        uVar8 = (uVar6 * ((iVar17 - uVar8) - 0x60)) / unaff_r7 + 0x60;
        if ((uVar18 < iVar14 - (uVar8 >> 1)) || (iVar14 + (uVar8 >> 1) < uVar18)) {
          FUN_0102a9e0();
        }
        iVar14 = FUN_01024e78(puVar7[5],uVar6);
        if ((undefined *)puVar7[5] < &DAT_00001d4c) {
          iVar14 = iVar14 + 2;
        }
        *(undefined1 *)((int)puVar7 + 0x332) = 0;
        puVar7[0xc9] = iVar14;
      }
    }
  case 2:
    *(undefined1 *)(puVar7 + 199) = 4;
LAB_010146b6:
    FUN_01020e34();
    puVar5 = (undefined4 *)FUN_01023284();
    *(undefined2 *)((int)puVar7 + 0x362) = 0;
    *(undefined2 *)((int)puVar7 + 0x32e) = *(undefined2 *)(puVar7 + 0x2f);
    *(undefined1 *)((int)puVar7 + 0x331) = 0;
  case 3:
    return puVar5;
  case 1:
    *(undefined1 *)(puVar7 + 199) = 3;
    return puVar7;
  case 4:
    uVar6 = FUN_01020ae4();
    puVar7[0xdb] = uVar6;
    uVar8 = FUN_010211e0((uint)*(byte *)((int)puVar7 + 0x6f));
    if (uVar8 <= uVar6) {
      iVar14 = puVar7[0xdb];
      puVar5 = (undefined4 *)FUN_010211e0((uint)*(byte *)((int)puVar7 + 0x6f));
      DAT_21000f60 = (iVar14 + DAT_21000f60) - (int)puVar5;
      return puVar5;
    }
    uVar20 = FUN_01009500(0x30,0x3da,extraout_r2_02,extraout_r3_02);
    uVar11 = extraout_r2_05;
    uVar6 = extraout_r3_04;
LAB_01014858:
    FUN_01013408((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar11,uVar6);
    uVar11 = extraout_r2_06;
    uVar16 = extraout_r3_05;
    break;
  case 5:
    bVar1 = *(byte *)((int)puVar7 + 0x6f);
    iVar14 = FUN_010211f0((uint)bVar1);
    if ((bVar1 & 0xc) == 0) {
      iVar15 = 0;
    }
    else {
      iVar15 = 0x28;
    }
    puVar5 = (undefined4 *)
             FUN_0100fc8c((uint)puVar7,iVar15 + (uint)(&DAT_0000df41 + iVar14) / 1000 + 0xc5);
    return puVar5;
  }
  iVar14 = FUN_01009500(0x30,0x7a3,uVar11,uVar16);
  _Reset = extraout_r2_07 >> 0x1d;
  iVar15 = (int)_Reset >> 1;
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING (jumptable): Read-only address (ram,0x00000008) is written */
                    /* WARNING (jumptable): Read-only address (ram,0x0000000c) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000008) is written */
                    /* WARNING: Read-only address (ram,0x0000000c) is written */
  _NMI = &DAT_f8942301;
  _MasterStackPointer = extraout_r3_06;
  _HardFault = (undefined *)unaff_r7;
  if (iVar15 == 1) {
LAB_01014890:
    uVar11 = FUN_01020af0();
    *(undefined4 *)(iVar14 + 0x368) = uVar11;
  }
  else {
    iVar12 = iVar14;
    if (iVar15 != 2) {
      if (iVar15 != 0) {
        FUN_01009500(0x30,0x7cd,iVar15,iVar14 << 4);
        goto LAB_01014890;
      }
      uVar11 = FUN_01020af0();
      FUN_010141a4(0x10,uVar11,0);
      iVar15 = FUN_01023688(0xff,0x1013e51,iVar14);
      if (iVar15 != 0) goto LAB_01014898;
      iVar12 = FUN_01009500(0x30,0x7b6,extraout_r2_08,extraout_r3_07);
    }
    FUN_010141a4(0x10,*(undefined4 *)(iVar12 + 0x368),1);
    iVar14 = FUN_01023688(0xff,0x1013e51,iVar14);
    if (iVar14 == 0) {
      puVar13 = (undefined1 *)FUN_01009500(0x30,0x7c7,extraout_r2_09,extraout_r3_08);
      if ((int)puVar13 * 0x10 != 0) {
        if ((int)puVar13 * 0x10 == 1) {
          puVar13[0x108] = 0;
          FUN_01020e34();
          puVar5 = (undefined4 *)FUN_01023284();
          return puVar5;
        }
        FUN_01009500(0x30,0x7dd,extraout_r2_10,extraout_r3_09);
        uVar11 = extraout_r2_12;
        uVar16 = extraout_r3_11;
LAB_010149c8:
        iVar14 = FUN_01009500(0x30,0x737,uVar11,uVar16);
        return (undefined4 *)(uint)*(byte *)(iVar14 + 0x120);
      }
      iVar14 = 0;
      if (*(short *)(puVar13 + 0x22) != 0) {
        uVar6 = FUN_0100fe3c();
        iVar14 = uVar6 - (uVar6 / *(ushort *)(puVar13 + 0x22)) * (uint)*(ushort *)(puVar13 + 0x22);
      }
      uVar6 = *(uint *)(puVar13 + 0x118);
      iVar12 = *(int *)(puVar13 + 0x11c);
      iVar15 = FUN_01012b2c((int)puVar13);
      *(undefined2 *)(puVar13 + 0x132) = 0x102;
      *(uint *)(puVar13 + 0x138) = iVar15 + iVar14 + uVar6;
      puVar13[0x128] = 0;
      *(uint *)(puVar13 + 0x13c) = iVar12 + (uint)CARRY4(iVar15 + iVar14,uVar6);
      iVar14 = FUN_01013414((int)puVar13);
      *(short *)(puVar13 + 0x130) = (short)iVar14;
      uVar6 = *(uint *)(puVar13 + 0x138);
      iVar14 = *(int *)(puVar13 + 0x13c);
      *(uint *)(puVar13 + 0x118) = uVar6;
      *(int *)(puVar13 + 0x11c) = iVar14;
      if (puVar13[0x148] == '\0') {
        if ((*(int *)(puVar13 + 0x144) == 0x7fffffff && *(int *)(puVar13 + 0x140) == -1) ||
           (uVar20 = FUN_01012ab4((int)puVar13,0),
           -1 < (int)(((*(int *)(puVar13 + 0x144) - iVar14) -
                      (uint)(*(uint *)(puVar13 + 0x140) < uVar6)) -
                     (uint)(*(uint *)(puVar13 + 0x140) - uVar6 < (int)uVar20 + 0x152U)))) {
          uVar6 = FUN_010239c8((uint)(byte)puVar13[0x100],puVar13 + 0x128);
          uVar11 = extraout_r2_11;
          uVar16 = extraout_r3_10;
          if (uVar6 == 0) goto LAB_010149c8;
        }
        else {
          FUN_010130bc(puVar13);
        }
      }
      *(undefined2 *)(puVar13 + 0x122) = 0;
      FUN_01020e34();
      puVar5 = (undefined4 *)FUN_01023284();
      return puVar5;
    }
  }
LAB_01014898:
                    /* WARNING: Could not recover jumptable at 0x01014898. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar5 = (undefined4 *)(*(code *)0x1014867)();
  return puVar5;
}


