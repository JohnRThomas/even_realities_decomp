/*
 * Function: nvs_flash_block_cmp
 * Entry:    00081d0c
 * Prototype: int __stdcall nvs_flash_block_cmp(nvs_fs * fs, uint32_t addr, void * data, size_t len)
 */


/* exclude_from_export_ai */

int nvs_flash_block_cmp(nvs_fs *fs,uint32_t addr,void *data,size_t len)

{
  int iVar1;
  uint uVar2;
  uint len_00;
  undefined1 auStack_40 [36];
  
  uVar2 = -**(int **)((int)&fs[1].data_wra + 3) & 0x20;
  while( true ) {
    if (len == 0) {
      return 0;
    }
    len_00 = len;
    if (uVar2 <= len) {
      len_00 = uVar2;
    }
    iVar1 = nvs_flash_rd(fs,addr,auStack_40,len_00);
    if (iVar1 != 0) break;
    iVar1 = memcmp(data,auStack_40,len_00);
    if (iVar1 != 0) {
      return 1;
    }
    len = len - len_00;
    addr = addr + len_00;
    data = (void *)((int)data + len_00);
  }
  return iVar1;
}


