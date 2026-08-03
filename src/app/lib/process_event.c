/*
 * Function: process_event
 * Entry:    0004e79c
 * Prototype: void __stdcall process_event(evtchn_port_t port)
 */


/* exclude_from_export */

void process_event(evtchn_port_t port)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int in_r1;
  uint uVar4;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  undefined4 *puVar5;
  ushort uVar6;
  ushort extraout_r2;
  ushort extraout_r2_00;
  undefined4 in_r2;
  char *extraout_r2_01;
  char *extraout_r2_02;
  char *file;
  char *file_00;
  int extraout_r3;
  int extraout_r3_00;
  int line;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  k_spinlock *l;
  
  uVar6 = *(ushort *)(port + 0x1c);
  if ((int)((uint)uVar6 << 0x1c) < 0) {
    if (in_r1 == 1) {
      uVar6 = uVar6 | 0x10;
    }
    else {
      uVar6 = uVar6 | 0x20;
    }
    *(ushort *)(port + 0x1c) = uVar6;
LAB_0004e7e0:
    bVar1 = z_spin_unlock_valid((k_spinlock *)(port + 0x14));
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(in_r2);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
            "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
    file = extraout_r2_01;
    iVar3 = extraout_r3;
LAB_0004e960:
    _ASSERT("\tNot my spinlock %p\n",(char *)(port + 0x14),file,iVar3);
LAB_0004e8c6:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  uVar4 = uVar6 & 7;
  if (in_r1 != 2) goto switchD_0004e7c4_caseD_1;
LAB_0004e7b4:
  iVar3 = process_recheck((onoff_manager *)port);
  if (iVar3 != 0) {
    uVar4 = extraout_r1;
    switch(iVar3) {
    case 1:
switchD_0004e7c4_caseD_1:
      do {
        puVar10 = *(undefined4 **)(port + 0x18);
        uVar6 = *(ushort *)(port + 0x1c);
        if ((int)puVar10 < 0) {
          puVar9 = *(undefined4 **)port;
          *(undefined4 *)port = 0;
          *(undefined4 *)(port + 4) = 0;
          *(ushort *)(port + 0x1c) = uVar6 & 0xfff8 | 1;
LAB_0004e89c:
          uVar6 = *(ushort *)(port + 0x1c);
          uVar11 = uVar6 & 7;
          if (uVar11 != uVar4) goto LAB_0004ea42;
          if (puVar9 != (undefined4 *)0x0) {
            pcVar8 = (code *)0x0;
            bVar1 = false;
            goto LAB_0004e93c;
          }
        }
        else {
          uVar4 = uVar6 & 7;
          if (uVar4 - 5 < 2) {
            puVar9 = *(undefined4 **)port;
            *(undefined4 *)port = 0;
            *(undefined4 *)(port + 4) = 0;
            puVar5 = puVar9;
            if (uVar4 == 6) {
              for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
                *(short *)(port + 0x1e) = *(short *)(port + 0x1e) + 1;
              }
              uVar6 = uVar6 & 0xfff8 | 2;
            }
            else {
              uVar6 = uVar6 & 0xfff8;
            }
            *(ushort *)(port + 0x1c) = uVar6;
            iVar3 = process_recheck((onoff_manager *)port);
            uVar4 = extraout_r1_00;
            if (iVar3 != 0) {
              *(ushort *)(port + 0x1c) = extraout_r2 | 0x20;
            }
            goto LAB_0004e89c;
          }
          if (uVar4 != 4) {
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x11b);
            break;
          }
          *(ushort *)(port + 0x1c) = uVar6 & 0xfff8;
          iVar3 = process_recheck((onoff_manager *)port);
          if (iVar3 != 0) {
            *(ushort *)(port + 0x1c) = extraout_r2_00 | 0x20;
          }
          uVar6 = *(ushort *)(port + 0x1c);
          uVar11 = uVar6 & 7;
          if (uVar11 == extraout_r1_01) goto LAB_0004e86c;
          puVar9 = (undefined4 *)0x0;
LAB_0004ea42:
          pcVar8 = (code *)0x0;
LAB_0004e928:
          if (*(int *)(port + 8) == 0) {
            if (puVar9 == (undefined4 *)0x0) {
              if (pcVar8 == (code *)0x0) goto LAB_0004e86c;
              bVar1 = false;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = true;
          }
LAB_0004e93c:
          l = (k_spinlock *)(port + 0x14);
          *(ushort *)(port + 0x1c) = uVar6 | 8;
          bVar2 = z_spin_unlock_valid(l);
          if (!bVar2) {
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
                    "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
            file = extraout_r2_02;
            iVar3 = extraout_r3_00;
            goto LAB_0004e960;
          }
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            setBasePriority(in_r2);
          }
          InstructionSynchronizationBarrier(0xf);
          if ((bVar1) && (puVar5 = *(undefined4 **)(port + 8), puVar5 != (undefined4 *)0x0)) {
            puVar7 = (undefined4 *)*puVar5;
            while (puVar5 != (undefined4 *)0x0) {
              (*(code *)puVar5[1])(port,puVar5,uVar11,puVar10);
              puVar5 = puVar7;
              if (puVar7 != (undefined4 *)0x0) {
                puVar7 = (undefined4 *)*puVar7;
              }
            }
          }
          while (puVar9 != (undefined4 *)0x0) {
            puVar9 = (undefined4 *)*puVar9;
            notify_one();
          }
          if (pcVar8 != (code *)0x0) {
            (*pcVar8)(port,0x4eb45);
          }
          in_r2 = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            in_r2 = getBasePriority();
          }
          bVar1 = (bool)isCurrentModePrivileged();
          if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x20 < uVar4)) {
            setBasePriority(0x20);
          }
          InstructionSynchronizationBarrier(0xf);
          bVar1 = z_spin_lock_valid(l);
          if (!bVar1) {
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
                    "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
            _ASSERT("\tInvalid spinlock %p\n",(char *)l,file_00,line);
            break;
          }
          z_spin_lock_set_owner(l);
          *(ushort *)(port + 0x1c) = *(ushort *)(port + 0x1c) & 0xfff7;
        }
