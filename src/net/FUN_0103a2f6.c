/*
 * Function: FUN_0103a2f6
 * Entry:    0103a2f6
 * Prototype: undefined __stdcall FUN_0103a2f6(undefined4 param_1, int param_2, undefined4 param_3, int param_4)
 */


void FUN_0103a2f6(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_0102d344((int *)(param_2 + 4),param_4);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0103a31c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
    return;
  }
  return;
}


