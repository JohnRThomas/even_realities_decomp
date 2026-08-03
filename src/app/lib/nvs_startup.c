/*
 * Function: nvs_startup
 * Entry:    00081fd2
 * Prototype: int __stdcall nvs_startup(nvs_fs * fs)
 */


/* exclude_from_export_ai */

int nvs_startup(nvs_fs *fs)

{
  uint32_t addr;
  uint uVar1;
  dword dVar2;
  size_t sVar3;
  int iVar4;
  size_t sVar5;
  nvs_ate *pnVar6;
  int extraout_r2;
  uint addr_00;
  uint uVar7;
  uint32_t addr_01;
  uint len;
  uint uVar8;
  uint32_t local_6c;
  uint local_68;
  dword local_64;
  nvs_ate nStack_60;
  nvs_ate local_58;
  nvs_ate local_50;
  undefined1 auStack_48 [36];
  
  sVar3 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
  local_6c = fs->ate_wra & 0xffff0000;
  nvs_sector_advance(fs,&local_6c);
  addr = local_6c;
  addr_00 = (fs->sector_size + local_6c) - sVar3;
  local_68 = addr_00;
  iVar4 = nvs_flash_rd(fs,addr_00,&nStack_60,8);
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = 0;
  pnVar6 = &nStack_60;
  while (*(char *)(*(int *)((int)&fs[1].data_wra + 3) + 4) == (char)pnVar6->id) {
    iVar4 = iVar4 + 1;
    pnVar6 = (nvs_ate *)((int)&pnVar6->id + 1);
    if (iVar4 == 8) goto LAB_0008202a;
  }
  iVar4 = nvs_close_ate_valid(fs,&nStack_60);
  if (iVar4 == 0) {
    iVar4 = nvs_recover_last_ate(fs,&local_68);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  else {
    local_68 = (addr_00 & 0xffff0000) + (uint)nStack_60.offset;
  }
  do {
    uVar1 = local_68;
    iVar4 = nvs_prev_ate(fs,&local_68,&local_58);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = nvs_ate_valid(fs,&local_58);
    if (iVar4 != 0) {
      local_64 = fs->ate_wra;
      do {
        dVar2 = local_64;
        iVar4 = nvs_prev_ate(fs,&local_64,&local_50);
        if (iVar4 != 0) {
          return iVar4;
        }
      } while (((local_50.id != local_58.id) || (iVar4 = nvs_ate_valid(fs,&local_50), iVar4 == 0))
              && (fs->ate_wra != local_64));
      if ((dVar2 == uVar1) && (local_58.len != 0)) {
        addr_01 = (uint)local_58.offset + (uVar1 & 0xffff0000);
        local_58.offset = (word)fs->data_wra;
        nvs_ate_crc8_update(&local_58);
        uVar7 = -**(int **)((int)&fs[1].data_wra + 3) & 0x20;
        for (uVar8 = (uint)local_58.len; uVar8 != 0; uVar8 = uVar8 - len) {
          len = uVar7;
          if (uVar8 <= uVar7) {
            len = uVar8;
          }
          iVar4 = nvs_flash_rd(fs,addr_01,auStack_48,len);
          if (iVar4 != 0) {
            return iVar4;
          }
          nvs_flash_al_wrt(fs,fs->data_wra,auStack_48,len);
          sVar5 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),len);
          fs->data_wra = fs->data_wra + sVar5;
          if (extraout_r2 != 0) {
            return extraout_r2;
          }
          addr_01 = addr_01 + len;
        }
        iVar4 = nvs_flash_ate_wrt(fs,&local_58);
        if (iVar4 != 0) {
          return iVar4;
        }
      }
    }
  } while (uVar1 != addr_00 - sVar3);
LAB_0008202a:
  if ((fs->ate_wra < fs->data_wra + sVar3) || (iVar4 = nvs_add_gc_done_ate(fs), iVar4 == 0)) {
    iVar4 = nvs_flash_erase_sector(fs,addr);
  }
  return iVar4;
}


