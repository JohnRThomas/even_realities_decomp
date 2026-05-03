/*
 * Function: FUN_0100fdb4
 * Entry:    0100fdb4
 * Prototype: uint __stdcall FUN_0100fdb4(uint * param_1, int param_2)
 */


uint FUN_0100fdb4(uint *param_1,int param_2)

{
  if (param_2 + 0x9cU < *param_1) {
    return (*param_1 - param_2) - 0x9c >> 1;
  }
  return 0;
}


