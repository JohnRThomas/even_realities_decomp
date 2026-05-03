/*
 * Function: FUN_01028ae0
 * Entry:    01028ae0
 * Prototype: bool __stdcall FUN_01028ae0(int param_1)
 */


bool FUN_01028ae0(int param_1)

{
  if (*(char *)(param_1 + 0xe4) != '\0') {
    return false;
  }
  return (*(byte *)(param_1 + 0x31c) & 0xfb) != 0;
}


