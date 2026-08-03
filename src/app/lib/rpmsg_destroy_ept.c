/*
 * Function: rpmsg_destroy_ept
 * Entry:    00089124
 * Prototype: void __stdcall rpmsg_destroy_ept(rpmsg_endpoint * ept)
 */


/* exclude_from_export */

void rpmsg_destroy_ept(rpmsg_endpoint *ept)

{
  int iVar1;
  
  if ((ept != (rpmsg_endpoint *)0x0) && (iVar1 = *(int *)((int)&ept[1].rdev + 2), iVar1 != 0)) {
    if (((ept->name_RPMSG_NAME_SIZE_ != '\0') && (*(char *)(iVar1 + 0x90) != '\0')) &&
       (0x3ff < *(uint *)((int)&ept[1].addr + 2))) {
      rpmsg_send_ns_message(ept,1);
    }
    rpmsg_unregister_endpoint(ept);
    return;
  }
  return;
}


