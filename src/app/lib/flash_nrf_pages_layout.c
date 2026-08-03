/*
 * Function: flash_nrf_pages_layout
 * Entry:    00064490
 * Prototype: void __stdcall flash_nrf_pages_layout(device * dev, flash_pages_layout * * layout, size_t * layout_size)
 */


/* exclude_from_export */

void flash_nrf_pages_layout(device *dev,flash_pages_layout **layout,size_t *layout_size)

{
  *layout = &dev_layout;
  *layout_size = 1;
  return;
}


