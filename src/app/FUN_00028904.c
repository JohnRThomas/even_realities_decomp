/*
 * Function: FUN_00028904
 * Entry:    00028904
 * Prototype: float __stdcall FUN_00028904(int param_1)
 */


float FUN_00028904(int param_1)

{
  if (*(char *)(param_1 + 0x28) == '\0') {
    FUN_0007fe2e(param_1);
  }
  return *(float *)(param_1 + 0x34) * 57.295 + 180.0;
}


