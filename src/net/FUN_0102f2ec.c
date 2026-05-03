/*
 * Function: FUN_0102f2ec
 * Entry:    0102f2ec
 * Prototype: undefined __stdcall FUN_0102f2ec(char param_1)
 */


void FUN_0102f2ec(char param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(&DAT_e000e100 + (uVar1 >> 5) * 4) = 1 << (uVar1 & 0x1f);
  }
  return;
}


