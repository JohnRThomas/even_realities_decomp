/*
 * Function: rpmsg_virtio_send_offchannel_nocopy
 * Entry:    0007435c
 * Prototype: int __stdcall rpmsg_virtio_send_offchannel_nocopy(rpmsg_device * rdev, uint32_t src, uint32_t dst, void * data, int len)
 */


/* exclude_from_export */

int rpmsg_virtio_send_offchannel_nocopy
              (rpmsg_device *rdev,uint32_t src,uint32_t dst,void *data,int len)

{
  metal_io_region *io;
  int iVar1;
  uint32_t uVar2;
  ulong offset;
  void *cookie;
  undefined4 uVar3;
  k_sem *sem;
  void *local_38;
  uint32_t uStack_34;
  uint32_t local_30;
  uint32_t uStack_2c;
  undefined4 local_28;
  undefined2 local_24;
  undefined2 local_22;
  
  cookie = (void *)((int)data + -0x10);
  uVar3 = *(undefined4 *)((int)data + -8);
  local_28 = 0;
  local_22 = 0;
  io = *(metal_io_region **)((int)&rdev[5].ops + 3);
  local_24 = (undefined2)len;
  offset = (int)cookie - (int)io->virt;
  if (io->size <= offset) {
    offset = 0xffffffff;
  }
  local_30 = src;
  uStack_2c = dst;
  iVar1 = metal_io_block_write(io,offset,&local_30,0x10);
  if (iVar1 == 0x10) {
    sem = (k_sem *)((int)&rdev[3].endpoints + 1);
    metal_mutex_acquire((metal_mutex_t *)sem);
    if (*(int *)(*(int *)((int)&rdev[5].lock + 3) + 0x18) == 0) {
      uVar2 = *(uint32_t *)((int)&rdev[5].endpoints + 3);
    }
    else {
      uVar2 = virtqueue_get_buffer_length
                        (*(virtqueue **)((int)&rdev[5].ns_unbind_cb + 3),(uint16_t)uVar3);
      if (*(int *)(*(int *)((int)&rdev[5].lock + 3) + 0x18) != 0) goto LAB_0007440e;
    }
    local_38 = cookie;
    uStack_34 = uVar2;
    iVar1 = virtqueue_add_buffer
                      (*(virtqueue **)((int)&rdev[5].ns_unbind_cb + 3),(virtqueue_buf *)&local_38,1,
                       0,cookie);
    if (iVar1 == 0) {
LAB_0007440e:
      virtqueue_kick(*(virtqueue **)((int)&rdev[5].ns_unbind_cb + 3));
      k_sem_give(sem);
      return len;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","status == 0",
            "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",0x1bc);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","status == sizeof(rp_hdr)",
            "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",431);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


