/*
 * Function: FUN_010368cc
 * Entry:    010368cc
 * Prototype: bool __stdcall FUN_010368cc(uint * param_1)
 */


bool FUN_010368cc(uint *param_1)

{
  if (*param_1 != 0) {
    return (*param_1 & 3) != (uint)DAT_21004b38;
  }
  return true;
}


