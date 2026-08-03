/*
 * Function: nvs_write
 * Entry:    0004fb98
 * Prototype: ssize_t __stdcall nvs_write(nvs_fs * fs, uint16_t id, void * data, size_t len)
 */


/* exclude_from_export */

ssize_t nvs_write(nvs_fs *fs,uint16_t id,void *data,size_t len)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar4;
  nvs_fs *fs_00;
  uint extraout_r2;
  k_mutex *mutex;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  k_timeout_t timeout;
  uint local_4c;
  nvs_ate local_48;
  nvs_ate local_40 [2];
  char local_30 [4];
  char *local_2c;
  
  if (fs->ready == 0) {
    sVar5 = 0xfffffff3;
    local_2c = "NVS not initialized";
    local_30[0] = '\x02';
    local_30[1] = '\0';
    local_30[2] = '\0';
    local_30[3] = '\0';
    LOG_ERR(&PTR_s_fs_nvs_0008b968,0x1040,local_30);
  }
  else {
    sVar1 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
    sVar2 = nvs_al_size(fs_00,len);
    if (((uint)fs->sector_size + sVar1 * -4 < len) || ((len != 0 && (data == (void *)0x0)))) {
      sVar5 = 0xffffffea;
    }
    else {
      local_4c = fs->ate_wra;
      do {
        uVar7 = local_4c;
        iVar3 = nvs_prev_ate(fs,&local_4c,&local_48);
        if (iVar3 != 0) {
          return iVar3;
        }
        uVar4 = extraout_r1;
        if ((local_48.id == id) &&
           (iVar3 = nvs_ate_valid(fs,&local_48), uVar4 = extraout_r1_00, iVar3 != 0)) {
          uVar6 = (uint)local_48.len;
          if (len != 0) {
            if ((local_48.len == len) &&
               (iVar3 = nvs_flash_block_cmp(fs,(uVar7 & 0xffff0000) + (uint)local_48.offset,data,len
                                           ), uVar4 = extraout_r1_01, iVar3 < 1)) {
              return iVar3;
            }
            goto LAB_0004fc5a;
          }
          break;
        }
        uVar6 = len;
      } while (fs->ate_wra != local_4c);
      sVar5 = 0;
      if (uVar6 != 0) {
LAB_0004fc5a:
        uVar7 = 0;
        if (sVar2 != 0) {
          uVar7 = sVar2 + sVar1 & 0xffff;
        }
        mutex = (k_mutex *)((int)&fs->nvs_lock + 3);
        timeout.ticks._4_4_ = 0xffffffff;
        timeout.ticks._0_4_ = uVar4;
        z_impl_k_mutex_lock(mutex,timeout);
        for (uVar6 = 0; uVar6 != fs->sector_count; uVar6 = uVar6 + 1) {
          if (uVar7 + fs->data_wra <= fs->ate_wra) {
            local_40[0].offset = (word)fs->data_wra;
            local_40[0].part = 0xff;
            local_40[0].len = (word)len;
            local_40[0].id = id;
            nvs_ate_crc8_update(local_40);
            sVar5 = nvs_flash_al_wrt(fs,fs->data_wra,data,len);
            sVar1 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),len);
            fs->data_wra = fs->data_wra + sVar1;
            if ((sVar5 == 0) && (sVar5 = nvs_flash_ate_wrt(fs,local_40), sVar5 == 0)) {
              sVar5 = len;
            }
            goto LAB_0004fcd0;
          }
          sVar1 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
          local_40[0].id = 0xffff;
          local_40[0].part = 0xff;
          local_40[0].len = 0;
          local_40[0].offset = (short)extraout_r2 + (short)sVar1;
          fs->ate_wra = ((extraout_r2 & 0xffff0000) + (uint)fs->sector_size) - sVar1;
          nvs_ate_crc8_update(local_40);
          nvs_flash_ate_wrt(fs,local_40);
          nvs_sector_advance(fs,&fs->ate_wra);
          fs->data_wra = fs->ate_wra & 0xffff0000;
          sVar5 = nvs_startup(fs);
          if (sVar5 != 0) goto LAB_0004fcd0;
        }
        sVar5 = 0xffffffe4;
LAB_0004fcd0:
        z_impl_k_mutex_unlock(mutex);
      }
    }
  }
  return sVar5;
}


