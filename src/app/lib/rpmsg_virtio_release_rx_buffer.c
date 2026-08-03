/*
 * Function: rpmsg_virtio_release_rx_buffer
 * Entry:    0008924c
 * Prototype: void __stdcall rpmsg_virtio_release_rx_buffer(rpmsg_device * rdev, void * rxbuf)
 */


/* exclude_from_export */

void rpmsg_virtio_release_rx_buffer(rpmsg_device *rdev,void *rxbuf)

{
  uint32_t uVar1;
  undefined4 uVar2;
  k_sem *sem;
  void *local_20;
  uint32_t uStack_1c;
  
  uVar2 = *(undefined4 *)((int)rxbuf + -8);
  sem = (k_sem *)((int)&rdev[3].endpoints + 1);
  metal_mutex_acquire((metal_mutex_t *)sem);
  uVar1 = virtqueue_get_buffer_length(*(virtqueue **)((int)&rdev[5].ns_bind_cb + 3),(uint16_t)uVar2)
  ;
  if (*(int *)(*(int *)((int)&rdev[5].lock + 3) + 0x18) == 0) {
    local_20 = (void *)((int)rxbuf + -0x10);
    uStack_1c = uVar1;
    virtqueue_add_buffer
              (*(virtqueue **)((int)&rdev[5].ns_bind_cb + 3),(virtqueue_buf *)&local_20,0,1,local_20
              );
  }
  virtqueue_kick(*(virtqueue **)((int)&rdev[5].ns_bind_cb + 3));
  k_sem_give(sem);
  return;
}


