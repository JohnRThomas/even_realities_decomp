/*
 * Function: z_impl_k_yield
 * Entry:    00077870
 * Prototype: void __stdcall z_impl_k_yield(void)
 */


/* exclude_from_export */

void z_impl_k_yield(void)

{
  dword dVar1;
  bool bVar2;
  char *test;
  dword *pdVar3;
  k_spinlock_key_t key;
  char *file;
  char *file_00;
  undefined4 *puVar4;
  char *file_01;
  uint uVar5;
  int line;
  int line_00;
  int line_01;
  k_spinlock *lock;
  
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getCurrentExceptionNumber();
    uVar5 = uVar5 & 0x1f;
  }
  if (uVar5 == 0) {
    lock = (k_spinlock *)0x0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      lock = (k_spinlock *)getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
    if (bVar2) {
      z_spin_lock_set_owner((k_spinlock *)((int)&_current.stack_obj + 2));
      dVar1 = _current.base;
      *(byte *)(_current.base + 0xd) = *(byte *)(_current.base + 0xd) & 0x7f;
      z_priq_dumb_remove((sys_dlist_t *)&_current.next_event_link,(k_thread *)dVar1);
      dVar1 = _current.base;
      *(byte *)(_current.base + 0xd) = *(byte *)(_current.base + 0xd) | 0x80;
      if ((undefined *)dVar1 == &DAT_20006900) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!z_is_idle_thread_object(thread)",
                "WEST_TOPDIR/zephyr/kernel/sched.c",193);
      }
      else {
        puVar4 = (undefined4 *)_current.next_event_link;
        if ((undefined **)_current.next_event_link == &_current.next_event_link) {
          puVar4 = (undefined4 *)0x0;
        }
        for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
          if ((*(char *)(dVar1 + 0xe) != *(char *)((int)puVar4 + 0xe)) &&
             (*(char *)(dVar1 + 0xe) < *(char *)((int)puVar4 + 0xe))) {
            pdVar3 = (dword *)puVar4[1];
            *(undefined4 **)dVar1 = puVar4;
            *(dword **)(dVar1 + 4) = pdVar3;
            *pdVar3 = dVar1;
            puVar4[1] = dVar1;
            goto LAB_00077934;
          }
          if (puVar4 == (undefined4 *)_current.events) break;
        }
        *(undefined4 *)dVar1 = 0x2000be4c;
        *(dword *)(dVar1 + 4) = _current.events;
        *(dword *)_current.events = dVar1;
        _current.events = dVar1;
LAB_00077934:
        update_cache(1);
        bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.stack_obj + 2));
        if (bVar2) {
          z_swap(lock,key);
          return;
        }
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
            1402);
    _ASSERT("\t\n",test,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


