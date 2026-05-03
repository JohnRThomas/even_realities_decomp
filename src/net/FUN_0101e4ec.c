/*
 * Function: FUN_0101e4ec
 * Entry:    0101e4ec
 * Prototype: bool __stdcall FUN_0101e4ec(int param_1)
 */


bool FUN_0101e4ec(int param_1)

{
  if ((*(int *)(param_1 + 0x1c) == 0) && (*(int *)(param_1 + 0x18) == 0)) {
    return DAT_2100113c == param_1;
  }
  return true;
}


