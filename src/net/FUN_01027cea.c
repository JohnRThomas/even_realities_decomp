/*
 * Function: FUN_01027cea
 * Entry:    01027cea
 * Prototype: int __stdcall FUN_01027cea(ushort * param_1, byte param_2)
 */


int FUN_01027cea(ushort *param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = FUN_01027cd0((byte)param_1[1]);
  return (uint)*param_1 * (uint)param_2 + iVar1 + (int)param_1;
}


