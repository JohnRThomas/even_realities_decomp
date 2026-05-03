/*
 * Function: FUN_01010140
 * Entry:    01010140
 * Prototype: undefined __stdcall FUN_01010140(byte * param_1)
 */


void FUN_01010140(byte *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = FUN_0100dbc0(iVar2 + 0xa8,1,(uint)*(byte *)(iVar2 + 199),(uint)*param_1);
  if (uVar1 == 0) {
    *(undefined1 *)(iVar2 + 199) = 8;
  }
  return;
}


