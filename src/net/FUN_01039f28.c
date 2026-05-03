/*
 * Function: FUN_01039f28
 * Entry:    01039f28
 * Prototype: uint __stdcall FUN_01039f28(int param_1, int param_2)
 */


uint FUN_01039f28(int param_1,int param_2)

{
  uint uVar1;
  uint extraout_r2;
  
  uVar1 = FUN_01039efc(param_1,param_2,1);
  return uVar1 >> (extraout_r2 & 0xff);
}


