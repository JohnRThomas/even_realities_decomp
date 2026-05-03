/*
 * Function: FUN_01037650
 * Entry:    01037650
 * Prototype: undefined4 __stdcall FUN_01037650(undefined * param_1)
 */


undefined4 FUN_01037650(undefined *param_1)

{
  if (*(ushort *)(param_1 + 0xe) < 0x80) {
    if (DAT_21004b64 == 0) {
      return 0;
    }
    if ((DAT_21004b60 <= (char)param_1[0xe]) && ((param_1[0xd] & 0x1f) == 0)) {
      if (param_1 == &DAT_210043a8) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}


