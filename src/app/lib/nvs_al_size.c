/*
 * Function: nvs_al_size
 * Entry:    00081df6
 * Prototype: size_t __stdcall nvs_al_size(nvs_fs * fs, size_t len)
 */


/* exclude_from_export_ai */

size_t nvs_al_size(nvs_fs *fs,size_t len)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)&fs->offset;
  if (1 < uVar1) {
    len = (len - 1) + uVar1 & -uVar1;
  }
  return len;
}


