/*
 * Function: onoff_start
 * Entry:    00063710
 * Prototype: void __stdcall onoff_start(k_thread * thread)
 */


/* exclude_from_export_ai */

void onoff_start(k_thread *thread)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = async_start(0x8b2e0,(byte)((int)&thread[-0x53996a].next_event_link >> 5),0x8700f,
                      UNRECOVERED_JUMPTABLE,0x40);
  if (iVar1 < 0) {
                    /* WARNING: Could not recover jumptable at 0x00063738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(thread);
    return;
  }
  return;
}


