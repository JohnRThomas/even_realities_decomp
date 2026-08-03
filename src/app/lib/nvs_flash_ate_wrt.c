/*
 * Function: nvs_flash_ate_wrt
 * Entry:    00081f82
 * Prototype: int __stdcall nvs_flash_ate_wrt(nvs_fs * fs, nvs_ate * entry)
 */


/* exclude_from_export_ai */

int nvs_flash_ate_wrt(nvs_fs *fs,nvs_ate *entry)

{
  size_t sVar1;
  int extraout_r2;
  
  nvs_flash_al_wrt(fs,fs->ate_wra,entry,8);
  sVar1 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
  fs->ate_wra = fs->ate_wra - sVar1;
  return extraout_r2;
}


