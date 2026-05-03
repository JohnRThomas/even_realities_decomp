/*
 * Function: FUN_0100a5d8
 * Entry:    0100a5d8
 * Prototype: undefined4 __stdcall FUN_0100a5d8(int * param_1)
 */


undefined4 FUN_0100a5d8(int *param_1)

{
  byte bVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  puVar3 = *(ushort **)(&DAT_21000b7c + (uint)*(byte *)((int)param_1 + 6) * 4);
  if (puVar3 == (ushort *)0x0) {
    uVar4 = 2;
  }
  else {
    do {
      if ((byte)puVar3[1] <= *(byte *)((int)param_1 + 7)) {
        return 2;
      }
      bVar1 = *(byte *)((int)param_1 + 7);
      *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    } while (puVar3[bVar1 + 5] == 0xfff0);
    *(ushort *)(param_1 + 1) = puVar3[bVar1 + 5];
    iVar2 = FUN_01027cea(puVar3,bVar1);
    *param_1 = iVar2;
    uVar4 = 0;
  }
  return uVar4;
}


