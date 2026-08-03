/*
 * Function: z_tick_sleep
 * Entry:    000779a4
 * Prototype: int32_t __stdcall z_tick_sleep(k_ticks_t ticks)
 */


/* exclude_from_export */

int32_t z_tick_sleep(k_ticks_t ticks)

{
  bool bVar1;
  uint32_t uVar2;
  int iVar3;
  char *test;
  k_spinlock_key_t key;
  char *test_00;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  uint uVar4;
  int line;
  int line_00;
  int line_01;
  int line_02;
  uint uVar5;
  k_spinlock *lock;
  
  iVar3 = (int)((ulonglong)ticks >> 0x20);
  uVar5 = (uint)ticks;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getCurrentExceptionNumber();
    uVar4 = uVar4 & 0x1f;
  }
  if (uVar4 == 0) {
    if (ticks == 0) {
      z_impl_k_yield();
      return 0;
    }
    if ((int)((iVar3 + 1) - (uint)(uVar5 < 0xfffffffe)) < 0 ==
        (SBORROW4(iVar3,-1) != SBORROW4(iVar3 + 1,(uint)(uVar5 < 0xfffffffe)))) {
      uVar2 = sys_clock_tick_get_32();
      uVar5 = uVar5 + uVar2;
    }
    else {
      uVar5 = -uVar5 - 2;
    }
    lock = (k_spinlock *)0x0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      lock = (k_spinlock *)getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
    if (bVar1) {
      z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
      _current._52_4_ = _current.base;
      unready_thread((k_thread *)_current.base);
      z_add_timeout((_timeout *)(_current.base + 0x18),(_timeout_func_t)0x89e11,(k_timeout_t)ticks);
      *(byte *)(_current.base + 0xd) = *(byte *)(_current.base + 0xd) | 0x10;
      bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
      if (bVar1) {
        z_swap(lock,key);
        if (-1 < (int)((uint)*(byte *)(_current.base + 0xd) << 0x1b)) {
          uVar2 = sys_clock_tick_get_32();
          if ((int)-(uint)(uVar5 < uVar2) < (int)(uint)(uVar5 - uVar2 == 0)) {
            return 0;
          }
          return uVar5 - uVar2;
        }
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "!z_is_thread_state_set(_kernel.cpus[0].current, ((1UL << (4))))",
                "WEST_TOPDIR/zephyr/kernel/sched.c",1458);
        _ASSERT("\t\n",test_00,file_02,line_02);
      }
      else {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x111);
        _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file_01,line_01);
      }
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file_00,line_00);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()","WEST_TOPDIR/zephyr/kernel/sched.c",
            1430);
    _ASSERT("\t\n",test,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


