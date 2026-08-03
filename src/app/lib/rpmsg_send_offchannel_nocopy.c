/*
 * Function: rpmsg_send_offchannel_nocopy
 * Entry:    000741f0
 * Prototype: int __stdcall rpmsg_send_offchannel_nocopy(rpmsg_endpoint * ept, uint32_t src, uint32_t dst, void * data, int len)
 */


/* exclude_from_export_ai */

int rpmsg_send_offchannel_nocopy(rpmsg_endpoint *ept,uint32_t src,uint32_t dst,void *data,int len)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((((ept != (rpmsg_endpoint *)0x0) && (iVar1 = *(int *)((int)&ept[1].rdev + 2), iVar1 != 0)) &&
      (data != (void *)0x0)) &&
     (((dst != 0xffffffff && (-1 < len)) &&
      (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x88), UNRECOVERED_JUMPTABLE != (code *)0x0)))) {
                    /* WARNING: Could not recover jumptable at 0x00074210. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return -0x7d3;
}


