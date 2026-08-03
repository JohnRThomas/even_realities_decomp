/*
 * Function: tx_rsp
 * Entry:    00075ca4
 * Prototype: int __stdcall tx_rsp(int * queue, int * dwork, longlong delay)
 */


/* exclude_from_export_ai */

int tx_rsp(int *queue,int *dwork,longlong delay)

{
  uint uVar1;
  bool bVar2;
  k_thread *thread;
  int extraout_r0;
  char *file;
  int line;
  k_spinlock_key_t key;
  
  key = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    key = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.entry + 3));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.entry + 3));
    while (thread = z_unpend_first_thread((_wait_q_t *)queue), thread != (k_thread *)0x0) {
      thread[1].userspace_local_data = (undefined *)0xfffffff5;
      z_ready_thread(thread);
    }
    queue[2] = 0;
    z_handle_obj_poll_events((sys_dlist_t *)(queue + 4),2);
    z_reschedule((k_spinlock *)((int)&_current.entry + 3),key);
    return extraout_r0;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
  _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.entry + 3),file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


