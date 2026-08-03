/*
 * Function: smp_bt_ud_free
 * Entry:    000843be
 * Prototype: void __stdcall smp_bt_ud_free(void * ud)
 */


/* exclude_from_export_ai */

void smp_bt_ud_free(void *ud)

{
  if (*(int *)ud != 0) {
    *(undefined4 *)ud = 0;
    *(undefined1 *)((int)ud + 4) = 0;
  }
  return;
}


