/*
 * Function: nvs_close_ate_valid
 * Entry:    00081e3e
 * Prototype: int __stdcall nvs_close_ate_valid(nvs_fs * fs, nvs_ate * entry)
 */


/* exclude_from_export_ai */

int nvs_close_ate_valid(nvs_fs *fs,nvs_ate *entry)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  
  iVar1 = nvs_ate_valid(fs,entry);
  uVar3 = 0;
  if (iVar1 != 0) {
    if (entry->len == 0) {
      uVar3 = 0;
      if (entry->id == 0xffff) {
        sVar2 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
        uVar3 = (uint)fs->sector_size - (uint)entry->offset;
        uVar3 = (uint)(uVar3 == (uVar3 / sVar2) * sVar2);
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


