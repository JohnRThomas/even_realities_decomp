/*
 * Function: $_?_FUN_0008b12c
 * Entry:    0008b12c
 * Prototype: undefined4 __stdcall $_?_FUN_0008b12c(undefined4 * param_1, undefined1 * param_2, uint param_3)
 */


undefined4 ____FUN_0008b12c(undefined4 *param_1,undefined1 *param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != (undefined1 *)0x0) {
    if (0xff < param_3) {
      *param_1 = 0x8a;
      return 0xffffffff;
    }
    uVar1 = 1;
    *param_2 = (char)param_3;
  }
  return uVar1;
}


