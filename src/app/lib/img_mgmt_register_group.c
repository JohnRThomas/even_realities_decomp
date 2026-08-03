/*
 * Function: img_mgmt_register_group
 * Entry:    00055284
 * Prototype: void __stdcall img_mgmt_register_group(void)
 */


/* exclude_from_export_ai */

void img_mgmt_register_group(void)

{
  DAT_20002898 = 0;
  if (DAT_2000b330 == (undefined4 *)0x0) {
    DAT_2000b32c = &DAT_20002898;
    DAT_2000b330 = &DAT_20002898;
    return;
  }
  *DAT_2000b330 = &DAT_20002898;
  DAT_2000b330 = &DAT_20002898;
  return;
}


