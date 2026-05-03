/*
 * Function: FUN_01010574
 * Entry:    01010574
 * Prototype: undefined4 __stdcall FUN_01010574(int param_1)
 */


undefined4 FUN_01010574(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_1 + 4);
  if (*(char *)((int)puVar1 + 0xc5) != '\x1c') {
    return 2;
  }
  *(undefined1 *)((int)puVar1 + 0x105) = 0;
  *(undefined1 *)(puVar1 + 0x80) = 0;
  *(undefined1 *)(puVar1 + 0x198) = 0;
  if (*(char *)(puVar1 + 0x83) == '\0') {
    *(undefined1 *)((int)puVar1 + 0x2c1) = 0;
    puVar1[0x161] = *puVar1;
    *(undefined1 *)(puVar1 + 0x162) = 1;
    FUN_0100f788((undefined4 *)(puVar1 + 0x15c),0x1010485,2);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0xc5) = 0;
    return 0;
  }
  *(undefined1 *)(puVar1 + 0x83) = 0;
  *(undefined1 *)((int)puVar1 + 0x2c1) = 0;
  puVar1[0x161] = *puVar1;
  FUN_0100f788((undefined4 *)(puVar1 + 0x15c),0x10104a1,2);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0xc5) = 0;
  return 0;
}


