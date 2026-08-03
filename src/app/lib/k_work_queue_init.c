/*
 * Function: k_work_queue_init
 * Entry:    0007635c
 * Prototype: void __stdcall k_work_queue_init(k_work_q * queue)
 */


/* exclude_from_export */

void k_work_queue_init(k_work_q *queue)

{
  if (queue == (k_work_q *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","queue != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/work.c",697);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  memset(queue,0,0xf8);
  return;
}


