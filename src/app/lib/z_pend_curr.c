/*
 * Function: z_pend_curr
 * Entry:    000782ac
 * Prototype: int __stdcall z_pend_curr(k_spinlock * lock, k_spinlock_key_t key, _wait_q_t * wait_q, k_timeout_t timeout)
 */


/* exclude_from_export_ai */

int z_pend_curr(k_spinlock *lock,k_spinlock_key_t key,_wait_q_t *wait_q,k_timeout_t timeout)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  int extraout_r0;
  uint uVar5;
  char *file;
  char *file_00;
  int iVar6;
  int line;
  int line_00;
  uint uVar7;
  int iVar8;
  k_thread *thread;
  uint uVar9;
  undefined4 uVar10;
  int64_t iVar11;
  k_timeout_t timeout_00;
  
  uVar10 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar10 = getBasePriority();
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if ((bVar4) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x20 < uVar7)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar4 = z_spin_lock_valid((k_spinlock *)((int)&_current.switch_handle + 2));
  if (!bVar4) {
LAB_000782c8:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.switch_handle + 2),file,line);
    goto LAB_000782de;
  }
  z_spin_lock_set_owner((k_spinlock *)((int)&_current.switch_handle + 2));
  if (lock->thread_cpu == 0) {
    uVar7 = lock[10].thread_cpu;
    uVar9 = lock[0xb].thread_cpu;
    uVar5 = uVar9 + (0xfffffffe < uVar7);
    if (uVar5 != 0 || uVar5 < (1 < uVar7 + 1)) {
      if ((int)uVar9 < (int)(uint)(uVar7 == 0)) {
        uVar7 = 1;
        uVar9 = 0;
      }
      lVar3 = CONCAT44((uVar9 - 1) + (uint)(uVar7 != 0),uVar7 - 1);
      iVar11 = sys_clock_tick_get();
      lVar2 = iVar11 + 1 + lVar3;
      if ((int)((ulonglong)lVar2 >> 0x20) < (int)(uint)((int)lVar2 == 0)) {
        iVar6 = -2;
        iVar8 = -1;
      }
      else {
        iVar11 = sys_clock_tick_get();
        lVar3 = iVar11 + 1 + lVar3;
        uVar7 = (uint)lVar3;
        iVar6 = -2 - uVar7;
        iVar8 = (-1 - (int)((ulonglong)lVar3 >> 0x20)) - (uint)(0xfffffffe < uVar7);
      }
      timeout_00.ticks._4_4_ = iVar8;
      timeout_00.ticks._0_4_ = iVar6;
      z_add_timeout((_timeout *)lock,(_timeout_func_t)0x782ad,timeout_00);
    }
    lock[0xc].thread_cpu = lock[0xc].thread_cpu + 1;
    if (lock[8].thread_cpu == 0) {
LAB_000783b4:
      thread = (k_thread *)((k_thread *)(lock + 6))->base;
      if ((thread == (k_thread *)(lock + 6)) || (thread == (k_thread *)0x0)) goto LAB_000782ee;
      z_unpend_thread_no_timeout(thread);
      thread[1].userspace_local_data = (undefined *)0x0;
      bVar4 = z_spin_unlock_valid((k_spinlock *)((int)&_current.switch_handle + 2));
      if (bVar4) {
        bVar4 = (bool)isCurrentModePrivileged();
        if (bVar4) {
          setBasePriority(uVar10);
        }
        InstructionSynchronizationBarrier(0xf);
        z_ready_thread(thread);
        return extraout_r0;
      }
    }
    else {
      bVar4 = z_spin_unlock_valid((k_spinlock *)((int)&_current.switch_handle + 2));
      if (bVar4) {
        bVar4 = (bool)isCurrentModePrivileged();
        if (bVar4) {
          setBasePriority(uVar10);
        }
        InstructionSynchronizationBarrier(0xf);
        (*(code *)lock[8].thread_cpu)(lock);
        uVar10 = 0;
        bVar4 = (bool)isCurrentModePrivileged();
        if (bVar4) {
          uVar10 = getBasePriority();
        }
        bVar4 = (bool)isCurrentModePrivileged();
        if ((bVar4) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x20 < uVar7)) {
          setBasePriority(0x20);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar4 = z_spin_lock_valid((k_spinlock *)((int)&_current.switch_handle + 2));
        if (!bVar4) goto LAB_000782c8;
        z_spin_lock_set_owner((k_spinlock *)((int)&_current.switch_handle + 2));
        goto LAB_000783b4;
      }
    }
  }
  else {
LAB_000782ee:
    bVar4 = z_spin_unlock_valid((k_spinlock *)((int)&_current.switch_handle + 2));
    if (bVar4 != 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar10);
      }
      InstructionSynchronizationBarrier(0xf);
      return (uint)bVar4;
    }
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
  _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.switch_handle + 2),file_00,line_00);
LAB_000782de:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


