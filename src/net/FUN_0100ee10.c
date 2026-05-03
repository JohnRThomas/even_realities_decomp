/*
 * Function: FUN_0100ee10
 * Entry:    0100ee10
 * Prototype: bool __stdcall FUN_0100ee10(int param_1)
 */


bool FUN_0100ee10(int param_1)

{
  if (*(char *)(param_1 + 1) == '\0') {
    return false;
  }
  if (*(byte *)(param_1 + 3) < 0x2b) {
    return (&DAT_0103c150)[*(byte *)(param_1 + 3)] == *(char *)(param_1 + 1);
  }
  return true;
}


