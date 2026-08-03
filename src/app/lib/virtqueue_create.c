/*
 * Function: virtqueue_create
 * Entry:    00088dd2
 * Prototype: int __stdcall virtqueue_create(virtio_device * device, ushort id, char * name, vring_alloc_info * ring, void * callback, void * notify, virtqueue * vq)
 */


/* exclude_from_export */

int virtqueue_create(virtio_device *device,ushort id,char *name,vring_alloc_info *ring,
                    void *callback,void *notify,virtqueue *vq)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  
  vq->vq_dev = (undefined *)device;
  vq->vq_name = name;
  vq->vq_queue_index = id;
  uVar1 = *(ushort *)(ring + 2);
  uVar2 = (uint)uVar1;
  vq->callback = callback;
  vq->vq_nentries = uVar1;
  vq->vq_available_idx = uVar1;
  vq->notify = notify;
  iVar3 = *ring;
  iVar6 = ring[1];
  puVar4 = (undefined *)(iVar3 + uVar2 * 0x10);
  vq->vq_ring = uVar2;
  vq->vq_free_cnt = (short)iVar3;
  vq->vq_queued_cnt = (short)((uint)iVar3 >> 0x10);
  vq->shm_io = puVar4;
  uVar5 = (uint)(puVar4 + iVar6 + 1 + (uVar2 + 2) * 2) & -iVar6;
  vq->vq_desc_head_idx = (short)uVar5;
  vq->vq_used_cons_idx = (short)(uVar5 >> 0x10);
  if (device[6] == 0) {
    iVar3 = 0;
    while (iVar6 = *(int *)&vq->vq_free_cnt + iVar3 * 0x10, iVar3 < (int)(uVar2 - 1)) {
      iVar3 = iVar3 + 1;
      *(short *)(iVar6 + 0xe) = (short)iVar3;
    }
    *(undefined1 *)(iVar6 + 0xe) = 0;
    *(undefined1 *)(iVar6 + 0xf) = 0x80;
  }
  return 0;
}


