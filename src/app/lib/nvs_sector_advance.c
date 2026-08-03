/*
 * Function: nvs_sector_advance
 * Entry:    00081cf2
 * Prototype: void __stdcall nvs_sector_advance(nvs_fs * fs, uint32_t * addr)
 */


/* exclude_from_export_ai */

void nvs_sector_advance(nvs_fs *fs,uint32_t *addr)

{
  uint uVar1;
  
  uVar1 = *addr + 0x10000;
  *addr = uVar1;
  if ((uint)fs->sector_count == uVar1 >> 0x10) {
    *addr = uVar1 - (uVar1 & 0xffff0000);
  }
  return;
}


