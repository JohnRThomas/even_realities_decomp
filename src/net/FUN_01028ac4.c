/*
 * Function: FUN_01028ac4
 * Entry:    01028ac4
 * Prototype: bool __stdcall FUN_01028ac4(int param_1)
 */


bool FUN_01028ac4(int param_1)

{
  if (*(char *)(param_1 + 0xe4) != '\0') {
    return false;
  }
  return (*(byte *)(param_1 + 0x300) & 0xfb) != 0;
}


