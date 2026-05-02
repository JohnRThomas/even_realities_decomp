/*
 * Function: FUN_00080fb2
 * Entry:    00080fb2
 * Prototype: undefined4 __stdcall FUN_00080fb2(uint param_1)
 */


undefined4 FUN_00080fb2(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (0x1f < param_1) {
    uVar1 = 0;
  }
  return uVar1;
}


