/*
 * Function: onoff_release
 * Entry:    0004ecd8
 * Prototype: int __stdcall onoff_release(onoff_manager * mgr)
 */


/* exclude_from_export */

int onoff_release(onoff_manager *mgr)

{
  short sVar1;
  uint uVar2;
  bool bVar3;
  char *file;
  char *file_00;
  int line;
  int line_00;
  ushort uVar4;
  int iVar5;
  word *l;
  undefined4 uVar6;
  
  l = &mgr->flags;
  uVar6 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar6 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar3 = z_spin_lock_valid((k_spinlock *)l);
  if (bVar3) {
    z_spin_lock_set_owner((k_spinlock *)l);
    uVar4 = *(ushort *)&mgr[1].monitors & 7;
    if (uVar4 == 2) {
      sVar1 = *(short *)((int)&mgr[1].monitors + 2);
      if (sVar1 == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","mgr->refs > 0","WEST_TOPDIR/zephyr/lib/os/onoff.c",
                495);
        goto LAB_0004ed66;
      }
      *(short *)((int)&mgr[1].monitors + 2) = sVar1 + -1;
      iVar5 = 2;
      if (sVar1 == 1) {
        process_event((evtchn_port_t)mgr);
        return 2;
      }
    }
    else if (uVar4 == 1) {
      iVar5 = -5;
    }
    else {
      iVar5 = -0x86;
    }
    bVar3 = z_spin_unlock_valid((k_spinlock *)l);
    if (bVar3) {
      bVar3 = (bool)isCurrentModePrivileged();
      if (bVar3) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      return iVar5;
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
LAB_0004ed66:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


