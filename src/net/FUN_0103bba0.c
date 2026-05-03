/*
 * Function: FUN_0103bba0
 * Entry:    0103bba0
 * Prototype: undefined __stdcall FUN_0103bba0(int * param_1, int * param_2, int param_3)
 */


void FUN_0103bba0(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if ((param_1 != (int *)*param_1) && (param_1[1] != 0)) {
    iVar1 = *(int *)(param_1[1] + 8);
    if (iVar1 != 0) {
      iVar1 = iVar1 + -0x60;
    }
    iVar1 = FUN_0103ba4a(iVar1,param_3 + -0x60);
    if ((iVar1 < 1) && (piVar3 = (int *)*param_1, param_1 != piVar3)) {
      for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
        iVar1 = piVar3[2];
        if (iVar1 != 0) {
          iVar1 = iVar1 + -0x60;
        }
        iVar1 = FUN_0103ba4a(param_3 + -0x60,iVar1);
        if (0 < iVar1) {
          puVar2 = (undefined4 *)piVar3[1];
          *param_2 = (int)piVar3;
          param_2[1] = (int)puVar2;
          *puVar2 = param_2;
          piVar3[1] = (int)param_2;
          return;
        }
        if (piVar3 == (int *)param_1[1]) break;
      }
    }
  }
  puVar2 = (undefined4 *)param_1[1];
  *param_2 = (int)param_1;
  param_2[1] = (int)puVar2;
  *puVar2 = param_2;
  param_1[1] = (int)param_2;
  return;
}


