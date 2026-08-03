/*
 * Function: zephyr_basic_mgmt_init
 * Entry:    000558a4
 * Prototype: void __stdcall zephyr_basic_mgmt_init(void)
 */


/* exclude_from_export_ai */

void zephyr_basic_mgmt_init(void)

{
  DAT_200028c8 = 0;
  if (DAT_2000b330 == (undefined4 *)0x0) {
    DAT_2000b32c = &DAT_200028c8;
    DAT_2000b330 = &DAT_200028c8;
    return;
  }
  *DAT_2000b330 = &DAT_200028c8;
  DAT_2000b330 = &DAT_200028c8;
  return;
}


