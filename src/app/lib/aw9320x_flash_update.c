/*
 * Function: aw9320x_flash_update
 * Entry:    000319c8
 * Prototype: int32_t __stdcall aw9320x_flash_update(aw_update_common * update_info)
 */


/* exclude_from_export_ai */

int32_t aw9320x_flash_update(aw_update_common *update_info)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  ushort uVar5;
  aw9320x_err_code aVar6;
  uint uVar7;
  uint32_t uVar8;
  int32_t iVar9;
  uint32_t *puVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  uint local_1c;
  
  aVar6 = aw9320x_i2c_write(0xff20,0x3c00ffff);
  uVar7 = (uint)aVar6;
  if (uVar7 == 0) {
    aVar6 = aw9320x_i2c_write(0x4444,0x10000);
    uVar7 = (uint)aVar6;
    if (uVar7 == 0) {
      aVar6 = aw9320x_i2c_write(0x4820,6);
      uVar7 = (uint)aVar6;
      if (uVar7 == 0) {
        if (update_info->update_flag == '\x01') {
          aVar6 = aw9320x_i2c_write(0x4794,0x5a637955);
          if (aVar6 != 0) {
            return (uint)aVar6;
          }
        }
        uVar11 = **(uint **)((int)&update_info->check_info + 3);
        aVar6 = aw9320x_i2c_write(0xff20,0x3c00f091);
        uVar7 = (uint)aVar6;
        if (uVar7 == 0) {
          aVar6 = aw9320x_i2c_write(0x4820,6);
          uVar7 = (uint)aVar6;
          if (uVar7 == 0) {
            if (update_info->update_flag == '\0') {
              aVar6 = aw9320x_i2c_write(0x4794,0x5a637955);
              if (aVar6 != 0) {
                return (uint)aVar6;
              }
            }
            for (iVar12 = 0; (uint)((uVar11 & 0x7f) != 0) + (uVar11 >> 7) != iVar12;
                iVar12 = iVar12 + 1) {
              aVar6 = aw9320x_i2c_write(0x4704,*(int *)(*(int *)((int)&update_info->check_info + 3)
                                                       + 4) + iVar12 * 0x80);
              if (aVar6 != 0) {
                return (uint)aVar6;
              }
              aVar6 = aw9320x_i2c_write(0x4710,5);
              if (aVar6 != 0) {
                return (uint)aVar6;
              }
              aVar6 = aw9320x_i2c_write(0x472c,0xf0);
              if (aVar6 != 0) {
                return (uint)aVar6;
              }
              aVar6 = aw9320x_i2c_write(0x4714,1);
              if (aVar6 != 0) {
                return (uint)aVar6;
              }
              iVar9 = aw9320x_check_isp_go_reg();
              if (iVar9 != 0) {
                return iVar9;
              }
            }
            aVar6 = aw9320x_i2c_write(0x472c,0x16);
            uVar7 = (uint)aVar6;
            if (uVar7 == 0) {
              aVar6 = aw9320x_i2c_write(0x4820,4);
              uVar7 = (uint)aVar6;
              if (uVar7 == 0) {
                pbVar13 = *(byte **)((int)&update_info->w_bin_offset + 3);
                uVar11 = *(uint *)((int)&update_info->update_data_len + 3);
                uVar5 = *(ushort *)((int)&update_info->flash_tr_start_addr + 3);
                iVar12 = print_object((uint)update_info->update_flag);
                uVar7 = 0;
                if (iVar12 == 0) {
                  for (; uVar7 < uVar11; uVar7 = uVar7 + 4) {
                    iVar12 = FUN_000804e6(uVar5 + uVar7 & 0xffff,
                                          (uint)pbVar13[1] << 0x10 | (uint)*pbVar13 << 0x18 |
                                          (uint)pbVar13[3] | (uint)pbVar13[2] << 8);
                    pbVar13 = pbVar13 + 4;
                    if (iVar12 != 0) goto LAB_00031ac2;
                  }
                  aVar6 = aw9320x_i2c_write(0x4820,4);
                  local_1c = (uint)aVar6;
                  if (local_1c == 0) {
                    pbVar13 = *(byte **)((int)&update_info->w_bin_offset + 3);
                    uVar7 = *(uint *)((int)&update_info->update_data_len + 3);
                    aVar6 = aw9320x_i2c_write(0xff20,0x3c00f091);
                    if (aVar6 == AW_OK) {
                      aVar6 = aw9320x_i2c_write(0x4820,4);
                      uVar11 = 0;
                      if (aVar6 == AW_OK) {
                        for (; uVar11 < uVar7; uVar11 = uVar11 + 4) {
                          iVar9 = aw9320x_reg_read_val
                                            (&local_1c,
                                             (short)*(undefined4 *)
                                                     ((int)&update_info->flash_tr_start_addr + 3) +
                                             (short)uVar11);
                          if ((iVar9 != 0) ||
                             (pbVar1 = pbVar13 + 1, bVar4 = *pbVar13, pbVar2 = pbVar13 + 3,
                             pbVar3 = pbVar13 + 2, pbVar13 = pbVar13 + 4,
                             ((uint)*pbVar1 << 0x10 | (uint)bVar4 << 0x18 | (uint)*pbVar2 |
                             (uint)*pbVar3 << 8) != local_1c)) goto LAB_00031ac2;
                        }
                        iVar12 = FUN_00080534((uint)*(ushort *)
                                                     (*(int *)((int)&update_info->check_info + 3) +
                                                     8),0x20222022,(uint)update_info->update_flag);
                        if (iVar12 == 0) {
                          puVar10 = *(uint32_t **)((int)&update_info->check_info + 3);
                          uVar8 = aw9320x_get_bin_checksum
                                            (*(uint8_t **)((int)&update_info->w_bin_offset + 3),
                                             *(uint32_t *)((int)&update_info->update_data_len + 3),
                                             *puVar10);
                          iVar12 = FUN_00080534((uint)(ushort)puVar10[3],uVar8,
                                                (uint)update_info->update_flag);
                          if (iVar12 == 0) {
                            if (update_info->update_flag != '\x01') {
                              return 0;
                            }
                            aVar6 = aw9320x_i2c_write(0x4794,0);
                            return (uint)aVar6;
                          }
                        }
                      }
                    }
                  }
                }
LAB_00031ac2:
                uVar7 = 0xffffffff;
              }
            }
          }
        }
      }
    }
  }
  return uVar7;
}


