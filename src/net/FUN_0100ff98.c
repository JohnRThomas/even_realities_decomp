/*
 * Function: FUN_0100ff98
 * Entry:    0100ff98
 * Prototype: undefined __stdcall FUN_0100ff98(int param_1)
 */


void FUN_0100ff98(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined2 *)(iVar1 + 0x102) = 0;
  *(char *)(iVar1 + 0x104) = *(char *)(iVar1 + 0x104) + '\x01';
  return;
}


