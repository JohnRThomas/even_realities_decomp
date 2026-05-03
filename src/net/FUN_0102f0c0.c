/*
 * Function: FUN_0102f0c0
 * Entry:    0102f0c0
 * Prototype: undefined __stdcall FUN_0102f0c0(undefined4 param_1, undefined4 param_2)
 */


void FUN_0102f0c0(undefined4 param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_0102e588(DAT_2100468c);
                    /* WARNING: Could not recover jumptable at 0x0102f0d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&DAT_0103c928,param_2,0xf);
  return;
}


