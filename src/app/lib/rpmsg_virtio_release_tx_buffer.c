/*
 * Function: rpmsg_virtio_release_tx_buffer
 * Entry:    00089172
 * Prototype: int __stdcall rpmsg_virtio_release_tx_buffer(rpmsg_device * rdev, void * txbuf)
 */


/* exclude_from_export */

int rpmsg_virtio_release_tx_buffer(rpmsg_device *rdev,void *txbuf)

{
  undefined4 uVar1;
  k_sem *sem;
  
  uVar1 = *(undefined4 *)((int)txbuf + -8);
  sem = (k_sem *)((int)&rdev[3].endpoints + 1);
  metal_mutex_acquire((metal_mutex_t *)sem);
  *(short *)((int)txbuf + -8) = (short)uVar1;
  *(undefined4 *)((int)txbuf + -0xc) =
       *(undefined4 *)((int)&rdev[6].bitmap_metal_bitmap_longs_RPMSG_ADDR_BMP_SIZE__ + 2);
  *(undefined1 **)((int)txbuf + -0x10) = (undefined1 *)((int)&rdev[6].ns_ept + 2);
  *(int *)((int)&rdev[6].bitmap_metal_bitmap_longs_RPMSG_ADDR_BMP_SIZE__ + 2) = (int)txbuf + -0x10;
  **(int **)((int)txbuf + -0xc) = (int)txbuf + -0x10;
  k_sem_give(sem);
  return 0;
}


