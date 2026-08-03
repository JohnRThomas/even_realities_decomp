/*
 * Function: bt_adv_reset_adv_pool
 * Entry:    000589c8
 * Prototype: void __stdcall bt_adv_reset_adv_pool(void)
 */


/* exclude_from_export_ai */

void bt_adv_reset_adv_pool(void)

{
  memset(&bt_dev,0,0x50);
  return;
}


