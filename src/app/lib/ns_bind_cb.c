/*
 * Function: ns_bind_cb
 * Entry:    00082316
 * Prototype: void __stdcall ns_bind_cb(rpmsg_device * rdev, char * name, uint32_t dest)
 */


/* exclude_from_export_ai */

void ns_bind_cb(rpmsg_device *rdev,char *name,uint32_t dest)

{
  ipc_rpmsg_ept *rpmsg_ept;
  bool bVar1;
  int iVar2;
  k_mutex *mutex;
  ipc_rpmsg_instance *rpmsg_inst;
  k_timeout_t timeout;
  ipc_rpmsg_ept *local_1c;
  
  if ((name != (char *)0x0) && (*name != '\0')) {
    iVar2 = *(int *)((int)&rdev[6].endpoints + 2);
    rpmsg_inst = (ipc_rpmsg_instance *)(iVar2 + -0x19c);
    mutex = (k_mutex *)(iVar2 + 0x14);
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = name;
    local_1c = (ipc_rpmsg_ept *)name;
    z_impl_k_mutex_lock(mutex,timeout);
    bVar1 = get_ept(rpmsg_inst,&local_1c,name);
    rpmsg_ept = local_1c;
    if (local_1c != (ipc_rpmsg_ept *)0x0) {
      if (bVar1) {
        z_impl_k_mutex_unlock(mutex);
        advertise_ept(rpmsg_inst,rpmsg_ept,name,dest);
        return;
      }
      strcpy((char *)(local_1c + 0x10),name);
      rpmsg_ept[0x18] = dest;
    }
    z_impl_k_mutex_unlock(mutex);
    return;
  }
  return;
}


