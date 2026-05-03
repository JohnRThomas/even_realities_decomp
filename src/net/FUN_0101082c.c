/*
 * Function: FUN_0101082c
 * Entry:    0101082c
 * Prototype: undefined4 __stdcall FUN_0101082c(byte * param_1, int param_2)
 */


undefined4 FUN_0101082c(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  
  puVar4 = *(undefined2 **)(param_1 + 4);
  bVar1 = *param_1;
  uVar2 = FUN_0100dbc0((int)(puVar4 + 0x54),7,(uint)*(byte *)((int)puVar4 + 0xc5),(uint)bVar1);
  if (uVar2 == 0) {
    return 1;
  }
  uVar2 = *(uint *)(param_2 + 8);
  *(uint *)(puVar4 + 0x8b) = *(uint *)(param_2 + 4) & 0xf704492f;
  *(uint *)(puVar4 + 0x8d) = uVar2 & 0x1807;
  *(byte *)((int)puVar4 + 0x119) = *(byte *)((int)puVar4 + 0x119) | 8;
  *(undefined1 *)(puVar4 + 0x80) = 0;
  *(undefined1 *)((int)puVar4 + 0xc5) = 0;
  if (bVar1 == 0) {
    *(byte *)(*(int *)(param_1 + 4) + 0x173) = bVar1;
  }
  if (*(char *)(puVar4 + 0x10c) != '\0') {
    return 0;
  }
  *(undefined1 *)((int)puVar4 + 0x219) = 0;
  puVar4[0x10d] = *puVar4;
  uVar3 = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(puVar4 + 0x10e) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(puVar4 + 0x110) = uVar3;
  FUN_0100f788((undefined4 *)(puVar4 + 0x108),0x1010761,2);
  return 0;
}


