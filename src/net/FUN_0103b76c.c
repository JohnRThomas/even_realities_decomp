/*
 * Function: FUN_0103b76c
 * Entry:    0103b76c
 * Prototype: undefined __stdcall FUN_0103b76c(int param_1, int param_2)
 */


void FUN_0103b76c(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + -8) & 0xffff;
  FUN_0103b686((int *)(param_1 + 0x58),param_2);
  uVar1 = FUN_0103b406(*(int *)(param_1 + 0xa4),uVar2);
  if (*(int *)(*(int *)(param_1 + 0xa0) + 0x18) == 1) {
    FUN_01035bac(*(int *)(param_1 + 0xa4),uVar2,uVar1);
  }
  FUN_0103b48a(*(int **)(param_1 + 0xa4));
  FUN_01036fe4((int *)(param_1 + 0x58));
  return;
}


