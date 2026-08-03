/*
 * Function: hold_rx_buffer
 * Entry:    000821ac
 * Prototype: int __stdcall hold_rx_buffer(device * instance, void * token, void * data)
 */


/* exclude_from_export_ai */

int hold_rx_buffer(device *instance,void *token,void *data)

{
  int iVar1;
  
  if (token == (void *)0x0) {
    iVar1 = -2;
  }
  else {
    rpmsg_hold_rx_buffer(token,data);
    iVar1 = 0;
  }
  return iVar1;
}


