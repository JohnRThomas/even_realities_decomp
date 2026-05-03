/*
 * Function: FUN_01039f80
 * Entry:    01039f80
 * Prototype: uint __stdcall FUN_01039f80(uint param_1, int param_2)
 */


uint FUN_01039f80(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_1 < 0x8000) {
    iVar1 = 4;
  }
  else {
    iVar1 = 8;
  }
  return (uint)(param_2 + 7 + iVar1) >> 3;
}


