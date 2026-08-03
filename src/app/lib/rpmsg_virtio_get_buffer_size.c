/*
 * Function: rpmsg_virtio_get_buffer_size
 * Entry:    000745bc
 * Prototype: int __stdcall rpmsg_virtio_get_buffer_size(rpmsg_device * rdev)
 */


/* exclude_from_export_ai */

int rpmsg_virtio_get_buffer_size(rpmsg_device *rdev)

{
  int iVar1;
  k_sem *sem;
  
  if (rdev == (rpmsg_device *)0x0) {
    iVar1 = -0x7d3;
  }
  else {
    sem = (k_sem *)((int)&rdev[3].endpoints + 1);
    metal_mutex_acquire((metal_mutex_t *)sem);
    if (*(int *)(*(int *)((int)&rdev[5].lock + 3) + 0x18) == 0) {
      iVar1 = *(int *)((int)&rdev[5].endpoints + 3) + -0x10;
      if (iVar1 < 1) {
        iVar1 = -0x7d2;
      }
    }
    else {
      iVar1 = -0x7d2;
    }
    k_sem_give(sem);
  }
  return iVar1;
}


