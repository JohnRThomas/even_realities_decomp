/*
 * Function: storage_commit_thread
 * Entry:    000258fc
 * Prototype: undefined __stdcall storage_commit_thread(GlassesState * param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void storage_commit_thread(GlassesState *param_1)

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
  global_state_struct_0FF0 *pgVar6;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  bool bVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 extraout_r2;
  int iVar12;
  uint uVar13;
  code *pcVar14;
  undefined1 *puVar15;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  ulonglong uVar16;
  ulonglong uVar17;
  
  __file_init();
  FUN_00025694();
  uVar11 = extraout_r1;
LAB_00025914:
  do {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = uVar11;
    z_impl_k_sem_take(&param_1->sem_6,timeout);
    bVar7 = false;
    uVar11 = extraout_r1_00;
    while (DAT_200083a4 != 0) {
      try_to_save_file((int)param_1);
      bVar7 = true;
      uVar11 = extraout_r1_01;
    }
    iVar12 = *(int *)&param_1->field_0x1060;
  } while ((iVar12 == 0x15) || (bVar7));
  uVar9 = 0;
  if (0x1a < iVar12) {
    if (iVar12 != 0x3e) goto switchD_0002594a_caseD_4;
    pGVar4 = __get_dashboard_state();
    update_burial_point_to_flash((int)pGVar4);
    goto LAB_000259a8;
  }
  switch(iVar12) {
  case 1:
    uVar11 = 1;
    pcVar14 = *(code **)&param_1->field_0x1054;
    pcVar3 = "brightness_level";
    pgVar6 = (global_state_struct_0FF0 *)&(param_1->jdb_panel_context).field834_0x369;
    break;
  case 2:
    uVar11 = 1;
    pcVar14 = *(code **)&param_1->field_0x1054;
    pcVar3 = "3dof_enable";
    pgVar6 = (global_state_struct_0FF0 *)&param_1->field_0xf64;
    break;
  case 3:
    uVar11 = 1;
    pcVar14 = *(code **)&param_1->field_0x1054;
    pcVar3 = "display_mode";
    pgVar6 = (global_state_struct_0FF0 *)&param_1->field_0xfee;
    break;
  default:
    goto switchD_0002594a_caseD_4;
  case 6:
    uVar11 = 0x75;
    pcVar14 = *(code **)&param_1->field_0x1054;
    pgVar6 = param_1->glasses_state_struct_0FF0;
    pcVar3 = "dashboard_ts";
    break;
  case 7:
    uVar11 = 7;
    pcVar14 = *(code **)&param_1->field_0x1054;
    pgVar6 = (global_state_struct_0FF0 *)param_1->glasses_state_struct_0FF4;
    pcVar3 = "countdown_ts";
    break;
  case 8:
    uVar11 = 0x16a;
    pcVar14 = *(code **)&param_1->field_0x1054;
    pgVar6 = *(global_state_struct_0FF0 **)&param_1->field_0xff8;
    pcVar3 = "user_sched_info";
    break;
  case 0xb:
    uVar11 = 1;
    pcVar14 = *(code **)&param_1->field_0x1054;
    pcVar3 = "wakeup_angle";
    pgVar6 = (global_state_struct_0FF0 *)&param_1->field_0xef8;
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
        uVar11 = extraout_r1_04;
      }
      else {
        pGVar4 = __get_dashboard_state();
        uVar8 = 0xc;
        puVar15 = *(undefined1 **)&pGVar4->field_0x1010;
        uVar11 = extraout_r1_05;
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
  (*pcVar14)(pcVar3,pgVar6,uVar11);
LAB_000259a8:
  do {
    uVar16 = sys_clock_tick_get();
    timeout_00.ticks._0_4_ = (int)(uVar16 >> 0x20);
    timeout_00.ticks._4_4_ = 0x28000;
    z_impl_k_sem_take(&param_1->sem_6,timeout_00);
    uVar17 = sys_clock_tick_get();
    lVar1 = (uVar17 & 0xffffffff) * 1000;
    uVar5 = (int)(uVar17 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
    lVar2 = (uVar16 & 0xffffffff) * 1000;
    uVar13 = (uint)lVar1 >> 0xf | uVar5 * 0x20000;
    uVar10 = (uint)lVar2 >> 0xf |
             ((int)timeout_00.ticks * 1000 + (int)((ulonglong)lVar2 >> 0x20)) * 0x20000;
  } while ((int)((uVar5 >> 0xf) - (uint)(uVar13 < uVar10)) < (int)(uint)(uVar13 - uVar10 < 5000));
  *(undefined4 *)&param_1->field_0x1060 = 0;
  FUN_0007f556((int)param_1);
  uVar11 = extraout_r1_02;
  if (DAT_20017d2f != '\0') {
    DAT_20017d2f = '\0';
    FUN_00024abc(param_1);
    uVar11 = extraout_r1_03;
  }
  goto LAB_00025914;
switchD_0002594a_caseD_17:
  FUN_0007ff66((int)param_1,0);
  change_work_mode(1);
  uVar11 = extraout_r1_06;
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


