/*
 * Function: nvs_recover_last_ate
 * Entry:    0004f784
 * Prototype: int __stdcall nvs_recover_last_ate(nvs_fs * fs, uint32_t * addr)
 */


/* exclude_from_export_ai */

int nvs_recover_last_ate(nvs_fs *fs,uint32_t *addr)

{
  size_t sVar1;
  int iVar2;
  uint addr_00;
  uint uVar3;
  nvs_fs *pnStack_28;
  uint32_t *local_24;
  
  pnStack_28 = fs;
  local_24 = addr;
  sVar1 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
  addr_00 = *addr - sVar1;
  *addr = addr_00;
  uVar3 = addr_00 & 0xffff0000;
  while( true ) {
    if (addr_00 <= uVar3) {
      return 0;
    }
    iVar2 = nvs_flash_rd(fs,addr_00,(nvs_ate *)&pnStack_28,8);
    if (iVar2 != 0) break;
    iVar2 = nvs_ate_valid(fs,(nvs_ate *)&pnStack_28);
    if (iVar2 != 0) {
      uVar3 = (uVar3 & 0xffff0000) + ((uint)pnStack_28 >> 0x10) + ((uint)local_24 & 0xffff);
      *addr = addr_00;
    }
    addr_00 = addr_00 - sVar1;
  }
  return iVar2;
}


