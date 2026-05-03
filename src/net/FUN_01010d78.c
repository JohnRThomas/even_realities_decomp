/*
 * Function: FUN_01010d78
 * Entry:    01010d78
 * Prototype: undefined __stdcall FUN_01010d78(char * param_1)
 */


void FUN_01010d78(char *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  longlong lVar11;
  
  puVar10 = *(undefined2 **)(param_1 + 4);
  iVar3 = FUN_0100df60();
  cVar1 = *param_1;
  iVar9 = *(int *)(param_1 + 4);
  *(char *)(iVar9 + 0xc1) = (char)iVar3;
  if (cVar1 == '\0') {
    if (iVar3 == 0x7f) {
      return;
    }
    iVar8 = iVar3 * (0x1000 - DAT_21000f0c) + (DAT_21000f0c * *(int *)(iVar9 + 0xb0) >> 0xc);
  }
  else {
    if (iVar3 == 0x7f) {
      return;
    }
    iVar8 = iVar3 * (0x1000 - DAT_21000f0c) + (*(int *)(iVar9 + 0xb0) * DAT_21000f0c >> 0xc);
  }
  *(int *)(iVar9 + 0xb0) = iVar8;
  *(undefined1 *)(iVar9 + 0xc2) = *(undefined1 *)(iVar9 + 0xdb);
  if (DAT_21000f10 != '\0') {
    iVar5 = (iVar8 + 0x800) * 0x1000 >> 0x18;
    cVar1 = DAT_21000f05;
    if ((((iVar5 < DAT_21000f04) || (cVar1 = DAT_21000f07, DAT_21000f06 < iVar5)) &&
        ((iVar8 = (int)(char)-(char)(iVar8 + 0x800 >> 0xc) + (int)cVar1, 0xff < iVar8 + 0x80U ||
         ((char)iVar8 != '\0')))) &&
       ((*(int *)(iVar9 + 0xac) != 0x7fffffff || *(uint *)(iVar9 + 0xa8) != 0xffffffff &&
        (lVar11 = FUN_01025834(), uVar4 = (uint)((ulonglong)lVar11 >> 0x20),
        *(uint *)(iVar9 + 0xac) < uVar4 ||
        uVar4 - *(uint *)(iVar9 + 0xac) < (uint)(*(uint *)(iVar9 + 0xa8) <= (uint)lVar11))))) {
      iVar8 = *(int *)(param_1 + 4);
      uVar2 = FUN_01020a9c();
      *(undefined1 *)(iVar8 + 0x6f) = uVar2;
      FUN_0100f748((undefined4 *)(iVar8 + 600),0x1010c71);
    }
  }
  uVar7 = (short)iVar3 - (short)*(char *)(iVar9 + 0xc3);
  if ((short)uVar7 < 0) {
    uVar7 = -uVar7;
  }
  if (((*(byte *)(iVar9 + 0x2d) <= uVar7) && (*(byte *)(iVar9 + 0x2d) != 0xff)) &&
     ((bVar6 = *(char *)(iVar9 + 0xc4) + 1, *(byte *)(iVar9 + 0xc4) = bVar6,
      *(byte *)(iVar9 + 0x2e) < bVar6 || (*(char *)(iVar9 + 0xc3) == '\x7f')))) {
    *(char *)(iVar9 + 0xc3) = (char)iVar3;
    *(undefined1 *)(iVar9 + 0xc4) = 0;
    if (*(char *)(puVar10 + 0x16) == '\x01') {
      iVar3 = *(int *)(param_1 + 4);
      if (*(char *)(iVar3 + 0x1c0) == '\0') {
        *(undefined2 *)(iVar3 + 0x1c1) = *puVar10;
        *(undefined1 *)(iVar3 + 0x1c3) = *(undefined1 *)((int)puVar10 + 0xc1);
        *(undefined1 *)(iVar3 + 0x1c4) = *(undefined1 *)(puVar10 + 0x61);
        FUN_0100f788((undefined4 *)(iVar3 + 0x1b8),0x1010c61,2);
        return;
      }
    }
  }
  return;
}


