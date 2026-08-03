/*
 * Function: boot_swap_type_multi
 * Entry:    000673dc
 * Prototype: int __stdcall boot_swap_type_multi(int image_index)
 */


/* exclude_from_export */

int boot_swap_type_multi(int image_index)

{
  uint8_t val;
  uint8_t val_00;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  boot_swap_state in_r2;
  uint8_t *puVar5;
  int extraout_r2;
  int extraout_r2_00;
  int iVar6;
  undefined4 local_20;
  undefined4 local_18;
  
  local_20 = image_index;
  local_18 = in_r2;
  bVar1 = BOOT_HOOK_CALL(image_index,(undefined1 *)&local_20);
  uVar2 = (uint)bVar1;
  if (uVar2 == 1) {
    uVar2 = boot_read_swap_state_by_id((int)(&PTR_Reset_0008f720)[image_index * 2],&local_20);
  }
  if (uVar2 == 0) {
    iVar3 = boot_read_swap_state_by_id((int)(&PTR_DAT_0008f724)[image_index * 2],&local_18);
    if (iVar3 == 1) {
      local_18 = CONCAT31(local_18._1_3_,3);
      local_18 = CONCAT13(3,(undefined3)local_18);
    }
    else if (iVar3 != 0) goto LAB_00067468;
    iVar3 = 0;
    val = (uint8_t)local_20;
    val_00 = (uint8_t)local_18;
    puVar5 = "\x04\x01\x04\x03\x04\x02\x04\x01\x04\x01\x04\x03\x01\x03\x03\x04\x01\x04mcuboot_util";
    do {
      iVar4 = boot_magic_compatible_check(*puVar5,val);
      iVar6 = extraout_r2;
      if (((((iVar4 != 0) &&
            (iVar4 = boot_magic_compatible_check(*(uint8_t *)(extraout_r2 + 1),val_00),
            iVar6 = extraout_r2_00, iVar4 != 0)) &&
           ((*(char *)(extraout_r2_00 + 2) == '\x04' ||
            (local_20._3_1_ == *(char *)(extraout_r2_00 + 2))))) &&
          ((*(char *)(extraout_r2_00 + 3) == '\x04' ||
           (local_18._3_1_ == *(char *)(extraout_r2_00 + 3))))) &&
         ((*(char *)(extraout_r2_00 + 4) == '\x04' ||
          (local_20._2_1_ == *(char *)(extraout_r2_00 + 4))))) {
        if (*(byte *)(extraout_r2_00 + 5) - 2 < 3) {
          return (uint)*(byte *)(extraout_r2_00 + 5);
        }
        goto LAB_00067468;
      }
      iVar3 = iVar3 + 1;
      puVar5 = (uint8_t *)(iVar6 + 6);
    } while (iVar3 != 3);
    iVar3 = 1;
  }
  else {
LAB_00067468:
    iVar3 = 0xff;
  }
  return iVar3;
}


