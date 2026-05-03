/*
 * Function: FUN_01039f92
 * Entry:    01039f92
 * Prototype: int __stdcall FUN_01039f92(uint param_1)
 */


int FUN_01039f92(uint param_1)

{
  uint uVar1;
  int extraout_r2;
  
  uVar1 = FUN_01039f80(param_1,1);
  return 0x1f - LZCOUNT((extraout_r2 + 1) - uVar1);
}


