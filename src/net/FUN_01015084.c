/*
 * Function: FUN_01015084
 * Entry:    01015084
 * Prototype: uint __stdcall FUN_01015084(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_01015084(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  
  iVar2 = FUN_01009500(0x31,0x8ed,param_3,param_4);
  while( true ) {
    iVar6 = *(int *)(iVar2 + 4);
    uVar3 = (uint)*(byte *)(iVar6 + 0xc6);
    if ((uVar3 != 0x23) && (uVar3 != 0)) break;
    *(undefined1 *)(iVar6 + 0xc6) = 0x24;
  }
  iVar2 = FUN_01009500(0x31,0x518,uVar3,iVar6);
  puVar7 = *(undefined2 **)(iVar2 + 4);
  if (*(byte *)(puVar7 + 99) == 0x1d) {
    *(undefined1 *)((int)puVar7 + 0x105) = 0;
    if (*(char *)(puVar7 + 0x83) == '\0') {
      *(undefined1 *)((int)puVar7 + 0x2c1) = 0;
      puVar7[0x161] = *puVar7;
      *(undefined1 *)(puVar7 + 0x162) = 1;
      uVar3 = FUN_0100f788((undefined4 *)(puVar7 + 0x15c),0x1010485,2);
      *(undefined1 *)(*(int *)(iVar2 + 4) + 0xc6) = 0;
      return uVar3;
    }
    *(undefined1 *)(puVar7 + 0x83) = 0;
    *(undefined1 *)((int)puVar7 + 0x2c1) = 0;
    puVar7[0x161] = *puVar7;
    uVar3 = FUN_0100f788((undefined4 *)(puVar7 + 0x15c),0x10104a1,2);
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0xc6) = 0;
    return uVar3;
  }
  uVar3 = FUN_01009500(0x31,0x4e7,(uint)*(byte *)(puVar7 + 99),puVar7);
  iVar2 = *(int *)(uVar3 + 4);
  uVar4 = (uint)*(byte *)(iVar2 + 0xc6);
  if (uVar4 == 0x30) {
    *(undefined1 *)(iVar2 + 0xc6) = 0;
    uVar3 = FUN_0100ffb0(uVar3);
    return uVar3;
  }
  if (uVar4 == 0x17) {
    *(undefined1 *)(iVar2 + 0xc6) = 0x1b;
    return uVar3;
  }
  uVar4 = FUN_01009500(0x31,0x4d6,uVar4,iVar2);
  iVar2 = *(int *)(uVar4 + 4);
  if ((*(char *)(iVar2 + 0xc5) == '\n') && (*(char *)(iVar2 + 0x149) == *(char *)(DAT_21000f78 + 4))
     ) {
    *(undefined1 *)(iVar2 + 0xc5) = 0;
    *(undefined1 *)(iVar2 + 0x100) = 0;
    return uVar4;
  }
  uVar5 = *(uint *)(iVar2 + 0xb4);
  if ((uVar5 & 8) != 0) {
    *(uint *)(iVar2 + 0xb4) = uVar5 & 0xfffffff7;
    uVar3 = FUN_0100ffb0(uVar4);
    return uVar3;
  }
  if (*(char *)(DAT_21000f78 + 4) == -1) {
    *(undefined1 *)(iVar2 + 0x3b4) = 0;
    *(undefined1 *)(iVar2 + 0xc5) = 0x32;
    return uVar4;
  }
  FUN_01009500(0x31,0x487,uVar5,iVar2);
  do {
    do {
    } while (DAT_21000f80 != '\0');
  } while ((((uVar3 << 0x12) >> 0x1d != 0) ||
           (*(undefined **)(DAT_21000f6c + 0x14) <= &DAT_00001d4b)) ||
          (*(ushort *)(DAT_21000f6c + 0x38) < *(ushort *)(DAT_21000f6c + 0x54)));
  bVar1 = FUN_01014564(DAT_21000f6c);
  return (uint)bVar1;
}


