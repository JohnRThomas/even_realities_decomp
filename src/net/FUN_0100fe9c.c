/*
 * Function: FUN_0100fe9c
 * Entry:    0100fe9c
 * Prototype: int __stdcall FUN_0100fe9c(int param_1, int param_2)
 */


int FUN_0100fe9c(int param_1,int param_2)

{
  if (param_1 < 0) {
    param_2 = -param_2;
    if (param_1 < param_2) goto LAB_0100feac;
  }
  else if (param_2 <= param_1) {
LAB_0100feac:
    return (int)(short)param_2;
  }
  return param_1;
}


