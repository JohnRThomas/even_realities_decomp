/*
 * Function: FUN_01009bb8
 * Entry:    01009bb8
 * Prototype: undefined4 __stdcall FUN_01009bb8(void)
 */


undefined4 FUN_01009bb8(void)

{
  undefined4 uVar1;
  
  FUN_01009ae4();
  uVar1 = FUN_01029060();
  if (DAT_21000b78 != (code *)0x0) {
    (*DAT_21000b78)();
  }
  return uVar1;
}


