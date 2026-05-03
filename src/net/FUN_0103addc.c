/*
 * Function: FUN_0103addc
 * Entry:    0103addc
 * Prototype: bool __stdcall FUN_0103addc(int * param_1)
 */


bool FUN_0103addc(int *param_1)

{
  bool bVar1;
  
  if (*(int *)(*param_1 + 0x158) == 0) {
    bVar1 = false;
    if (-1 < param_1[1] << 0x1e) {
      return *(int *)(*param_1 + 0x120) != 0;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


