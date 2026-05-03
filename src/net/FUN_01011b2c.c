/*
 * Function: FUN_01011b2c
 * Entry:    01011b2c
 * Prototype: undefined4 __stdcall FUN_01011b2c(int param_1)
 */


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_01011b2c(int param_1)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 extraout_r1;
  uint uVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  char cVar9;
  int iVar10;
  longlong lVar11;
  int local_30 [6];
  
  local_30[5] = *(undefined4 *)(DAT_21000f48 + 4);
  local_30[2] = 0x1012439;
  DAT_21000f25 = 0;
  *(undefined1 *)(param_1 + 0x79) = 0;
  local_30[4] = 0x1011f29;
  local_30[3] = 0x101205d;
  DAT_21000f30 = 0;
  DAT_21000f28 = 0;
  DAT_21000f26 = 0;
  FUN_01020f38(local_30 + 2);
  FUN_01020bd0();
  FUN_010210b0();
  FUN_010204a8();
  FUN_01020ce0(0x8e89bed6);
  FUN_01020f2c(0x555555);
  FUN_01026444(0,extraout_r1,extraout_r2,extraout_r3);
  FUN_010131e8(param_1 + 0x28);
  uVar4 = FUN_010131f4(param_1 + 0x28);
  FUN_01020cf4((char)uVar4);
  FUN_01020afc(0x25,(uint)*(byte *)(param_1 + 4),extraout_r2_00);
  FUN_01020cd4(*(undefined1 *)(param_1 + 0x10));
  DAT_21000f2c = FUN_01021aec(0,(undefined4 *)(uint)*(byte *)(param_1 + 4));
  if (DAT_21000f2c == 0) {
    DAT_21000f24 = 1;
    return 0;
  }
  uVar5 = FUN_010286d4(*(int *)(param_1 + 0x44),(undefined4 *)(param_1 + 0x48));
  uVar6 = FUN_010286f2(*(int *)(param_1 + 0x44),(undefined4 *)(param_1 + 0x50));
  if ((uVar5 == 0) || (*(char *)(param_1 + 0x20) == '\0')) {
    if (uVar6 == 0) {
      cVar9 = '\0';
    }
    else {
      cVar9 = *(char *)(param_1 + 0x21);
    }
  }
  else {
    cVar9 = '\x01';
  }
  if ((*(char *)(param_1 + 0x1a) != '\0') || ((int)((uint)*(ushort *)(param_1 + 2) << 0x1d) < 0)) {
    if (((*(int *)(param_1 + 0x5c) == 0x7fffffff && *(int *)(param_1 + 0x58) == -1) ||
        (lVar11 = FUN_01025834(), uVar8 = (uint)((ulonglong)lVar11 >> 0x20),
        uVar8 <= *(uint *)(param_1 + 0x5c) &&
        (uint)(*(uint *)(param_1 + 0x58) <= (uint)lVar11) <= uVar8 - *(uint *)(param_1 + 0x5c))) &&
       (cVar9 == '\0')) {
      cVar9 = *(char *)(param_1 + 0x7b);
      goto joined_r0x01011cea;
    }
    uVar3 = FUN_0100cf38();
    uVar8 = (uint)uVar3;
    lVar11 = FUN_01025834();
    iVar10 = (uint)(uVar8 * 0x20 < uVar8) * -0x200 + (uint)CARRY4(uVar8 * 0x3e00,uVar8);
    *(longlong *)(param_1 + 0x58) =
         lVar11 + CONCAT44((((iVar10 * 0x40 | uVar8 * 0x3e01 >> 0x1a) - iVar10) -
                           (uint)(uVar8 * 0xf8040 < uVar8 * 0x3e01)) +
                           (uint)CARRY4(uVar8 * 999999,uVar8),uVar8 * 1000000);
    FUN_01011a4c(param_1,1);
  }
  cVar9 = *(char *)(param_1 + 0x7b);
joined_r0x01011cea:
  if (((((uVar5 | uVar6) & 0xff) != 0) || (cVar9 != '\0')) &&
     (-1 < (int)((uint)*(ushort *)(param_1 + 2) << 0x1b))) {
    iVar10 = *(int *)(param_1 + 0x3c);
    do {
      uVar5 = FUN_0100fe3c();
    } while ((uint)(iVar10 << 0xc) >> 0x14 == (uVar5 & 0xfff));
    *(char *)(param_1 + 0x3d) = (char)uVar5;
    *(byte *)(param_1 + 0x3e) = *(byte *)(param_1 + 0x3e) & 0xf0 | (byte)((uVar5 << 0x14) >> 0x1c);
    *(undefined1 *)(param_1 + 0x7b) = 0;
  }
  DAT_21000f32 = FUN_0100d34c(DAT_21000f20 + 3);
  if ((int)((uint)*(ushort *)(param_1 + 2) << 0x1f) < 0) {
    DAT_21000f40 = 0xff;
    iVar10 = *(int *)(param_1 + 0x1c);
    local_30[0] = 0;
    local_30[1] = 0x10000;
    do {
      iVar7 = FUN_0100a5d8(local_30);
      iVar1 = local_30[0];
      if (iVar7 != 0) {
        return 0;
      }
    } while ((iVar10 == local_30[0]) ||
            (bVar2 = FUN_0100b23c((uint)*(byte *)(local_30[0] + 9),(byte *)(local_30[0] + 10),
                                  (uint)*(byte *)(iVar10 + 9),(byte *)(iVar10 + 10)), !bVar2));
    DAT_21000f40 = *(undefined1 *)(iVar1 + 2);
    DAT_21000f41 = *(undefined4 *)(iVar1 + 3);
    DAT_21000f45 = *(undefined2 *)(iVar1 + 7);
  }
  return 0;
}


