/*
 * Function: clear_event_registration
 * Entry:    00078694
 * Prototype: void __stdcall clear_event_registration(k_poll_event * event)
 */


/* exclude_from_export */

void clear_event_registration(k_poll_event *event)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int in_r1;
  char *test;
  char *test_00;
  char *test_01;
  char *test_02;
  char *test_03;
  undefined4 in_r2;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  char *file_03;
  int *piVar4;
  char *file_04;
  char *file_05;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int iVar5;
  int line_04;
  int line_05;
  
  iVar3 = (int)&event->_node + in_r1 * 0x14;
  do {
    if (in_r1 == 0) {
      return;
    }
    *(undefined4 *)(iVar3 + -0xc) = 0;
    switch(*(byte *)(iVar3 + -7) & 0x3f) {
    case 0:
      goto switchD_000786c0_caseD_0;
    case 1:
      if (*(int *)(iVar3 + -4) == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->signal != ((void *)0)",
                "WEST_TOPDIR/zephyr/kernel/poll.c",190);
        _ASSERT("\tinvalid poll signal\n\n",test_01,file_01,line_01);
        goto LAB_000786ec;
      }
      break;
    case 2:
      if (*(int *)(iVar3 + -4) == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->sem != ((void *)0)",
                "WEST_TOPDIR/zephyr/kernel/poll.c",0xb6);
        _ASSERT("\tinvalid semaphore\n\n",test,file,line);
        goto LAB_000786ec;
      }
      break;
    default:
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/kernel/poll.c",0xcf);
      _ASSERT("\tinvalid event type\n\n",test_03,file_03,line_03);
      goto LAB_000786ec;
    case 4:
      if (*(int *)(iVar3 + -4) == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->queue != ((void *)0)",
                "WEST_TOPDIR/zephyr/kernel/poll.c",0xba);
        _ASSERT("\tinvalid queue\n\n",test_00,file_00,line_00);
        goto LAB_000786ec;
      }
      break;
    case 8:
      if (*(int *)(iVar3 + -4) == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->msgq != ((void *)0)",
                "WEST_TOPDIR/zephyr/kernel/poll.c",0xc2);
        _ASSERT("\tinvalid message queue\n\n",test_02,file_02,line_02);
        goto LAB_000786ec;
      }
    }
    iVar5 = *(int *)(iVar3 + -0x14);
    if (iVar5 != 0) {
      piVar4 = *(int **)(iVar3 + -0x10);
      *piVar4 = iVar5;
      *(int **)(iVar5 + 4) = piVar4;
      *(undefined4 *)(iVar3 + -0x14) = 0;
      *(undefined4 *)(iVar3 + -0x10) = 0;
    }
switchD_000786c0_caseD_0:
    bVar2 = z_spin_unlock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
    if (!bVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file_04,line_04);
LAB_000786ec:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(in_r2);
    }
    InstructionSynchronizationBarrier(0xf);
    in_r2 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      in_r2 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = z_spin_lock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
    in_r1 = in_r1 + -1;
    if (!bVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72);
      _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file_05,line_05);
      goto LAB_000786ec;
    }
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.resource_pool + 2));
    iVar3 = iVar3 + -0x14;
  } while( true );
}


