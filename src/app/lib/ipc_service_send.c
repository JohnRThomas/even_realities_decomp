/*
 * Function: ipc_service_send
 * Entry:    000501cc
 * Prototype: int __stdcall ipc_service_send(ipc_ept * ept, void * data, size_t len)
 */


/* exclude_from_export_ai */

int ipc_service_send(ipc_ept *ept,void *data,size_t len)

{
  int iVar1;
  int in_r3;
  
  if (ept[2].instance[0x27].pm == (undefined *)0x2) {
    if (in_r3 == 0) {
      iVar1 = -0x4d;
    }
    else if (data == (void *)0x0) {
      iVar1 = -2;
    }
    else {
      iVar1 = rpmsg_send_offchannel_raw
                        ((int)data,*(undefined4 *)((int)data + 0x24),*(int *)((int)data + 0x28),len,
                         in_r3);
      if (iVar1 == -0x7d2) {
        iVar1 = -0xc;
      }
    }
  }
  else {
    iVar1 = -0x10;
  }
  return iVar1;
}


