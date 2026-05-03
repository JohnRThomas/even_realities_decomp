/*
 * Function: FUN_01010c70
 * Entry:    01010c70
 * Prototype: undefined __stdcall FUN_01010c70(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01010c70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 extraout_r2;
  int iVar5;
  byte bVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  undefined4 extraout_r3;
  uint *puVar10;
  uint uVar11;
  char cVar12;
  undefined2 *puVar13;
  longlong lVar14;
  undefined1 auStack_28 [12];
  
  puVar10 = (uint *)(param_1 + -0x1b0);
  iVar2 = FUN_0101eacc((uint)*(byte *)(param_1 + -0x1e9),param_2,param_3,param_4);
  iVar8 = *(int *)(param_1 + -0x1a8) + 0x800;
  iVar4 = iVar8 * 0x1000 >> 0x18;
  cVar12 = (char)(iVar8 >> 0xc);
  if (iVar4 < DAT_21000f04) {
    iVar4 = (int)-cVar12 + (int)DAT_21000f05;
  }
  else {
    if (iVar4 <= DAT_21000f06) {
      return;
    }
    iVar4 = (int)-cVar12 + (int)DAT_21000f07;
  }
  if (iVar4 < 0x80) {
    if (iVar4 < -0x80) {
      cVar12 = -0x80;
    }
    else {
      cVar12 = (char)iVar4;
      if (cVar12 == '\0') {
        return;
      }
    }
  }
  else {
    cVar12 = '\x7f';
  }
  if ((*(uint *)(param_1 + -0x1ac) != 0x7fffffff || *puVar10 != 0xffffffff) &&
     (lVar14 = src/*FUN_01025834(), uVar11 = (uint)((ulonglong)lVar14 >> 0x20),
     uVar9 = *(uint *)(param_1 + -0x1ac),
     uVar9 < uVar11 || uVar11 - uVar9 < (uint)(*puVar10 <= (uint)lVar14))) {
    iVar4 = FUN_0100d7c0(*(ushort *)(param_1 + -600),auStack_28);
    if (iVar4 == 0) {
      iVar2 = FUN_0101eafc((int)auStack_28,iVar2 + 1U & 0xff,cVar12,2);
      if (iVar2 == 0) {
        uVar11 = (uint)DAT_21000f08;
        lVar14 = src/*FUN_01025834();
        *(longlong *)puVar10 =
             lVar14 + CONCAT44((((uint)(uVar11 * 0x20 < uVar11) * -0x200 +
                                (uint)CARRY4(uVar11 * 0x3e00,uVar11)) * 0x3f -
                               (uint)(uVar11 * 0xf8040 < uVar11 * 0x3e01)) +
                               (uint)CARRY4(uVar11 * 999999,uVar11),uVar11 * 1000000);
        return;
      }
      return;
    }
    pcVar3 = (char *)FUN_01009500(0x7a,0x85,extraout_r2,extraout_r3);
    puVar13 = *(undefined2 **)(pcVar3 + 4);
    iVar2 = FUN_0100df60();
    cVar12 = *pcVar3;
    iVar4 = *(int *)(pcVar3 + 4);
    *(char *)(iVar4 + 0xc1) = (char)iVar2;
    if (cVar12 == '\0') {
      if (iVar2 == 0x7f) {
        return;
      }
      iVar8 = iVar2 * (0x1000 - DAT_21000f0c) + (DAT_21000f0c * *(int *)(iVar4 + 0xb0) >> 0xc);
    }
    else {
      if (iVar2 == 0x7f) {
        return;
      }
      iVar8 = iVar2 * (0x1000 - DAT_21000f0c) + (*(int *)(iVar4 + 0xb0) * DAT_21000f0c >> 0xc);
    }
    *(int *)(iVar4 + 0xb0) = iVar8;
    *(undefined1 *)(iVar4 + 0xc2) = *(undefined1 *)(iVar4 + 0xdb);
    if (DAT_21000f10 != '\0') {
      iVar5 = (iVar8 + 0x800) * 0x1000 >> 0x18;
      cVar12 = DAT_21000f05;
      if ((((iVar5 < DAT_21000f04) || (cVar12 = DAT_21000f07, DAT_21000f06 < iVar5)) &&
          ((iVar8 = (int)(char)-(char)(iVar8 + 0x800 >> 0xc) + (int)cVar12, 0xff < iVar8 + 0x80U ||
           ((char)iVar8 != '\0')))) &&
         ((*(int *)(iVar4 + 0xac) != 0x7fffffff || *(uint *)(iVar4 + 0xa8) != 0xffffffff &&
          (lVar14 = src/*FUN_01025834(), uVar11 = (uint)((ulonglong)lVar14 >> 0x20),
          *(uint *)(iVar4 + 0xac) < uVar11 ||
          uVar11 - *(uint *)(iVar4 + 0xac) < (uint)(*(uint *)(iVar4 + 0xa8) <= (uint)lVar14))))) {
        iVar8 = *(int *)(pcVar3 + 4);
        uVar1 = FUN_01020a9c();
        *(undefined1 *)(iVar8 + 0x6f) = uVar1;
        FUN_0100f748((undefined4 *)(iVar8 + 600),0x1010c71);
      }
    }
    uVar7 = (short)iVar2 - (short)*(char *)(iVar4 + 0xc3);
    if ((short)uVar7 < 0) {
      uVar7 = -uVar7;
    }
    if (((*(byte *)(iVar4 + 0x2d) <= uVar7) && (*(byte *)(iVar4 + 0x2d) != 0xff)) &&
       ((bVar6 = *(char *)(iVar4 + 0xc4) + 1, *(byte *)(iVar4 + 0xc4) = bVar6,
        *(byte *)(iVar4 + 0x2e) < bVar6 || (*(char *)(iVar4 + 0xc3) == '\x7f')))) {
      *(char *)(iVar4 + 0xc3) = (char)iVar2;
      *(undefined1 *)(iVar4 + 0xc4) = 0;
      if (*(char *)(puVar13 + 0x16) == '\x01') {
        iVar2 = *(int *)(pcVar3 + 4);
        if (*(char *)(iVar2 + 0x1c0) == '\0') {
          *(undefined2 *)(iVar2 + 0x1c1) = *puVar13;
          *(undefined1 *)(iVar2 + 0x1c3) = *(undefined1 *)((int)puVar13 + 0xc1);
          *(undefined1 *)(iVar2 + 0x1c4) = *(undefined1 *)(puVar13 + 0x61);
          FUN_0100f788((undefined4 *)(iVar2 + 0x1b8),0x1010c61,2);
          return;
        }
      }
    }
    return;
  }
  return;
}


