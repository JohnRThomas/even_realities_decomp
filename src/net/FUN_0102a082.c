/*
 * Function: FUN_0102a082
 * Entry:    0102a082
 * Prototype: undefined4 __stdcall FUN_0102a082(int param_1, int param_2, undefined2 * param_3, undefined2 param_4)
 */


undefined4 FUN_0102a082(int param_1,int param_2,undefined2 *param_3,undefined2 param_4)

{
  if (param_2 == 8) {
    if (param_1 == 1) {
      *param_3 = param_4;
      param_3[1] = 4;
      return 1;
    }
  }
  else if ((param_2 == 4) && (param_1 != 1)) {
    *param_3 = param_4;
    param_3[1] = 8;
    return 1;
  }
  return 0;
}


