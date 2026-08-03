/*
 * Function: transition_complete
 * Entry:    0004eb44
 * Prototype: void __stdcall transition_complete(onoff_manager * mgr, int res)
 */


/* exclude_from_export */

void transition_complete(onoff_manager *mgr,int res)

{
  uint uVar1;
  bool bVar2;
  char *file;
  int line;
  word *l;
  
  l = &mgr->flags;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = z_spin_lock_valid((k_spinlock *)l);
  if (bVar2) {
    z_spin_lock_set_owner((k_spinlock *)l);
    mgr[1].clients = res;
    process_event((evtchn_port_t)mgr);
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
  _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


