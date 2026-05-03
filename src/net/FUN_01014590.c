/*
 * Function: FUN_01014590
 * Entry:    01014590
 * Prototype: uint __stdcall FUN_01014590(uint * param_1)
 */


uint FUN_01014590(uint *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0100fdb4(param_1,0x27c);
  if (0xa8f < uVar1) {
    uVar1 = 0xa90;
  }
  return uVar1 & 0xffff;
}


