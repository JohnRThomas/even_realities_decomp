/*
 * Function: rpmsg_hold_rx_buffer
 * Entry:    0008907a
 * Prototype: void __stdcall rpmsg_hold_rx_buffer(rpmsg_endpoint * ept, void * rxbuf)
 */


/* exclude_from_export_ai */

void rpmsg_hold_rx_buffer(rpmsg_endpoint *ept,void *rxbuf)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((((ept != (rpmsg_endpoint *)0x0) && (iVar1 = *(int *)((int)&ept[1].rdev + 2), iVar1 != 0)) &&
      (rxbuf != (void *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x7c), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00089086. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}


