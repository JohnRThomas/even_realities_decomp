/*
 * Function: sys_clock_tick_get
 * Entry:    00078210
 * Prototype: int64_t __stdcall sys_clock_tick_get(void)
 */


/* exclude_from_export */

int64_t sys_clock_tick_get(void)

{
  bool bVar1;
  uint uVar2;
  char *file;
  char *file_00;
  int line;
  int line_00;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
  if (bVar1) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.swap_retval + 2));
    uVar2 = elapsed();
    iVar3 = uVar2 + DAT_20006bc0;
    iVar4 = DAT_20006bc4 + ((int)uVar2 >> 0x1f) + (uint)CARRY4(uVar2,DAT_20006bc0);
    bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.swap_retval + 2));
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar5);
      }
      InstructionSynchronizationBarrier(0xf);
      return CONCAT44(iVar4,iVar3);
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


