/*
 * Function: FUN_00027204
 * Entry:    00027204
 * Prototype: int __stdcall FUN_00027204(void * param_1, ushort param_2)
 */


int FUN_00027204(void *param_1,ushort param_2)

{
  int iVar1;
  
  iVar1 = FUN_0007f738((uint)param_2,param_1);
  if (iVar1 == -1) {
    DAT_200083f4 = 0x14040e1;
    iVar1 = FUN_00027194();
    FUN_0007f738((uint)param_2,param_1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


