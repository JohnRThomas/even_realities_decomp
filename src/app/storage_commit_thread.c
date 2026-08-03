/*
 * Function: storage_commit_thread
 * Entry:    000258fc
 * Prototype: undefined __stdcall storage_commit_thread(GlassesState * gs_state)
 */


void storage_commit_thread(GlassesState *gs_state)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  char *pcVar4;
  GlassesState *pGVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar6;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  void *puVar6;
  undefined4 extraout_r1_04;
  undefined4 uVar7;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined1 uVar8;
  uint uVar9;
  size_t sVar10;
  int iVar11;
  uint uVar12;
  local_store_write_cb *plVar13;
  undefined1 *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  
  __file_init();
  FUN_00025694();
  uVar7 = extraout_r1;
LAB_00025914:
  do {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = uVar7;
    z_impl_k_sem_take(&gs_state->dashboard_position_sem,timeout);
    bVar3 = false;
    uVar7 = extraout_r1_00;
    while (DAT_200083a4 != 0) {
      try_to_save_file(gs_state);
      bVar3 = true;
      uVar7 = extraout_r1_01;
    }
    iVar11 = *(int *)&gs_state->field_0x1060;
  } while ((iVar11 == 0x15) || (bVar3));
  if (0x1a < iVar11) {
    if (iVar11 != 0x3e) goto switchD_0002594a_caseD_4;
    pGVar5 = __get_dashboard_state();
    update_burial_point_to_flash(pGVar5);
    goto LAB_000259a8;
  }
  switch(iVar11) {
  case 1:
    sVar10 = 1;
    plVar13 = (gs_state->settings_ctx).write_cb;
    pcVar4 = "brightness_level";
    puVar6 = &(gs_state->jdb_panel_context).panel_brightness_level;
    break;
  case 2:
    sVar10 = 1;
    plVar13 = (gs_state->settings_ctx).write_cb;
    pcVar4 = "3dof_enable";
    puVar6 = &(gs_state->imu_fusion_context)._dof_enable;
    break;
  case 3:
    sVar10 = 1;
    plVar13 = (gs_state->settings_ctx).write_cb;
    pcVar4 = "display_mode";
    puVar6 = &gs_state->display_mode;
    break;
  default:
    goto switchD_0002594a_caseD_4;
  case 6:
    sVar10 = 0x75;
    plVar13 = (gs_state->settings_ctx).write_cb;
    puVar6 = gs_state->dashboard_ts;
    pcVar4 = "dashboard_ts";
    break;
  case 7:
    sVar10 = 7;
    plVar13 = (gs_state->settings_ctx).write_cb;
    puVar6 = gs_state->countdown_ts;
    pcVar4 = "countdown_ts";
    break;
  case 8:
    sVar10 = 0x16a;
    plVar13 = (gs_state->settings_ctx).write_cb;
    puVar6 = gs_state->user_sched_info;
    pcVar4 = "user_sched_info";
    break;
  case 0xb:
    sVar10 = 1;
    plVar13 = (gs_state->settings_ctx).write_cb;
    pcVar4 = "wakeup_angle";
    puVar6 = &(gs_state->imu_fusion_context).wakeup_angle;
    break;
  case 0x11:
    z_impl_k_sleep((k_timeout_t)0x50000);
    change_work_mode(7);
    goto switchD_0002594a_caseD_4;
  case 0x16:
    if (DAT_200083b4 == 0x1c0000) {
      get_demo_image_source_from_flash();
      pGVar5 = __get_dashboard_state();
      if (pGVar5->is_master == true) {
        pGVar5 = __get_dashboard_state();
        uVar8 = 0xd;
        puVar14 = *(undefined1 **)&pGVar5->field_0x1010;
        uVar7 = extraout_r1_04;
      }
      else {
        pGVar5 = __get_dashboard_state();
        uVar8 = 0xc;
        puVar14 = *(undefined1 **)&pGVar5->field_0x1010;
        uVar7 = extraout_r1_05;
      }
      *puVar14 = uVar8;
    }
    DAT_200083b4 = 0;
    DAT_200083b8 = 0;
    LAST_FILE_CRC = 0;
    DAT_200083bc = 0;
    goto LAB_00025914;
  case 0x17:
    goto switchD_0002594a_caseD_17;
  case 0x19:
  case 0x1a:
    goto LAB_000259a8;
  }
  (*plVar13)(pcVar4,puVar6,sVar10);
LAB_000259a8:
  do {
    uVar15 = sys_clock_tick_get();
    timeout_00.ticks._0_4_ = (int)(uVar15 >> 0x20);
    timeout_00.ticks._4_4_ = 0x28000;
    z_impl_k_sem_take(&gs_state->dashboard_position_sem,timeout_00);
    uVar16 = sys_clock_tick_get();
    lVar1 = (uVar16 & 0xffffffff) * 1000;
    uVar6 = (int)(uVar16 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
    lVar2 = (uVar15 & 0xffffffff) * 1000;
    uVar12 = (uint)lVar1 >> 0xf | uVar6 * 0x20000;
    uVar9 = (uint)lVar2 >> 0xf |
            ((int)timeout_00.ticks * 1000 + (int)((ulonglong)lVar2 >> 0x20)) * 0x20000;
  } while ((int)((uVar6 >> 0xf) - (uint)(uVar12 < uVar9)) < (int)(uint)(uVar12 - uVar9 < 5000));
  *(undefined4 *)&gs_state->field_0x1060 = 0;
  FUN_0007f556((int)gs_state);
  uVar7 = extraout_r1_02;
  if (DAT_20017d2f != '\0') {
    DAT_20017d2f = '\0';
    __save_sys_settings(gs_state);
    uVar7 = extraout_r1_03;
  }
  goto LAB_00025914;
switchD_0002594a_caseD_17:
  FUN_0007ff66((int)gs_state,0);
  change_work_mode(1);
  uVar7 = extraout_r1_06;
  goto LAB_00025914;
switchD_0002594a_caseD_4:
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): ignore.\n","storage_commit_thread");
    }
    else {
      ble_printk("%s(): ignore.\n");
    }
  }
  goto LAB_000259a8;
}


