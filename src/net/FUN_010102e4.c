/*
 * Function: FUN_010102e4
 * Entry:    010102e4
 * Prototype: undefined __stdcall FUN_010102e4(int param_1)
 */


void FUN_010102e4(int param_1)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_1 + 4);
  if (*(char *)(puVar1 + 0x32) == '\x01') {
    *(undefined1 *)(puVar1 + 0x32) = 2;
    return;
  }
  FUN_0100fb00(*puVar1,(int)(puVar1 + 0x18),(undefined4 *)(puVar1 + 0xe7));
  return;
}


