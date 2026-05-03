/*
 * Function: $_?_k_poll_signal_raise
 * Entry:    00078a58
 * Prototype: int __stdcall $_?_k_poll_signal_raise(k_poll_signal * sig, int result)
 */


int ____k_poll_signal_raise(k_poll_signal *sig,int result)

{
  uint uVar1;
  bool bVar2;
  k_poll_event *event;
  int iVar3;
  char *file;
  char *file_00;
  undefined4 *puVar4;
  int line;
  int line_00;
  void *pvVar5;
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
  bVar2 = z_spin_lock_valid((k_spinlock *)&DAT_2000be88);
  if (bVar2) goto LAB_00078a92;
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
  _ASSERT("\tInvalid spinlock %p\n",&DAT_2000be88,file,line);
  while( true ) {
    k_panic();
LAB_00078a92:
    z_spin_lock_set_owner((k_spinlock *)&DAT_2000be88);
    event = (sig->poll_events).next;
    sig->result = result;
    sig->signaled = 1;
    if ((k_poll_event *)sig != event) break;
    bVar2 = z_spin_unlock_valid((k_spinlock *)&DAT_2000be88);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(key);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",&DAT_2000be88,file_00,line_00);
  }
  pvVar5 = (event->_node).next;
  puVar4 = (event->_node).prev;
  *puVar4 = pvVar5;
  *(undefined4 **)((int)pvVar5 + 4) = puVar4;
  (event->_node).next = (void *)0x0;
  (event->_node).prev = (void *)0x0;
  iVar3 = signal_poll_event(event,1);
  z_reschedule((k_spinlock *)&DAT_2000be88,key);
  return iVar3;
}


