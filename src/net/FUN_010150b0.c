/*
 * Function: FUN_010150b0
 * Entry:    010150b0
 * Prototype: uint __stdcall FUN_010150b0(int param_1)
 */


uint FUN_010150b0(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  
  puVar5 = *(undefined2 **)(param_1 + 4);
  if (*(byte *)(puVar5 + 99) == 0x1d) {
    *(undefined1 *)((int)puVar5 + 0x105) = 0;
    if (*(char *)(puVar5 + 0x83) == '\0') {
      *(undefined1 *)((int)puVar5 + 0x2c1) = 0;
      puVar5[0x161] = *puVar5;
      *(undefined1 *)(puVar5 + 0x162) = 1;
      uVar2 = FUN_0100f788((undefined4 *)(puVar5 + 0x15c),0x1010485,2);
      *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0;
      return uVar2;
    }
    *(undefined1 *)(puVar5 + 0x83) = 0;
    *(undefined1 *)((int)puVar5 + 0x2c1) = 0;
    puVar5[0x161] = *puVar5;
    uVar2 = FUN_0100f788((undefined4 *)(puVar5 + 0x15c),0x10104a1,2);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0;
    return uVar2;
  }
  uVar2 = FUN_01009500(0x31,0x4e7,(uint)*(byte *)(puVar5 + 99),puVar5);
  iVar6 = *(int *)(uVar2 + 4);
  uVar3 = (uint)*(byte *)(iVar6 + 0xc6);
  if (uVar3 == 0x30) {
    *(undefined1 *)(iVar6 + 0xc6) = 0;
    uVar2 = FUN_0100ffb0(uVar2);
    return uVar2;
  }
  if (uVar3 == 0x17) {
    *(undefined1 *)(iVar6 + 0xc6) = 0x1b;
    return uVar2;
  }
  uVar3 = FUN_01009500(0x31,0x4d6,uVar3,iVar6);
  iVar6 = *(int *)(uVar3 + 4);
  if ((*(char *)(iVar6 + 0xc5) == '\n') && (*(char *)(iVar6 + 0x149) == *(char *)(DAT_21000f78 + 4))
     ) {
    *(undefined1 *)(iVar6 + 0xc5) = 0;
    *(undefined1 *)(iVar6 + 0x100) = 0;
    return uVar3;
  }
  uVar4 = *(uint *)(iVar6 + 0xb4);
  if ((uVar4 & 8) != 0) {
    *(uint *)(iVar6 + 0xb4) = uVar4 & 0xfffffff7;
    uVar2 = FUN_0100ffb0(uVar3);
    return uVar2;
  }
  if (*(char *)(DAT_21000f78 + 4) == -1) {
    *(undefined1 *)(iVar6 + 0x3b4) = 0;
    *(undefined1 *)(iVar6 + 0xc5) = 0x32;
    return uVar3;
  }
  FUN_01009500(0x31,0x487,uVar4,iVar6);
  do {
    do {
    } while (DAT_21000f80 != '\0');
  } while ((((uVar2 << 0x12) >> 0x1d != 0) ||
           (*(undefined **)(DAT_21000f6c + 0x14) <= &DAT_00001d4b)) ||
          (*(ushort *)(DAT_21000f6c + 0x38) < *(ushort *)(DAT_21000f6c + 0x54)));
  bVar1 = FUN_01014564(DAT_21000f6c);
  return (uint)bVar1;
}


