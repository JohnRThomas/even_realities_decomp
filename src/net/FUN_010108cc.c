/*
 * Function: FUN_010108cc
 * Entry:    010108cc
 * Prototype: undefined __stdcall FUN_010108cc(int param_1)
 */


void FUN_010108cc(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_1 + 4);
  if (*(char *)(puVar1 + 0x10c) != '\0') {
    return;
  }
  puVar1[0x10d] = *puVar1;
  *(undefined1 *)((int)puVar1 + 0x219) = 0x1a;
  FUN_0100f788((undefined4 *)(puVar1 + 0x108),0x1010761,2);
  return;
}


