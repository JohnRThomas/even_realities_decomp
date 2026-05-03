/*
 * Function: FUN_010270ce
 * Entry:    010270ce
 * Prototype: undefined1 __stdcall FUN_010270ce(ushort param_1, ushort param_2)
 */


undefined1 FUN_010270ce(ushort param_1,ushort param_2)

{
  undefined1 uVar1;
  
  if ((((param_2 ^ param_1) & 0x7fff) == 0) && ((short)(param_2 ^ param_1) < 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


