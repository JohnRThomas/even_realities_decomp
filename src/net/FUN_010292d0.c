/*
 * Function: FUN_010292d0
 * Entry:    010292d0
 * Prototype: undefined4 __stdcall FUN_010292d0(undefined4 * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_010292d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_01028d28(1,param_2,param_3);
  if (bVar1) {
    FUN_0100b1d4(1,param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}


