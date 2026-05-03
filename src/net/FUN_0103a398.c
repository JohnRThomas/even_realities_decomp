/*
 * Function: FUN_0103a398
 * Entry:    0103a398
 * Prototype: int __stdcall FUN_0103a398(uint * param_1, int * param_2)
 */


int FUN_0103a398(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1[4] & 8) == 0) {
    uVar2 = *param_1;
    if (uVar2 < param_1[3]) {
      iVar1 = 0;
      iVar3 = param_1[3] - uVar2;
    }
    else {
      iVar1 = 1;
      iVar3 = param_1[9] - uVar2;
    }
  }
  else {
    iVar1 = 0;
    iVar3 = iVar1;
  }
  *param_2 = iVar3;
  return iVar1;
}


