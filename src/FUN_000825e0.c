/*
 * Function: FUN_000825e0
 * Entry:    000825e0
 * Prototype: uint __stdcall FUN_000825e0(void * param_1, uint param_2, int * param_3)
 */


uint FUN_000825e0(void *param_1,uint param_2,int *param_3)

{
  if ((uint)(param_3[1] - param_3[2]) < param_2) {
    param_2 = 0xffffffe4;
  }
  else {
    memcpy((void *)(*param_3 + param_3[2]),param_1,param_2);
    param_3[2] = param_3[2] + param_2;
  }
  return param_2;
}


