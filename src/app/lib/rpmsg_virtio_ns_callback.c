/*
 * Function: rpmsg_virtio_ns_callback
 * Entry:    000891b4
 * Prototype: int __stdcall rpmsg_virtio_ns_callback(rpmsg_endpoint * ept, void * data, size_t len, uint32_t src, void * priv)
 */


/* exclude_from_export */

int rpmsg_virtio_ns_callback(rpmsg_endpoint *ept,void *data,size_t len,uint32_t src,void *priv)

{
  metal_io_region *io;
  rpmsg_endpoint *prVar1;
  ulong offset;
  code *pcVar2;
  rpmsg_device *rvdev;
  k_sem *sem;
  uint32_t dest_addr;
  char acStack_38 [32];
  
  rvdev = *(rpmsg_device **)((int)&ept[1].rdev + 2);
  io = *(metal_io_region **)((int)&rvdev[5].ops + 3);
  if (len == 0x28) {
    offset = (int)data - (int)io->virt;
    if (io->size <= offset) {
      offset = 0xffffffff;
    }
    metal_io_block_read(io,offset,acStack_38,0x20);
    sem = (k_sem *)((int)&rvdev[3].endpoints + 1);
    dest_addr = *(uint32_t *)((int)data + 0x20);
    metal_mutex_acquire((metal_mutex_t *)sem);
    prVar1 = rpmsg_get_endpoint(rvdev,acStack_38,0xffffffff,dest_addr);
    if (*(int *)((int)data + 0x24) << 0x1f < 0) {
      if (prVar1 == (rpmsg_endpoint *)0x0) {
        k_sem_give(sem);
      }
      else {
        *(undefined4 *)((int)&prVar1[1].dest_addr + 2) = 0xffffffff;
        k_sem_give(sem);
        pcVar2 = *(code **)((int)&prVar1[1].ns_unbind_cb + 2);
        if (pcVar2 != (code *)0x0) {
          (*pcVar2)(prVar1);
        }
      }
      pcVar2 = (code *)rvdev[4].endpoints;
    }
    else {
      if (prVar1 != (rpmsg_endpoint *)0x0) {
        *(uint32_t *)((int)&prVar1[1].dest_addr + 2) = dest_addr;
        k_sem_give(sem);
        return 0;
      }
      k_sem_give(sem);
      pcVar2 = *(code **)((int)&rvdev[3].ops + 1);
    }
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(rvdev,acStack_38,dest_addr);
    }
  }
  return 0;
}


