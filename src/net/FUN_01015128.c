/*
 * Function: FUN_01015128
 * Entry:    01015128
 * Prototype: uint __stdcall FUN_01015128(uint param_1)
 */


uint FUN_01015128(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint unaff_r5;
  
  iVar4 = *(int *)(param_1 + 4);
  uVar2 = (uint)*(byte *)(iVar4 + 0xc6);
  if (uVar2 == 0x30) {
    *(undefined1 *)(iVar4 + 0xc6) = 0;
    uVar2 = FUN_0100ffb0(param_1);
    return uVar2;
  }
  if (uVar2 == 0x17) {
    *(undefined1 *)(iVar4 + 0xc6) = 0x1b;
    return param_1;
  }
  uVar2 = FUN_01009500(0x31,0x4d6,uVar2,iVar4);
  iVar4 = *(int *)(uVar2 + 4);
  if ((*(char *)(iVar4 + 0xc5) == '\n') && (*(char *)(iVar4 + 0x149) == *(char *)(DAT_21000f78 + 4))
     ) {
    *(undefined1 *)(iVar4 + 0xc5) = 0;
    *(undefined1 *)(iVar4 + 0x100) = 0;
    return uVar2;
  }
  uVar3 = *(uint *)(iVar4 + 0xb4);
  if ((uVar3 & 8) != 0) {
    *(uint *)(iVar4 + 0xb4) = uVar3 & 0xfffffff7;
    uVar2 = FUN_0100ffb0(uVar2);
    return uVar2;
  }
  if (*(char *)(DAT_21000f78 + 4) == -1) {
    *(undefined1 *)(iVar4 + 0x3b4) = 0;
    *(undefined1 *)(iVar4 + 0xc5) = 0x32;
    return uVar2;
  }
  FUN_01009500(0x31,0x487,uVar3,iVar4);
  do {
    do {
    } while (DAT_21000f80 != '\0');
  } while (((unaff_r5 >> 0x1d != 0) || (*(undefined **)(DAT_21000f6c + 0x14) <= &DAT_00001d4b)) ||
          (*(ushort *)(DAT_21000f6c + 0x38) < *(ushort *)(DAT_21000f6c + 0x54)));
  bVar1 = FUN_01014564(DAT_21000f6c);
  return (uint)bVar1;
}


