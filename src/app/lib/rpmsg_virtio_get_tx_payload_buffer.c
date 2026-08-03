/*
 * Function: rpmsg_virtio_get_tx_payload_buffer
 * Entry:    000892bc
 * Prototype: void * __stdcall rpmsg_virtio_get_tx_payload_buffer(rpmsg_device * rdev, uint32_t * len, int wait)
 */


/* exclude_from_export */

void * rpmsg_virtio_get_tx_payload_buffer(rpmsg_device *rdev,uint32_t *len,int wait)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  k_sem *sem;
  int iVar4;
  undefined4 uStack_24;
  
  uStack_24 = len;
  iVar1 = (**(code **)(*(int *)(*(int *)((int)&rdev[5].lock + 3) + 0x20) + 8))();
  if (-1 < iVar1 << 0x1d) {
    return (void *)0x0;
  }
  iVar1 = 0;
  if (wait != 0) {
    iVar1 = 15000;
  }
  sem = (k_sem *)((int)&rdev[3].endpoints + 1);
  while( true ) {
    metal_mutex_acquire((metal_mutex_t *)sem);
    piVar3 = *(int **)((int)&rdev[6].ns_ept + 2);
    iVar4 = *(int *)(*(int *)((int)&rdev[5].lock + 3) + 0x18);
    if ((piVar3 != (int *)((int)&rdev[6].ns_ept + 2)) && (piVar3 != (int *)0x0)) break;
    if (iVar4 == 0) {
      piVar3 = virtqueue_get_buffer
                         (*(virtqueue **)((int)&rdev[5].ns_unbind_cb + 3),len,
                          (uint16_t *)((int)&uStack_24 + 2));
      if (piVar3 != (int *)0x0) goto LAB_0008931a;
      if (*(short *)(*(int *)((int)&rdev[5].ns_unbind_cb + 3) + 0x24) == 0) goto LAB_00089340;
      piVar3 = (int *)rpmsg_virtio_shm_pool_get_buffer
                                (*(int **)((int)&rdev[6].endpoints + 2),
                                 *(uint *)((int)&rdev[5].endpoints + 3));
      *len = *(uint32_t *)((int)&rdev[5].endpoints + 3);
      uStack_24 = (uint32_t *)((uint)uStack_24 & 0xffff);
      k_sem_give(sem);
      if (piVar3 != (int *)0x0) goto LAB_00089320;
    }
    else {
LAB_00089340:
      k_sem_give(sem);
    }
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    z_impl_k_sleep((k_timeout_t)0x21);
    iVar1 = iVar1 + -1;
  }
  piVar2 = (int *)piVar3[1];
  *(int **)(*piVar3 + 4) = piVar2;
  *piVar2 = *piVar3;
  *piVar3 = (int)piVar3;
  piVar3[1] = (int)piVar3;
  if (iVar4 == 0) {
    *len = *(uint32_t *)((int)&rdev[5].endpoints + 3);
  }
LAB_0008931a:
  k_sem_give(sem);
LAB_00089320:
  piVar3[2] = (uint)uStack_24 >> 0x10;
  *len = *len - 0x10;
  return piVar3 + 4;
}


