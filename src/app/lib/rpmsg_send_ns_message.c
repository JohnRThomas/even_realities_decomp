/*
 * Function: rpmsg_send_ns_message
 * Entry:    00089048
 * Prototype: int __stdcall rpmsg_send_ns_message(rpmsg_endpoint * ept, ulong flags)
 */


/* exclude_from_export */

int rpmsg_send_ns_message(rpmsg_endpoint *ept,ulong flags)

{
  uint uVar1;
  undefined4 uVar2;
  char acStack_38 [32];
  undefined4 local_18;
  ulong local_14;
  
  uVar2 = *(undefined4 *)((int)&ept[1].addr + 2);
  local_18 = uVar2;
  local_14 = flags;
  strcpy(acStack_38,&ept->name_RPMSG_NAME_SIZE_);
  uVar1 = rpmsg_send_offchannel_raw((int)ept,uVar2,0x35,(int)acStack_38,0x28);
  return uVar1 & (int)uVar1 >> 0x1f;
}


