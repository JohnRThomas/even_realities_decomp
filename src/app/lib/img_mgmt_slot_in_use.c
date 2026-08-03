/*
 * Function: img_mgmt_slot_in_use
 * Entry:    000841ae
 * Prototype: int __stdcall img_mgmt_slot_in_use(int slot)
 */


/* exclude_from_export_ai */

int img_mgmt_slot_in_use(int slot)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint in_r1;
  undefined4 uStack_14;
  
  iVar1 = slot;
  uStack_14 = in_r1;
  if (3 < (uint)slot) {
    iVar1 = img_mgmt_slot_to_image(slot);
  }
  iVar2 = img_mgmt_active_slot(iVar1 >> 1);
  uStack_14 = uStack_14 & 0xffffff;
  iVar1 = img_mgmt_get_next_boot_slot(iVar1 >> 1,(img_mgmt_next_boot_type *)((int)&uStack_14 + 3));
  if (((iVar1 == slot) && (uStack_14._3_1_ - 1 < 2)) || ((iVar1 != iVar2 && (uStack_14._3_1_ == 0)))
     ) {
    uVar3 = 1;
  }
  else {
    uVar3 = (uint)(iVar2 == slot);
  }
  return uVar3;
}


