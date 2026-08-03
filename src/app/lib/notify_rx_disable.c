/*
 * Function: notify_rx_disable
 * Entry:    00088060
 * Prototype: void __stdcall notify_rx_disable(device * dev)
 */


/* exclude_from_export */

void notify_rx_disable(device *dev)

{
  undefined1 local_1c [20];
  
  memset(local_1c,0,0x14);
  local_1c[0] = 5;
  user_callback(dev,(uart_event *)local_1c);
  return;
}


