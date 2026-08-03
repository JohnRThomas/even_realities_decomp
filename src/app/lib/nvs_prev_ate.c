/*
 * Function: nvs_prev_ate
 * Entry:    00081e7a
 * Prototype: int __stdcall nvs_prev_ate(nvs_fs * fs, uint32_t * addr, nvs_ate * ate)
 */


/* exclude_from_export_ai */

int nvs_prev_ate(nvs_fs *fs,uint32_t *addr,nvs_ate *ate)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  uint32_t addr_00;
  void *data;
  uint uVar4;
  nvs_ate *pnVar5;
  dword dVar6;
  undefined8 uStack_20;
  nvs_ate *pnStack_18;
  
  uStack_20._0_4_ = fs;
  uStack_20._4_4_ = addr;
  pnStack_18 = ate;
  sVar1 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
  iVar2 = nvs_flash_rd(fs,*addr,data,8);
  iVar3 = iVar2;
  if (iVar2 == 0) {
    uVar4 = *addr + sVar1;
    *addr = uVar4;
    if ((uVar4 & 0xffff) == fs->sector_size - sVar1) {
      if (uVar4 >> 0x10 == 0) {
        addr_00 = uVar4 + (fs->sector_count - 1) * 0x10000;
      }
      else {
        addr_00 = uVar4 - 0x10000;
      }
      *addr = addr_00;
      iVar3 = nvs_flash_rd(fs,addr_00,(nvs_ate *)&uStack_20,8);
      if (iVar3 == 0) {
        iVar3 = 0;
        pnVar5 = (nvs_ate *)&uStack_20;
        do {
          if (*(char *)(*(int *)((int)&fs[1].data_wra + 3) + 4) != (char)pnVar5->id) {
            iVar3 = nvs_close_ate_valid(fs,(nvs_ate *)&uStack_20);
            if (iVar3 == 0) {
              iVar3 = nvs_recover_last_ate(fs,addr);
              return iVar3;
            }
            dVar6 = (*addr & 0xffff0000) + ((uint)(nvs_fs *)uStack_20 >> 0x10);
            goto LAB_00081eee;
          }
          iVar3 = iVar3 + 1;
          pnVar5 = (nvs_ate *)((int)&pnVar5->id + 1);
        } while (iVar3 != 8);
        dVar6 = fs->ate_wra;
LAB_00081eee:
        *addr = dVar6;
        iVar3 = iVar2;
      }
    }
  }
  return iVar3;
}


