/*
 * Function: FUN_01010118
 * Entry:    01010118
 * Prototype: undefined4 __stdcall FUN_01010118(byte * param_1, int param_2)
 */


undefined4 FUN_01010118(byte *param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  uVar2 = FUN_0100dbc0(iVar3 + 0xa8,1,(uint)*(byte *)(iVar3 + 199),(uint)*param_1);
  if (uVar2 == 0) {
    uVar1 = FUN_0100ef28(param_2);
    *(undefined1 *)(iVar3 + 200) = uVar1;
    *(undefined1 *)(iVar3 + 199) = 7;
  }
  return 0;
}


