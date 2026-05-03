/*
 * Function: FUN_01011adc
 * Entry:    01011adc
 * Prototype: int __stdcall FUN_01011adc(int param_1, undefined1 * param_2)
 */


/* WARNING: Type propagation algorithm not settling */

int FUN_01011adc(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  bool bVar2;
  ushort uVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 extraout_r1;
  uint uVar10;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  char cVar11;
  int iVar12;
  longlong lVar13;
  int aiStack_38 [6];
  uint uStack_20;
  
  *param_2 = 0x16;
  uVar1 = *(undefined1 *)(param_1 + 0xd);
  *(undefined4 *)(param_2 + 3) = *(undefined4 *)(param_1 + 9);
  param_2[7] = uVar1;
  if ((param_2[3] == '\0') || ((int)((uint)*(ushort *)(param_1 + -0xa4) << 0x1c) < 0)) {
    return param_1;
  }
  uVar3 = *(ushort *)(param_2 + 5);
  puVar4 = (ushort *)FUN_0100a518(uVar3,1);
  if (puVar4 == (ushort *)0x0) {
    return 0;
  }
  FUN_0100b0dc((uint)*puVar4);
  iVar5 = FUN_0100a564(uVar3,1);
  if (iVar5 == 0) {
    return 0;
  }
  iVar5 = FUN_01009500(0x2d,0x285,extraout_r2,extraout_r3);
  aiStack_38[5] = *(undefined4 *)(DAT_21000f48 + 4);
  aiStack_38[2] = 0x1012439;
  DAT_21000f25 = 0;
  *(undefined1 *)(iVar5 + 0x79) = 0;
  aiStack_38[4] = 0x1011f29;
  aiStack_38[3] = 0x101205d;
  DAT_21000f30 = 0;
  DAT_21000f28 = 0;
  DAT_21000f26 = 0;
  uStack_20 = (uint)uVar3;
  FUN_01020f38(aiStack_38 + 2);
  FUN_01020bd0();
  FUN_010210b0();
  FUN_010204a8();
  FUN_01020ce0(0x8e89bed6);
  FUN_01020f2c(0x555555);
  FUN_01026444(0,extraout_r1,extraout_r2_00,extraout_r3_00);
  FUN_010131e8(iVar5 + 0x28);
  uVar6 = FUN_010131f4(iVar5 + 0x28);
  FUN_01020cf4((char)uVar6);
  FUN_01020afc(0x25,(uint)*(byte *)(iVar5 + 4),extraout_r2_01);
  FUN_01020cd4(*(undefined1 *)(iVar5 + 0x10));
  DAT_21000f2c = FUN_01021aec(0,(undefined4 *)(uint)*(byte *)(iVar5 + 4));
  if (DAT_21000f2c == 0) {
    DAT_21000f24 = 1;
    return 0;
  }
  uVar7 = FUN_010286d4(*(int *)(iVar5 + 0x44),(undefined4 *)(iVar5 + 0x48));
  uVar8 = FUN_010286f2(*(int *)(iVar5 + 0x44),(undefined4 *)(iVar5 + 0x50));
  if ((uVar7 == 0) || (*(char *)(iVar5 + 0x20) == '\0')) {
    if (uVar8 == 0) {
      cVar11 = '\0';
    }
    else {
      cVar11 = *(char *)(iVar5 + 0x21);
    }
  }
  else {
    cVar11 = '\x01';
  }
  if ((*(char *)(iVar5 + 0x1a) != '\0') || ((int)((uint)*(ushort *)(iVar5 + 2) << 0x1d) < 0)) {
    if (((*(int *)(iVar5 + 0x5c) == 0x7fffffff && *(int *)(iVar5 + 0x58) == -1) ||
        (lVar13 = thunk_FUN_01025834(), uVar10 = (uint)((ulonglong)lVar13 >> 0x20),
        uVar10 <= *(uint *)(iVar5 + 0x5c) &&
        (uint)(*(uint *)(iVar5 + 0x58) <= (uint)lVar13) <= uVar10 - *(uint *)(iVar5 + 0x5c))) &&
       (cVar11 == '\0')) {
      cVar11 = *(char *)(iVar5 + 0x7b);
      goto joined_r0x01011cea;
    }
    uVar3 = FUN_0100cf38();
    uVar10 = (uint)uVar3;
    lVar13 = thunk_FUN_01025834();
    iVar12 = (uint)(uVar10 * 0x20 < uVar10) * -0x200 + (uint)CARRY4(uVar10 * 0x3e00,uVar10);
    *(longlong *)(iVar5 + 0x58) =
         lVar13 + CONCAT44((((iVar12 * 0x40 | uVar10 * 0x3e01 >> 0x1a) - iVar12) -
                           (uint)(uVar10 * 0xf8040 < uVar10 * 0x3e01)) +
                           (uint)CARRY4(uVar10 * 999999,uVar10),uVar10 * 1000000);
    FUN_01011a4c(iVar5,1);
  }
  cVar11 = *(char *)(iVar5 + 0x7b);
joined_r0x01011cea:
  if (((((uVar7 | uVar8) & 0xff) != 0) || (cVar11 != '\0')) &&
     (-1 < (int)((uint)*(ushort *)(iVar5 + 2) << 0x1b))) {
    iVar12 = *(int *)(iVar5 + 0x3c);
    do {
      uVar7 = FUN_0100fe3c();
    } while ((uint)(iVar12 << 0xc) >> 0x14 == (uVar7 & 0xfff));
    *(char *)(iVar5 + 0x3d) = (char)uVar7;
    *(byte *)(iVar5 + 0x3e) = *(byte *)(iVar5 + 0x3e) & 0xf0 | (byte)((uVar7 << 0x14) >> 0x1c);
    *(undefined1 *)(iVar5 + 0x7b) = 0;
  }
  DAT_21000f32 = FUN_0100d34c(DAT_21000f20 + 3);
  if ((int)((uint)*(ushort *)(iVar5 + 2) << 0x1f) < 0) {
    DAT_21000f40 = 0xff;
    iVar5 = *(int *)(iVar5 + 0x1c);
    aiStack_38[0] = 0;
    aiStack_38[1] = 0x10000;
    do {
      iVar9 = FUN_0100a5d8(aiStack_38);
      iVar12 = aiStack_38[0];
      if (iVar9 != 0) {
        return 0;
      }
    } while ((iVar5 == aiStack_38[0]) ||
            (bVar2 = FUN_0100b23c((uint)*(byte *)(aiStack_38[0] + 9),(byte *)(aiStack_38[0] + 10),
                                  (uint)*(byte *)(iVar5 + 9),(byte *)(iVar5 + 10)), !bVar2));
    DAT_21000f40 = *(undefined1 *)(iVar12 + 2);
    DAT_21000f41 = *(undefined4 *)(iVar12 + 3);
    DAT_21000f45 = *(undefined2 *)(iVar12 + 7);
  }
  return 0;
}


