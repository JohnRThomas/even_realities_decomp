/*
 * Function: FUN_0103aa8c
 * Entry:    0103aa8c
 * Prototype: uint __stdcall FUN_0103aa8c(undefined1 * param_1, uint param_2, int * param_3)
 */


uint FUN_0103aa8c(undefined1 *param_1,uint param_2,int *param_3)

{
  if ((uint)(param_3[1] - param_3[2]) < param_2) {
    param_2 = 0xffffffe4;
  }
  else {
    FUN_0103bdd4(*param_3 + param_3[2],param_1,param_2);
    param_3[2] = param_3[2] + param_2;
  }
  return param_2;
}


