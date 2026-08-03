/*
 * Function: flash_get_write_block_size
 * Entry:    000827fc
 * Prototype: size_t __stdcall flash_get_write_block_size(device * dev)
 */


/* exclude_from_export */

size_t flash_get_write_block_size(device *dev)

{
  size_t *psVar1;
  
  psVar1 = (size_t *)(**(code **)(dev->api + 0xc))();
  return *psVar1;
}


