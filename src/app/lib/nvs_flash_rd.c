/*
 * Function: nvs_flash_rd
 * Entry:    00081cd6
 * Prototype: int __stdcall nvs_flash_rd(nvs_fs * fs, uint32_t addr, void * data, size_t len)
 */


/* exclude_from_export_ai */

int nvs_flash_rd(nvs_fs *fs,uint32_t addr,void *data,size_t len)

{
  int iVar1;
  
  iVar1 = *(int *)((int)&fs[1].ate_wra + 3);
                    /* WARNING: Could not recover jumptable at 0x00081cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)**(undefined4 **)(iVar1 + 8))
                    (iVar1,fs->offset + (addr >> 0x10) * (uint)fs->sector_size + (addr & 0xffff));
  return iVar1;
}


