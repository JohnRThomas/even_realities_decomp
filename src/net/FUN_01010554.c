/*
 * Function: FUN_01010554
 * Entry:    01010554
 * Prototype: undefined4 __stdcall FUN_01010554(int param_1)
 */


undefined4 FUN_01010554(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(char *)(iVar1 + 0xc5) == '\x11') {
    *(undefined1 *)(iVar1 + 0xca) = 0;
    *(undefined1 *)(iVar1 + 0xc5) = 0x14;
    return 0;
  }
  return 2;
}


