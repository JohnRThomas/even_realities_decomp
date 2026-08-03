/*
 * Function: aw9320x_update_fw_to_flash
 * Entry:    00031bb0
 * Prototype: int32_t __stdcall aw9320x_update_fw_to_flash(void)
 */


/* exclude_from_export */

int32_t aw9320x_update_fw_to_flash(void)

{
  uint8_t *in_r0;
  int32_t iVar1;
  uint32_t in_r1;
  check_info fw_check_info;
  aw_update_common fw_update;
  
  iVar1 = aw9320x_check_sum(in_r0,in_r1);
  if (iVar1 == 0) {
    unique0x00187400 = &fw_check_info;
    fw_check_info.check_len = 0x37f8;
    fw_check_info.flash_check_start_addr = 0x800;
    fw_check_info.w_check_en_addr = 0x3ff8;
    fw_check_info.w_check_code_addr = 0x3ffc;
    fw_update.update_flag = 1;
    fw_update._4_4_ = 0xa73a2;
    fw_update._8_4_ = 0x1b9c;
    fw_update._12_4_ = 0x2000;
    iVar1 = aw9320x_flash_update(&fw_update);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


