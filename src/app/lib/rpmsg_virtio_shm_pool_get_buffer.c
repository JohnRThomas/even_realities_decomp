/*
 * Function: rpmsg_virtio_shm_pool_get_buffer
 * Entry:    0008929e
 * Prototype: int __stdcall rpmsg_virtio_shm_pool_get_buffer(int * shpool, uint size)
 */


/* exclude_from_export */

int rpmsg_virtio_shm_pool_get_buffer(int *shpool,uint size)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (shpool != (int *)0x0) {
    if ((size == 0) || (uVar2 = shpool[1], uVar2 < size)) {
      iVar1 = 0;
    }
    else {
      shpool[1] = uVar2 - size;
      iVar1 = *shpool + (shpool[2] - uVar2);
    }
  }
  return iVar1;
}


