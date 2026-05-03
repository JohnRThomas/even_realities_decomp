/*
 * Function: FUN_010104dc
 * Entry:    010104dc
 * Prototype: undefined4 __stdcall FUN_010104dc(int param_1)
 */


undefined4 FUN_010104dc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(char *)(iVar1 + 0xc5) != '\x18') {
    return 2;
  }
  FUN_010110b8(iVar1 + 0x33b,iVar1 + 0x34b,0,(undefined4 *)(iVar1 + 0x130));
  iVar1 = *(int *)(param_1 + 4);
  *(undefined1 *)(iVar1 + 0xca) = 1;
  *(undefined1 *)(iVar1 + 0xc5) = 0x1a;
  *(undefined4 *)(iVar1 + 0x120) = 0;
  *(undefined4 *)(iVar1 + 0x124) = 0;
  return 0;
}


