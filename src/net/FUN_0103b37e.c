/*
 * Function: FUN_0103b37e
 * Entry:    0103b37e
 * Prototype: int __stdcall FUN_0103b37e(int * param_1, uint param_2)
 */


int FUN_0103b37e(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((code *)param_1[0xd] == (code *)0x0) {
    if (param_1[4] == 0xffffffff) {
      uVar3 = param_2 - *(int *)param_1[1];
    }
    else {
      uVar3 = param_1[4] & param_2;
    }
    do {
      uVar1 = FUN_0103b346((int)param_1,uVar3);
      if (param_2 == uVar1) goto LAB_0103b3b2;
      uVar3 = uVar3 + param_1[4] + 1;
    } while (uVar3 < (uint)param_1[2]);
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = (*(code *)param_1[0xd])();
  }
LAB_0103b3b2:
  if ((*param_1 == -1) || ((uint)param_1[2] <= uVar3)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *param_1 + uVar3;
  }
  return iVar2;
}


