/*
 * Function: FUN_01027fc2
 * Entry:    01027fc2
 * Prototype: uint __stdcall FUN_01027fc2(ushort param_1, short param_2)
 */


uint FUN_01027fc2(ushort param_1,short param_2)

{
  int iVar1;
  
  iVar1 = FUN_01027f1a(param_1,10,param_2);
  return iVar1 + 3U & 0xfffc;
}


