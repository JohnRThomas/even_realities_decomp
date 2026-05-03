/*
 * Function: FUN_0101006c
 * Entry:    0101006c
 * Prototype: undefined4 __stdcall FUN_0101006c(int param_1, int param_2)
 */


undefined4 FUN_0101006c(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = FUN_0100dbc0(iVar2 + 0xa8,0,(uint)*(byte *)(iVar2 + 0xc6),0);
  if (uVar1 != 0) {
    *(undefined1 *)(iVar2 + 0x148) = *(undefined1 *)(param_2 + 3);
    *(undefined2 *)(iVar2 + 0x102) = 0;
    *(undefined1 *)(iVar2 + 0xc6) = 3;
    *(undefined1 *)(iVar2 + 0x104) = 1;
    return 0;
  }
  return 1;
}


