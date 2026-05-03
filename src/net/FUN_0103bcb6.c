/*
 * Function: FUN_0103bcb6
 * Entry:    0103bcb6
 * Prototype: undefined __stdcall FUN_0103bcb6(int * param_1, uint param_2)
 */


void FUN_0103bcb6(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (param_1 != piVar1) {
    iVar3 = *piVar1;
    piVar2 = (int *)piVar1[1];
    *piVar2 = iVar3;
    *(int **)(iVar3 + 4) = piVar2;
    *piVar1 = 0;
    piVar1[1] = 0;
    FUN_0103bc02((int)piVar1,param_2);
    return;
  }
  return;
}


