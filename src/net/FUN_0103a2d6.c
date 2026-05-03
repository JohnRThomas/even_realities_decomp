/*
 * Function: FUN_0103a2d6
 * Entry:    0103a2d6
 * Prototype: int __stdcall FUN_0103a2d6(int param_1, int param_2)
 */


int FUN_0103a2d6(int param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 == 0) || (param_2 == 0)) ||
     ((iVar1 = FUN_0103a348((int *)(param_2 + 4)), iVar1 == 0 && (3 < *(uint *)(param_2 + 8))))) {
    iVar1 = -0x16;
  }
  return iVar1;
}


