/*
 * Function: register_events
 * Entry:    00078478
 * Prototype: int __stdcall register_events(k_poll_event * events, int num_events, z_poller * poller, bool just_check)
 */


/* exclude_from_export */

int register_events(k_poll_event *events,int num_events,z_poller *poller,bool just_check)

{
  bool bVar1;
  sys_dlist_t *events_00;
  char *test;
  char *test_00;
  char *test_01;
  char *test_02;
  char *test_03;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  char *file_03;
  char *file_04;
  char *file_05;
  char *file_06;
  int line;
  int line_00;
  uint uVar2;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  int line_05;
  int line_06;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    if (num_events <= iVar3) {
      return iVar4;
    }
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = z_spin_lock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
    if (!bVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_lock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",114);
      _ASSERT("\tInvalid spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file,line);
      goto LAB_0007858e;
    }
    z_spin_lock_set_owner((k_spinlock *)((int)&_current.resource_pool + 2));
    switch(*(byte *)((int)&events->tag + 1) & 0x3f) {
    case 0:
      break;
    case 1:
      if (*(int *)(events->type__POLL_NUM_TYPES + 8) == 0) break;
      uVar2 = 1;
LAB_000784f2:
      events->poller = (undefined *)0x0;
      events->tag = events->tag & 0xffe03fff | (uVar2 | (events->tag & 0x1fffff) >> 0xe) << 0xe;
      *(undefined1 *)poller = 0;
      goto LAB_00078508;
    case 2:
      if (*(int *)(events->type__POLL_NUM_TYPES + 8) != 0) {
        uVar2 = 2;
        goto LAB_000784f2;
      }
      break;
    default:
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/kernel/poll.c",99);
      _ASSERT("\tinvalid event type (0x%x)\n\n",(char *)(*(byte *)((int)&events->tag + 1) & 0x3f),
              file_01,line_01);
      goto LAB_0007858e;
    case 4:
      if (*(int *)events->type__POLL_NUM_TYPES != 0) {
        uVar2 = 4;
        goto LAB_000784f2;
      }
      break;
    case 8:
      if (*(int *)(events->type__POLL_NUM_TYPES + 0x24) != 0) {
        uVar2 = 0x10;
        goto LAB_000784f2;
      }
    }
    if ((!just_check) && ((char)*poller != '\0')) {
      switch(*(byte *)((int)&events->tag + 1) & 0x3f) {
      case 0:
        goto switchD_0007854c_caseD_0;
      case 1:
        events_00 = (sys_dlist_t *)events->type__POLL_NUM_TYPES;
        if (events_00 == (sys_dlist_t *)0x0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->signal != ((void *)0)",
                  "WEST_TOPDIR/zephyr/kernel/poll.c",149);
          _ASSERT("\tinvalid poll signal\n\n",test_01,file_04,line_04);
          goto LAB_0007858e;
        }
        break;
      case 2:
        if (events->type__POLL_NUM_TYPES == 0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->sem != ((void *)0)",
                  "WEST_TOPDIR/zephyr/kernel/poll.c",0x8d);
          _ASSERT("\tinvalid semaphore\n\n",test,file_02,line_02);
          goto LAB_0007858e;
        }
        events_00 = (sys_dlist_t *)(events->type__POLL_NUM_TYPES + 0x10);
        break;
      default:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/kernel/poll.c",0xa6);
        _ASSERT("\tinvalid event type\n\n",test_03,file_06,line_06);
        goto LAB_0007858e;
      case 4:
        if (events->type__POLL_NUM_TYPES == 0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->queue != ((void *)0)",
                  "WEST_TOPDIR/zephyr/kernel/poll.c",145);
          _ASSERT("\tinvalid queue\n\n",test_00,file_03,line_03);
          goto LAB_0007858e;
        }
        events_00 = (sys_dlist_t *)(events->type__POLL_NUM_TYPES + 0x14);
        break;
      case 8:
        if (events->type__POLL_NUM_TYPES == 0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->msgq != ((void *)0)",
                  "WEST_TOPDIR/zephyr/kernel/poll.c",153);
          _ASSERT("\tinvalid message queue\n\n",test_02,file_05,line_05);
          goto LAB_0007858e;
        }
        events_00 = (sys_dlist_t *)(events->type__POLL_NUM_TYPES + 0x28);
      }
      add_event(events_00,events,poller);
switchD_0007854c_caseD_0:
      events->poller = (undefined *)poller;
      iVar4 = iVar4 + 1;
    }
LAB_00078508:
    bVar1 = z_spin_unlock_valid((k_spinlock *)((int)&_current.resource_pool + 2));
    events = (k_poll_event *)&events->state__POLL_NUM_STATES;
    if (!bVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","z_spin_unlock_valid(l)",
              "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0);
      _ASSERT("\tNot my spinlock %p\n",(char *)((int)&_current.resource_pool + 2),file_00,line_00);
LAB_0007858e:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar3 = iVar3 + 1;
  } while( true );
}


