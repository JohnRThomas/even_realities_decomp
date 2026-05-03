/*
 * Function: FUN_0102a312
 * Entry:    0102a312
 * Prototype: bool __stdcall FUN_0102a312(int param_1)
 */


bool FUN_0102a312(int param_1)

{
  if (*(char *)(param_1 + 0x10) != '\x02') {
    return *(char *)(param_1 + 0x10) == '\x03';
  }
  return true;
}


