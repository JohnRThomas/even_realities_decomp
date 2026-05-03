/*
 * Function: FUN_0100d400
 * Entry:    0100d400
 * Prototype: bool __stdcall FUN_0100d400(uint param_1)
 */


bool FUN_0100d400(uint param_1)

{
  if (param_1 < DAT_21000d19) {
    return (&DAT_21000e52)[param_1] == '\0';
  }
  return false;
}


