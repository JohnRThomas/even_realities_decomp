/*
 * Function: find_flash_total_size
 * Entry:    00082808
 * Prototype: bool __stdcall find_flash_total_size(flash_pages_info * info, void * data)
 */


/* exclude_from_export */

bool find_flash_total_size(flash_pages_info *info,void *data)

{
  undefined1 uVar1;
  
  if (info->size < *(uint *)data) {
    uVar1 = find_flash_total_size_error((int)data);
    return (bool)uVar1;
  }
  *(uint *)((int)data + 4) = *(int *)((int)data + 4) + info->size;
  return true;
}


