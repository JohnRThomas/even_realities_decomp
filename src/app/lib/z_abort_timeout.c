/*
 * Function: z_abort_timeout
 * Entry:    0007801c
 * Prototype: int __stdcall z_abort_timeout(_timeout * to)
 */


/* exclude_from_export */

int z_abort_timeout(_timeout *to)

{
  uint uVar1;
  bool bVar2;
  char *file;
  char *file_00;
  int line;
  int line_00;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.swap_retval + 2));
    if ((to->node).next == (void *)0x0) {
      iVar3 = -0x16;
    }
    else {
      remove_timeout((int *)to);
      iVar3 = 0;
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return iVar3;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.swap_retval + 2),file_00,line_00);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.swap_retval + 2),file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


