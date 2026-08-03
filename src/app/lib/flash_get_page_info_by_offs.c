/*
 * Function: flash_get_page_info_by_offs
 * Entry:    00087242
 * Prototype: int __stdcall flash_get_page_info_by_offs(device * dev, off_t offset, flash_pages_info * info)
 */


/* exclude_from_export */

int flash_get_page_info_by_offs(device *dev,off_t offset,flash_pages_info *info)

{
  int iVar1;
  
  iVar1 = flash_get_page_info(dev,offset,0,info);
  return iVar1;
}


