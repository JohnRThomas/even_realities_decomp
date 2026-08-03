/*
 * Function: img_mgmt_upload
 * Entry:    000554a8
 * Prototype: int __stdcall img_mgmt_upload(smp_streamer * ctxt)
 */


/* WARNING: Type propagation algorithm not settling */
/* exclude_from_export_ai */

int img_mgmt_upload(smp_streamer *ctxt)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  uint offset;
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  dword in_stack_fffffee8;
  uint8_t *in_stack_fffffeec;
  void *in_stack_fffffef0;
  undefined4 local_108;
  char *local_104;
  int iStack_100;
  size_t local_f4;
  uint local_f0 [2];
  uint local_e8;
  undefined4 local_e4;
  char local_e0;
  img_mgmt_upload_req iStack_d8;
  uint local_d4 [2];
  void *local_cc;
  int local_c8;
  void *local_c4;
  size_t local_c0;
  undefined1 auStack_bc [4];
  uint8_t auStack_b8 [32];
  char *local_98;
  undefined4 local_94;
  undefined4 local_90;
  img_mgmt_upload_req *piStack_8c;
  undefined1 local_88;
  char *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  void **local_78;
  undefined1 local_74;
  char *local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint *local_64;
  undefined1 local_60;
  char *local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  uint *local_50;
  undefined1 local_4c;
  char *local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  void **local_3c;
  undefined1 local_38;
  char *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined1 local_24;
  
  puVar4 = ctxt->reader;
  puVar5 = ctxt->writer;
  local_f4 = 0;
  memset(&iStack_d8,0,0x20);
  local_d4[0] = 0xffffffff;
  local_d4[1] = 0xffffffff;
  local_98 = "image";
  local_94 = 5;
  local_78 = &local_cc;
  local_90 = 0x8973d;
  local_84 = "data";
  local_80 = 4;
  local_7c = 0x89747;
  local_40 = 0x89747;
  local_3c = &local_c4;
  local_70 = "len";
  local_34 = "upgrade";
  local_64 = local_d4 + 1;
  local_68 = 0x89743;
  local_54 = 0x89743;
  local_30 = 7;
  local_50 = local_d4;
  local_2c = 0x897b7;
  local_28 = auStack_bc;
  local_5c = "off";
  uStack_58 = 3;
  local_48 = "sha";
  uStack_44 = 3;
  local_88 = 0;
  local_74 = 0;
  local_60 = 0;
  local_4c = 0;
  local_38 = 0;
  local_24 = 0;
  local_6c = 3;
  piStack_8c = &iStack_d8;
  iVar2 = zcbor_map_decode_bulk
                    ((zcbor_state_t *)(puVar4 + 4),(zcbor_map_decode_key_val *)&local_98,6,&local_f4
                    );
  if (iVar2 != 0) {
    return 3;
  }
  iVar3 = img_mgmt_upload_inspect(&iStack_d8,(img_mgmt_upload_action *)local_f0);
  offset = local_d4[0];
  iVar2 = 0;
  if (iVar3 == 0) {
    if (local_e0 == '\0') {
      iVar2 = img_mgmt_upload_good_rsp((smp_streamer *)ctxt->writer);
      return iVar2;
    }
    DAT_2000b55c = local_e4;
    DAT_2000b564 = local_f0[0];
    if (local_d4[0] == 0) {
      DAT_2000b560 = local_d4[0];
      DAT_2000b568 = (undefined1)local_c0;
      memcpy(&DAT_2000b569,local_c4,local_c0);
      memset(&DAT_2000b569 + local_c0,0,0x20 - local_c0);
    }
    if (local_c8 == 0) {
      if (DAT_2000b564 == DAT_2000b560) {
        img_mgmt_read_info(1,(image_version *)0x0,auStack_b8,(uint32_t *)0x0);
      }
    }
    else {
      iVar3 = img_mgmt_write_image_data
                        (offset,local_cc,local_e8,local_c8 + DAT_2000b560 == DAT_2000b564);
      if (iVar3 != 0) {
        local_104 = "Irrecoverable error: flash write failed: %d";
        local_108 = 3;
        desc.level = (dword)&local_108;
        desc.domain = 0x1840;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_fffffee8;
        iStack_100 = iVar3;
        z_impl_z_log_msg_static_create
                  (&PTR_s_mcumgr_img_grp_0008b9b8,desc,in_stack_fffffeec,in_stack_fffffef0);
        goto LAB_000555ac;
      }
      DAT_2000b560 = DAT_2000b560 + local_e8;
      if (DAT_2000b560 == DAT_2000b564) {
        img_mgmt_read_info(1,(image_version *)0x0,auStack_b8,(uint32_t *)0x0);
        img_mgmt_upload_good_rsp((smp_streamer *)ctxt->writer);
        img_mgmt_reset_upload();
        return 0;
      }
    }
    img_mgmt_upload_good_rsp((smp_streamer *)ctxt->writer);
  }
  else {
    local_104 = "Image upload inspect failed: %d";
    local_108 = 3;
    desc_00.level = (dword)&local_108;
    desc_00.domain = 0x1840;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_fffffee8;
    iStack_100 = iVar3;
    z_impl_z_log_msg_static_create
              (&PTR_s_mcumgr_img_grp_0008b9b8,desc_00,in_stack_fffffeec,in_stack_fffffef0);
LAB_000555ac:
    bVar1 = smp_add_cmd_err((zcbor_state_t *)(puVar5 + 4),1,(uint16_t)iVar3);
    img_mgmt_read_info(1,(image_version *)0x0,auStack_b8,(uint32_t *)0x0);
    img_mgmt_reset_upload();
    if (!bVar1) {
      iVar2 = 7;
    }
  }
  return iVar2;
}


