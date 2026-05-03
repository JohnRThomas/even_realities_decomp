/*
 * Function: FUN_01028332
 * Entry:    01028332
 * Prototype: short __stdcall FUN_01028332(ushort param_1)
 */


short FUN_01028332(ushort param_1)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = FUN_0102830c(param_1);
  if ((int)((uint)param_1 - (uint)uVar1) < 0x672) {
    sVar2 = param_1 - uVar1;
  }
  else {
    sVar2 = 0x672;
  }
  return sVar2;
}


