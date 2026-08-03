/*
 * Function: z_device_is_ready
 * Entry:    00089b3c
 * Prototype: bool __stdcall z_device_is_ready(device * dev)
 */


/* exclude_from_export */

bool z_device_is_ready(device *dev)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = false;
  if (dev != (device *)0x0) {
    bVar1 = dev->state[1];
    bVar2 = (bool)(bVar1 & 1);
    if ((bVar1 & 1) != 0) {
      bVar2 = *dev->state == '\0';
    }
  }
  return bVar2;
}


