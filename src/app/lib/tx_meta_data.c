/*
 * Function: tx_meta_data
 * Entry:    00085a66
 * Prototype: undefined __stdcall tx_meta_data(undefined4 param_1, int * param_2)
 */


/* exclude_from_export_ai */

void tx_meta_data(undefined4 param_1,int *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*param_2 + 0xc) + 0x18);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00085a70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*param_2 + 8);
    return;
  }
  return;
}


