/*
 * Function: FUN_01027d1a
 * Entry:    01027d1a
 * Prototype: int __stdcall FUN_01027d1a(ushort * param_1, ushort param_2, byte param_3)
 */


int FUN_01027d1a(ushort *param_1,ushort param_2,byte param_3)

{
  int iVar1;
  
  param_1[param_3 + 5] = param_2;
  iVar1 = FUN_01027cea(param_1,param_3);
  return iVar1;
}


