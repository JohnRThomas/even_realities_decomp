/*
 * Function: virtqueue_get_buffer_length
 * Entry:    00088f58
 * Prototype: uint32_t __stdcall virtqueue_get_buffer_length(virtqueue * vq, uint16_t idx)
 */


/* exclude_from_export */

uint32_t virtqueue_get_buffer_length(virtqueue *vq,uint16_t idx)

{
  return *(uint32_t *)(*(int *)&vq->vq_free_cnt + (uint)idx * 0x10 + 8);
}


