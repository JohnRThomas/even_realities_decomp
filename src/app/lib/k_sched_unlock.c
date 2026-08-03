/*
 * Function: k_sched_unlock
 * Entry:    00076e9c
 * Prototype: void __stdcall k_sched_unlock(void)
 */


/* exclude_from_export */

void k_sched_unlock(void)

{
  bool bVar1;
  uint uVar2;
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar1) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
    if (*(char *)(_current.base + 0xf) == '\0') {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","_kernel.cpus[0].current->base.sched_locked != 0U",
              "WEST_TOPDIR/zephyr/kernel/sched.c",1016);
      _ASSERT("\t\n",test,file_00,line_00);
    }
    else {
      uVar2 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar2 = getCurrentExceptionNumber();
        uVar2 = uVar2 & 0x1f;
      }
      if (uVar2 == 0) {
        *(char *)(_current.base + 0xf) = *(char *)(_current.base + 0xf) + '\x01';
        update_cache(0);
        bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
        if (bVar1) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar3);
          }
          InstructionSynchronizationBarrier(0xf);
          z_reschedule_unlocked();
          return;
        }
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
        _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file_02,line_02);
      }
      else {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()",
                "WEST_TOPDIR/zephyr/kernel/sched.c",0x3f9);
        _ASSERT("\t\n",test_00,file_01,line_01);
      }
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


