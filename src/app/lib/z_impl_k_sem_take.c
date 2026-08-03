/*
 * Function: z_impl_k_sem_take
 * Entry:    00075bb0
 * Prototype: int __stdcall z_impl_k_sem_take(k_sem * sem, k_timeout_t timeout)
 */


/* exclude_from_export */

int z_impl_k_sem_take(k_sem *sem,k_timeout_t timeout)

{
  k_timeout_t timeout_00;
  bool bVar1;
  int iVar2;
  char *test;
  uint uVar3;
  char *file;
  char *file_00;
  char *file_01;
  uint in_r3;
  uint uVar4;
  int line;
  int line_00;
  int line_01;
  k_spinlock_key_t key;
  
  uVar3 = (uint)((ulonglong)timeout.ticks >> 0x20);
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getCurrentExceptionNumber();
    uVar4 = uVar4 & 0x1f;
  }
  if ((uVar4 == 0) || (uVar3 == 0 && in_r3 == 0)) {
    key = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      key = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.entry + 3));
    if (bVar1) {
      z_spin_lock_set_owner((k_spinlock *)((int)&_current.entry + 3));
      if (sem->count == 0) {
        if ((uVar3 | in_r3) != 0) {
          timeout_00.ticks._4_4_ = uVar3;
          timeout_00.ticks._0_4_ = uVar3 | in_r3;
          iVar2 = z_pend_curr((k_spinlock *)((int)&_current.entry + 3),key,(_wait_q_t *)sem,
                              timeout_00);
          return iVar2;
        }
        bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.entry + 3));
        if (bVar1) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(key);
          }
          InstructionSynchronizationBarrier(0xf);
          return -0x10;
        }
      }
      else {
        sem->count = sem->count - 1;
        bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.entry + 3));
        if (bVar1) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(key);
          }
          InstructionSynchronizationBarrier(0xf);
          return 0;
        }
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.entry + 3),file_01,line_01);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.entry + 3),file_00,line_00);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "((arch_is_in_isr() == 0) || ((timeout).ticks == (((k_timeout_t) {0})).ticks))",
            "WEST_TOPDIR/zephyr/kernel/sem.c",128);
    _ASSERT("\t\n",test,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


