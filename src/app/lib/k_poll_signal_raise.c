/*
 * Function: k_poll_signal_raise
 * Entry:    00078a58
 * Prototype: int __stdcall k_poll_signal_raise(k_poll_signal * sig, int result)
 */


/* exclude_from_export */

int k_poll_signal_raise(k_poll_signal *sig,int result)

{
  uint uVar1;
  bool bVar2;
  k_poll_event *event;
  char *file;
  char *file_00;
  undefined4 *puVar3;
  int line;
  int line_00;
  void *pvVar4;
  int iVar5;
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
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.resource_pool + 2));
    event = (sig->poll_events).next;
    sig->result = result;
    sig->signaled = 1;
    if ((k_poll_event *)sig == event) {
      bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
      if (!bVar2) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
        _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file_00,line_00)
        ;
        goto LAB_00078a8c;
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(key);
      }
      InstructionSynchronizationBarrier(0xf);
      iVar5 = 0;
    }
    else {
      pvVar4 = (event->_node).next;
      puVar3 = (event->_node).prev;
      *puVar3 = pvVar4;
      *(undefined4 **)((int)pvVar4 + 4) = puVar3;
      (event->_node).next = (void *)0x0;
      (event->_node).prev = (void *)0x0;
      iVar5 = signal_poll_event(event,1);
      z_reschedule((k_spinlock *)((int)&_current.resource_pool + 2),key);
    }
    return iVar5;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
  _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file,line);
LAB_00078a8c:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


