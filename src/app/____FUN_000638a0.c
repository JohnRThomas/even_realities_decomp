/*
 * Function: $_?_FUN_000638a0
 * Entry:    000638a0
 * Prototype: undefined __stdcall $_?_FUN_000638a0(int param_1)
 */


void ____FUN_000638a0(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(&DAT_2000bb00)[param_1 * 3];
  (&DAT_2000bb00)[param_1 * 3] = 0;
  set_on_state(&DAT_2000bb08 + param_1 * 3);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000638ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(&PTR_s_clock_5000_0008b2e0);
    return;
  }
  return;
}


