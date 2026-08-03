/*
 * Function: work_timeout
 * Entry:    00076054
 * Prototype: void __stdcall work_timeout(_timeout * to)
 */


/* exclude_from_export_ai */

void work_timeout(_timeout *to)

{
  uint uVar1;
  bool bVar2;
  int extraout_r0;
  k_work_q *in_r1;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar3;
  k_work_q *local_14;
  
  uVar3 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar3 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  local_14 = in_r1;
  bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.userspace_local_data + 2));
    local_14 = (k_work_q *)0x0;
    flag_clear((uint32_t *)((int)&to[-1].dticks + 4),3);
    if (extraout_r0 != 0) {
      local_14 = to[1].node.next;
      submit_to_queue_locked((k_work *)&to[-1].fn,&local_14);
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.userspace_local_data + 2));
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
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


