/*
 * Function: onoff_stop
 * Entry:    00063808
 * Prototype: undefined __stdcall onoff_stop(int param_1, undefined * UNRECOVERED_JUMPTABLE)
 */


/* exclude_from_export */

void onoff_stop(int param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  undefined4 uVar1;
  
  uVar1 = stop(0x8b2e0,(byte)(param_1 + -0x2000ba80 >> 5),0x40);
                    /* WARNING: Could not recover jumptable at 0x00063826. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)(param_1,uVar1);
  return;
}


