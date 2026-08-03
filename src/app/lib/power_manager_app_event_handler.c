/*
 * Function: power_manager_app_event_handler
 * Entry:    00066fc8
 * Prototype: undefined4 __stdcall power_manager_app_event_handler(uint param_1, undefined4 param_2)
 */


/* WARNING: Removing unreachable block (ram,0x00067082) */
/* exclude_from_export */

undefined4 power_manager_app_event_handler(uint param_1,undefined4 param_2)

{
  char cVar1;
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  log_msg_desc desc_02;
  log_msg_desc desc_03;
  log_msg_desc desc_04;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  app_event_header *paVar6;
  uint extraout_r0;
  uint size;
  uint uVar7;
  undefined **ppuVar8;
  int iVar9;
  undefined **extraout_r3;
  uint uVar10;
  uint uVar11;
  k_timeout_t delay;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  
  ppuVar8 = *(undefined ***)(param_1 + 4);
  if (ppuVar8 != &PTR_s_power_manager_restrict_event_000f8bbc) {
    if (ppuVar8 == (undefined **)&DAT_000f8ba4) {
      if (power_state_2001e2d7 == POWER_STATE_ERROR) {
        delay.ticks._4_4_ = 0xf0000;
        delay.ticks._0_4_ = param_2;
        k_work_reschedule((k_work_delayable *)&error_trigger,delay);
        return 0;
      }
      if (power_state_2001e2d7 != POWER_STATE_ERROR_SUSPENDED) {
        if (power_state_2001e2d7 != POWER_STATE_SUSPENDING) {
          return 0;
        }
        local_28 = 2;
        local_24 = "Power down the board";
        desc_03.level = (dword)&local_28;
        desc_03.domain = 0x10c0;
        desc_03.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc_03.data_len = in_stack_ffffffc8;
        z_impl_z_log_msg_static_create
                  (&PTR_s_power_manager_0008ba18,desc_03,in_stack_ffffffcc,in_stack_ffffffd0);
        set_power_state(POWER_STATE_SUSPENDED);
        system_off();
        return 0;
      }
      power_state_2001e2d7 = POWER_STATE_ERROR_OFF;
      local_24 = "System turned off because of unrecoverable error";
      local_28 = 2;
      desc.level = (dword)&local_28;
      desc.domain = 0x1080;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffc8;
      z_impl_z_log_msg_static_create
                (&PTR_s_power_manager_0008ba18,desc,in_stack_ffffffcc,in_stack_ffffffd0);
      z_impl_log_panic();
      sys_poweroff();
      param_1 = extraout_r0;
      ppuVar8 = extraout_r3;
    }
    if (ppuVar8 == (undefined **)&DAT_000f8bd4) {
      uVar7 = (uint)power_state_2001e2d7;
      if (uVar7 - 4 < 2) {
        local_24 = "Wake up event consumed";
        local_28 = 2;
        desc_02.level = (dword)&local_28;
        desc_02.domain = 0x10c0;
        desc_02.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc_02.data_len = in_stack_ffffffc8;
        z_impl_z_log_msg_static_create
                  (&PTR_s_power_manager_0008ba18,desc_02,in_stack_ffffffcc,in_stack_ffffffd0);
        return 1;
      }
      if ((uVar7 == 3) || (uVar7 == 6)) {
        local_24 = "Wake up when going into sleep - rebooting";
        goto LAB_000670b6;
      }
      local_24 = "Wake up the board";
      local_28 = 2;
      desc_01.level = (dword)&local_28;
      desc_01.domain = 0x10c0;
      desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_01.data_len = in_stack_ffffffc8;
      z_impl_z_log_msg_static_create
                (&PTR_s_power_manager_0008ba18,desc_01,in_stack_ffffffcc,in_stack_ffffffd0);
      set_power_state(POWER_STATE_IDLE);
LAB_0006718a:
      power_down_counter_reset();
    }
    else {
      if (ppuVar8 != (undefined **)&DAT_000f8b8c) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",s_WEST_TOPDIR_nrf_subsys_caf_modul_000f4750,359)
        ;
LAB_000671e2:
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      uVar7 = (uint)*(byte *)(param_1 + 0xc);
      if (uVar7 - 1 < 2) {
        if ((power_state_2001e2d7 != 1) && (1 < power_state_2001e2d7 - 4)) {
          return 0;
        }
        paVar6 = _APP_EVENT_ALLOCATOR_FN(param_1);
        bVar2 = power_state_2001e2d7 == POWER_STATE_ERROR;
      }
      else {
        if ((*(undefined ***)(param_1 + 8) == &PTR_s_main_000f8c04) && (uVar7 == 0)) {
          if (DAT_2001e2d5 != POWER_STATE_IDLE) {
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!initialized",
                    s_WEST_TOPDIR_nrf_subsys_caf_modul_000f4750,0x151);
            goto LAB_000671e2;
          }
          power_state_2001e2d7 = DAT_2001e2d5;
          DAT_2001e2d5 = POWER_STATE_SUSPENDING;
          local_24 = "Activate power manager";
          local_28 = 2;
          desc_00.level = (dword)&local_28;
          desc_00.domain = 0x10c0;
          desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
          desc_00.data_len = in_stack_ffffffc8;
          z_impl_z_log_msg_static_create
                    (&PTR_s_power_manager_0008ba18,desc_00,in_stack_ffffffcc,in_stack_ffffffd0);
          k_work_init_delayable((k_work_delayable *)&error_trigger,(void *)0x884e7);
          k_work_init_delayable((k_work_delayable *)&power_down_trigger,(void *)0x66f69);
          goto LAB_0006718a;
        }
        if (uVar7 != 3) {
          return 0;
        }
        set_power_state(POWER_STATE_ERROR);
        paVar6 = _APP_EVENT_ALLOCATOR_FN(size);
        bVar2 = true;
      }
      *(bool *)&paVar6[1].node.next = bVar2;
      _event_submit(paVar6);
    }
    return 0;
  }
  bVar2 = check_if_power_state_allowed(POWER_MANAGER_LEVEL_SUSPENDED);
  bVar3 = check_if_power_state_allowed(POWER_MANAGER_LEVEL_OFF);
  cVar1 = *(char *)(param_1 + 0xc);
  uVar11 = *(uint *)(param_1 + 8) >> 5;
  uVar7 = *(uint *)(param_1 + 8) & 0x1f;
  if (cVar1 < '\0') {
    iVar9 = 0;
LAB_00067000:
    (&power_mode_restrict_flags)[iVar9 + uVar11] =
         (&power_mode_restrict_flags)[iVar9 + uVar11] | 1 << uVar7;
  }
  else {
    iVar9 = 1;
    uVar10 = ~(1 << uVar7);
    (&power_mode_restrict_flags)[uVar11] = (&power_mode_restrict_flags)[uVar11] & uVar10;
    if (cVar1 == '\0') goto LAB_00067000;
    *(uint *)(&DAT_2000bcf4 + uVar11 * 4) = *(uint *)(&DAT_2000bcf4 + uVar11 * 4) & uVar10;
  }
  bVar4 = check_if_power_state_allowed(POWER_MANAGER_LEVEL_SUSPENDED);
  bVar5 = check_if_power_state_allowed(POWER_MANAGER_LEVEL_OFF);
  if (bVar2) {
    if ((!bVar4) &&
       (k_work_cancel_delayable((k_work_delayable *)&power_down_trigger),
       power_state_2001e2d7 != POWER_STATE_IDLE)) {
      paVar6 = app_event_manager_alloc(8);
      if (paVar6 != (app_event_header *)0x0) {
        paVar6->type_id = (event_type *)&DAT_000f8bd4;
      }
      _event_submit(paVar6);
    }
  }
  else if (bVar4) {
    power_down_counter_reset();
  }
  if (bVar3) {
    if ((!bVar5) && (power_state_2001e2d7 == POWER_STATE_OFF)) {
      local_24 = "Off restricted - rebooting";
LAB_000670b6:
      local_28 = 2;
      desc_04.level = (dword)&local_28;
      desc_04.domain = 0x10c0;
      desc_04.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc_04.data_len = in_stack_ffffffc8;
      z_impl_z_log_msg_static_create
                (&PTR_s_power_manager_0008ba18,desc_04,in_stack_ffffffcc,in_stack_ffffffd0);
                    /* WARNING: Subroutine does not return */
      sys_reboot(0);
    }
  }
  else if ((bVar5) && (power_state_2001e2d7 == POWER_STATE_SUSPENDED)) {
    system_off();
  }
  return 1;
}


