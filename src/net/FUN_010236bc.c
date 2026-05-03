/*
 * Function: FUN_010236bc
 * Entry:    010236bc
 * Prototype: undefined1 __stdcall FUN_010236bc(uint param_1)
 */


undefined1 FUN_010236bc(uint param_1)

{
  if (((param_1 < 0x20) && ((&DAT_21001740)[(param_1 + (uint)DAT_21001739 * 0x20) * 2] != '\0')) &&
     ((&DAT_21001740)[(param_1 + (uint)DAT_21001739 * 0x20) * 2] == '\x01')) {
    (&DAT_21001740)[(param_1 + (uint)DAT_21001739 * 0x20) * 2] = 0;
    return 1;
  }
  return 0;
}


