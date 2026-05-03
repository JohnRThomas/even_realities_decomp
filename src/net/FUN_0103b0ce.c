/*
 * Function: FUN_0103b0ce
 * Entry:    0103b0ce
 * Prototype: uint __stdcall FUN_0103b0ce(uint param_1)
 */


uint FUN_0103b0ce(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint extraout_r1;
  
  uVar1 = FUN_01034cc8(param_1);
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = FUN_01034c94(extraout_r1);
  }
  return uVar2 & 1;
}


