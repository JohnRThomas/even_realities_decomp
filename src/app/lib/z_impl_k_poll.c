/*
 * Function: z_impl_k_poll
 * Entry:    000788a0
 * Prototype: int __stdcall z_impl_k_poll(k_poll_event * events, int num_events, k_timeout_t timeout)
 */


/* exclude_from_export */

int z_impl_k_poll(k_poll_event *events,int num_events,k_timeout_t timeout)

{
  k_timeout_t timeout_00;
  dword dVar1;
  bool bVar2;
  int iVar3;
  char *test;
  char *test_00;
  char *test_01;
  z_poller *poller;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  char *file_03;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  undefined4 uVar4;
  k_spinlock_key_t key;
  uint uVar5;
  
  dVar1 = _current.base;
  poller = (z_poller *)(_current.base + 0x60);
  *(undefined1 *)(_current.base + 0x60) = 1;
  *(undefined1 *)(dVar1 + 0x61) = 1;
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getCurrentExceptionNumber();
    uVar5 = uVar5 & 0x1f;
  }
  if (uVar5 != 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!arch_is_in_isr()","WEST_TOPDIR/zephyr/kernel/poll.c",
            301);
    _ASSERT("\t\n",test,file,line);
    goto LAB_000788e2;
  }
  if (events == (k_poll_event *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","events != ((void *)0)",
            "WEST_TOPDIR/zephyr/kernel/poll.c",302);
    _ASSERT("\tNULL events\n\n",test_00,file_00,line_00);
    goto LAB_000788e2;
  }
  if (num_events < 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","num_events >= 0","WEST_TOPDIR/zephyr/kernel/poll.c",303
           );
    _ASSERT("\t<0 events\n\n",test_01,file_01,line_01);
    goto LAB_000788e2;
  }
  register_events(events,num_events,poller,timeout.ticks == 0);
  key = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    key = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.resource_pool + 2));
    if (*(char *)(dVar1 + 0x60) == '\0') {
      clear_event_registration(events);
      bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
    }
    else {
      uVar5 = (uint)timeout.ticks | (uint)((ulonglong)timeout.ticks >> 0x20);
      *(undefined1 *)(dVar1 + 0x60) = 0;
      if (uVar5 == 0) {
        bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
        if (bVar2) {
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            setBasePriority(key);
          }
          InstructionSynchronizationBarrier(0xf);
          return -0xb;
        }
      }
      else {
        timeout_00.ticks._4_4_ = (uint)timeout.ticks;
        timeout_00.ticks._0_4_ = uVar5;
        iVar3 = z_pend_curr((k_spinlock *)((int)&_current.resource_pool + 2),key,
                            (_wait_q_t *)&DAT_20002d24,timeout_00);
        uVar4 = 0;
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          uVar4 = getBasePriority();
        }
        bVar2 = (bool)isCurrentModePrivileged();
        if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
          setBasePriority(0x20);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
        if (!bVar2) goto LAB_00078948;
        z_spin_lock_set_owner((k_spinlock *)((int)&_current.resource_pool + 2));
        clear_event_registration(events);
        bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
        if (bVar2) {
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            setBasePriority(uVar4);
          }
          InstructionSynchronizationBarrier(0xf);
          return iVar3;
        }
      }
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file_03,line_03);
  }
  else {
LAB_00078948:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file_02,line_02);
  }
LAB_000788e2:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


