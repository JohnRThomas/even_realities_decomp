/*
 * Function: FUN_01035c10
 * Entry:    01035c10
 * Prototype: undefined4 __stdcall FUN_01035c10(int param_1, undefined4 param_2, int param_3, int param_4, int param_5)
 */


undefined4 FUN_01035c10(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) && (param_4 != 0)) &&
     (((param_3 != -1 && (-1 < param_5)) &&
      (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0x20) + 0x88),
      UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x01035c30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0xfffff82d;
}


