/*
 * Function: rx_buf_release
 * Entry:    00088030
 * Prototype: void __stdcall rx_buf_release(device * dev, uint8_t * * buf)
 */


/* exclude_from_export */

void rx_buf_release(device *dev,uint8_t **buf)

{
  uint8_t *puVar1;
  undefined1 local_24 [4];
  uint8_t *local_20;
  
  puVar1 = *buf;
  if (puVar1 != (uint8_t *)0x0) {
    memset(local_24,0,0x14);
    local_24[0] = 4;
    local_20 = puVar1;
    user_callback(dev,(uart_event *)local_24);
    *buf = (uint8_t *)0x0;
  }
  return;
}


