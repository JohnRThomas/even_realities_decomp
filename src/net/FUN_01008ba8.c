/*
 * Function: FUN_01008ba8
 * Entry:    01008ba8
 * Prototype: undefined __stdcall FUN_01008ba8(int * param_1, int * param_2, int param_3)
 */


void FUN_01008ba8(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 4;
  do {
    iVar3 = *param_2;
    iVar4 = param_2[1];
    uVar1 = *param_1 - iVar3 & -param_3;
    uVar2 = param_1[1] - iVar4 & -param_3;
    *param_1 = *param_1 - uVar1;
    param_1[1] = param_1[1] - uVar2;
    param_1 = param_1 + 2;
    *param_2 = iVar3 + uVar1;
    param_2[1] = iVar4 + uVar2;
    param_2 = param_2 + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


