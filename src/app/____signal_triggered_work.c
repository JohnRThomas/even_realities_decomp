/*
 * Function: $_?_signal_triggered_work
 * Entry:    0007755c
 * Prototype: int __stdcall $_?_signal_triggered_work(k_poll_event * event, uint32_t status)
 */


int ____signal_triggered_work(k_poll_event *event,uint32_t status)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
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
  bVar2 = z_spin_lock_valid((k_spinlock *)&DAT_2000be78);
  if (bVar2) goto LAB_00077594;
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
  _ASSERT("\tInvalid spinlock %p\n",&DAT_2000be78,file,line);
  while( true ) {
    k_panic();
LAB_00077594:
    z_spin_lock_set_owner((k_spinlock *)&DAT_2000be78);
    if (event->poller != (undefined *)0x0) {
      pended_on_thread((k_thread *)event);
    }
    bVar2 = z_spin_unlock_valid((k_spinlock *)&DAT_2000be78);
    if (bVar2) break;
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    _ASSERT("\tNot my spinlock %p\n",&DAT_2000be78,file_00,line_00);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = z_abort_timeout((_timeout *)&event->mode);
  return iVar3;
}


