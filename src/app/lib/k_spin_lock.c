/*
 * Function: k_spin_lock
 * Entry:    00076144
 * Prototype: k_spinlock_key_t __stdcall k_spin_lock(k_spinlock * l)
 */


/* exclude_from_export_ai */

k_spinlock_key_t k_spin_lock(k_spinlock *l)

{
  bool bVar1;
  char *file;
  char *file_00;
  int line;
  int line_00;
  uint uVar2;
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
  bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
  if (bVar1) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
    uVar2 = l[3].thread_cpu;
    bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      return uVar2 & 0xf;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file_00,
            line_00);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.userspace_local_data + 2),file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


