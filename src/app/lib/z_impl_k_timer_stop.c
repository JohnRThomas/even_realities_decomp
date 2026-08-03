/*
 * Function: z_impl_k_timer_stop
 * Entry:    00089eee
 * Prototype: void __stdcall z_impl_k_timer_stop(k_timer * timer)
 */


/* exclude_from_export */

void z_impl_k_timer_stop(k_timer *timer)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  k_thread *thread;
  uint32_t key;
  
  iVar3 = z_abort_timeout(&timer->timeout);
  if (iVar3 == 0) {
    if ((code *)timer->stop_fn != (code *)0x0) {
      (*(code *)timer->stop_fn)(timer);
    }
    thread = z_unpend1_no_timeout(&timer->wait_q);
    if (thread != (k_thread *)0x0) {
      z_ready_thread(thread);
      key = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        key = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      z_reschedule_irqlock(key);
      return;
    }
  }
  return;
}


