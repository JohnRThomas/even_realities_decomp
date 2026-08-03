/*
 * Function: gpio_nrfx_init
 * Entry:    00087464
 * Prototype: int __stdcall gpio_nrfx_init(device * port)
 */


/* exclude_from_export_ai */

int gpio_nrfx_init(device *port)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = z_device_is_ready(*(device **)(port->config + 4));
  if (bVar1) {
    iVar2 = 0;
  }
  else {
    iVar2 = -0x13;
  }
  return iVar2;
}


