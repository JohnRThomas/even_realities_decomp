/*
 * Function: img_mgmt_erased_val
 * Entry:    00054d08
 * Prototype: int __stdcall img_mgmt_erased_val(int slot, uint8_t * erased_val)
 */


/* exclude_from_export */

int img_mgmt_erased_val(int slot,uint8_t *erased_val)

{
  uint8_t uVar1;
  uint8_t *extraout_r1;
  int iVar2;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  int iStack_28;
  int local_24;
  flash_area *local_1c [2];
  
  iStack_28 = img_mgmt_flash_area_id(slot);
  if (iStack_28 < 0) {
    iVar2 = 0xe;
  }
  else {
    local_24 = flash_area_open((uint8_t)iStack_28,local_1c);
    if (local_24 == 0) {
      uVar1 = flash_area_erased_val(local_1c[0]);
      *extraout_r1 = uVar1;
      flash_area_close(local_1c[0]);
      iVar2 = 0;
    }
    else {
      local_2c = "Failed to open flash area ID %u: %d";
      local_30 = 4;
      LOG_ERR(&PTR_s_mcumgr_img_grp_0008b9b8,0x2040,&local_30,4,in_stack_ffffffc0,in_stack_ffffffc4,
              in_stack_ffffffc8);
      iVar2 = 10;
    }
  }
  return iVar2;
}


