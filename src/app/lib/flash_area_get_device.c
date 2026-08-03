/*
 * Function: flash_area_get_device
 * Entry:    000827a6
 * Prototype: device * __stdcall flash_area_get_device(flash_area * fa)
 */


/* exclude_from_export */

device * flash_area_get_device(flash_area *fa)

{
  return (device *)fa->fa_dev;
}


