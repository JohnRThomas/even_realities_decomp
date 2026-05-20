/*
 * Function: FUN_000824ea
 * Entry:    000824ea
 * Prototype: undefined __stdcall FUN_000824ea(int * param_1)
 */


void FUN_000824ea(int *param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0xe0);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000824f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,*(undefined4 *)(*param_1 + 0xdc));
    return;
  }
  return;
}


