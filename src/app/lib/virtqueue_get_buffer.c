/*
 * Function: virtqueue_get_buffer
 * Entry:    00088ee4
 * Prototype: void * __stdcall virtqueue_get_buffer(virtqueue * vq, uint32_t * len, uint16_t * idx)
 */


/* exclude_from_export */

void * virtqueue_get_buffer(virtqueue *vq,uint32_t *len,uint16_t *idx)

{
  ushort uVar1;
  short sVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  pvVar3 = (void *)0x0;
  if (vq != (virtqueue *)0x0) {
    iVar7 = *(int *)&vq->vq_desc_head_idx;
    uVar1 = *(ushort *)((int)&vq[1].vq_dev + 3);
    if ((uint)*(ushort *)(iVar7 + 2) == (uint)uVar1) {
      pvVar3 = (void *)0x0;
    }
    else {
      *(ushort *)((int)&vq[1].vq_dev + 3) = uVar1 + 1;
      DataMemoryBarrier(0x1b);
      uVar6 = (uint)uVar1 & vq->vq_nentries - 1;
      iVar7 = iVar7 + uVar6 * 8;
      uVar4 = *(uint *)(iVar7 + 4);
      if (len != (uint32_t *)0x0) {
        *len = *(uint32_t *)(iVar7 + 8);
      }
      iVar8 = *(int *)&vq->vq_free_cnt;
      uVar5 = uVar4 & 0xffff;
      iVar7 = iVar8 + uVar5 * 0x10;
      sVar2 = *(short *)((int)&vq[1].callback + uVar5 * 8 + 1);
      vq->vq_available_idx = vq->vq_available_idx + sVar2;
      *(short *)((int)&vq[1].callback + uVar5 * 8 + 1) = sVar2 + -1;
      if (-1 < (int)((uint)*(ushort *)(iVar7 + 0xc) << 0x1d)) {
        while ((int)((uint)*(ushort *)(iVar7 + 0xc) << 0x1f) < 0) {
          iVar7 = iVar8 + (uint)*(ushort *)(iVar7 + 0xe) * 0x10;
          *(short *)((int)&vq[1].callback + uVar5 * 8 + 1) =
               *(short *)((int)&vq[1].callback + uVar5 * 8 + 1) + -1;
        }
      }
      *(undefined2 *)(iVar7 + 0xe) = *(undefined2 *)((int)&vq[1].vq_dev + 1);
      *(short *)((int)&vq[1].vq_dev + 1) = (short)uVar4;
      pvVar3 = *(void **)((int)&vq[1].vq_queue_index + uVar5 * 8 + 1);
      *(undefined4 *)((int)&vq[1].vq_queue_index + uVar5 * 8 + 1) = 0;
      if (idx != (uint16_t *)0x0) {
        *idx = (uint16_t)uVar6;
      }
    }
  }
  return pvVar3;
}


