/*
 * Function: FUN_0008259c
 * Entry:    0008259c
 * Prototype: uint __stdcall FUN_0008259c(uint * param_1)
 */


uint FUN_0008259c(uint *param_1)

{
  uint uVar1;
  
  if ((int)((uint)(byte)*param_1 << 0x1d) < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (((*param_1 & 0xfffff) >> 9) + (uint)(*(ushort *)((int)param_1 + 2) >> 4) + 0x17 &
            0xfffffff8) >> 2;
  }
  return uVar1;
}


