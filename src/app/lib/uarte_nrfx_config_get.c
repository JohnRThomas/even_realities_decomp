/*
 * Function: uarte_nrfx_config_get
 * Entry:    00087fd2
 * Prototype: int __stdcall uarte_nrfx_config_get(device * dev, uart_config * cfg)
 */


/* exclude_from_export */

int uarte_nrfx_config_get(device *dev,uart_config *cfg)

{
  uart_config uVar1;
  
  uVar1 = *(uart_config *)(dev->data + 8);
  *cfg = *(uart_config *)(dev->data + 4);
  cfg[1] = uVar1;
  return 0;
}


