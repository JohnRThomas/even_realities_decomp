/*
 * Function: notify_uart_rx_rdy
 * Entry:    00087ffe
 * Prototype: void __stdcall notify_uart_rx_rdy(device * dev, size_t len)
 */


/* exclude_from_export */

void notify_uart_rx_rdy(device *dev,size_t len)

{
  undefined *puVar1;
  undefined1 local_24 [4];
  dword local_20;
  dword local_1c;
  size_t sStack_18;
  
  puVar1 = dev->data;
  memset(local_24,0,0x14);
  local_24[0] = 2;
  local_20 = *(dword *)(*(int *)(puVar1 + 0xc) + 0x58);
  local_1c = *(dword *)(*(int *)(puVar1 + 0xc) + 0x60);
  sStack_18 = len;
  user_callback(dev,(uart_event *)local_24);
  return;
}


