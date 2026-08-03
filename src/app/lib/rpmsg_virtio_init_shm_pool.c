/*
 * Function: rpmsg_virtio_init_shm_pool
 * Entry:    00089398
 * Prototype: void __stdcall rpmsg_virtio_init_shm_pool(rpmsg_virtio_shm_pool * shpool, void * shbuf, size_t size)
 */


/* exclude_from_export_ai */

void rpmsg_virtio_init_shm_pool(rpmsg_virtio_shm_pool *shpool,void *shbuf,size_t size)

{
  if (((shpool != (rpmsg_virtio_shm_pool *)0x0) && (shbuf != (void *)0x0)) && (size != 0)) {
    shpool[1] = size;
    shpool[2] = size;
    *shpool = (rpmsg_virtio_shm_pool)shbuf;
  }
  return;
}


