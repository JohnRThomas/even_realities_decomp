/*
 * Function: $_?_onoff_request
 * Entry:    0004eba8
 * Prototype: int __stdcall $_?_onoff_request(onoff_manager * mgr, onoff_client * cli)
 */


int ____onoff_request(onoff_manager *mgr,onoff_client *cli)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  char *file;
  char *file_00;
  int line;
  int line_00;
  undefined4 *puVar5;
  undefined4 *extraout_r3;
  uint unaff_r6;
  word *l;
  undefined4 uVar6;
  
  uVar4 = validate_args(mgr,cli);
  if (-1 < (int)uVar4) {
    l = &mgr->flags;
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)l);
    if (bVar2) {
      z_spin_lock_set_owner((k_spinlock *)l);
      sVar1 = *(short *)((int)&mgr[1].monitors + 2);
      uVar4 = *(ushort *)&mgr[1].monitors & 7;
      unaff_r6 = uVar4;
      if (sVar1 == -1) {
        uVar4 = 0xfffffff5;
        goto LAB_0004ec46;
      }
      if (uVar4 == 2) {
        *(short *)((int)&mgr[1].monitors + 2) = sVar1 + 1;
        bVar2 = true;
        goto LAB_0004ec10;
      }
      switch(uVar4) {
      case 0:
      case 4:
      case 6:
        *cli = 0;
        puVar5 = (undefined4 *)mgr->monitors;
        if (puVar5 != (undefined4 *)0x0) goto LAB_0004ec76;
        mgr->clients = cli;
        mgr->monitors = cli;
        goto LAB_0004ec58;
      case 1:
        uVar4 = 0xfffffffb;
        goto LAB_0004ec46;
      default:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","state == (1UL << (0))",
                "WEST_TOPDIR/zephyr/lib/os/onoff.c",456);
        break;
      case 5:
        uVar4 = 0xffffff7a;
        goto LAB_0004ec46;
      }
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
    }
    while( true ) {
      k_panic();
      puVar5 = extraout_r3;
      uVar4 = unaff_r6;
LAB_0004ec76:
      *puVar5 = cli;
      mgr->monitors = cli;
LAB_0004ec58:
      unaff_r6 = uVar4;
      if (uVar4 == 0) {
        process_event((evtchn_port_t)mgr);
        return 0;
      }
LAB_0004ec46:
      bVar2 = false;
LAB_0004ec10:
      bVar3 = z_spin_unlock_valid((k_spinlock *)l);
      if (bVar3) break;
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    if (bVar2) {
      ____notify_one();
    }
  }
  return uVar4;
}


