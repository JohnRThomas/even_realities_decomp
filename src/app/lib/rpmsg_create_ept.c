/*
 * Function: rpmsg_create_ept
 * Entry:    0007425c
 * Prototype: int __stdcall rpmsg_create_ept(rpmsg_endpoint * ept, rpmsg_device * rdev, char * name, uint32_t src, uint32_t dest, rpmsg_ept_cb cb, rpmsg_ns_unbind_cb ns_unbind_cb)
 */


/* exclude_from_export */

int rpmsg_create_ept(rpmsg_endpoint *ept,rpmsg_device *rdev,char *name,uint32_t src,uint32_t dest,
                    rpmsg_ept_cb cb,rpmsg_ns_unbind_cb ns_unbind_cb)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  k_sem *sem;
  k_timeout_t timeout;
  
  if (((ept == (rpmsg_endpoint *)0x0) || (rdev == (rpmsg_device *)0x0)) || (cb == (rpmsg_ept_cb)0x0)
     ) {
    return -0x7d3;
  }
  sem = (k_sem *)((int)&rdev[3].endpoints + 1);
  timeout.ticks._4_4_ = name;
  timeout.ticks._0_4_ = rdev;
  k_sem_take(sem,timeout);
  if (src == 0xffffffff) {
    uVar2 = 0;
    if ((*(uint *)((int)&rdev[2].lock + 2) & 1) != 0) {
      uVar2 = 0;
      do {
        uVar2 = uVar2 + 1;
        if (uVar2 == 0x80) goto LAB_00074346;
      } while ((int)((*(uint *)((int)&rdev[2].lock + (uVar2 >> 5) * 4 + 2) >> (uVar2 & 0x1f)) <<
                    0x1f) < 0);
    }
    src = uVar2 + 0x400;
    *(uint *)((int)&rdev[2].lock + (uVar2 >> 5) * 4 + 2) =
         *(uint *)((int)&rdev[2].lock + (uVar2 >> 5) * 4 + 2) | 1 << (uVar2 & 0x1f);
  }
  else if (0x3ff < src) {
    uVar2 = src - 0x400;
    if (uVar2 < 0x80) {
      uVar3 = *(uint *)((int)&rdev[2].lock + (uVar2 >> 5) * 4 + 2);
      if (-1 < (int)((uVar3 >> (uVar2 & 0x1f)) << 0x1f)) {
        *(uint *)((int)&rdev[2].lock + (uVar2 >> 5) * 4 + 2) = 1 << (uVar2 & 0x1f) | uVar3;
        goto LAB_000742c4;
      }
LAB_00074346:
      iVar1 = -0x7d7;
    }
    else {
      iVar1 = -0x7d3;
    }
    k_sem_give(sem);
    return iVar1;
  }
LAB_000742c4:
  rpmsg_register_endpoint(rdev,ept,name,src,dest,cb,ns_unbind_cb);
  k_sem_give(sem);
  iVar1 = 0;
  if ((ept->name_RPMSG_NAME_SIZE_ != '\0') && (iVar1 = 0, rdev[4].support_ns != 0)) {
    if (*(int *)((int)&ept[1].dest_addr + 2) == -1) {
      iVar1 = rpmsg_send_ns_message(ept,0);
      if (iVar1 != 0) {
        rpmsg_unregister_endpoint(ept);
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}


