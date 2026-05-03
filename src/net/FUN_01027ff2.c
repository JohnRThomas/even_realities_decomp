/*
 * Function: FUN_01027ff2
 * Entry:    01027ff2
 * Prototype: uint __stdcall FUN_01027ff2(ushort param_1, short param_2)
 */


uint FUN_01027ff2(ushort param_1,short param_2)

{
  int iVar1;
  
  iVar1 = FUN_01027e3a(param_1,9,param_2);
  return iVar1 + 3U & 0xfffc;
}


