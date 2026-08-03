/*
 * Function: k_work_init_delayable
 * Entry:    0007657c
 * Prototype: void __stdcall k_work_init_delayable(k_work_delayable * dwork, void * handler)
 */


/* exclude_from_export */

void k_work_init_delayable(k_work_delayable *dwork,void *handler)

{
  if (dwork == (k_work_delayable *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","dwork != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",832);
  }
  else {
    if (handler != (void *)0x0) {
      memset(dwork,0,0x30);
      (dwork->work).handler = handler;
      (dwork->work).flags = 0x100;
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","handler != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",833);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


