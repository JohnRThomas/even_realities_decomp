/*
 * Function: FUN_010267d4
 * Entry:    010267d4
 * Prototype: undefined __stdcall FUN_010267d4(uint param_1, int param_2)
 */


void FUN_010267d4(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_01009b0c(param_1);
  if ((uVar1 != 0) && (param_1 == 0x3e)) {
    FUN_01009b8c(param_2);
    return;
  }
  return;
}


