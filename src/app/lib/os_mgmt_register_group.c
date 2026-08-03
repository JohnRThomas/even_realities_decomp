/*
 * Function: os_mgmt_register_group
 * Entry:    000556f4
 * Prototype: void __stdcall os_mgmt_register_group(void)
 */


/* exclude_from_export_ai */

void os_mgmt_register_group(void)

{
  DAT_200028a8 = 0;
  if (DAT_2000b330 == (undefined4 *)0x0) {
    DAT_2000b32c = &DAT_200028a8;
    DAT_2000b330 = &DAT_200028a8;
    return;
  }
  *DAT_2000b330 = &DAT_200028a8;
  DAT_2000b330 = &DAT_200028a8;
  return;
}


