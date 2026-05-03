/*
 * Function: FUN_0002dd80
 * Entry:    0002dd80
 * Prototype: uint __stdcall FUN_0002dd80(uint param_1)
 */


uint FUN_0002dd80(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 0x15) {
    uVar1 = 0x191a00U >> (param_1 & 0xff) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


