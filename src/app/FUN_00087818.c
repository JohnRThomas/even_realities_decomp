/*
 * Function: FUN_00087818
 * Entry:    00087818
 * Prototype: undefined4 __stdcall FUN_00087818(int param_1, int param_2, int param_3)
 */


undefined4 FUN_00087818(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 8) + 0x10);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    uVar1 = 0xffffffa8;
  }
  else {
    if ((param_2 <= (*(int **)(param_1 + 4))[1]) && (**(int **)(param_1 + 4) <= param_3)) {
                    /* WARNING: Could not recover jumptable at 0x00087830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


