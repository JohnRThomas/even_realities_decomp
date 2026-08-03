/*
 * Function: virtqueue_kick
 * Entry:    00088f90
 * Prototype: void __stdcall virtqueue_kick(virtqueue * vq)
 */


/* exclude_from_export */

void virtqueue_kick(virtqueue *vq)

{
  int iVar1;
  
  DataMemoryBarrier(0x1b);
  iVar1 = *(int *)(vq->vq_dev + 0x18);
  if ((*(uint *)(vq->vq_dev + 0x10) & 0x20000000) == 0) {
    if ((iVar1 != 0) || ((int)((uint)**(ushort **)&vq->vq_desc_head_idx << 0x1f) < 0))
    goto LAB_00088fc0;
  }
  else if ((iVar1 != 0) ||
          (*(ushort *)&vq->vq_inuse <=
           (ushort)((*(short *)(vq->shm_io + 2) + -1) -
                   *(short *)(*(int *)&vq->vq_desc_head_idx + vq->vq_ring * 8 + 4))))
  goto LAB_00088fc0;
  if ((code *)vq->notify != (code *)0x0) {
    (*(code *)vq->notify)(vq);
  }
LAB_00088fc0:
  *(undefined2 *)&vq->vq_inuse = 0;
  return;
}


