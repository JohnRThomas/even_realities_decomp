/*
 * Function: FUN_0103b692
 * Entry:    0103b692
 * Prototype: undefined4 __stdcall FUN_0103b692(int param_1, int param_2)
 */


undefined4 FUN_0103b692(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_2 + -8);
  FUN_0103b686((int *)(param_1 + 0x58),param_2);
  *(short *)(param_2 + -8) = (short)uVar1;
  *(undefined4 *)(param_2 + -0xc) = *(undefined4 *)(param_1 + 0xb8);
  *(int *)(param_2 + -0x10) = param_1 + 0xb4;
  *(int *)(param_1 + 0xb8) = param_2 + -0x10;
  **(int **)(param_2 + -0xc) = param_2 + -0x10;
  FUN_01036fe4((int *)(param_1 + 0x58));
  return 0;
}


