/*
 * Function: k_heap_free
 * Entry:    00074dd4
 * Prototype: undefined __stdcall k_heap_free(sys_heap * param_1, void * param_2)
 */


/* exclude_from_export */

void k_heap_free(sys_heap *param_1,void *param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  size_t *l;
  k_spinlock_key_t key;
  
  l = &param_1[1].init_bytes;
  key = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    key = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)l);
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)l);
    sys_heap_free(param_1,param_2);
    iVar3 = z_unpend_all((_wait_q_t *)(param_1 + 1));
    if (iVar3 != 0) {
      z_reschedule((k_spinlock *)l,key);
      return;
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)l);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(key);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


