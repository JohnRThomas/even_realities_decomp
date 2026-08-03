/*
 * Function: img_mgmt_state_write
 * Entry:    00055148
 * Prototype: int __stdcall img_mgmt_state_write(smp_streamer * njb)
 */


/* exclude_from_export_ai */

int img_mgmt_state_write(smp_streamer *njb)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint16_t ret;
  undefined4 *puVar5;
  undefined *puVar6;
  uint8_t *puVar7;
  bool local_6d;
  size_t local_6c;
  undefined4 *local_68;
  int local_64;
  uint8_t local_60 [4];
  undefined4 auStack_5c [7];
  char *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 **ppuStack_34;
  undefined1 local_30;
  char *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  bool *local_20;
  undefined1 local_1c;
  
  local_40 = "hash";
  local_3c = 4;
  ppuStack_34 = &local_68;
  local_38 = 0x89747;
  local_2c = "confirm";
  local_28 = 7;
  puVar6 = njb->writer;
  local_24 = 0x897b7;
  local_20 = &local_6d;
  local_68 = (undefined4 *)0x0;
  local_64 = 0;
  local_6d = false;
  local_6c = 0;
  local_30 = 0;
  local_1c = 0;
  iVar2 = zcbor_map_decode_bulk
                    ((zcbor_state_t *)(njb->reader + 4),(zcbor_map_decode_key_val *)&local_40,2,
                     &local_6c);
  if (iVar2 != 0) {
    return 3;
  }
  img_mgmt_take_lock();
  if (local_64 == 0) {
    if (local_6d == false) {
LAB_000551c2:
      ret = 0x18;
      goto LAB_000551c4;
    }
    iVar2 = img_mgmt_active_image();
    iVar2 = img_mgmt_active_slot(iVar2);
  }
  else {
    if (local_64 != 0x20) goto LAB_000551c2;
    puVar7 = local_60;
    puVar5 = local_68;
    do {
      uVar3 = *puVar5;
      uVar4 = puVar5[1];
      puVar5 = puVar5 + 2;
      *(undefined4 *)puVar7 = uVar3;
      *(undefined4 *)(puVar7 + 4) = uVar4;
      puVar7 = puVar7 + 8;
    } while (puVar5 != local_68 + 8);
    iVar2 = img_mgmt_find_by_hash(local_60,(image_version *)0x0);
    if (iVar2 < 0) {
      ret = 8;
      goto LAB_000551c4;
    }
  }
  iVar2 = img_mgmt_set_next_boot_slot(iVar2,local_6d);
  if (iVar2 == 0) {
    iVar2 = img_mgmt_state_read(njb);
    if (iVar2 == 0) {
      img_mgmt_release_lock();
      return 0;
    }
    img_mgmt_release_lock();
    return iVar2;
  }
  ret = (uint16_t)iVar2;
LAB_000551c4:
  bVar1 = smp_add_cmd_err((zcbor_state_t *)(puVar6 + 4),1,ret);
  img_mgmt_release_lock();
  if (bVar1) {
    return 0;
  }
  return 7;
}


