/*
 * Function: ipc_rpmsg_init
 * Entry:    000503a0
 * Prototype: int __stdcall ipc_rpmsg_init(ipc_rpmsg_instance * instance, uint role, uint buffer_size, metal_io_region * shm_io, virtio_device * vdev, void * shb, size_t size, rpmsg_ns_bind_cb ns_bind_cb)
 */


/* exclude_from_export_ai */

int ipc_rpmsg_init(ipc_rpmsg_instance *instance,uint role,uint buffer_size,metal_io_region *shm_io,
                  virtio_device *vdev,void *shb,size_t size,rpmsg_ns_bind_cb ns_bind_cb)

{
  int iVar1;
  undefined1 local_2c [16];
  
  if ((instance == (ipc_rpmsg_instance *)0x0) || (shb == (void *)0x0)) {
    iVar1 = -0x16;
  }
  else {
    if (ns_bind_cb == (rpmsg_ns_bind_cb)0x0) {
      ns_bind_cb = (code *)0x502f9;
    }
    if (role != 0) {
      iVar1 = ipc_rpmsg_init_outline
                        (instance + 0x38,vdev,ns_bind_cb,shm_io,(rpmsg_virtio_shm_pool *)0x0);
      return iVar1;
    }
    local_2c._0_4_ = buffer_size;
    local_2c._4_4_ = buffer_size;
    local_2c._8_4_ = role;
    rpmsg_virtio_init_shm_pool(instance + 0x67,shb,size);
    iVar1 = rpmsg_init_vdev_with_config
                      (instance + 0x38,vdev,ns_bind_cb,shm_io,instance + 0x67,
                       (rpmsg_virtio_config *)local_2c);
  }
  return iVar1;
}


