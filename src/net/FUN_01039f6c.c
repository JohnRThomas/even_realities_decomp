/*
 * Function: FUN_01039f6c
 * Entry:    01039f6c
 * Prototype: uint __stdcall FUN_01039f6c(int param_1, int param_2)
 */


uint FUN_01039f6c(int param_1,int param_2)

{
  int iVar1;
  
  if (*(uint *)(param_1 + 8) < 0x8000) {
    iVar1 = 4;
  }
  else {
    iVar1 = 8;
  }
  return (uint)((param_2 - iVar1) - param_1) >> 3;
}


