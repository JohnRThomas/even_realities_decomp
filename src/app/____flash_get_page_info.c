/*
 * Function: $_?_flash_get_page_info
 * Entry:    000871dc
 * Prototype: int __stdcall $_?_flash_get_page_info(device * dev, off_t offs, uint32_t index, flash_pages_info * info)
 */


int ____flash_get_page_info(device *dev,off_t offs,uint32_t index,flash_pages_info *info)

{
  undefined *puVar1;
  undefined *puVar2;
  device *local_20;
  off_t local_1c;
  
  puVar1 = dev->api;
  info->start_offset = 0;
  info->index = 0;
  local_20 = dev;
  local_1c = offs;
  (**(code **)(puVar1 + 0x10))(dev,&local_20,&local_1c);
  while( true ) {
    if (local_1c == 0) {
      return -0x16;
    }
    puVar1 = local_20->config;
    info->size = (uint)puVar1;
    if (offs == 0) {
      puVar2 = (undefined *)(index - info->index);
    }
    else {
      puVar2 = (undefined *)((uint)(offs - info->start_offset) / (uint)puVar1);
    }
    if (local_20->name <= puVar2) {
      puVar2 = local_20->name;
    }
    info->start_offset = (int)puVar2 * (int)puVar1 + info->start_offset;
    info->index = (dword)(puVar2 + info->index);
    if (puVar2 < local_20->name) break;
    local_20 = (device *)&local_20->api;
    local_1c = local_1c + -1;
  }
  return 0;
}


