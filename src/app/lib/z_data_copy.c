/*
 * Function: z_data_copy
 * Entry:    00077ddc
 * Prototype: void __stdcall z_data_copy(void)
 */


/* exclude_from_export */

void z_data_copy(void)

{
  memcpy(&bt_dev,&DAT_000f6d9c,0x1df0);
  memcpy(&bt_dev,&DAT_000f6d9c,0);
  return;
}


