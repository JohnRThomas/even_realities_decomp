/*
 * Function: bt_smp_init
 * Entry:    00061864
 * Prototype: int __stdcall bt_smp_init(void)
 */


/* exclude_from_export */

int bt_smp_init(void)

{
  DAT_2001e2a6 = (DAT_200020a2 & 6) == 6;
  bt_pub_key_gen((bt_pub_key_cb *)&DAT_20002a70);
  return 0;
}


