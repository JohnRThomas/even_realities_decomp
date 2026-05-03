/*
 * Function: FUN_01014564
 * Entry:    01014564
 * Prototype: byte __stdcall FUN_01014564(int param_1)
 */


byte FUN_01014564(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_01020af0();
  if ((uVar1 <= DAT_21000f60) && (&DAT_00001d4b < *(undefined **)(param_1 + 0x14))) {
    return DAT_21000f64 ^ 1;
  }
  return 0;
}


