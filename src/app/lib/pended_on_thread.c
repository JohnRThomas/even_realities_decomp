/*
 * Function: pended_on_thread
 * Entry:    0007751c
 * Prototype: _wait_q_t * __stdcall pended_on_thread(k_thread * thread)
 */


/* exclude_from_export */

_wait_q_t * pended_on_thread(k_thread *thread)

{
  _wait_q_t *extraout_r0;
  
  if ((sys_dlist_t *)thread->init_data == (sys_dlist_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","thread->base.pended_on",
            "WEST_TOPDIR/zephyr/kernel/sched.c",722);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  z_priq_dumb_remove((sys_dlist_t *)thread->init_data,thread);
  *(byte *)((int)&thread->join_queue + 1) = *(byte *)((int)&thread->join_queue + 1) & 0xfd;
  thread->init_data = (undefined *)0x0;
  return extraout_r0;
}


