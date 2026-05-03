/*
 * Function: FUN_010109dc
 * Entry:    010109dc
 * Prototype: undefined4 __stdcall FUN_010109dc(byte * param_1)
 */


undefined4 FUN_010109dc(byte *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = FUN_0100dbc0(iVar2 + 0xa8,9,(uint)*(byte *)(iVar2 + 0xc5),(uint)*param_1);
  if (uVar1 != 0) {
    *(undefined1 *)(iVar2 + 0xf4) = 0;
    *(undefined1 *)(iVar2 + 0x100) = 0;
    *(undefined1 *)(iVar2 + 0xc5) = 0;
  }
  return 0;
}


