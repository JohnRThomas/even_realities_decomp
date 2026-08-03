/*
 * Function: keys_commit
 * Entry:    00061a60
 * Prototype: int __stdcall keys_commit(void)
 */


/* exclude_from_export */

int keys_commit(void)

{
  bt_keys_foreach_type(BT_KEYS_LTK,(void *)0x61891,(void *)0x0);
  return 0;
}


