/*
 * Function: nvs_flash_cmp_const
 * Entry:    00081d72
 * Prototype: int __stdcall nvs_flash_cmp_const(nvs_fs * fs, uint32_t addr, uint8_t value, size_t len)
 */


/* exclude_from_export_ai */

int nvs_flash_cmp_const(nvs_fs *fs,uint32_t addr,uint8_t value,size_t len)

{
  int iVar1;
  uint n;
  uint len_00;
  undefined1 auStack_38 [32];
  
  n = -**(int **)((int)&fs[1].data_wra + 3) & 0x20;
  memset(auStack_38,(uint)value,n);
  while( true ) {
    if (len == 0) {
      return 0;
    }
    len_00 = len;
    if (n <= len) {
      len_00 = n;
    }
    iVar1 = nvs_flash_block_cmp(fs,addr,auStack_38,len_00);
    if (iVar1 != 0) break;
    len = len - len_00;
    addr = addr + len_00;
  }
  return iVar1;
}


