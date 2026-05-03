/*
 * Function: FUN_010099cc
 * Entry:    010099cc
 * Prototype: undefined4 __stdcall FUN_010099cc(int param_1)
 */


undefined4 FUN_010099cc(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_21000a5c == '\0') {
    FUN_0101f14c(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


