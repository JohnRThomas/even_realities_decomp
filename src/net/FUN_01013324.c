/*
 * Function: FUN_01013324
 * Entry:    01013324
 * Prototype: uint __stdcall FUN_01013324(byte * param_1)
 */


uint FUN_01013324(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1[2];
  return ((-((int)(uVar1 << 0x1d) >> 0x1f) - ((int)(uVar1 << 0x1e) >> 0x1f)) + (uVar1 & 1)) *
         (uint)param_1[1] * (uint)*param_1 & 0xff;
}


