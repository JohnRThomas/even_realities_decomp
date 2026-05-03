/*
 * Function: FUN_010292ac
 * Entry:    010292ac
 * Prototype: undefined4 __stdcall FUN_010292ac(undefined4 * param_1)
 */


undefined4 FUN_010292ac(undefined4 *param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  cVar1 = FUN_01020044();
  if ((cVar1 == '\0') || (bVar2 = FUN_01028d28(0,extraout_r1,extraout_r2), bVar2)) {
    FUN_0100b1d4(0,param_1);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc;
  }
  return uVar3;
}


