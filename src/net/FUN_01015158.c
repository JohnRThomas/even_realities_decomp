/*
 * Function: FUN_01015158
 * Entry:    01015158
 * Prototype: uint __stdcall FUN_01015158(uint param_1)
 */


uint FUN_01015158(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint unaff_r5;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((*(char *)(iVar3 + 0xc5) == '\n') && (*(char *)(iVar3 + 0x149) == *(char *)(DAT_21000f78 + 4))
     ) {
    *(undefined1 *)(iVar3 + 0xc5) = 0;
    *(undefined1 *)(iVar3 + 0x100) = 0;
    return param_1;
  }
  uVar2 = *(uint *)(iVar3 + 0xb4);
  if ((uVar2 & 8) != 0) {
    *(uint *)(iVar3 + 0xb4) = uVar2 & 0xfffffff7;
    uVar2 = FUN_0100ffb0(param_1);
    return uVar2;
  }
  if (*(char *)(DAT_21000f78 + 4) == -1) {
    *(undefined1 *)(iVar3 + 0x3b4) = 0;
    *(undefined1 *)(iVar3 + 0xc5) = 0x32;
    return param_1;
  }
  FUN_01009500(0x31,0x487,uVar2,iVar3);
  do {
    do {
    } while (DAT_21000f80 != '\0');
  } while (((unaff_r5 >> 0x1d != 0) || (*(undefined **)(DAT_21000f6c + 0x14) <= &DAT_00001d4b)) ||
          (*(ushort *)(DAT_21000f6c + 0x38) < *(ushort *)(DAT_21000f6c + 0x54)));
  bVar1 = FUN_01014564(DAT_21000f6c);
  return (uint)bVar1;
}


