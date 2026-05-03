/*
 * Function: FUN_010236a8
 * Entry:    010236a8
 * Prototype: uint __stdcall FUN_010236a8(void)
 */


uint FUN_010236a8(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = FUN_01024e44();
  uVar2 = FUN_01024dd8((uint)uVar1);
  uVar2 = FUN_01024c40(uVar2);
  return uVar2 & 0xffff;
}


