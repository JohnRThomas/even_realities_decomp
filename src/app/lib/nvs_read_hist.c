/*
 * Function: nvs_read_hist
 * Entry:    0004fd54
 * Prototype: ssize_t __stdcall nvs_read_hist(nvs_fs * fs, uint16_t id, void * data, size_t len, uint16_t cnt)
 */


/* exclude_from_export */

ssize_t nvs_read_hist(nvs_fs *fs,uint16_t id,void *data,size_t len,uint16_t cnt)

{
  ssize_t sVar1;
  size_t sVar2;
  int iVar3;
  dword dVar4;
  uint len_00;
  ushort uVar5;
  dword dVar6;
  dword local_3c;
  nvs_ate local_38 [2];
  char local_28 [4];
  char *local_24;
  
  if (fs->ready == 0) {
    local_24 = "NVS not initialized";
    local_28[0] = '\x02';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    LOG_ERR(&PTR_s_fs_nvs_0008b968,0x1040,local_28);
    sVar1 = -0xd;
  }
  else {
    sVar2 = nvs_al_size(*(nvs_fs **)((int)&fs[1].data_wra + 3),8);
    if ((uint)fs->sector_size + sVar2 * -2 < len) {
      sVar1 = -0x16;
    }
    else {
      uVar5 = 0;
      local_3c = fs->ate_wra;
      dVar6 = local_3c;
      do {
        dVar4 = local_3c;
        if (cnt < uVar5) {
          dVar4 = dVar6;
          if (fs->ate_wra != local_3c) goto LAB_0004fdf2;
          break;
        }
        iVar3 = nvs_prev_ate(fs,&local_3c,local_38);
        if (iVar3 != 0) {
          return iVar3;
        }
        if ((local_38[0].id == id) && (iVar3 = nvs_ate_valid(fs,local_38), iVar3 != 0)) {
          uVar5 = uVar5 + 1;
        }
        dVar6 = dVar4;
      } while (fs->ate_wra != local_3c);
      if (local_38[0].id == id) {
LAB_0004fdf2:
        len_00 = (uint)local_38[0].len;
        if ((len_00 != 0) && (cnt <= uVar5)) {
          if (len <= len_00) {
            len_00 = len;
          }
          iVar3 = nvs_flash_rd(fs,(dVar4 & 0xffff0000) + (uint)local_38[0].offset,data,len_00);
          if (iVar3 != 0) {
            return iVar3;
          }
          return (uint)local_38[0].len;
        }
      }
      sVar1 = -2;
    }
  }
  return sVar1;
}


