/*
 * Function: bt_le_ext_adv_foreach
 * Entry:    000589bc
 * Prototype: void __stdcall bt_le_ext_adv_foreach(void * func, void * data)
 */


/* exclude_from_export_ai */

void bt_le_ext_adv_foreach(void *func,void *data)

{
                    /* WARNING: Could not recover jumptable at 0x000589c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*func)(&bt_dev);
  return;
}


