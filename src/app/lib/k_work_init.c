/*
 * Function: k_work_init
 * Entry:    000760f8
 * Prototype: void __stdcall k_work_init(k_work * work, void * handler)
 */


/* exclude_from_export */

void k_work_init(k_work *work,void *handler)

{
  if (work == (k_work *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","work != ((void *)0)","WEST_TOPDIR/zephyr/kernel/work.c"
            ,137);
  }
  else {
    if (handler != (void *)0x0) {
      memset(work,0,0x10);
      work->handler = handler;
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","handler != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",138);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


