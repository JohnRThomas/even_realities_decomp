/*
 * Function: nvs_flash_erase_sector
 * Entry:    00081dbc
 * Prototype: int __stdcall nvs_flash_erase_sector(nvs_fs * fs, uint32_t addr)
 */


/* exclude_from_export_ai */

int nvs_flash_erase_sector(nvs_fs *fs,uint32_t addr)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)&fs[1].ate_wra + 3);
  iVar1 = (**(code **)(*(int *)(iVar1 + 8) + 8))
                    (iVar1,fs->offset + (uint)fs->sector_size * (addr >> 0x10));
  if ((iVar1 == 0) &&
     (iVar2 = nvs_flash_cmp_const(fs,addr & 0xffff0000,
                                  *(uint8_t *)(*(int *)((int)&fs[1].data_wra + 3) + 4),
                                  (uint)fs->sector_size), iVar1 = 0, iVar2 != 0)) {
    iVar1 = -6;
  }
  return iVar1;
}