LAB_0004e86c:
        uVar6 = *(ushort *)(port + 0x1c);
        uVar4 = (uint)uVar6;
        if (-1 < (int)(uVar4 << 0x1b)) goto LAB_0004eb12;
        *(ushort *)(port + 0x1c) = uVar6 & 0xffef;
        uVar4 = uVar4 & 7;
      } while( true );
    default:
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/lib/os/onoff.c",363);
      break;
    case 3:
      if (extraout_r1 == 0) {
        if (*(int *)port == 0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!sys_slist_is_empty(&mgr->clients)",
                  "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x157);
        }
        else {
          pcVar8 = (code *)**(int **)(port + 0x10);
          if (pcVar8 != (code *)0x0) {
            uVar11 = 6;
            uVar6 = *(ushort *)(port + 0x1c) & 0xfff8 | 6;
            *(ushort *)(port + 0x1c) = uVar6;
            puVar9 = (undefined4 *)0x0;
            puVar10 = (undefined4 *)0x0;
            goto LAB_0004e928;
          }
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","transit != ((void *)0)",
                  "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x15a);
        }
      }
      else {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","state == 0U","WEST_TOPDIR/zephyr/lib/os/onoff.c",
                342);
      }
      break;
    case 4:
      if (extraout_r1 == 2) {
        if (*(short *)(port + 0x1e) == 0) {
          pcVar8 = *(code **)(*(int *)(port + 0x10) + 4);
          if (pcVar8 != (code *)0x0) {
            uVar6 = *(ushort *)(port + 0x1c) & 0xfff8 | 4;
            uVar11 = 4;
            *(ushort *)(port + 0x1c) = uVar6;
            puVar9 = (undefined4 *)0x0;
            puVar10 = (undefined4 *)0x0;
            goto LAB_0004e928;
          }
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","transit != ((void *)0)",
                  "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x161);
        }
        else {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","mgr->refs == 0",
                  "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x15e);
        }
      }
      else {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","state == (1UL << (1))",
                "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x15d);
      }
      break;
    case 5:
      if (extraout_r1 == 1) {
        if (*(int *)port == 0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!sys_slist_is_empty(&mgr->clients)",
                  "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x165);
        }
        else {
          pcVar8 = *(code **)(*(int *)(port + 0x10) + 8);
          if (pcVar8 != (code *)0x0) {
            puVar9 = (undefined4 *)0x0;
            uVar6 = *(ushort *)(port + 0x1c) & 0xfff8 | 5;
            uVar11 = 5;
            *(ushort *)(port + 0x1c) = uVar6;
            puVar10 = puVar9;
            goto LAB_0004e928;
          }
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","transit != ((void *)0)",
                  "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x168);
        }
      }
      else {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","state == (1UL << (0))",
                "WEST_TOPDIR/zephyr/lib/os/onoff.c",0x164);
      }
    }
    goto LAB_0004e8c6;
  }
  goto LAB_0004e7e0;
LAB_0004eb12:
  if (-1 < (int)(uVar4 << 0x1a)) goto LAB_0004e7e0;
  *(ushort *)(port + 0x1c) = uVar6 & 0xffdf;
  goto LAB_0004e7b4;
}


