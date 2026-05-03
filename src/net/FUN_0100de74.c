/*
 * Function: FUN_0100de74
 * Entry:    0100de74
 * Prototype: int __stdcall FUN_0100de74(int param_1, undefined * param_2)
 */


int FUN_0100de74(int param_1,undefined *param_2)

{
  int iVar1;
  
  if (param_2 < &DAT_00001d4c) {
    iVar1 = 100;
  }
  else {
    iVar1 = 0x4e2;
  }
  return iVar1 * param_1;
}


