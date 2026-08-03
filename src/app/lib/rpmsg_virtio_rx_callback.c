/*
 * Function: rpmsg_virtio_rx_callback
 * Entry:    00074434
 * Prototype: void __stdcall rpmsg_virtio_rx_callback(virtqueue * vq)
 */


/* exclude_from_export */

void rpmsg_virtio_rx_callback(virtqueue *vq)

{
  undefined4 *cookie;
  rpmsg_endpoint *prVar1;
  int iVar2;
  undefined4 uVar3;
  rpmsg_device *rvdev;
  k_sem *sem;
  ushort local_26;
  uint32_t local_24;
  undefined4 *local_20;
  uint32_t uStack_1c;
  
  rvdev = *(rpmsg_device **)(vq->vq_dev + 0x24);
  sem = (k_sem *)((int)&rvdev[3].endpoints + 1);
  metal_mutex_acquire((metal_mutex_t *)sem);
  if (*(int *)(*(int *)((int)&rvdev[5].lock + 3) + 0x18) != 0) {
    k_sem_give(sem);
    return;
  }
  cookie = virtqueue_get_buffer(*(virtqueue **)((int)&rvdev[5].ns_bind_cb + 3),&local_24,&local_26);
  k_sem_give(sem);
  if (cookie == (undefined4 *)0x0) {
    return;
  }
  do {
    cookie[2] = (uint)local_26;
    metal_mutex_acquire((metal_mutex_t *)sem);
    prVar1 = rpmsg_get_endpoint(rvdev,(char *)0x0,cookie[1],0xffffffff);
    k_sem_give(sem);
    if (prVar1 != (rpmsg_endpoint *)0x0) {
      uVar3 = *(undefined4 *)((int)&prVar1[2].rdev + 1);
      if (*(int *)((int)&prVar1[1].dest_addr + 2) == -1) {
        *(undefined4 *)((int)&prVar1[1].dest_addr + 2) = *cookie;
      }
      iVar2 = (**(code **)((int)&prVar1[1].cb + 2))
                        (prVar1,cookie + 4,*(undefined2 *)(cookie + 3),*cookie,uVar3);
      if (iVar2 < 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","status >= 0",
                "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",581);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
    }
    metal_mutex_acquire((metal_mutex_t *)sem);
    if (-1 < (int)cookie[2]) {
      if (*(int *)(*(int *)((int)&rvdev[5].lock + 3) + 0x18) != 0) {
LAB_000744ec:
        virtqueue_kick(*(virtqueue **)((int)&rvdev[5].ns_bind_cb + 3));
        k_sem_give(sem);
        return;
      }
      uStack_1c = local_24;
      local_20 = cookie;
      virtqueue_add_buffer
                (*(virtqueue **)((int)&rvdev[5].ns_bind_cb + 3),(virtqueue_buf *)&local_20,0,1,
                 cookie);
    }
    if ((*(int *)(*(int *)((int)&rvdev[5].lock + 3) + 0x18) != 0) ||
       (cookie = virtqueue_get_buffer
                           (*(virtqueue **)((int)&rvdev[5].ns_bind_cb + 3),&local_24,&local_26),
       cookie == (undefined4 *)0x0)) goto LAB_000744ec;
    k_sem_give(sem);
  } while( true );
}


