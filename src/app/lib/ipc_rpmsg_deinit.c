/*
 * Function: ipc_rpmsg_deinit
 * Entry:    000824c2
 * Prototype: int __stdcall ipc_rpmsg_deinit(ipc_rpmsg_instance * instance, uint role)
 */


/* exclude_from_export */

int ipc_rpmsg_deinit(ipc_rpmsg_instance *instance,uint role)

{
  int iVar1;
  
  if (instance == (ipc_rpmsg_instance *)0x0) {
    iVar1 = -0x16;
  }
  else {
    rpmsg_deinit_vdev(instance + 0x38);
    if (role == 0) {
      instance[0x67] = 0;
      instance[0x68] = 0;
      instance[0x69] = 0;
    }
    iVar1 = 0;
  }
  return iVar1;
}


