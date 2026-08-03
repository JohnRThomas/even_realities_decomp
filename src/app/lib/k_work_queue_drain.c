/*
 * Function: k_work_queue_drain
 * Entry:    00076460
 * Prototype: int __stdcall k_work_queue_drain(k_work_q * queue, bool plug)
 */


/* exclude_from_export */

int k_work_queue_drain(k_work_q *queue,bool plug)

{
  bool bVar1;
  int iVar2;
  char *file;
  char *file_00;
  int line;
  uint uVar3;
  dword dVar4;
  int line_00;
  k_spinlock_key_t key;
  
  if (queue == (k_work_q *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","queue","WEST_TOPDIR/zephyr/kernel/work.c",749);
LAB_0007647c:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  bVar1 = k_is_in_isr();
  if (bVar1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!k_is_in_isr()","WEST_TOPDIR/zephyr/kernel/work.c",
            0x2ee);
    goto LAB_0007647c;
  }
  key = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    key = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
  if (!bVar1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file,line);
    goto LAB_0007647c;
  }
  z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
  uVar3 = queue[0xc].thread;
  if ((uVar3 & 6) == 0) {
    if (plug) goto LAB_000764de;
    if (queue[10].flags == 0) {
      bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file_00,
              line_00);
      goto LAB_0007647c;
    }
    dVar4 = uVar3 | 4;
  }
  else {
    queue[0xc].thread = uVar3 | 4;
    if (!plug) goto LAB_000764e6;
LAB_000764de:
    dVar4 = uVar3 | 0xc;
  }
  queue[0xc].thread = dVar4;
LAB_000764e6:
  notify_queue_locked(queue);
  iVar2 = z_sched_wait((k_spinlock *)((int)&_current.userspace_local_data + 2),key,
                       (_wait_q_t *)&queue[0xb].drainq,(k_timeout_t)0xffffffffffffffff,
                       (void **)0xffffffff);
  return iVar2;
}


