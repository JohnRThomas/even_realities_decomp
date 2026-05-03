/*
 * Function: FUN_0103b88c
 * Entry:    0103b88c
 * Prototype: undefined __stdcall FUN_0103b88c(int * param_1, undefined4 param_2)
 */


void FUN_0103b88c(int *param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  
  if (param_1 != (int *)0x0) {
    while (param_1 != (int *)*param_1) {
      FUN_0103b644((char *)((int *)*param_1 + -0xd),param_2);
      param_2 = extraout_r1;
    }
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
  }
  return;
}


