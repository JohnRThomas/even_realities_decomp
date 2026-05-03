/*
 * Function: FUN_00082d88
 * Entry:    00082d88
 * Prototype: undefined __stdcall FUN_00082d88(undefined4 param_1, undefined4 param_2, int param_3)
 */


void FUN_00082d88(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_3 + 0x10);
  atomic_clear_bit((atomic_t *)(param_3 + -0x10),2);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00082da8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_3 + -0x14,param_2);
    return;
  }
  return;
}


