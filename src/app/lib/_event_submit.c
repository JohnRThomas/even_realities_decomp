/*
 * Function: _event_submit
 * Entry:    00052a1c
 * Prototype: void __stdcall _event_submit(app_event_header * aeh)
 */


/* exclude_from_export */

void _event_submit(app_event_header *aeh)

{
  uint uVar1;
  app_event_header *paVar2;
  bool bVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 uVar4;
  
  if (aeh == (app_event_header *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","aeh",
            "WEST_TOPDIR/nrf/subsys/app_event_manager/app_event_manager.c",209);
  }
  else if (((event_type *)&UNK_000f8b8b < aeh->type_id) &&
          (aeh->type_id < (event_type *)&DAT_000f8bec)) {
    uVar4 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar4 = getBasePriority();
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if ((bVar3) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar3 = z_spin_lock_valid((k_spinlock *)&app_event_manager_lock);
    if (bVar3) {
      z_spin_lock_set_owner((k_spinlock *)&app_event_manager_lock);
      (aeh->node).next = (sys_snode_t *)0x0;
      paVar2 = aeh;
      if (DAT_2000acac != (app_event_header *)0x0) {
        (DAT_2000acac->node).next = &aeh->node;
        paVar2 = DAT_2000aca8;
      }
      DAT_2000aca8 = paVar2;
      DAT_2000acac = aeh;
      bVar3 = z_spin_unlock_valid((k_spinlock *)&app_event_manager_lock);
      if (bVar3) {
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        k_work_submit(&event_processor);
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",&app_event_manager_lock,file_00,line_00);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",&app_event_manager_lock,file,line);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "(aeh->type_id >= _event_type_list_start) && (aeh->type_id < _event_type_list_end)",
            "WEST_TOPDIR/nrf/subsys/app_event_manager/app_event_manager.c",210);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


