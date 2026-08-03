/*
 * Function: z_sched_lock
 * Entry:    00076dc4
 * Prototype: void __stdcall z_sched_lock(void)
 */


/* exclude_from_export */

void z_sched_lock(void)

{
  bool bVar1;
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  int line;
  uint uVar2;
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
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1f;
    }
    if (uVar2 == 0) {
      if (*(char *)(_current.base + 0xf) == '\x01') {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","_kernel.cpus[0].current->base.sched_locked != 1U",
                "WEST_TOPDIR/zephyr/kernel/include/ksched.h",254);
        _ASSERT("\t\n",test_00,file_01,line_01);
      }
      else {
        *(char *)(_current.base + 0xf) = *(char *)(_current.base + 0xf) + -1;
        bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
        if (bVar1) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar3);
          }
          InstructionSynchronizationBarrier(0xf);
          return;
        }
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
        _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file_02,line_02);
      }
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()",
              "WEST_TOPDIR/zephyr/kernel/include/ksched.h",0xfd);
      _ASSERT("\t\n",test,file_00,line_00);
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


