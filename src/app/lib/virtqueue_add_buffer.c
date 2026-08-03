/*
 * Function: virtqueue_add_buffer
 * Entry:    00088e2c
 * Prototype: int __stdcall virtqueue_add_buffer(virtqueue * vq, virtqueue_buf * buf_list, int readable, int writable, void * cookie)
 */


/* exclude_from_export */

int virtqueue_add_buffer
              (virtqueue *vq,virtqueue_buf *buf_list,int readable,int writable,void *cookie)

{
  word wVar1;
  ushort uVar2;
  metal_io_region *io;
  metal_phys_addr_t mVar3;
  ulong offset;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  virtqueue_buf *pvVar8;
  int iVar9;
  uint uVar10;
  
  uVar2 = *(ushort *)((int)&vq[1].vq_dev + 1);
  uVar10 = (uint)uVar2;
  iVar9 = readable + writable;
  *(void **)((int)&vq[1].vq_queue_index + uVar10 * 8 + 1) = cookie;
  *(short *)((int)&vq[1].callback + uVar10 * 8 + 1) = (short)iVar9;
  iVar5 = *(int *)&vq->vq_free_cnt;
  pvVar8 = buf_list + 1;
  for (iVar7 = 0; iVar7 < iVar9; iVar7 = iVar7 + 1) {
    io = *(metal_io_region **)((int)&vq->vq_descx + 1);
    iVar6 = iVar5 + uVar10 * 0x10;
    offset = pvVar8[-1] - (int)io->virt;
    if (io->size <= offset) {
      offset = 0xffffffff;
    }
    mVar3 = metal_io_phys(io,offset);
    *(metal_phys_addr_t *)(iVar5 + uVar10 * 0x10) = mVar3;
    *(undefined4 *)(iVar6 + 4) = 0;
    *(virtqueue_buf *)(iVar6 + 8) = *pvVar8;
    uVar4 = (ushort)(iVar7 < iVar9 + -1);
    if (readable <= iVar7) {
      uVar4 = uVar4 | 2;
    }
    *(ushort *)(iVar6 + 0xc) = uVar4;
    uVar10 = (uint)*(ushort *)(iVar6 + 0xe);
    pvVar8 = pvVar8 + 2;
  }
  wVar1 = vq->vq_available_idx;
  *(short *)((int)&vq[1].vq_dev + 1) = (short)uVar10;
  vq->vq_available_idx = wVar1 - (short)iVar9;
  *(ushort *)(vq->shm_io + ((uint)*(ushort *)(vq->shm_io + 2) & vq->vq_nentries - 1) * 2 + 4) =
       uVar2;
  DataMemoryBarrier(0x1b);
  *(short *)(vq->shm_io + 2) = *(short *)(vq->shm_io + 2) + 1;
  *(short *)&vq->vq_inuse = *(short *)&vq->vq_inuse + 1;
  return 0;
}


