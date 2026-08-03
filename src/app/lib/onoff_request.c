/*
 * Function: onoff_request
 * Entry:    0004eba8
 * Prototype: int __stdcall onoff_request(onoff_manager * mgr, onoff_client * cli)
 */


/* exclude_from_export */

int onoff_request(onoff_manager *mgr,onoff_client *cli)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  char *file;
  char *file_00;
  int line;
  int line_00;
  uint uVar6;
  word *l;
  undefined4 uVar7;
  
  iVar5 = validate_args(mgr,cli);
  if (iVar5 < 0) {
    return iVar5;
  }
  l = &mgr->flags;
  uVar7 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar7 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x20 < uVar6)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar3 = z_spin_lock_valid((k_spinlock *)l);
  if (!bVar3) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
    _ASSERT("\tInvalid spinlock %p\n",(char *)l,file,line);
    goto LAB_0004ec72;
  }
  z_spin_lock_set_owner((k_spinlock *)l);
  sVar1 = *(short *)((int)&mgr[1].monitors + 2);
  uVar2 = *(ushort *)&mgr[1].monitors;
  uVar6 = uVar2 & 7;
  if (sVar1 == -1) {
    uVar6 = 0xfffffff5;
LAB_0004ec46:
    bVar3 = false;
  }
  else {
    if (uVar6 != 2) {
      switch(uVar6) {
      case 0:
      case 4:
      case 6:
        *cli = 0;
        if ((undefined4 *)mgr->monitors == (undefined4 *)0x0) {
          mgr->clients = cli;
          mgr->monitors = cli;
        }
        else {
          *(undefined4 *)mgr->monitors = cli;
          mgr->monitors = cli;
        }
        if ((uVar2 & 7) == 0) {
          process_event((evtchn_port_t)mgr);
          return uVar6;
        }
        break;
      case 1:
        uVar6 = 0xfffffffb;
        break;
      default:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","state == (1UL << (0))",
                "WEST_TOPDIR/zephyr/lib/os/onoff.c",456);
        goto LAB_0004ec72;
      case 5:
        uVar6 = 0xffffff7a;
      }
      goto LAB_0004ec46;
    }
    *(short *)((int)&mgr[1].monitors + 2) = sVar1 + 1;
    bVar3 = true;
  }
  bVar4 = z_spin_unlock_valid((k_spinlock *)l);
  if (bVar4) {
    bVar4 = (bool)isCurrentModePrivileged();
    if (bVar4) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    if (bVar3) {
      notify_one();
    }
    return uVar6;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
          "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
  _ASSERT("\tNot my spinlock %p\n",(char *)l,file_00,line_00);
LAB_0004ec72:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


