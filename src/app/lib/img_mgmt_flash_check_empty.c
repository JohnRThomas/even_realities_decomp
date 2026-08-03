/*
 * Function: img_mgmt_flash_check_empty
 * Entry:    00054958
 * Prototype: int __stdcall img_mgmt_flash_check_empty(uint8_t fa_id)
 */


/* exclude_from_export_ai */

int img_mgmt_flash_check_empty(uint8_t fa_id)

{
  flash_area *pfVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint32_t off;
  uint32_t len;
  uint uVar6;
  dword in_stack_ffffff78;
  uint8_t *in_stack_ffffff7c;
  void *in_stack_ffffff80;
  undefined4 local_78;
  char *local_74;
  int iStack_70;
  int local_6c;
  flash_area *local_64;
  int aiStack_60 [17];
  
  iVar3 = img_mgmt_flash_area_id((uint)fa_id);
  if (iVar3 < 0) {
    iVar3 = 0xe;
  }
  else {
    local_6c = flash_area_open((uint8_t)iVar3,&local_64);
    pfVar1 = local_64;
    if (local_6c < 0) {
      local_74 = "Failed to open flash area ID %u: %d";
      local_78 = 4;
      iStack_70 = iVar3;
      LOG_ERR(&PTR_s_mcumgr_img_grp_0008b9b8,0x2040,&local_78,4,in_stack_ffffff78,in_stack_ffffff7c,
              in_stack_ffffff80);
      iVar3 = 10;
    }
    else {
      off = local_64->fa_size & 3;
      if (off != 0) {
        __assert_func("WEST_TOPDIR/zephyr/subsys/mgmt/mcumgr/grp/img_mgmt/src/zephyr_img_mgmt.c",67,
                      "img_mgmt_flash_check_empty_inner","fa->fa_size % 4 == 0");
      }
      bVar2 = flash_area_erased_val(pfVar1);
      uVar6 = pfVar1->fa_size;
      for (; (int)off < (int)uVar6; off = off + 0x40) {
        len = uVar6 - off;
        if (0x3f < (int)len) {
          len = 0x40;
        }
        iVar3 = flash_area_read(pfVar1,off,aiStack_60,len);
        if (iVar3 < 0) {
          local_74 = "Failed to read data from flash area: %d";
          local_78 = 3;
          iStack_70 = iVar3;
          LOG_ERR(&PTR_s_mcumgr_img_grp_0008b9b8,0x1840,&local_78,3,in_stack_ffffff78,
                  in_stack_ffffff7c,in_stack_ffffff80);
          iVar3 = 0xb;
          goto LAB_00054a1c;
        }
        piVar5 = aiStack_60;
        for (iVar3 = 0; iVar3 != (int)len >> 2; iVar3 = iVar3 + 1) {
          if (*piVar5 != (uint)bVar2 * 0x1010101) {
            iVar4 = flash_area_erase(local_64,0,local_64->fa_size);
            iVar3 = 0;
            if (iVar4 != 0) {
              local_74 = "Failed to erase flash area: %d";
              local_78 = 3;
              iStack_70 = iVar4;
              LOG_ERR(&PTR_s_mcumgr_img_grp_0008b9b8,0x1840,&local_78,3,in_stack_ffffff78,
                      in_stack_ffffff7c,in_stack_ffffff80);
              iVar3 = 0xd;
            }
            goto LAB_00054a1c;
          }
          piVar5 = piVar5 + 1;
        }
      }
      iVar3 = 1;
LAB_00054a1c:
      flash_area_close(local_64);
    }
  }
  return iVar3;
}


