/*
 * Function: nvs_mount
 * Entry:    0004f7e8
 * Prototype: int __stdcall nvs_mount(nvs_fs * fs)
 */


/* exclude_from_export */

int nvs_mount(nvs_fs *fs)

{
  uint8_t value;
  int iVar1;
  int *piVar2;
  size_t sVar3;
  nvs_fs *fs_00;
  size_t sVar4;
  undefined4 extraout_r1;
  uint32_t addr;
  dword extraout_r2;
  nvs_ate *pnVar5;
  dword dVar6;
  uint uVar7;
  k_mutex *mutex;
  uint uVar8;
  k_timeout_t timeout;
  char local_70 [4];
  char *local_6c;
  uint local_68;
  uint local_64;
  uint32_t local_60;
  nvs_ate local_5c;
  nvs_ate local_54;
  flash_pages_info afStack_4c [2];
  char local_30 [4];
  char *local_2c;
  
  mutex = (k_mutex *)((int)&fs->nvs_lock + 3);
  z_impl_k_mutex_init(mutex);
  iVar1 = (**(code **)(*(int *)(*(int *)((int)&fs[1].ate_wra + 3) + 8) + 0xc))();
  *(int *)((int)&fs[1].data_wra + 3) = iVar1;
  if (iVar1 == 0) {
    local_2c = "Could not obtain flash parameters";
LAB_0004f80a:
    local_30[0] = '\x02';
    local_30[1] = '\0';
    local_30[2] = '\0';
    local_30[3] = '\0';
    LOG_ERR(&PTR_s_fs_nvs_0008b968,0x1040,local_30);
    return -0x16;
  }
  piVar2 = (int *)(**(code **)(*(int *)(*(int *)((int)&fs[1].ate_wra + 3) + 8) + 0xc))();
  if (0x1f < *piVar2 - 1U) {
    local_2c = "Unsupported write block size";
    goto LAB_0004f80a;
  }
  iVar1 = flash_get_page_info_by_offs
                    (*(device **)((int)&fs[1].ate_wra + 3),(off_t)fs->offset,afStack_4c);
  if (iVar1 != 0) {
    local_2c = "Unable to get page info";
    goto LAB_0004f80a;
  }
  local_60 = (uint32_t)fs->sector_size;
  if ((local_60 == 0) ||
     (local_60 = local_60 - afStack_4c[0].size * (local_60 / afStack_4c[0].size), local_60 != 0)) {
    local_2c = "Invalid sector size";
    goto LAB_0004f80a;
  }
  if (fs->sector_count < 2) {
    local_2c = "Configuration error - sector count";
    goto LAB_0004f80a;
  }
  value = *(uint8_t *)(*(int *)((int)&fs[1].data_wra + 3) + 4);
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1;
  z_impl_k_mutex_lock(mutex,timeout);
  sVar3 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
  uVar7 = 0;
  for (uVar8 = 0; (uVar8 & 0xffff) < (uint)fs->sector_count; uVar8 = uVar8 + 1) {
    local_60 = uVar8 * 0x10000 + (fs->sector_size - sVar3 & 0xffff);
    iVar1 = nvs_flash_cmp_const(fs,local_60,value,8);
    if (iVar1 != 0) {
      nvs_sector_advance(fs,&local_60);
      uVar7 = uVar7 + 1 & 0xffff;
      iVar1 = nvs_flash_cmp_const(fs,local_60,value,8);
      if (iVar1 == 0) break;
    }
  }
  if (fs->sector_count == uVar7) {
    z_impl_k_mutex_unlock(mutex);
    return -0x2d;
  }
  if (((uint)fs->sector_count == (uVar8 & 0xffff)) &&
     (iVar1 = nvs_flash_cmp_const(fs,local_60 - sVar3,value,8), iVar1 == 0)) {
    nvs_sector_advance(fs,&local_60);
  }
  iVar1 = nvs_recover_last_ate(fs,&local_60);
  if (iVar1 == 0) {
    uVar8 = local_60 & 0xffff0000;
    fs->ate_wra = local_60;
    fs->data_wra = uVar8;
    while (fs->data_wra <= fs->ate_wra) {
      iVar1 = nvs_flash_rd(fs,fs->ate_wra,&local_5c,8);
      if (iVar1 != 0) goto LAB_0004f912;
      iVar1 = 0;
      pnVar5 = &local_5c;
      while (value == (uint8_t)pnVar5->id) {
        iVar1 = iVar1 + 1;
        pnVar5 = (nvs_ate *)((int)&pnVar5->id + 1);
        if (iVar1 == 8) goto LAB_0004f952;
      }
      iVar1 = nvs_ate_valid(fs,&local_5c);
      dVar6 = fs->ate_wra;
      if (iVar1 != 0) {
        uVar7 = (uint)local_5c.len;
        fs_00 = *(nvs_fs **)((int)&fs[1].data_wra + 3);
        fs->data_wra = uVar8;
        sVar4 = nvs_al_size(fs_00,local_5c.offset + uVar7);
        fs->data_wra = sVar4 + uVar8;
        dVar6 = extraout_r2;
        if ((sVar4 + uVar8 == extraout_r2) && (uVar7 != 0)) {
          iVar1 = -0x1d;
          goto LAB_0004fb44;
        }
      }
      fs->ate_wra = dVar6 - sVar3;
    }
LAB_0004f952:
    local_60 = fs->ate_wra & 0xffff0000;
    nvs_sector_advance(fs,&local_60);
    iVar1 = nvs_flash_cmp_const(fs,local_60,value,(uint)fs->sector_size);
    if (iVar1 < 0) goto LAB_0004f912;
    dVar6 = fs->ate_wra;
    if (iVar1 == 0) {
      while( true ) {
        addr = fs->data_wra;
        if (fs->ate_wra <= addr) break;
        iVar1 = nvs_flash_cmp_const(fs,addr,value,fs->ate_wra - addr);
        if (iVar1 < 0) goto LAB_0004f912;
        if (iVar1 == 0) break;
        fs->data_wra = fs->data_wra + **(int **)((int)&fs[1].data_wra + 3);
      }
      uVar8 = fs->ate_wra;
      if ((uVar8 + sVar3 * 2 == (uint)fs->sector_size) && (fs->data_wra != (uVar8 & 0xffff0000))) {
        iVar1 = nvs_flash_erase_sector(fs,uVar8);
        if (iVar1 != 0) goto LAB_0004f912;
        fs->data_wra = fs->ate_wra & 0xffff0000;
        goto LAB_0004fab4;
      }
    }
    else {
      do {
        dVar6 = sVar3 + dVar6;
        local_60 = dVar6;
        if (fs->sector_size - sVar3 <= (dVar6 & 0xffff)) {
          local_2c = "No GC Done marker found: restarting gc";
          local_30[0] = '\x02';
          local_30[1] = '\0';
          local_30[2] = '\0';
          local_30[3] = '\0';
          LOG_ERR(&PTR_s_fs_nvs_0008b968,0x10c0,local_30);
          iVar1 = nvs_flash_erase_sector(fs,fs->ate_wra);
          if (iVar1 != 0) goto LAB_0004f912;
          uVar8 = (fs->ate_wra & 0xffff0000) + (uint)fs->sector_size + sVar3 * -2;
          fs->ate_wra = uVar8;
          fs->data_wra = uVar8 & 0xffff0000;
          iVar1 = nvs_startup(fs);
          goto LAB_0004f9d0;
        }
        iVar1 = nvs_flash_rd(fs,dVar6,&local_54,8);
        if (iVar1 != 0) goto LAB_0004f912;
        iVar1 = nvs_ate_valid(fs,&local_54);
      } while (((iVar1 == 0) || (local_54.id != 0xffff)) || (local_54.len != 0));
      local_2c = "GC Done marker found";
      local_30[0] = '\x02';
      local_30[1] = '\0';
      local_30[2] = '\0';
      local_30[3] = '\0';
      LOG_ERR(&PTR_s_fs_nvs_0008b968,0x10c0,local_30);
      local_60 = fs->ate_wra & 0xffff0000;
      nvs_sector_advance(fs,&local_60);
      iVar1 = nvs_flash_erase_sector(fs,local_60);
    }
LAB_0004f9d0:
    if (iVar1 == 0) {
LAB_0004fab4:
      if ((uint)(ushort)fs->ate_wra == (uint)fs->sector_size + sVar3 * -2) {
        iVar1 = nvs_add_gc_done_ate(fs);
LAB_0004fb44:
        z_impl_k_mutex_unlock(mutex);
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      else {
        z_impl_k_mutex_unlock(mutex);
      }
      fs->ready = 1;
      local_68 = (uint)fs->sector_count;
      local_64 = (uint)fs->sector_size;
      local_6c = "%d Sectors of %d bytes";
      local_70[0] = '\x04';
      local_70[1] = '\0';
      local_70[2] = '\0';
      local_70[3] = '\0';
      LOG_ERR(&PTR_s_fs_nvs_0008b968,0x20c0,local_70);
      local_6c = "alloc wra: %d, %x";
      local_68 = fs->ate_wra >> 0x10;
      local_64 = fs->ate_wra & 0xffff;
      local_70[0] = '\x04';
      local_70[1] = '\0';
      local_70[2] = '\0';
      local_70[3] = '\0';
      LOG_ERR(&PTR_s_fs_nvs_0008b968,0x20c0,local_70);
      local_70[0] = '\x04';
      local_70[1] = '\0';
      local_70[2] = '\0';
      local_70[3] = '\0';
      local_6c = "data wra: %d, %x";
      local_68 = fs->data_wra >> 0x10;
      local_64 = fs->data_wra & 0xffff;
      LOG_ERR(&PTR_s_fs_nvs_0008b968,0x20c0,local_70);
      return 0;
    }
  }
LAB_0004f912:
  z_impl_k_mutex_unlock(mutex);
  return iVar1;
}


