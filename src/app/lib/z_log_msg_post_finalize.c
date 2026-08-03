/*
 * Function: z_log_msg_post_finalize
 * Entry:    00050a78
 * Prototype: void __stdcall z_log_msg_post_finalize(void)
 */


/* exclude_from_export_ai */

void z_log_msg_post_finalize(void)

{
  uint uVar1;
  bool bVar2;
  atomic_val_t aVar3;
  log_msg_generic *msg;
  undefined4 extraout_r1;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar4;
  k_timeout_t duration;
  
  aVar3 = atomic_inc(&buffered_cnt);
  if (panic_mode == '\0') {
    if (DAT_2000aab0 != 0) {
      if (aVar3 == 0) {
        duration.ticks._4_4_ = 0x8000;
        duration.ticks._0_4_ = extraout_r1;
        k_timer_start((k_timer *)&DAT_20005888,duration,(k_timeout_t)0x0);
      }
      else if (aVar3 == 9) {
        z_impl_k_timer_stop((k_timer *)&DAT_20005888);
        k_sem_give((k_sem *)&DAT_20003b98);
        return;
      }
    }
    return;
  }
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
  bVar2 = z_spin_lock_valid((k_spinlock *)&DAT_2000aaa8);
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)&DAT_2000aaa8);
    z_impl_log_process(msg);
    bVar2 = z_spin_unlock_valid((k_spinlock *)&DAT_2000aaa8);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",&DAT_2000aaa8,file_00,line_00);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",&DAT_2000aaa8,file,line);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


