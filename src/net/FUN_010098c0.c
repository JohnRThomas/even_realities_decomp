/*
 * Function: FUN_010098c0
 * Entry:    010098c0
 * Prototype: undefined4 __stdcall FUN_010098c0(void)
 */


undefined4 FUN_010098c0(void)

{
  undefined4 uVar1;
  
  if ((DAT_21000a5d == '\0') && (DAT_21000a5c == '\0')) {
    if (DAT_21000a50 == '\0') {
      FUN_0101ffa8();
    }
    else {
      FUN_0101ffe0();
    }
    uVar1 = 0;
    DAT_21000a4f = 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


