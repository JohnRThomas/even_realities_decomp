/*
 * Function: rpmsg_init_vdev_with_config
 * Entry:    00074600
 * Prototype: int __stdcall rpmsg_init_vdev_with_config(rpmsg_virtio_device * rvdev, virtio_device * vdev, rpmsg_ns_bind_cb ns_bind_cb, metal_io_region * shm_io, rpmsg_virtio_shm_pool * shpool, rpmsg_virtio_config * config)
 */


/* exclude_from_export */

int rpmsg_init_vdev_with_config
              (rpmsg_virtio_device *rvdev,virtio_device *vdev,rpmsg_ns_bind_cb ns_bind_cb,
              metal_io_region *shm_io,rpmsg_virtio_shm_pool *shpool,rpmsg_virtio_config *config)

{
  virtio_device vVar1;
  void *cookie;
  uint32_t uVar2;
  ulong offset;
  rpmsg_virtio_device rVar3;
  rpmsg_virtio_shm_pool *prVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *local_38;
  char *local_34;
  code *local_30;
  undefined4 local_2c;
  void *local_28;
  rpmsg_virtio_device local_24;
  
  if (((rvdev == (rpmsg_virtio_device *)0x0) || (vdev == (virtio_device *)0x0)) ||
     (shm_io == (metal_io_region *)0x0)) {
    return -0x7d3;
  }
  memset(rvdev,0,0x94);
  z_impl_k_sem_init((k_sem *)(rvdev + 0x16),1,1);
  rvdev[0x28] = (rpmsg_virtio_device)vdev;
  rvdev[0x1c] = (rpmsg_virtio_device)ns_bind_cb;
  vdev[9] = (virtio_device)rvdev;
  rvdev[0x1e] = 0x7453d;
  iVar7 = rvdev[0x28];
  rvdev[0x1f] = 0x89153;
  rvdev[0x20] = 0x8924d;
  rvdev[0x21] = 0x892bd;
  rvdev[0x22] = 0x7435d;
  rvdev[0x23] = 0x89173;
  iVar5 = *(int *)(iVar7 + 0x18);
  if (iVar5 == 0) {
    if (config == (rpmsg_virtio_config *)0x0) {
      return -0x7d3;
    }
    uVar2 = config->r2h_buf_size;
    rVar3 = *(rpmsg_virtio_device *)&config->split_shpool;
    rvdev[0x25] = config->h2r_buf_size;
    rvdev[0x26] = uVar2;
    rvdev[0x27] = rVar3;
  }
  vVar1 = (**(code **)(*(int *)(iVar7 + 0x20) + 0x10))(iVar7);
  vdev[4] = vVar1;
  vdev[5] = 0;
  *(byte *)(rvdev + 0x24) = (byte)vVar1 & 1;
  if (iVar5 == 0) {
    prVar4 = shpool;
    if (config->split_shpool != false) {
      prVar4 = shpool + 3;
    }
    rvdev[0x2c] = (rpmsg_virtio_device)prVar4;
    if (shpool == (rpmsg_virtio_shm_pool *)0x0) {
      return -0x7d3;
    }
    if ((shpool[2] == 0) || (prVar4[2] == 0)) {
      return -0x7d2;
    }
    local_38 = "rx_vq";
    local_34 = "tx_vq";
    local_30 = (code *)0x74435;
    local_2c = 0x89161;
    rvdev[0x29] = *(rpmsg_virtio_device *)vdev[0xb];
    rvdev[0x2a] = *(rpmsg_virtio_device *)(vdev[0xb] + 0x18);
  }
  rvdev[0x2d] = (rpmsg_virtio_device)(rvdev + 0x2d);
  rvdev[0x2e] = (rpmsg_virtio_device)(rvdev + 0x2d);
  rvdev[0x2b] = (rpmsg_virtio_device)shm_io;
  iVar7 = virtio_create_virtqueues((virtio_device *)rvdev[0x28],0,2,&local_38,&local_30);
  if (iVar7 != 0) {
    return iVar7;
  }
  virtqueue_disable_cb((virtqueue *)rvdev[0x2a]);
  *(metal_io_region **)(*(int *)vdev[0xb] + 0x28) = shm_io;
  *(metal_io_region **)(*(int *)(vdev[0xb] + 0x18) + 0x28) = shm_io;
  if (iVar5 == 0) {
    local_24 = rvdev[0x26];
    for (uVar6 = 0; uVar6 < *(ushort *)(rvdev[0x29] + 10); uVar6 = uVar6 + 1) {
      cookie = (void *)rpmsg_virtio_shm_pool_get_buffer(shpool,rvdev[0x26]);
      if (cookie == (void *)0x0) {
        return -0x7d2;
      }
      offset = (int)cookie - (int)shm_io->virt;
      if (shm_io->size <= offset) {
        offset = 0xffffffff;
      }
      local_28 = cookie;
      metal_io_block_set(shm_io,offset,'\0',rvdev[0x26]);
      iVar7 = virtqueue_add_buffer((virtqueue *)rvdev[0x29],(virtqueue_buf *)&local_28,0,1,cookie);
      if (iVar7 != 0) {
        return iVar7;
      }
    }
    *rvdev = (rpmsg_virtio_device)rvdev;
    rvdev[1] = (rpmsg_virtio_device)rvdev;
    if ((char)rvdev[0x24] == '\0') goto LAB_00074740;
  }
  else {
    *rvdev = (rpmsg_virtio_device)rvdev;
    rvdev[1] = (rpmsg_virtio_device)rvdev;
    if ((char)rvdev[0x24] == '\0') {
      return 0;
    }
  }
  rpmsg_register_endpoint
            ((rpmsg_device *)rvdev,(rpmsg_endpoint *)(rvdev + 2),"NS",0x35,0x35,
             (rpmsg_ept_cb)0x891b5,(rpmsg_ns_unbind_cb)0x0);
  if (iVar5 != 0) {
    return 0;
  }
LAB_00074740:
  (**(code **)(*(int *)(rvdev[0x28] + 0x20) + 0xc))(rvdev[0x28],4);
  return 0;
}


