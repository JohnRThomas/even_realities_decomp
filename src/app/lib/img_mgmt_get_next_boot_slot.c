/*
 * Function: img_mgmt_get_next_boot_slot
 * Entry:    00084168
 * Prototype: int __stdcall img_mgmt_get_next_boot_slot(int image, img_mgmt_next_boot_type * type)
 */


/* exclude_from_export_ai */

int img_mgmt_get_next_boot_slot(int image,img_mgmt_next_boot_type *type)

{
  uint uVar1;
  int slot;
  uint uVar2;
  undefined1 uVar3;
  int extraout_r3;
  
  uVar1 = img_mgmt_active_slot(image);
  slot = boot_swap_type_multi(image);
  if (3 < uVar1) {
    img_mgmt_get_opposite_slot(slot);
    slot = extraout_r3;
  }
  uVar2 = uVar1 ^ 1;
  switch(slot) {
  case 1:
    uVar2 = uVar1;
  case 3:
    uVar3 = NEXT_BOOT_TYPE_NORMAL;
    break;
  case 2:
    uVar3 = NEXT_BOOT_TYPE_TEST;
    break;
  case 4:
    uVar3 = NEXT_BOOT_TYPE_REVERT;
    break;
  default:
    return -1;
  }
  if (type != (img_mgmt_next_boot_type *)0x0) {
    *(undefined1 *)type = uVar3;
  }
  return uVar2;
}


