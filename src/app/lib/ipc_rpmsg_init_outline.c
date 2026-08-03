/*
 * Function: ipc_rpmsg_init_outline
 * Entry:    00074808
 * Prototype: undefined __stdcall ipc_rpmsg_init_outline(rpmsg_virtio_device * param_1, virtio_device * param_2, rpmsg_ns_bind_cb param_3, metal_io_region * param_4, rpmsg_virtio_shm_pool * param_5)
 */


/* exclude_from_export */

void ipc_rpmsg_init_outline
               (rpmsg_virtio_device *param_1,virtio_device *param_2,rpmsg_ns_bind_cb param_3,
               metal_io_region *param_4,rpmsg_virtio_shm_pool *param_5)

{
  rpmsg_virtio_config local_24;
  
  local_24.h2r_buf_size = 0x200;
  local_24.r2h_buf_size = 0x200;
  stack0xffffffe4 = 0;
  rpmsg_init_vdev_with_config(param_1,param_2,param_3,param_4,param_5,&local_24);
  return;
}


