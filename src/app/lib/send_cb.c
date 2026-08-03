/*
 * Function: send_cb
 * Entry:    000821c2
 * Prototype: int __stdcall send_cb(int param_1, rpmsg_endpoint * param_2, void * param_3, int param_4)
 */


/* exclude_from_export_ai */

int send_cb(int param_1,rpmsg_endpoint *param_2,void *param_3,int param_4)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x10) + 0x3bc) == 2) {
    if (param_4 == 0) {
      iVar1 = -0x4d;
    }
    else if (param_2 == (rpmsg_endpoint *)0x0) {
      iVar1 = -2;
    }
    else {
      iVar1 = rpmsg_send_offchannel_nocopy
                        (param_2,*(uint32_t *)((int)&param_2[1].addr + 2),
                         *(uint32_t *)((int)&param_2[1].dest_addr + 2),param_3,param_4);
    }
  }
  else {
    iVar1 = -0x10;
  }
  return iVar1;
}


