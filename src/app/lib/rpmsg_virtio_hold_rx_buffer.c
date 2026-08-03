/*
 * Function: rpmsg_virtio_hold_rx_buffer
 * Entry:    00089152
 * Prototype: void __stdcall rpmsg_virtio_hold_rx_buffer(rpmsg_device * rdev, void * rxbuf)
 */


/* exclude_from_export */

void rpmsg_virtio_hold_rx_buffer(rpmsg_device *rdev,void *rxbuf)

{
  *(uint *)((int)rxbuf + -8) = *(uint *)((int)rxbuf + -8) | 0x80000000;
  return;
}


