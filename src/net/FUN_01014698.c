/*
 * Function: FUN_01014698
 * Entry:    01014698
 * Prototype: undefined4 * __stdcall FUN_01014698(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_01014698(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  uint extraout_r2_04;
  int iVar12;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 uVar13;
  int iVar14;
  uint unaff_r7;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  
  puVar9 = param_1;
  switch(param_2) {
  case 0:
    if (param_1[0xdb] != 0) goto LAB_01014778;
    while (DAT_21000f64 == '\0') {
      puVar5 = FUN_01013718(param_1,(uint)*(ushort *)(param_1 + 0xb9),0,1,(undefined2 *)0x0);
      if (puVar5 == (undefined *)0x0) goto LAB_010146b6;
      puVar9 = (undefined4 *)FUN_01009500(0x30,0x717,extraout_r2_00,extraout_r3_00);
LAB_01014778:
      if ((*(char *)((int)puVar9 + 0x332) != '\0') && (*(char *)(puVar9 + 199) == '\x03')) {
        bVar1 = *(byte *)((int)puVar9 + 0x6f);
        uVar4 = (uint)bVar1;
        uVar3 = thunk_FUN_01024ecc();
        uVar17 = CONCAT44(extraout_r1,(uint)uVar3);
        uVar15 = (uint)*(byte *)(param_1 + 0xb6);
        uVar8 = extraout_r2_01;
        if (0xb < uVar15) goto LAB_01014858;
        iVar12 = param_1[0xdb];
        uVar2 = *(ushort *)(&DAT_0103c1b8 + uVar15 * 2);
        unaff_r7 = uVar2 + 0x640 & 0xffff;
        iVar7 = FUN_010211e0(uVar4);
        uVar15 = (uint)uVar3 + (uint)uVar2 & 0xffff;
        if ((bVar1 & 0xc) == 0) {
          iVar10 = FUN_010211f0(uVar4);
          iVar14 = param_1[0xbc];
          iVar10 = -((iVar10 + 999U) / 1000);
          iVar6 = FUN_010211e0(uVar4);
          iVar14 = iVar14 - iVar6;
          iVar6 = FUN_010211f0(uVar4);
          uVar4 = (uint)(&DAT_0000a3a1 + iVar6) / 1000;
        }
        else {
          iVar14 = param_1[0xbc];
          iVar10 = -0x3c;
          iVar6 = FUN_010211e0(uVar4);
          uVar4 = 0x65;
          iVar14 = iVar14 - iVar6;
        }
        uVar16 = (iVar12 - iVar7) + iVar10;
        iVar7 = (iVar14 - uVar4 >> 1) + 0x29;
        uVar4 = (uVar15 * ((iVar14 - uVar4) - 0x60)) / unaff_r7 + 0x60;
        if ((uVar16 < iVar7 - (uVar4 >> 1)) || (iVar7 + (uVar4 >> 1) < uVar16)) {
          FUN_0102a9e0();
        }
        iVar7 = FUN_01024e78(param_1[5],uVar15);
        if ((undefined *)param_1[5] < &DAT_00001d4c) {
          iVar7 = iVar7 + 2;
        }
        *(undefined1 *)((int)param_1 + 0x332) = 0;
        param_1[0xc9] = iVar7;
      }
    }
  case 2:
    *(undefined1 *)(param_1 + 199) = 4;
LAB_010146b6:
    FUN_01020e34();
    puVar9 = (undefined4 *)FUN_01023284();
    *(undefined2 *)((int)param_1 + 0x362) = 0;
    *(undefined2 *)((int)param_1 + 0x32e) = *(undefined2 *)(param_1 + 0x2f);
    *(undefined1 *)((int)param_1 + 0x331) = 0;
  case 3:
    return puVar9;
  case 1:
    *(undefined1 *)(param_1 + 199) = 3;
    return param_1;
  case 4:
    uVar15 = FUN_01020ae4();
    param_1[0xdb] = uVar15;
    uVar4 = FUN_010211e0((uint)*(byte *)((int)param_1 + 0x6f));
    if (uVar4 <= uVar15) {
      iVar7 = param_1[0xdb];
      puVar9 = (undefined4 *)FUN_010211e0((uint)*(byte *)((int)param_1 + 0x6f));
      DAT_21000f60 = (iVar7 + DAT_21000f60) - (int)puVar9;
      return puVar9;
    }
    uVar17 = FUN_01009500(0x30,0x3da,extraout_r2,extraout_r3);
    uVar8 = extraout_r2_02;
    uVar15 = extraout_r3_01;
LAB_01014858:
    FUN_01013408((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar8,uVar15);
    param_3 = extraout_r2_03;
    param_4 = extraout_r3_02;
    break;
  case 5:
    bVar1 = *(byte *)((int)param_1 + 0x6f);
    iVar7 = FUN_010211f0((uint)bVar1);
    if ((bVar1 & 0xc) == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = 0x28;
    }
    puVar9 = (undefined4 *)
             FUN_0100fc8c((uint)param_1,iVar12 + (uint)(&DAT_0000df41 + iVar7) / 1000 + 0xc5);
    return puVar9;
  }
  iVar7 = FUN_01009500(0x30,0x7a3,param_3,param_4);
  _Reset = extraout_r2_04 >> 0x1d;
  iVar12 = (int)_Reset >> 1;
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING (jumptable): Read-only address (ram,0x00000008) is written */
                    /* WARNING (jumptable): Read-only address (ram,0x0000000c) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000008) is written */
                    /* WARNING: Read-only address (ram,0x0000000c) is written */
  _NMI = &DAT_f8942301;
  _MasterStackPointer = extraout_r3_03;
  _HardFault = unaff_r7;
  if (iVar12 == 1) {
LAB_01014890:
    uVar8 = FUN_01020af0();
    *(undefined4 *)(iVar7 + 0x368) = uVar8;
  }
  else {
    iVar10 = iVar7;
    if (iVar12 != 2) {
      if (iVar12 != 0) {
        FUN_01009500(0x30,0x7cd,iVar12,iVar7 << 4);
        goto LAB_01014890;
      }
      uVar8 = FUN_01020af0();
      FUN_010141a4(0x10,uVar8,0);
      iVar12 = FUN_01023688(0xff,0x1013e51,iVar7);
      if (iVar12 != 0) goto LAB_01014898;
      iVar10 = FUN_01009500(0x30,0x7b6,extraout_r2_05,extraout_r3_04);
    }
    FUN_010141a4(0x10,*(undefined4 *)(iVar10 + 0x368),1);
    iVar7 = FUN_01023688(0xff,0x1013e51,iVar7);
    if (iVar7 == 0) {
      puVar11 = (undefined1 *)FUN_01009500(0x30,0x7c7,extraout_r2_06,extraout_r3_05);
      if ((int)puVar11 * 0x10 == 0) {
        iVar7 = 0;
        if (*(short *)(puVar11 + 0x22) != 0) {
          uVar15 = FUN_0100fe3c();
          iVar7 = uVar15 - (uVar15 / *(ushort *)(puVar11 + 0x22)) *
                           (uint)*(ushort *)(puVar11 + 0x22);
        }
        uVar15 = *(uint *)(puVar11 + 0x118);
        iVar10 = *(int *)(puVar11 + 0x11c);
        iVar12 = FUN_01012b2c((int)puVar11);
        *(undefined2 *)(puVar11 + 0x132) = 0x102;
        *(uint *)(puVar11 + 0x138) = iVar12 + iVar7 + uVar15;
        puVar11[0x128] = 0;
        *(uint *)(puVar11 + 0x13c) = iVar10 + (uint)CARRY4(iVar12 + iVar7,uVar15);
        iVar7 = FUN_01013414((int)puVar11);
        *(short *)(puVar11 + 0x130) = (short)iVar7;
        uVar15 = *(uint *)(puVar11 + 0x138);
        iVar7 = *(int *)(puVar11 + 0x13c);
        *(uint *)(puVar11 + 0x118) = uVar15;
        *(int *)(puVar11 + 0x11c) = iVar7;
        if (puVar11[0x148] == '\0') {
          if ((*(int *)(puVar11 + 0x144) == 0x7fffffff && *(int *)(puVar11 + 0x140) == -1) ||
             (uVar17 = FUN_01012ab4((int)puVar11,0),
             -1 < (int)(((*(int *)(puVar11 + 0x144) - iVar7) -
                        (uint)(*(uint *)(puVar11 + 0x140) < uVar15)) -
                       (uint)(*(uint *)(puVar11 + 0x140) - uVar15 < (int)uVar17 + 0x152U)))) {
            uVar15 = FUN_010239c8((uint)(byte)puVar11[0x100],puVar11 + 0x128);
            uVar8 = extraout_r2_08;
            uVar13 = extraout_r3_07;
            if (uVar15 == 0) goto LAB_010149c8;
          }
          else {
            FUN_010130bc(puVar11);
          }
        }
        *(undefined2 *)(puVar11 + 0x122) = 0;
        FUN_01020e34();
        puVar9 = (undefined4 *)FUN_01023284();
        return puVar9;
      }
      if ((int)puVar11 * 0x10 == 1) {
        puVar11[0x108] = 0;
        FUN_01020e34();
        puVar9 = (undefined4 *)FUN_01023284();
        return puVar9;
      }
      FUN_01009500(0x30,0x7dd,extraout_r2_07,extraout_r3_06);
      uVar8 = extraout_r2_09;
      uVar13 = extraout_r3_08;
LAB_010149c8:
      iVar7 = FUN_01009500(0x30,0x737,uVar8,uVar13);
      return (undefined4 *)(uint)*(byte *)(iVar7 + 0x120);
    }
  }
LAB_01014898:
                    /* WARNING: Could not recover jumptable at 0x01014898. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar9 = (undefined4 *)(*(code *)0x1014867)();
  return puVar9;
}


