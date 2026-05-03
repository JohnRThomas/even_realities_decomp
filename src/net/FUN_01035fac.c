/*
 * Function: FUN_01035fac
 * Entry:    01035fac
 * Prototype: int __stdcall FUN_01035fac(int param_1, undefined4 param_2)
 */


int FUN_01035fac(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    return -0x7d3;
  }
  FUN_0103b686((int *)(param_1 + 0x58),param_2);
  if (*(int *)(*(int *)(param_1 + 0xa0) + 0x18) == 1) {
    iVar1 = FUN_0103b4da(*(int *)(param_1 + 0xa8));
    iVar1 = iVar1 + -0x10;
    if (0 < iVar1) goto LAB_01035fc8;
  }
  iVar1 = -0x7d2;
LAB_01035fc8:
  thunk_FUN_01036fe4((int *)(param_1 + 0x58));
  return iVar1;
}


