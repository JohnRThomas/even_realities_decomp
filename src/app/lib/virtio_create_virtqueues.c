/*
 * Function: virtio_create_virtqueues
 * Entry:    000740d0
 * Prototype: int __stdcall virtio_create_virtqueues(virtio_device * vdev, uint flags, uint nvqs, char * * names, vq_callback * callbacks)
 */


/* exclude_from_export */

int virtio_create_virtqueues
              (virtio_device *vdev,uint flags,uint nvqs,char **names,vq_callback *callbacks)

{
  int iVar1;
  metal_io_region *io;
  ulong offset;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  int iVar3;
  
  if (vdev == (virtio_device *)0x0) {
    iVar1 = -0x16;
  }
  else {
    if (((undefined4 *)vdev[8] != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)vdev[8], UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000740f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    if ((uint)vdev[10] < nvqs) {
      iVar1 = -0xbc0;
    }
    else {
      for (uVar2 = 0; uVar2 != nvqs; uVar2 = uVar2 + 1) {
        iVar3 = vdev[0xb];
        iVar1 = iVar3 + uVar2 * 0x18;
        if (vdev[6] == 0) {
          io = *(metal_io_region **)(iVar1 + 0x14);
          offset = *(int *)(iVar1 + 4) - (int)io->virt;
          if (io->size <= offset) {
            offset = 0xffffffff;
          }
          metal_io_block_set(io,offset,'\0',
                             (*(int *)(iVar1 + 8) + (uint)*(ushort *)(iVar1 + 0xc) * 0x12 + 5 &
                             -*(int *)(iVar1 + 8)) + (uint)*(ushort *)(iVar1 + 0xc) * 8 + 6);
        }
        iVar1 = virtqueue_create(vdev,(ushort)uVar2,names[uVar2],(vring_alloc_info *)(iVar1 + 4),
                                 callbacks[uVar2],*(void **)(vdev[8] + 0x28),
                                 *(virtqueue **)(iVar3 + uVar2 * 0x18));
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}


