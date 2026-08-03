/*
 * Function: bt_ancs_parse_get_attrs_response
 * Entry:    00052470
 * Prototype: void __stdcall bt_ancs_parse_get_attrs_response(bt_ancs_client * ancs_c, uint8_t * data_src, uint16_t data_len)
 */


/* exclude_from_export */

void bt_ancs_parse_get_attrs_response(bt_ancs_client *ancs_c,uint8_t *data_src,uint16_t data_len)

{
  uint8_t *puVar1;
  bt_ancs_client bVar2;
  ushort uVar3;
  log_msg_desc desc;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  bt_ancs_client bVar7;
  int iVar8;
  uint uVar9;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  
  uVar6 = 0;
switchD_0005249c_caseD_8:
  uVar9 = uVar6;
  if (data_len <= uVar9) {
    return;
  }
  bVar7 = ancs_c[0x1108];
  uVar6 = (uint)data_len;
  switch(bVar7) {
  case (bt_ancs_client)0x0:
    bVar7 = *(bt_ancs_client *)(data_src + uVar9);
    ancs_c[0x1109] = bVar7;
    if (bVar7 == (bt_ancs_client)0x0) {
      ancs_c[0x1118] = (bt_ancs_client)0x0;
      *(bt_ancs_client **)(ancs_c + 0x10fc) = ancs_c + 0x1068;
      *(undefined4 *)(ancs_c + 0x1100) = 8;
      bVar7 = (bt_ancs_client)0x1;
    }
    else {
      if (bVar7 != (bt_ancs_client)0x1) goto LAB_000524d2;
      *(bt_ancs_client **)(ancs_c + 0x10fc) = ancs_c + 0x10e8;
      *(undefined4 *)(ancs_c + 0x1100) = 1;
      ancs_c[0x1118] = (bt_ancs_client)0x1;
      *(undefined4 *)(ancs_c + 0x1114) = 0;
      bVar7 = (bt_ancs_client)0x2;
    }
    goto LAB_000524ec;
  case (bt_ancs_client)0x1:
    *(undefined4 *)(ancs_c + 0x1128) = *(undefined4 *)(data_src + uVar9);
    bVar7 = (bt_ancs_client)0x3;
    uVar6 = uVar9 + 4;
    break;
  case (bt_ancs_client)0x2:
    uVar4 = *(uint *)(ancs_c + 0x1114);
    if (uVar4 < 0x100) {
      uVar6 = uVar9 + 1;
      bVar2 = *(bt_ancs_client *)(data_src + uVar9);
      ancs_c[uVar4 + 0x112c] = bVar2;
      if (bVar2 == (bt_ancs_client)0x0) {
        bVar7 = (bt_ancs_client)0x3;
      }
      else {
        *(uint *)(ancs_c + 0x1114) = uVar4 + 1;
      }
    }
    else {
      local_24 = "App ID cannot be stored in response buffer.";
      local_28 = 2;
      desc.level = (dword)&local_28;
      desc.domain = 0x1080;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffc8;
      z_impl_z_log_msg_static_create
                (&PTR_s_ancs_c_0008b898,desc,in_stack_ffffffcc,in_stack_ffffffd0);
      bVar7 = (bt_ancs_client)0x8;
      uVar6 = uVar9;
    }
    break;
  case (bt_ancs_client)0x3:
    uVar6 = (uint)data_src[uVar9];
    *(uint *)(ancs_c + 0x1120) = uVar6;
    if (uVar6 < *(uint *)(ancs_c + 0x1100)) {
      *(undefined4 *)(ancs_c + 0x1124) =
           *(undefined4 *)(*(int *)(ancs_c + 0x10fc) + uVar6 * 0x10 + 0xc);
      if (*(int *)(ancs_c + 0x1104) != 0) {
        if (*(char *)(*(int *)(ancs_c + 0x10fc) + uVar6 * 0x10) != '\0') {
          *(int *)(ancs_c + 0x1104) = *(int *)(ancs_c + 0x1104) + -1;
        }
        bVar7 = (bt_ancs_client)0x4;
        goto LAB_000524ec;
      }
    }
LAB_000524d2:
    bVar7 = (bt_ancs_client)0x8;
LAB_000524ec:
    uVar6 = uVar9 + 1;
    break;
  case (bt_ancs_client)0x4:
    *(ushort *)(ancs_c + 0x111c) = (ushort)data_src[uVar9];
    bVar7 = (bt_ancs_client)0x5;
    uVar6 = uVar9 + 1;
    break;
  case (bt_ancs_client)0x5:
    uVar5 = *(ushort *)(ancs_c + 0x111c) | (ushort)data_src[uVar9] << 8;
    *(undefined2 *)(ancs_c + 0x1110) = 0;
    uVar6 = uVar9 + 1;
    *(ushort *)(ancs_c + 0x111c) = uVar5;
    iVar8 = *(int *)(ancs_c + 0x10fc) + *(int *)(ancs_c + 0x1120) * 0x10;
    if (uVar5 == 0) {
      if (*(char *)(*(int *)(ancs_c + 0x10fc) + *(int *)(ancs_c + 0x1120) * 0x10) != '\0') {
        bt_ancs_do_ds_notif_cb(ancs_c,(bt_ancs_attr_response *)(ancs_c + 0x1118));
      }
      if (*(int *)(ancs_c + 0x1104) == 0) {
        bVar7 = (bt_ancs_client)0x8;
      }
      else {
        bVar7 = (bt_ancs_client)0x3;
      }
    }
    else if (*(short *)(iVar8 + 8) == 0) {
      bVar7 = (bt_ancs_client)0x7;
    }
    else if (*(int *)(iVar8 + 0xc) == 0) {
      bVar7 = (bt_ancs_client)0x7;
    }
    else {
      bVar7 = (bt_ancs_client)0x6;
    }
    break;
  case (bt_ancs_client)0x6:
    uVar6 = (uint)*(ushort *)(ancs_c + 0x1110);
    if ((uVar6 < *(ushort *)(*(int *)(ancs_c + 0x10fc) + *(int *)(ancs_c + 0x1120) * 0x10 + 8)) &&
       (uVar6 < *(ushort *)(ancs_c + 0x111c))) {
      *(ushort *)(ancs_c + 0x1110) = *(ushort *)(ancs_c + 0x1110) + 1;
      puVar1 = data_src + uVar9;
      uVar9 = uVar9 + 1;
      *(uint8_t *)(*(int *)(ancs_c + 0x1124) + uVar6) = *puVar1;
    }
    uVar4 = (uint)*(ushort *)(ancs_c + 0x1110);
    uVar6 = uVar9;
    if ((*(ushort *)(ancs_c + 0x111c) == uVar4) ||
       (uVar4 == *(ushort *)(*(int *)(ancs_c + 0x10fc) + *(int *)(ancs_c + 0x1120) * 0x10 + 8) - 1))
    {
      if (*(char *)(*(int *)(ancs_c + 0x10fc) + *(int *)(ancs_c + 0x1120) * 0x10) != '\0') {
        *(undefined1 *)(*(int *)(ancs_c + 0x1124) + uVar4) = 0;
      }
      if (*(ushort *)(ancs_c + 0x111c) <= *(ushort *)(ancs_c + 0x1110)) goto LAB_00052668;
      bVar7 = (bt_ancs_client)0x7;
    }
    break;
  case (bt_ancs_client)0x7:
    uVar5 = *(ushort *)(ancs_c + 0x1110);
    uVar3 = *(ushort *)(ancs_c + 0x111c);
    if (uVar5 < uVar3) {
      *(ushort *)(ancs_c + 0x1110) = uVar5 + 1;
    }
    if (uVar5 < uVar3) {
      uVar9 = uVar9 + 1;
    }
    uVar6 = uVar9;
    if (*(ushort *)(ancs_c + 0x1110) == uVar3) {
LAB_00052668:
      if (*(char *)(*(int *)(ancs_c + 0x10fc) + *(int *)(ancs_c + 0x1120) * 0x10) != '\0') {
        bt_ancs_do_ds_notif_cb(ancs_c,(bt_ancs_attr_response *)(ancs_c + 0x1118));
      }
      uVar6 = uVar9;
      if (*(int *)(ancs_c + 0x1104) == 0) {
        bVar7 = (bt_ancs_client)0x8;
      }
      else {
        bVar7 = (bt_ancs_client)0x3;
      }
    }
    break;
  case (bt_ancs_client)0x8:
    goto switchD_0005249c_caseD_8;
  default:
    bVar7 = (bt_ancs_client)0x8;
    uVar6 = uVar9;
  }
  ancs_c[0x1108] = bVar7;
  goto switchD_0005249c_caseD_8;
}


