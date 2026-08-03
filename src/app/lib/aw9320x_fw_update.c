/*
 * Function: aw9320x_fw_update
 * Entry:    00031bf4
 * Prototype: int32_t __stdcall aw9320x_fw_update(uint8_t load_fw_mode)
 */


/* exclude_from_export_ai */

int32_t aw9320x_fw_update(uint8_t load_fw_mode)

{
  uint uVar1;
  int8_t iVar2;
  aw9320x_err_code aVar3;
  uint8_t *para_data;
  int32_t iVar4;
  uint32_t uVar5;
  undefined *puVar6;
  uint8_t *send_value;
  uint32_t in_r1;
  int iVar7;
  undefined1 *puVar8;
  uint8_t uVar9;
  bool bVar10;
  uint32_t local_4c;
  uint local_48;
  uint32_t local_44;
  undefined *local_40;
  undefined *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  uint local_2c;
  
  para_data = (uint8_t *)(uint)load_fw_mode;
  iVar4 = aw9320x_check_sum(para_data,in_r1);
  if (iVar4 != 0) {
    return -1;
  }
  if (para_data == (uint8_t *)0x0) {
    local_38 = para_data;
    iVar2 = aw9320x_i2c_read(0x1ba8,&local_38);
    if (iVar2 < '\0') {
      return 0;
    }
    if (local_38 == (uint8_t *)0x6000007) {
      return 0;
    }
  }
  local_4c = 0;
  local_44 = 0;
  local_38 = (undefined *)0x0;
  aVar3 = aw9320x_i2c_write(0x4408,0x14);
  if (aVar3 == AW_OK) {
    AW_DELAY(1);
    iVar7 = 200;
    while( true ) {
      iVar2 = aw9320x_i2c_read(0x4410,&local_38);
      puVar6 = (undefined *)(int)iVar2;
      if (puVar6 != (undefined *)0x0) break;
      if ((int)local_38 << 2 < 0) {
        local_40 = puVar6;
        local_3c = puVar6;
        local_38 = puVar6;
        iVar2 = aw9320x_i2c_read(0x1c30,(uint32_t *)&local_40);
        if ((((iVar2 == '\0') &&
             (iVar2 = aw9320x_i2c_read(0x1c34,(uint32_t *)&local_3c), iVar2 == '\0')) &&
            (aVar3 = aw9320x_i2c_write(0xff20,(uint32_t)&uint32_t_3c00f091), aVar3 == AW_OK)) &&
           ((aVar3 = aw9320x_i2c_write(0x4820,4), aVar3 == AW_OK &&
            (iVar4 = aw9320x_reg_read_val(&local_38,0x7fc), iVar4 == 0)))) {
          uVar5 = aw9320x_get_bin_checksum(fw_para_data + 0x48,0x1b9c,0x37f8);
          local_48 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                     uVar5 >> 0x18;
          AW_UPDATE_FW_STATE_2001aa7b = SEND_START_CMD;
          iVar4 = aw9320x_send_once_cmd('\x01','\x01',(uint8_t *)0x0,0);
          if (iVar4 == 0) {
            local_38 = (undefined *)0x803f0010;
            AW_UPDATE_FW_STATE_2001aa7b = SEND_ERASE_SECTOR_CMD;
            puVar6 = (undefined *)aw9320x_send_once_cmd('\x02','\x02',(uint8_t *)&local_38,4);
            uVar1 = local_48;
            if (puVar6 == (undefined *)0x0) {
              AW_UPDATE_FW_STATE_2001aa7b = SEND_UPDATE_CHECK_CODE_CMD;
              local_30 = &DAT_22202220;
              local_34 = 0xf83f0010;
              local_2c = local_48;
              local_40 = puVar6;
              local_3c = puVar6;
              local_38 = puVar6;
              iVar4 = aw9320x_send_once_cmd('\x01','\x02',(uint8_t *)&local_38,0x10);
              if (((iVar4 == 0) &&
                  (iVar4 = aw9320x_reg_read_val((uint32_t *)&local_40,0x3ff8), iVar4 == 0)) &&
                 ((iVar4 = aw9320x_reg_read_val((uint32_t *)&local_3c,0x3ffc), iVar4 == 0 &&
                  ((local_40 == &DAT_20222022 &&
                   (local_3c ==
                    (undefined *)
                    (uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
                    uVar1 >> 0x18))))))) {
                puVar8 = &DAT_10002000;
                goto LAB_00031dfa;
              }
            }
          }
        }
        break;
      }
      AW_DELAY(1);
      bVar10 = iVar7 == 0;
      iVar7 = iVar7 + -1;
      if (bVar10) break;
    }
  }
  goto LAB_00031c56;
  while (puVar8 = puVar8 + 0x80, puVar8 != &DAT_10003f80) {
LAB_00031dfa:
    local_38 = (uint8_t *)
               CONCAT22((ushort)(((uint)puVar8 & 0xff) << 8) | (ushort)((uint)puVar8 >> 8) & 0xff,
                        0x10);
    AW_UPDATE_FW_STATE_2001aa7b = SEND_ERASE_SECTOR_CMD;
    iVar4 = aw9320x_send_once_cmd('\x02','\x02',(uint8_t *)&local_38,4);
    if (iVar4 != 0) goto LAB_00031c56;
  }
  uVar9 = '\x01';
  puVar8 = &DAT_10002000;
  AW_UPDATE_FW_STATE_2001aa7b = SEND_UPDATE_FW_CMD;
  do {
    send_value = malloc(0x108);
    if (send_value == (uint8_t *)0x0) goto LAB_00031c56;
    memset(send_value,1,0x108);
    send_value[4] = '\x10';
    send_value[5] = '\0';
    send_value[0] = '\0';
    send_value[1] = '\0';
    send_value[2] = '\0';
    send_value[6] = (uint8_t)((uint)puVar8 >> 8);
    send_value[7] = '\0';
    send_value[3] = uVar9;
    memcpy(send_value + 8,&DAT_f00a53a2 + (int)puVar8,0x100);
    iVar4 = aw9320x_send_once_cmd('\x01','\x02',send_value,0x108);
    if (iVar4 != 0) goto LAB_00031c68;
    free(send_value);
    puVar8 = puVar8 + 0x100;
    uVar9 = uVar9 + '\x01';
  } while (puVar8 != &DAT_10003b00);
  send_value = malloc(0xa4);
  if (send_value != (uint8_t *)0x0) {
    memset(send_value + 1,1,0xa3);
    *(undefined1 **)(send_value + 4) = &DAT_003b0010;
    send_value[0] = '\0';
    send_value[1] = '\0';
    send_value[2] = '\0';
    send_value[3] = uVar9;
    memcpy(send_value + 8,fw_para_data + 0x1b48,0x9c);
    iVar4 = aw9320x_send_once_cmd('\x01','\x02',send_value,0xa4);
    if (iVar4 == 0) {
      free(send_value);
      AW_UPDATE_FW_STATE_2001aa7b = SEND_STOP_CMD;
      iVar7 = 10;
      aw9320x_i2c_write(0x4444,0x10000);
      aw9320x_i2c_write(0xff20,(uint32_t)&DAT_3c00ffff);
      aw9320x_i2c_read(0x4744,&local_38);
      aw9320x_i2c_write(0x4744,(uint)local_38 & 0xffffff);
      aw9320x_i2c_write(0xff20,(uint32_t)&DAT_3c00f011);
      aw9320x_i2c_write(0x4444,0);
      AW_DELAY(0x19);
      local_38 = (undefined *)0x0;
      do {
        iVar2 = aw9320x_i2c_read(0x4410,&local_38);
        if (iVar2 != '\0') break;
        if ((int)local_38 << 0x1f < 0) {
          return 0;
        }
        AW_DELAY(1);
        bVar10 = iVar7 != 0;
        iVar7 = iVar7 + -1;
      } while (bVar10);
    }
    else {
LAB_00031c68:
      free(send_value);
    }
  }
LAB_00031c56:
  aVar3 = aw9320x_i2c_write(0xff20,(uint32_t)&uint32_t_3c00f091);
  if ((((aVar3 == AW_OK) && (iVar2 = aw9320x_i2c_read(0x4748,&local_44), iVar2 == '\0')) &&
      ((local_44 == 0 || (aVar3 = aw9320x_i2c_write(0x4748,0), aVar3 == AW_OK)))) &&
     (((iVar2 = aw9320x_i2c_read(0x4744,&local_4c), iVar2 == '\0' &&
       (((local_4c >> 0x18 == 0 ||
         (aVar3 = aw9320x_i2c_write(0x4744,local_4c & 0xffffff), aVar3 == AW_OK)) &&
        (aVar3 = aw9320x_i2c_write(0xff20,(uint32_t)&DAT_3c00f011), aVar3 == AW_OK)))) &&
      (para_data != &DAT_00000001)))) {
    return -3;
  }
  return -1;
}


