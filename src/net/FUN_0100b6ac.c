/*
 * Function: FUN_0100b6ac
 * Entry:    0100b6ac
 * Prototype: bool __stdcall FUN_0100b6ac(int param_1)
 */


bool FUN_0100b6ac(int param_1)

{
  int iVar1;
  
  if ((char)DAT_21000c6c == '\0') {
    if (param_1 != 1) {
      return false;
    }
  }
  else if (param_1 != 0) {
    return false;
  }
  if ((int)((uint)(byte)DAT_21000cfc << 0x1b) < 0) {
    if ((char)DAT_21000c6c == '\0') goto LAB_0100b702;
    iVar1 = 0;
LAB_0100b6c2:
    if ((int)((uint)DAT_21000c7a << 0x1e) < 0) {
      return *(char *)(DAT_21000cc4 + 3) != '\x02';
    }
  }
  else {
    iVar1 = ((int)((uint)*DAT_21000d00 << 0x1b) >> 0x1f) + 1;
    if ((DAT_21000c80 == 0) && (DAT_21000d04 != 0)) {
      return true;
    }
    if ((char)DAT_21000c6c != '\0') goto LAB_0100b6c2;
  }
  if (iVar1 != 0) {
    return true;
  }
LAB_0100b702:
  return DAT_21000c7a != 0;
}


