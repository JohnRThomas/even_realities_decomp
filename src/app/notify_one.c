/*
 * Function: notify_one
 * Entry:    0008197e
 * Prototype: void __stdcall notify_one(void)
 */


void notify_one(void)

{
  code *UNRECOVERED_JUMPTABLE;
  int in_r1;
  int in_r3;
  
                    /* exclude_from_export */
  UNRECOVERED_JUMPTABLE = (code *)sys_notify_finalize((sys_notify *)(in_r1 + 4),in_r3);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000819a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


