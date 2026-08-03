/*
 * Function: event_processor_fn
 * Entry:    0005285c
 * Prototype: void __stdcall event_processor_fn(k_work * work)
 */


/* exclude_from_export */

void event_processor_fn(k_work *work)

{
  log_msg_desc desc;
  bool bVar1;
  int iVar2;
  char *file;
  char *file_00;
  int line;
  int line_00;
  uint uVar3;
  code *pcVar4;
  undefined4 *ptr;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int *piVar8;
  dword in_stack_ffffffb8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined1 *local_38;
  char *local_34;
  undefined4 uStack_30;
  undefined2 local_2c;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x20 < uVar3)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = z_spin_lock_valid((k_spinlock *)&app_event_manager_lock);
  if (bVar1) {
    z_spin_lock_set_owner((k_spinlock *)&app_event_manager_lock);
    if (DAT_2000aca8 == (void *)0x0) {
      bVar1 = z_spin_unlock_valid((k_spinlock *)&app_event_manager_lock);
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar5);
        }
        InstructionSynchronizationBarrier(0xf);
        return;
      }
    }
    else {
      ptr = DAT_2000aca8;
      if (DAT_2000acac == 0) {
        ptr = (void *)0x0;
      }
      DAT_2000aca8 = (void *)0x0;
      DAT_2000acac = 0;
      bVar1 = z_spin_unlock_valid((k_spinlock *)&app_event_manager_lock);
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar5);
        }
        InstructionSynchronizationBarrier(0xf);
        while( true ) {
          if (ptr == (void *)0x0) {
            return;
          }
          pvVar7 = (void *)*ptr;
          puVar6 = (undefined4 *)ptr[1];
          if ((puVar6 < &DAT_000f8b8c) || (&UNK_000f8beb < puVar6)) break;
          uVar3 = ((int)(puVar6 + -0x3e2e3) >> 3) * -0x55555555;
          if ((*(int *)(&DAT_2000acb0 + (uVar3 >> 5) * 4) >> (uVar3 & 0x1f)) << 0x1f < 0) {
            if ((code *)puVar6[3] == (code *)0x0) {
              uStack_30 = *puVar6;
              local_34 = "e: %s";
              local_2c = 0x200;
              local_38 = &DAT_01000003;
              desc.level = (dword)&local_38;
              desc.domain = 0x1cc0;
              desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
              desc.data_len = in_stack_ffffffb8;
              z_impl_z_log_msg_static_create
                        (&PTR_s_app_event_manager_0008b8a0,desc,in_stack_ffffffbc,in_stack_ffffffc0)
              ;
            }
            else {
              (*(code *)puVar6[3])(ptr);
            }
          }
          iVar2 = 0;
          piVar8 = (int *)puVar6[1];
          while (((int *)puVar6[2] != piVar8 && (iVar2 == 0))) {
            if (piVar8 == (int *)0x0) {
              _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","es != ((void *)0)",
                      "WEST_TOPDIR/nrf/subsys/app_event_manager/app_event_manager.c",181);
              goto LAB_00052892;
            }
            if (*piVar8 == 0) {
              _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","el != ((void *)0)",
                      "WEST_TOPDIR/nrf/subsys/app_event_manager/app_event_manager.c",0xb9);
              goto LAB_00052892;
            }
            pcVar4 = *(code **)(*piVar8 + 4);
            if (pcVar4 == (code *)0x0) {
              _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","el->notification != ((void *)0)",
                      "WEST_TOPDIR/nrf/subsys/app_event_manager/app_event_manager.c",0xba);
              goto LAB_00052892;
            }
            iVar2 = (*pcVar4)(ptr);
            piVar8 = piVar8 + 1;
          }
          k_free(ptr);
          ptr = pvVar7;
        }
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(aeh->type_id >= _event_type_list_start) && (aeh->type_id < _event_type_list_end)",
                "WEST_TOPDIR/nrf/subsys/app_event_manager/app_event_manager.c",163);
        goto LAB_00052892;
      }
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
LAB_00052892:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


