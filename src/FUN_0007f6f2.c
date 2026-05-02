/*
 * Function: FUN_0007f6f2
 * Entry:    0007f6f2
 * Prototype: undefined4 __stdcall FUN_0007f6f2(char * param_1)
 */


undefined4 FUN_0007f6f2(char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (char *)0x0) {
    if (*param_1 == '\a') {
      uVar1 = 6;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


