/*
 * Function: nvs_add_gc_done_ate
 * Entry:    00081fa4
 * Prototype: int __stdcall nvs_add_gc_done_ate(nvs_fs * fs)
 */


/* exclude_from_export_ai */

int nvs_add_gc_done_ate(nvs_fs *fs)

{
  int iVar1;
  undefined4 in_r1;
  nvs_ate local_10;
  
  local_10.crc8 = (byte)((uint)in_r1 >> 0x18);
  local_10.len = 0;
  local_10.part = 0xff;
  local_10.offset = (word)fs->data_wra;
  local_10.id = 0xffff;
  nvs_ate_crc8_update(&local_10);
  iVar1 = nvs_flash_ate_wrt(fs,&local_10);
  return iVar1;
}


