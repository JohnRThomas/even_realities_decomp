/*
 * Function: storage_commit_thread
 * Entry:    000258fc
 * Prototype: undefined __stdcall storage_commit_thread(GlassesState * gs_state)
 */


void storage_commit_thread(GlassesState *gs_state)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar5;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  void *puVar6;
  undefined4 extraout_r1_04;
  undefined4 uVar6;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  bool bVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  uint uVar10;
  size_t sVar11;
  undefined4 extraout_r2;
  int iVar12;
  uint uVar13;
  local_store_write_cb *plVar14;
  undefined1 *puVar15;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  ulonglong uVar16;
  ulonglong uVar17;
  
  __file_init();
  FUN_00025694();
  uVar6 = extraout_r1;
LAB_00025914:
  do {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = uVar6;
    z_impl_k_sem_take(&gs_state->sem_6,timeout);
    bVar7 = false;
    uVar6 = extraout_r1_00;
    while (DAT_200083a4 != 0) {
      try_to_save_file(gs_state);
      bVar7 = true;
      uVar6 = extraout_r1_01;
    }
    iVar12 = *(int *)&gs_state->field_0x1060;
  } while ((iVar12 == 0x15) || (bVar7));
  uVar9 = 0;
  if (0x1a < iVar12) {
    if (iVar12 != 0x3e) goto switchD_0002594a_caseD_4;
    pGVar4 = __get_dashboard_state();
    update_burial_point_to_flash(pGVar4);
    goto LAB_000259a8;
  }
  switch(iVar12) {
  case 1:
    sVar11 = 1;
    plVar14 = (gs_state->settings_ctx).write_cb;
    pcVar3 = "brightness_level";
    puVar6 = &(gs_state->jdb_panel_context).panel_brightness_level;
    break;
  case 2:
    sVar11 = 1;
    plVar14 = (gs_state->settings_ctx).write_cb;
    pcVar3 = "3dof_enable";
    puVar6 = &(gs_state->imu_fusion_context)._dof_enable;
    break;
  case 3:
    sVar11 = 1;
    plVar14 = (gs_state->settings_ctx).write_cb;
    pcVar3 = "display_mode";
    puVar6 = &gs_state->display_mode;
    break;
  default:
    goto switchD_0002594a_caseD_4;
  case 6:
    sVar11 = 0x75;
    plVar14 = (gs_state->settings_ctx).write_cb;
    puVar6 = gs_state->dashboard_ts;
    pcVar3 = "dashboard_ts";
    break;
  case 7:
    sVar11 = 7;
    plVar14 = (gs_state->settings_ctx).write_cb;
    puVar6 = gs_state->countdown_ts;
    pcVar3 = "countdown_ts";
    break;
  case 8:
    sVar11 = 0x16a;
    plVar14 = (gs_state->settings_ctx).write_cb;
    puVar6 = gs_state->user_sched_info;
    pcVar3 = "user_sched_info";
    break;
  case 0xb:
    sVar11 = 1;
    plVar14 = (gs_state->settings_ctx).write_cb;
    pcVar3 = "wakeup_angle";
    puVar6 = &(gs_state->imu_fusion_context).wakeup_angle;
    break;
  case 0x11:
    z_impl_k_sleep((k_timeout_t)0x50000);
    change_work_mode(7);
    uVar9 = extraout_r2;
    goto switchD_0002594a_caseD_4;
  case 0x16:
    if (DAT_200083b4 == 0x1c0000) {
      get_demo_image_source_from_flash();
      pGVar4 = __get_dashboard_state();
      if (*(char *)pGVar4 == '\x01') {
        pGVar4 = __get_dashboard_state();
        uVar8 = 0xd;
        puVar15 = *(undefined1 **)&pGVar4->field_0x1010;
        uVar6 = extraout_r1_04;
      }
      else {
        pGVar4 = __get_dashboard_state();
        uVar8 = 0xc;
        puVar15 = *(undefined1 **)&pGVar4->field_0x1010;
        uVar6 = extraout_r1_05;
      }
      *puVar15 = uVar8;
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
  (*plVar14)(pcVar3,puVar6,sVar11);
LAB_000259a8:
  do {
    uVar16 = sys_clock_tick_get();
    timeout_00.ticks._0_4_ = (int)(uVar16 >> 0x20);
    timeout_00.ticks._4_4_ = 0x28000;
    z_impl_k_sem_take(&gs_state->sem_6,timeout_00);
    uVar17 = sys_clock_tick_get();
    lVar1 = (uVar17 & 0xffffffff) * 1000;
    uVar5 = (int)(uVar17 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
    lVar2 = (uVar16 & 0xffffffff) * 1000;
    uVar13 = (uint)lVar1 >> 0xf | uVar5 * 0x20000;
    uVar10 = (uint)lVar2 >> 0xf |
             ((int)timeout_00.ticks * 1000 + (int)((ulonglong)lVar2 >> 0x20)) * 0x20000;
  } while ((int)((uVar5 >> 0xf) - (uint)(uVar13 < uVar10)) < (int)(uint)(uVar13 - uVar10 < 5000));
  *(undefined4 *)&gs_state->field_0x1060 = 0;
  FUN_0007f556((int)gs_state);
  uVar6 = extraout_r1_02;
  if (DAT_20017d2f != '\0') {
    DAT_20017d2f = '\0';
    __save_sys_settings(gs_state);
    uVar6 = extraout_r1_03;
  }
  goto LAB_00025914;
switchD_0002594a_caseD_17:
  FUN_0007ff66((int)gs_state,0);
  change_work_mode(1);
  uVar6 = extraout_r1_06;
  goto LAB_00025914;
switchD_0002594a_caseD_4:
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): ignore.\n");
    }
    else {
      ble_printk("%s(): ignore.\n","storage_commit_thread",uVar9,BLE_DEBUG);
    }
  }
  goto LAB_000259a8;
}


