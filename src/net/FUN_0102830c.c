/*
 * Function: FUN_0102830c
 * Entry:    0102830c
 * Prototype: ushort __stdcall FUN_0102830c(ushort param_1)
 */


ushort FUN_0102830c(ushort param_1)

{
  ushort uVar1;
  
  if (param_1 < 0x1fe) {
    uVar1 = param_1 >> 1;
  }
  else {
    uVar1 = 0xff;
  }
  return uVar1;
}


