/*
 * Function: k_heap_aligned_alloc
 * Entry:    00074c9c
 * Prototype: void * __stdcall k_heap_aligned_alloc(k_heap * h, size_t align, size_t bytes, k_timeout_t timeout)
 */


/* exclude_from_export */

void * k_heap_aligned_alloc(k_heap *h,size_t align,size_t bytes,k_timeout_t timeout)

{
  k_timeout_t timeout_00;
  uint uVar1;
  uint uVar2;
  bool bVar3;
  void *pvVar4;
  int extraout_r1;
  char *test;
  char *file;
  char *file_00;
  char *file_01;
  int line;
  uint uVar5;
  int line_00;
  int line_01;
  k_heap *l;
  k_spinlock_key_t key;
  uint uVar6;
  k_timeout_t timeout_01;
  uint in_stack_00000004;
  uint local_30;
  uint uStack_2c;
  
  uVar6 = (uint)((ulonglong)timeout.ticks >> 0x20);
  timeout_01.ticks._4_4_ = align;
  timeout_01.ticks._0_4_ = &local_30;
  sys_timepoint_calc(timeout_01);
  uVar2 = uStack_2c;
  uVar1 = local_30;
  l = h + 5;
  key = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    key = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar3 = z_spin_lock_valid((k_spinlock *)l);
  if (bVar3) {
    z_spin_lock_set_owner((k_spinlock *)l);
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = getCurrentExceptionNumber();
      uVar5 = uVar5 & 0x1f;
    }
    if ((uVar5 == 0) || (uVar6 == 0 && in_stack_00000004 == 0)) {
      while ((pvVar4 = sys_heap_aligned_alloc((sys_heap *)h,align,bytes), pvVar4 == (void *)0x0 &&
             (uVar6 != 0 || in_stack_00000004 != 0))) {
        sys_timepoint_timeout((int *)&local_30,extraout_r1,uVar1,uVar2);
        in_stack_00000004 = uStack_2c;
        uVar6 = local_30;
        timeout_00.ticks._4_4_ = local_30;
        timeout_00.ticks._0_4_ = uStack_2c;
        z_pend_curr((k_spinlock *)l,key,(_wait_q_t *)(h + 3),timeout_00);
        key = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          key = getBasePriority();
        }
        bVar3 = (bool)isCurrentModePrivileged();
        if ((bVar3) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x20 < uVar5)) {
          setBasePriority(0x20);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar3 = z_spin_lock_valid((k_spinlock *)l);
        if (!bVar3) goto LAB_00074cda;
        z_spin_lock_set_owner((k_spinlock *)l);
      }
      bVar3 = z_spin_unlock_valid((k_spinlock *)l);
      if (bVar3) {
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          setBasePriority(key);
        }
        InstructionSynchronizationBarrier(0xf);
        return pvVar4;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "!arch_is_in_isr() || ((timeout).ticks == (((k_timeout_t) {0})).ticks)",
              "WEST_TOPDIR/zephyr/kernel/kheap.c",74);
      _ASSERT("\t\n",test,file_01,line_01);
    }
  }
  else {
LAB_00074cda:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


