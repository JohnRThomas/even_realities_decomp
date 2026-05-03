/*
 * Function: FUN_01028aac
 * Entry:    01028aac
 * Prototype: uint __stdcall FUN_01028aac(uint param_1)
 */


uint FUN_01028aac(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 1;
  if ((int)(param_1 << 0x1e) < 0) {
    uVar1 = uVar1 | 2;
  }
  if ((int)(param_1 << 0x1d) < 0) {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}


