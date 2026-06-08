/*
 * Function: FUN_0002df54
 * Entry:    0002df54
 * Prototype: int __stdcall FUN_0002df54(int param_1, int param_2)
 */


int FUN_0002df54(int param_1,int param_2)

{
  if (param_1 != 0xb) {
    if (param_1 == 0xc) {
      param_2 = 1;
    }
    return param_2;
  }
                    /* 31536000 = 1 year in seconds */
  return 31536000;
}


