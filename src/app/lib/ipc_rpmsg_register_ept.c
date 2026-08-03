/*
 * Function: ipc_rpmsg_register_ept
 * Entry:    00050364
 * Prototype: int __stdcall ipc_rpmsg_register_ept(ipc_rpmsg_instance * instance, uint role, ipc_rpmsg_ept * ept)
 */


/* exclude_from_export */

int ipc_rpmsg_register_ept(ipc_rpmsg_instance *instance,uint role,ipc_rpmsg_ept *ept)

{
  int iVar1;
  
  if ((instance == (ipc_rpmsg_instance *)0x0) || (ept == (ipc_rpmsg_ept *)0x0)) {
    iVar1 = -0x16;
  }
  else if (role == 1) {
    iVar1 = rpmsg_create_ept((rpmsg_endpoint *)ept,(rpmsg_device *)(instance + 0x38),
                             (char *)(ept + 0x10),0xffffffff,0xffffffff,(rpmsg_ept_cb)instance[0x6b]
                             ,&LAB_000824be_1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


