/*
 * Function: rpmsg_get_tx_payload_buffer
 * Entry:    0008909c
 * Prototype: void * __stdcall rpmsg_get_tx_payload_buffer(rpmsg_endpoint * ept, uint32_t * len, int wait)
 */


/* exclude_from_export_ai */

void * rpmsg_get_tx_payload_buffer(rpmsg_endpoint *ept,uint32_t *len,int wait)

{
  int iVar1;
  void *pvVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((((ept != (rpmsg_endpoint *)0x0) && (iVar1 = *(int *)((int)&ept[1].rdev + 2), iVar1 != 0)) &&
      (len != (uint32_t *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x84), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000890aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pvVar2 = (void *)(*UNRECOVERED_JUMPTABLE)();
    return pvVar2;
  }
  return (void *)0x0;
}


