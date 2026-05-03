/*
 * Function: FUN_010166cc
 * Entry:    010166cc
 * Prototype: undefined __stdcall FUN_010166cc(ushort * param_1, undefined4 param_2)
 */


void FUN_010166cc(ushort *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  ushort *puVar8;
  uint extraout_r1;
  undefined4 extraout_r2;
  uint uVar9;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  uint extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar10;
  ushort *extraout_r3_02;
  int extraout_r3_03;
  int unaff_r6;
  int unaff_r7;
  undefined8 uVar11;
  longlong lVar12;
  
  uVar9 = 0;
  DAT_21000f68 = CONCAT31(DAT_21000f68._1_3_,1);
  *(undefined1 *)((int)param_1 + 0x2eb) = 1;
  DAT_21000f74 = 0;
  DAT_21000f80 = 0;
  DAT_21000f84 = 0;
  DAT_21000f6c = param_1;
  iVar4 = FUN_0100a97c(*param_1,param_2,0);
  uVar7 = extraout_r2;
  uVar10 = extraout_r3;
  if (iVar4 == 0) {
LAB_01016924:
    lVar12 = FUN_01009500(0x31,0x9d9,uVar7,uVar10);
    uVar5 = extraout_r2_04;
    puVar8 = extraout_r3_02;
    iVar4 = unaff_r6;
  }
  else {
    FUN_0100b0f8(*DAT_21000f6c);
    FUN_0100b154(*DAT_21000f6c);
    if (DAT_21000f6c[0x171] == 0) {
LAB_01016802:
      uVar5 = (uint)(byte)DAT_21000f6c[0xa7];
      if (uVar5 == 0xfe) {
        if (*(char *)((int)DAT_21000f6c + 0x2ed) != '\0') goto LAB_01016724;
LAB_01016812:
        if ((char)DAT_21000f6c[0x116] == '\0') {
          DAT_21000f82 = DAT_21000f6c[0xe];
          if (DAT_21000f82 < DAT_21000f6c[0x15]) {
            DAT_21000f82 = DAT_21000f6c[0x15];
          }
        }
        else {
          DAT_21000f82 = DAT_21000f6c[0xe];
        }
      }
      else {
LAB_01016716:
        FUN_01014ce4(uVar5);
LAB_0101671c:
        if (*(char *)((int)DAT_21000f6c + 0x2ed) == '\0') goto LAB_01016812;
LAB_01016724:
        DAT_21000f82 = 0;
      }
      puVar8 = DAT_21000f6c;
      uVar9 = (uint)DAT_21000f6c[0x173];
      uVar5 = uVar9 - 1 & 0xffff;
      sVar2 = (short)(uVar9 - 1);
      DAT_21000f6c[0x174] = DAT_21000f6c[0x174] + sVar2;
      puVar8[0x7b] = puVar8[0x7b] + sVar2;
      if (*(char *)((int)puVar8 + 0xcb) == '\0') {
        uVar6 = FUN_0100dbc0((int)(puVar8 + 0x54),6,(uint)(byte)puVar8[99],1);
        uVar9 = (uint)DAT_21000f6c[0x173];
        puVar8 = DAT_21000f6c;
        if (uVar6 != 0) goto LAB_0101674e;
      }
      else {
LAB_0101674e:
        *(uint *)(puVar8 + 0x74) = *(int *)(puVar8 + 0x74) + uVar5;
      }
      if (puVar8[0x171] < 2) {
        puVar8[0x171] = puVar8[0x171] + 1;
      }
      if (uVar5 != 0) {
        *(undefined1 *)(puVar8 + 0x17a) = 0;
      }
      *(undefined1 *)(puVar8 + 0x175) = 0;
      uVar9 = FUN_0100e41c((int)(puVar8 + 0x54),(int)puVar8,uVar9);
      puVar8 = DAT_21000f6c;
      if (uVar9 == 0) {
        if ((byte)DAT_21000f6c[99] - 0xb < 2) {
          if (-1 < (int)(((uint)DAT_21000f6c[0x5e] - (uint)DAT_21000f6c[0x1de]) * 0x10000)) {
            *(undefined4 *)(DAT_21000f6c + 0x67) = *(undefined4 *)(DAT_21000f6c + 0x1df);
            *(char *)(puVar8 + 0x69) = (char)puVar8[0x1e1];
            FUN_0100d7f4((undefined4 *)puVar8,3);
            puVar8 = DAT_21000f6c;
            *(undefined1 *)(DAT_21000f6c + 99) = 0;
            *(undefined1 *)(puVar8 + 0x8f) = 0xff;
          }
        }
        else if ((byte)DAT_21000f6c[99] == 0x26) {
          if (-1 < (int)(((uint)DAT_21000f6c[0x5e] - (uint)DAT_21000f6c[0x1de]) * 0x10000)) {
            *(undefined1 *)(DAT_21000f6c + 99) = 0;
            bVar3 = FUN_01014f48();
            if (!bVar3) {
              *(bool *)(DAT_21000f6c + 0xb6) = bVar3;
              uVar7 = extraout_r2_02;
LAB_010168bc:
              FUN_01015318(0,(undefined1 *)0x0,uVar7);
              return;
            }
            *(undefined1 *)(DAT_21000f6c + 0xb6) = 0;
          }
        }
        else if (((*(char *)((int)DAT_21000f6c + 0xc5) == '&') ||
                 (*(char *)((int)DAT_21000f6c + 0xc5) == '(')) &&
                (-1 < (int)(((uint)DAT_21000f6c[0x5e] - (uint)DAT_21000f6c[0x1de]) * 0x10000))) {
          *(undefined1 *)((int)DAT_21000f6c + 0xc5) = 0;
          bVar3 = FUN_01014f48();
          uVar7 = extraout_r2_01;
          if (!bVar3) goto LAB_010168bc;
        }
        bVar3 = FUN_01027516(iVar4);
        if (bVar3) {
          if ((char)DAT_21000f6c[0x177] != '\0') {
            return;
          }
        }
        else {
          *(undefined1 *)(DAT_21000f6c + 0x177) = 0;
        }
        FUN_0100b980(DAT_21000f68,DAT_21000f6c,0x1014c0d,0x10151b9,0x1015319);
        if (DAT_21000f88 != (uint *)0x0) {
          FUN_01021064((uint)DAT_21000f8c,DAT_21000f88);
        }
        uVar9 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),5,(uint)(byte)DAT_21000f6c[99],1);
        if (uVar9 != 0) {
          FUN_0100b970();
          return;
        }
        return;
      }
      FUN_01009500(0x31,0xa20,extraout_r2_00,extraout_r3_00);
      uVar7 = extraout_r2_03;
      uVar10 = extraout_r3_01;
      unaff_r6 = iVar4;
      goto LAB_01016924;
    }
    uVar5 = (uint)(byte)DAT_21000f6c[0xa7];
    if (uVar5 != 0xfe) goto LAB_01016716;
    if ((char)DAT_21000f6c[0xb0] == '\0') goto LAB_0101671c;
    uVar5 = FUN_0100dbc0((int)(DAT_21000f6c + 0x54),1,(uint)*(byte *)((int)DAT_21000f6c + 199),1);
    puVar8 = DAT_21000f6c;
    if (uVar5 != 0) goto LAB_01016802;
    puVar1 = (undefined1 *)((int)DAT_21000f6c + 0x161);
    DAT_21000f6c[0x7d] = 0;
    *(undefined1 *)(puVar8 + 0xa8) = *puVar1;
    uVar5 = (uint)(byte)puVar8[0xa7];
    lVar12 = (ulonglong)extraout_r1 << 0x20;
    if (uVar5 == 0xfe) {
      puVar8[0x7e] = 0;
      *(undefined1 *)(puVar8 + 0x175) = 0;
      *(undefined1 *)(puVar8 + 0x80) = 1;
      *(undefined1 *)(puVar8 + 0xa7) = 2;
      FUN_01014ce4(2);
      goto LAB_0101671c;
    }
  }
  FUN_01015084((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),uVar5,puVar8);
  uVar9 = uVar9 >> 0x1d;
  *(undefined2 *)((int)&DAT_21000f68 + extraout_r3_03) = 0;
  *(uint *)(unaff_r7 + iVar4) = uVar9 << 4;
  uVar11 = CONCAT44(uVar9 << 4,uVar9);
  if ((char)DAT_21000f6c[0x177] != '\0') {
    FUN_01015318(0,(undefined1 *)0x0,extraout_r2_05);
    return;
  }
  if (DAT_21000c8c != 0) {
    if ((char)DAT_21000c6c != '\0') {
      if (DAT_21000c8c != 2) {
        FUN_01009500(0x27,0x224,extraout_r2_05,(uint)DAT_21000c8c);
        FUN_0100b434();
        return;
      }
      uVar11 = FUN_01020fcc(*(uint *)(DAT_21000c70 + 0x2f0));
      goto LAB_0100bdb6;
    }
    if (DAT_21000c8c == 1) goto LAB_0100bdb6;
    FUN_01009500(0x27,0x220,extraout_r2_05,(uint)DAT_21000c8c);
  }
  uVar11 = FUN_0100b434();
LAB_0100bdb6:
  uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
  if ((*(char *)(DAT_21000c70 + 0x7b) == '\0') && (uVar7 = 0, *(int *)(DAT_21000c70 + 0x74) != 0)) {
    FUN_01023250((uint)*(byte *)(DAT_21000c70 + 0x7a),(uint *)0x0,0,DAT_21000c70);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0100bdc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x1016933)((int)uVar11,uVar7);
  return;
}


