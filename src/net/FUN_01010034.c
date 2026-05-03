/*
 * Function: FUN_01010034
 * Entry:    01010034
 * Prototype: undefined4 __stdcall FUN_01010034(int param_1, int param_2)
 */


undefined4 FUN_01010034(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((*(uint *)(iVar2 + 0xb4) & 8) == 0) {
    *(uint *)(iVar2 + 0xb4) = *(uint *)(iVar2 + 0xb4) | 8;
    uVar1 = *(undefined1 *)(param_2 + 3);
    *(undefined2 *)(iVar2 + 0x102) = 0;
    *(undefined1 *)(iVar2 + 0x148) = uVar1;
    *(char *)(iVar2 + 0x104) = *(char *)(iVar2 + 0x104) + '\x01';
    return 0;
  }
  return 1;
}


