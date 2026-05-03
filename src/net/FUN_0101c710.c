/*
 * Function: FUN_0101c710
 * Entry:    0101c710
 * Prototype: undefined __stdcall FUN_0101c710(int param_1)
 */


void FUN_0101c710(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(char *)(iVar1 + 0x150) != '\0') {
    *(undefined1 *)(iVar1 + 0xc5) = 0;
    *(undefined1 *)(iVar1 + 0x100) = 0;
    return;
  }
  *(undefined1 *)(iVar1 + 0xc6) = 0;
  *(undefined1 *)(iVar1 + 0x104) = 0;
  return;
}


