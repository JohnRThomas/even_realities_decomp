/*
 * Function: img_mgmt_set_next_boot_slot
 * Entry:    00055038
 * Prototype: int __stdcall img_mgmt_set_next_boot_slot(int slot, bool confirm)
 */


/* exclude_from_export_ai */

int img_mgmt_set_next_boot_slot(int slot,bool confirm)

{
  log_msg_desc desc;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  int iStack_38;
  int local_34;
  int iStack_30;
  uint local_2c;
  undefined1 local_25;
  flash_area *local_24;
  
  iVar1 = slot;
  if (3 < (uint)slot) {
    iVar1 = img_mgmt_slot_to_image(slot);
  }
  iVar1 = iVar1 >> 1;
  iVar2 = img_mgmt_active_slot(iVar1);
  local_25 = NEXT_BOOT_TYPE_NORMAL;
  iVar3 = img_mgmt_get_next_boot_slot(iVar1,(img_mgmt_next_boot_type *)&local_25);
  if (confirm == 0) {
    if (iVar2 == slot) {
      return 0x21;
    }
    if (local_25 == NEXT_BOOT_TYPE_TEST) {
      if (iVar3 == slot) {
        return 0;
      }
      return 0x1c;
    }
    if (local_25 == NEXT_BOOT_TYPE_NORMAL) {
      bVar5 = iVar3 == slot;
    }
    else {
      bVar5 = local_25 == NEXT_BOOT_TYPE_REVERT;
    }
LAB_000550b4:
    if (bVar5) {
      return 0x1c;
    }
    goto LAB_00055090;
  }
  iVar4 = img_mgmt_active_image();
  if (iVar4 == iVar1) {
    if (local_25 == NEXT_BOOT_TYPE_TEST) {
      return 0x1c;
    }
    if (local_25 == NEXT_BOOT_TYPE_NORMAL) {
      if (iVar3 == slot) {
        return 0;
      }
      bVar5 = iVar2 == slot;
      goto LAB_000550b4;
    }
LAB_0005508c:
    if (local_25 != NEXT_BOOT_TYPE_REVERT) goto LAB_00055090;
  }
  else {
    if (iVar2 == slot) {
      return 0x20;
    }
    if (local_25 == NEXT_BOOT_TYPE_TEST) {
      return 0x1c;
    }
    if (local_25 != NEXT_BOOT_TYPE_NORMAL) goto LAB_0005508c;
  }
  if (iVar3 == slot) {
    return 0;
  }
LAB_00055090:
  iVar1 = img_mgmt_flash_area_id(slot);
  iVar1 = flash_area_open((uint8_t)iVar1,&local_24);
  if (iVar1 == 0) {
    iVar3 = boot_set_next(local_24,iVar2 == slot,confirm);
    iVar1 = 0;
    if (iVar3 != 0) {
      local_3c = "Faled boot_set_next with code %d, for slot %d, with active slot %d and confirm %d"
      ;
      local_40 = 6;
      desc.level = (dword)&local_40;
      desc.domain = 0x3040;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffb0;
      iStack_38 = iVar3;
      local_34 = slot;
      iStack_30 = iVar2;
      local_2c = (uint)confirm;
      z_impl_z_log_msg_static_create
                (&PTR_s_mcumgr_img_grp_0008b9b8,desc,in_stack_ffffffb4,in_stack_ffffffb8);
      if (iVar3 == 1) {
        iVar1 = 0xc;
      }
      else if (iVar3 == 4) {
        iVar1 = 0x1d;
      }
      else if (iVar3 == 3) {
        iVar1 = 0x17;
      }
      else {
        iVar1 = 1;
      }
    }
    flash_area_close(local_24);
    return iVar1;
  }
  return 10;
}


