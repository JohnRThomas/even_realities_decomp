/*
 * Function: nvs_ate_valid
 * Entry:    00081e0a
 * Prototype: int __stdcall nvs_ate_valid(nvs_fs * fs, nvs_ate * entry)
 */


/* exclude_from_export_ai */

int nvs_ate_valid(nvs_fs *fs,nvs_ate *entry)

{
  byte bVar1;
  size_t sVar2;
  int iVar3;
  
  sVar2 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
  bVar1 = crc8_ccitt(0xff,entry,7);
  if (entry->crc8 == bVar1) {
    if ((uint)entry->offset < fs->sector_size - sVar2) {
      iVar3 = 1;
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


