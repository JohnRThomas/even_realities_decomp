/*
 * Function: virtqueue_disable_cb
 * Entry:    00088f62
 * Prototype: void __stdcall virtqueue_disable_cb(virtqueue * vq)
 */


/* exclude_from_export */

void virtqueue_disable_cb(virtqueue *vq)

{
  int iVar1;
  
  iVar1 = *(int *)(vq->vq_dev + 0x18);
  if (*(int *)(vq->vq_dev + 0x10) << 2 < 0) {
    if (iVar1 == 0) {
      *(word *)(vq->shm_io + vq->vq_ring * 2 + 4) =
           (*(short *)((int)&vq[1].vq_dev + 3) + -1) - vq->vq_nentries;
      return;
    }
  }
  else if (iVar1 == 0) {
    *(ushort *)vq->shm_io = *(ushort *)vq->shm_io | 1;
  }
  return;
}


