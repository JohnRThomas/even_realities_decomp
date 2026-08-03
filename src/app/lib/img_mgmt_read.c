/*
 * Function: img_mgmt_read
 * Entry:    00054a84
 * Prototype: int __stdcall img_mgmt_read(int slot, uint offset, void * dst, uint num_bytes)
 */


/* exclude_from_export */

int img_mgmt_read(int slot,uint offset,void *dst,uint num_bytes)

{
  int iVar1;
  uint32_t off;
  void *dst_00;
  int iVar2;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  int iStack_28;
  int local_24;
  flash_area *local_1c;
  
  iStack_28 = img_mgmt_flash_area_id(slot);
  if (iStack_28 < 0) {
    iVar2 = 0xe;
  }
  else {
    local_24 = flash_area_open((uint8_t)iStack_28,&local_1c);
    if (local_24 == 0) {
      iVar1 = flash_area_read(local_1c,off,dst_00,num_bytes);
      flash_area_close(local_1c);
      iVar2 = 0;
      if (iVar1 != 0) {
        local_2c = "Failed to read data from flash: %d";
        local_30 = 3;
        iStack_28 = iVar1;
        LOG_ERR(&PTR_s_mcumgr_img_grp_0008b9b8,0x1840,&local_30,3,in_stack_ffffffc0,
                in_stack_ffffffc4,in_stack_ffffffc8);
        iVar2 = 0xb;
      }
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


