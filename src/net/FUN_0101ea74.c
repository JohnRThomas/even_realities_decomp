/*
 * Function: FUN_0101ea74
 * Entry:    0101ea74
 * Prototype: undefined __stdcall FUN_0101ea74(int param_1)
 */


void FUN_0101ea74(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x94) = 0;
  *(undefined4 *)(iVar1 + 0x98) = 0;
  *(undefined4 *)(iVar1 + 0x9c) = 0;
  *(undefined4 *)(iVar1 + 0x8c) = 0;
  *(undefined4 *)(iVar1 + 0x90) = 0;
  *(undefined4 *)(iVar1 + 0x9f) = 0;
  *(undefined2 *)(iVar1 + 0x1a4) = 0;
  *(undefined1 *)(iVar1 + 0x1a6) = 0;
  *(undefined2 *)(iVar1 + 0x1a7) = 0;
  *(undefined1 *)(iVar1 + 0x1a9) = 0;
  *(undefined1 *)(iVar1 + 0x95) = 0x7f;
  *(undefined1 *)(iVar1 + 0x97) = 0x7f;
  *(undefined1 *)(iVar1 + 0x99) = 0x7f;
  *(undefined1 *)(iVar1 + 0x9b) = 0x7f;
  FUN_0101e9e4(iVar1,(int)*(char *)(iVar1 + 0x72));
  *(undefined4 *)(iVar1 + 0x9c) = 0xffffffff;
  return;
}


