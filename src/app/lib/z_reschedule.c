/*
 * Function: z_reschedule
 * Entry:    000780b4
 * Prototype: void __stdcall z_reschedule(k_spinlock * lock, k_spinlock_key_t key)
 */


/* exclude_from_export_ai */

void z_reschedule(k_spinlock *lock,k_spinlock_key_t key)

{
  uint uVar1;
  dword thread;
  bool bVar2;
  k_thread *curr;
  int iVar3;
  int32_t ticks;
  int iVar4;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar7 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
  if (!bVar2) {
LAB_000780d2:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.swap_retval + 2),file_01,line_01);
LAB_000780e8:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  z_spin_lock_set_owner((k_spinlock *)((int)&_current.swap_retval + 2));
  piVar5 = DAT_20002d1c;
  _current._68_4_ = lock;
  if ((int **)DAT_20002d1c == &DAT_20002d1c) {
    piVar5 = (int *)0x0;
  }
  do {
    if (piVar5 == (int *)0x0) break;
    uVar6 = piVar5[4];
    iVar4 = piVar5[5];
    iVar3 = (int)_current._68_4_ >> 0x1f;
    if ((int)((iVar3 - iVar4) - (uint)((uint)_current._68_4_ < uVar6)) < 0 !=
        (SBORROW4(iVar3,iVar4) != SBORROW4(iVar3 - iVar4,(uint)((uint)_current._68_4_ < uVar6)))) {
      piVar5[4] = uVar6 - _current._68_4_;
      piVar5[5] = (iVar4 - iVar3) - (uint)(uVar6 < (uint)_current._68_4_);
      break;
    }
    bVar2 = CARRY4(uVar6,DAT_20006bc0);
    DAT_20006bc0 = uVar6 + DAT_20006bc0;
    DAT_20006bc4 = DAT_20006bc4 + ((int)uVar6 >> 0x1f) + (uint)bVar2;
    piVar5[4] = 0;
    piVar5[5] = 0;
    remove_timeout(piVar5);
    bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
    if (!bVar2) goto LAB_00078156;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    (*(code *)piVar5[2])(piVar5);
    uVar7 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar7 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
    if (!bVar2) goto LAB_000780d2;
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.swap_retval + 2));
    _current._68_4_ = _current._68_4_ - uVar6;
    piVar5 = DAT_20002d1c;
  } while ((int **)DAT_20002d1c != &DAT_20002d1c);
  bVar2 = CARRY4(_current._68_4_,DAT_20006bc0);
  DAT_20006bc0 = _current._68_4_ + DAT_20006bc0;
  DAT_20006bc4 = DAT_20006bc4 + ((int)_current._68_4_ >> 0x1f) + (uint)bVar2;
  _current._68_4_ = 0;
  ticks = next_timeout();
  sys_clock_set_timeout(ticks,false);
  bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
  if (!bVar2) {
LAB_00078156:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.swap_retval + 2),file_02,line_02);
    goto LAB_000780e8;
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar7 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (!bVar2) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file,line);
    goto LAB_00077098;
  }
  z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
  thread = _current.base;
  curr = (k_thread *)_current._52_4_;
  if (_current._52_4_ == _current.base) {
LAB_000770b0:
    z_reset_time_slice(curr);
  }
  else {
    _current._52_4_ = 0;
    if (((&DAT_2001e2d9)[(byte)_current.init_data] != '\0') &&
       (bVar2 = sliceable((k_thread *)_current.base), bVar2)) {
      curr = (k_thread *)thread;
      if ((*(byte *)(thread + 0xd) & 0x1f) == 0) {
        move_thread_to_end_of_prio_q((k_thread *)thread);
      }
      goto LAB_000770b0;
    }
  }
  bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
  if (bVar2) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
  _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.stack_obj + 2),file_00,line_00);
LAB_00077098:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


