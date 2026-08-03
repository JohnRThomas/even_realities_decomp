/*
 * Function: img_mgmt_flash_area_id
 * Entry:    00054948
 * Prototype: int __stdcall img_mgmt_flash_area_id(int slot)
 */


/* exclude_from_export_ai */

int img_mgmt_flash_area_id(int slot)

{
  uint uVar1;
  
  if ((uint)slot < 4) {
    uVar1 = (uint)(byte)(&DAT_000f0720)[slot];
  }
  else {
    uVar1 = 0xff;
  }
  return uVar1;
}


