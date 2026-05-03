/*
 * Function: register_ept
 * Entry:    00050218
 * Prototype: undefined4 __stdcall register_ept(int param_1, ipc_rpmsg_ept * param_2, undefined4 * param_3)
 */


/* Library Function - Single Match
    register_ept
   
   Libraries: application fake_app 2.5.1, network hci_rpmsg 2.5.1 */

undefined4 register_ept(int param_1,ipc_rpmsg_ept *param_2,undefined4 *param_3)

{
  bool bVar1;
  ipc_rpmsg_ept *ept;
  int iVar2;
  ipc_rpmsg_ept iVar3;
  ipc_rpmsg_instance *rpmsg_inst;
  k_mutex *mutex;
  k_timeout_t timeout;
  ipc_rpmsg_ept *local_24;
  undefined4 *puStack_20;
  
  rpmsg_inst = *(ipc_rpmsg_instance **)(param_1 + 0x10);
  if (rpmsg_inst[0xef] != 2) {
    return 0xfffffff0;
  }
  if (((char *)*param_3 != (char *)0x0) && (*(char *)*param_3 != '\0')) {
    local_24 = param_2;
    puStack_20 = param_3;
    if (rpmsg_inst[0xee] == 0) {
      mutex = (k_mutex *)(rpmsg_inst + 0x6c);
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = param_2;
      z_impl_k_mutex_lock(mutex,timeout);
      bVar1 = get_ept(rpmsg_inst,&local_24,(char *)*param_3);
      ept = local_24;
      if (local_24 != (ipc_rpmsg_ept *)0x0) {
        local_24[0x1a] = (ipc_rpmsg_ept)(param_3 + 2);
        iVar3 = param_3[5];
        *(undefined1 *)(local_24 + 0x19) = 0;
        local_24[0x1b] = iVar3;
        local_24[0xf] = (ipc_rpmsg_ept)local_24;
        if (bVar1) {
          z_impl_k_mutex_unlock(mutex);
          advertise_ept(rpmsg_inst,ept,(char *)*param_3,ept[0x18]);
        }
        else {
          strcpy((char *)(local_24 + 0x10),(char *)*param_3);
          z_impl_k_mutex_unlock(mutex);
        }
LAB_00050298:
        *param_2 = (ipc_rpmsg_ept)ept;
        return 0;
      }
      z_impl_k_mutex_unlock(mutex);
    }
    else {
      ept = get_ept_slot_with_name(rpmsg_inst,"");
      if (ept != (ipc_rpmsg_ept *)0x0) {
        ept[0x1a] = (ipc_rpmsg_ept)(param_3 + 2);
        iVar3 = param_3[5];
        ept[0xf] = (ipc_rpmsg_ept)ept;
        ept[0x1b] = iVar3;
        *(undefined1 *)(ept + 0x19) = 0;
        strcpy((char *)(ept + 0x10),(char *)*param_3);
        iVar2 = ipc_rpmsg_register_ept(rpmsg_inst,1,ept);
        if (iVar2 == 0) goto LAB_00050298;
      }
    }
  }
  return 0xffffffea;
}


