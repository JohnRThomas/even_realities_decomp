/*
 * Function: rpmsg_virtio_send_offchannel_raw
 * Entry:    0007453c
 * Prototype: int __stdcall rpmsg_virtio_send_offchannel_raw(rpmsg_device * rdev, uint32_t src, uint32_t dst, void * data, int len, int wait)
 */


/* exclude_from_export */

int rpmsg_virtio_send_offchannel_raw
              (rpmsg_device *rdev,uint32_t src,uint32_t dst,void *data,int len,int wait)

{
  void *data_00;
  metal_io_region *io;
  void *pvVar1;
  int iVar2;
  ulong offset;
  void *local_24;
  
  local_24 = data;
  data_00 = rpmsg_virtio_get_tx_payload_buffer(rdev,(uint32_t *)&local_24,wait);
  if (data_00 == (void *)0x0) {
    iVar2 = -0x7d2;
  }
  else {
    io = *(metal_io_region **)((int)&rdev[5].ops + 3);
    if ((int)local_24 <= len) {
      len = (int)local_24;
    }
    offset = (int)data_00 - (int)io->virt;
    if (io->size <= offset) {
      offset = 0xffffffff;
    }
    pvVar1 = (void *)metal_io_block_write(io,offset,data,len);
    if ((void *)len != pvVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","status == len",
              "WEST_TOPDIR/modules/lib/open-amp/open-amp/lib/rpmsg/rpmsg_virtio.c",519);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar2 = rpmsg_virtio_send_offchannel_nocopy(rdev,src,dst,data_00,len);
  }
  return iVar2;
}


