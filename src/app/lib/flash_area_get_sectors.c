/*
 * Function: flash_area_get_sectors
 * Entry:    00051338
 * Prototype: int __stdcall flash_area_get_sectors(int fa_id, uint32_t * count, flash_sector * sectors)
 */


/* exclude_from_export */

int flash_area_get_sectors(int fa_id,uint32_t *count,flash_sector *sectors)

{
  int iVar1;
  device *dev;
  flash_area *local_30;
  int local_2c;
  int local_28;
  uint local_24;
  flash_sector *pfStack_20;
  uint32_t local_1c;
  uint32_t local_18;
  int local_14;
  
  iVar1 = flash_area_open((uint8_t)fa_id,&local_30);
  if ((iVar1 < 0) || (local_30 == (flash_area *)0x0)) {
    local_14 = -0x16;
  }
  else {
    local_28 = local_30->fa_off;
    local_18 = *count;
    local_24 = local_30->fa_size;
    local_14 = 0;
    local_1c = 0;
    dev = (device *)local_30->fa_dev;
    local_2c = fa_id;
    pfStack_20 = sectors;
    flash_area_close(local_30);
    if (dev == (device *)0x0) {
      local_14 = -0x13;
    }
    else {
      flash_page_foreach(dev,(flash_page_cb)0x827b9,&local_2c);
      if (local_14 == 0) {
        *count = local_1c;
      }
    }
  }
  return local_14;
}


