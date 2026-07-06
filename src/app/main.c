/*
 * Function: main
 * Entry:    00016f5c
 * Prototype: undefined __stdcall main(void)
 */


/* WARNING: Unable to use type for symbol uVar8 */

void main(void)

{
  byte bVar1;
  bool bVar2;
  app_event_header *aeh;
  GlassesState *s;
  dashboard_ts_context *buf;
  countdown_ts_context *pcVar3;
  global_state_struct_1068_glasses_state *puVar4;
  void *pvVar4;
  user_schedule_context *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  global_state_struct_1028 *pgVar9;
  uint8_t *buf_00;
  undefined4 uVar10;
  int iVar11;
  char *pcVar12;
  size_t extraout_r0;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  uint extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  gpio_flags_t extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  uint uVar13;
  k_sem *sem;
  k_timeout_t duration;
  k_timeout_t timeout;
  k_timeout_t duration_00;
  k_timeout_t timeout_00;
  undefined8 uVar14;
  undefined4 in_stack_ffffffcc;
  GlassesState *uVar8;
  
  FUN_0004d528();
  aeh = app_event_manager_alloc(0x10);
  if (aeh != (app_event_header *)0x0) {
    aeh->type_id = (event_type *)&DAT_000f8b8c;
  }
  aeh[1].node.next = (sys_snode_t *)&PTR_s_main_000f8c04;
  *(undefined1 *)&aeh[1].type_id = 0;
  _event_submit(aeh);
  uVar10 = extraout_r1;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Synchronization using %s driver\n","main","mbox");
      uVar10 = extraout_r1_01;
    }
    else {
      ble_printk("%s(): Synchronization using %s driver\n");
      uVar10 = extraout_r1_00;
    }
  }
  duration.ticks._4_4_ = 0x667;
  duration.ticks._0_4_ = uVar10;
  k_timer_start((k_timer *)&DAT_200038a0,duration,(k_timeout_t)0x66700000000);
  serialization_init();
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): [Build Info: Ver:v%d.%d.%d Commit:%s] [Build Time:%s]\n","main",1,6,3,"fcebbab6"
             ,"2025-06-28 17:28:42");
    }
    else {
      ble_printk("%s(): [Build Info: Ver:v%d.%d.%d Commit:%s] [Build Time:%s]\n","main");
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [cpuapp] global context init\n\n","init_context");
      }
      else {
        ble_printk("%s(): [cpuapp] global context init\n\n");
      }
    }
  }
  s = malloc(0x1248);
  memset(s,0,0x1248);
  *(undefined4 *)&s->field_0xfde = 0xffffffff;
  *(undefined2 *)&s->field_0xfe2 = 0xffff;
  *(undefined4 *)&s->field_0xfe4 = 0xffffffff;
  *(undefined2 *)&s->field_0xfe8 = 0xffff;
  s->is_master = true;
  GLOBAL_STATE = s;
  k_sem_init(&s->sem_0,1);
  k_sem_init((k_sem *)&s->sem_1,10);
  k_sem_init(&s->sem_2,1);
  k_sem_init(&s->sem_3,1);
  sem = &s->sem_4;
  k_sem_init(&s->sem_5,1);
  k_sem_init(sem,1);
  k_sem_init(&s->dashboard_position_sem,1);
  k_sem_init(&s->sem_7,1);
  k_sem_init(&s->sem_8,1);
  uVar8 = GLOBAL_STATE;
  GLOBAL_STATE->field_0x1 = 0xff;
  *(undefined2 *)&uVar8->field_0x1070 = 0;
  change_work_mode(0);
  buf = malloc(0x75);
  s->dashboard_ts = buf;
  if (buf != (dashboard_ts_context *)0x0) {
    memset(buf,0,0x75);
  }
                    /* 1704067200 = 01-01-2024 */
  __set_date(1704067200);
  pcVar3 = malloc(7);
  s->countdown_ts = pcVar3;
  puVar4 = malloc(5);
  s->___glasses_state = puVar4;
  if (puVar4 != (global_state_struct_1068_glasses_state *)0x0) {
    puVar4->___glasses_state = 0;
    puVar4->field1_0x4 = 0;
  }
  pvVar4 = malloc(0x217);
  *(void **)&s->field_0x1000 = pvVar4;
  if (pvVar4 != (void *)0x0) {
    memset(pvVar4,0,0x217);
  }
  pvVar4 = malloc(0xf5);
  *(void **)&s->field_0x1004 = pvVar4;
  pvVar4 = malloc(0x1e8);
  *(void **)&s->field_0x1008 = pvVar4;
  pvVar4 = malloc(0x1e8);
  *(void **)&s->field_0x100c = pvVar4;
  pvVar4 = malloc(0x1e9);
  *(void **)&s->field_0x1010 = pvVar4;
  pvVar4 = malloc(0x210);
  *(void **)&s->field_0x1014 = pvVar4;
  if (pvVar4 != (void *)0x0) {
    memset(pvVar4,0,0x210);
  }
  pvVar4 = malloc(0x50f);
  *(void **)&s->field_0x1030 = pvVar4;
  if (pvVar4 != (void *)0x0) {
    memset(pvVar4,0,0x50f);
  }
  pvVar4 = malloc(0x152);
  *(void **)&s->field_0x1034 = pvVar4;
  if (pvVar4 != (void *)0x0) {
    memset(pvVar4,0,0x152);
  }
  pvVar4 = malloc(0x201);
  *(void **)&s->field_0x1038 = pvVar4;
  if (pvVar4 != (void *)0x0) {
    memset(pvVar4,0,0x201);
  }
  pvVar4 = malloc(0x201);
  *(void **)&s->field_0x103c = pvVar4;
  if (pvVar4 != (void *)0x0) {
    memset(pvVar4,0,0x201);
  }
  puVar5 = malloc(0x16a);
  s->user_sched_info = puVar5;
  if (puVar5 != (user_schedule_context *)0x0) {
    puVar5->field_0x168 = 0;
    *(undefined4 *)&puVar5->field_0x164 = 0;
  }
  pvVar4 = malloc(0xaf);
  *(void **)&s->field_0xffc = pvVar4;
  puVar6 = malloc(0xb);
  *(undefined4 **)&s->field_0x1018 = puVar6;
  if (puVar6 != (undefined4 *)0x0) {
    *puVar6 = 0;
    puVar6[1] = 0;
    *(undefined4 *)((int)puVar6 + 7) = 0;
  }
  pvVar4 = malloc(0x21);
  *(void **)&s->field_0x101c = pvVar4;
  FUN_0004280c();
  puVar7 = malloc(1);
  *(undefined1 **)&s->field_0x1020 = puVar7;
  if (puVar7 != (undefined1 *)0x0) {
    *puVar7 = 0;
  }
  puVar8 = malloc(2);
  *(undefined2 **)&s->field_0x1024 = puVar8;
  if (puVar8 != (undefined2 *)0x0) {
    *puVar8 = 0;
  }
  pgVar9 = malloc(10);
  s->field_global_state_struct_1028 = pgVar9;
  if (pgVar9 != (global_state_struct_1028 *)0x0) {
    pgVar9->field0_0x0 = 0;
    pgVar9->field1_0x4 = 0;
    pgVar9->field2_0x8 = 0;
  }
  buf_00 = malloc(0x208);
  s->___multi_packet_data_buffer = buf_00;
  if (buf_00 != (uint8_t *)0x0) {
    memset(buf_00,0,0x208);
  }
  s->field1211_0x1080[1] = 0xff;
  s->field1211_0x1080[2] = 0xff;
  s->field1211_0x1080[3] = 0xff;
  s->field1211_0x1080[4] = 0xff;
  *(undefined4 *)(s->field1211_0x1080 + 4) = 0xffffffff;
  *(undefined2 *)((int)&s->field1212_0x1087 + 1) = 0;
  register_ipc_service_context(&s->ipc_service_context,s->field1211_0x1080 + 1,0x1081);
  s->field_0x6e4 = 1;
  s->field53_0x6e8 = "cpuapp-hw-id";
  *(undefined4 *)&s->local_ipc_recv_cb = 0x1638d;
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x6e4);
  s->field_0x6f0 = 6;
  s->field62_0x6f4 = "cpunet-esbm-cpu-sync";
  *(undefined4 *)&s->esbm_recv_cb = 0x16c6d;
  s->field_0x6fc = 4;
  s->field71_0x700 = "cpunet-esbs";
  *(undefined4 *)&s->esbs_recv_cb = 0x158c5;
  s->field_0x708 = 5;
  s->field80_0x70c = "cpunet-esbs-ctrl";
  *(undefined4 *)&s->field_0x710 = 0x7f2b5;
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x6f0);
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x6fc);
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x708);
  (s->spi_master_callbacks).is_initialized = 0;
  (s->spi_master_callbacks).bus_id = 0xa090804;
  *(undefined2 *)&s->field_0xb2c = 0x200b;
  uVar14 = spi_master_register_context(&s->spi_master_callbacks);
  DEVICE_ROLE = button_init((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),extraout_r2);
  uVar10 = ext_flash_api_init((undefined4 *)&s->field_0x1044,(undefined4 *)&s->field_0x1048,
                              (undefined4 *)&s->field_0x104c,&DEVICE_ROLE);
  s->field_0x10a1 = (char)uVar10;
  s->field_0x1 = 0;
  sett_init(&s->settings_ctx);
  FUN_0007f6c8(s);
  iVar11 = LOG_LEVEL;
  if (DEVICE_ROLE == MASTER) {
    s->is_master = true;
    if (0 < iVar11) {
      pcVar12 = "%s(): Master!------\n";
LAB_00017390:
      if (BLE_DEBUG == 0) {
        printk(pcVar12,"role_init");
      }
      else {
        ble_printk(pcVar12);
      }
    }
  }
  else if (DEVICE_ROLE == SLAVE) {
    s->is_master = true;
    if (0 < LOG_LEVEL) {
      pcVar12 = "%s(): Slave!------\n";
      goto LAB_00017390;
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): error --hw_id:0x%x\n","role_init");
    }
    else {
      ble_printk("%s(): error --hw_id:0x%x\n");
    }
  }
  runtime_info_sync((undefined2 *)s);
  if (s->is_master == true) {
    *(undefined2 *)&s->field_0xfd0 = 0x601;
    s->field_0xfd2 = 3;
    s->field20_0xc8[0x1c] = s->field20_0xc8[0x1c] | 4;
  }
  else if (s->is_master == true) {
    s->field_0xfd3 = 1;
    *(undefined2 *)&s->field_0xfd4 = 0x306;
    s->field_0x6de = s->field_0x6de | 4;
  }
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1_02;
  z_impl_k_sem_take(&s->sem_0,timeout);
  if (s->field_0x1 == '\x01') {
LAB_00017458:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): enter\n","component_init");
      }
      else {
        ble_printk("%s(): enter\n");
      }
    }
  }
  else {
    uVar14 = FUN_0001832c((undefined4 *)&s->ble_context);
    if (s->is_master == true) {
      burial_point_record_info_init((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),extraout_r2_00,1);
      duration_00.ticks._4_4_ = 0x1e0000;
      duration_00.ticks._0_4_ = extraout_r1_03;
      k_timer_start((k_timer *)&DAT_20003868,duration_00,(k_timeout_t)0x1e000000000000);
      power_for_imu_and_mic();
      *(undefined ***)&(s->imu_fusion_context).field_0x1c = &PTR_s_lsm6dso_6b_0008b508;
      lsm6dso_init_chip((device *)&PTR_s_lsm6dso_6b_0008b508);
      register_imu_funsion_context(&s->imu_fusion_context,extraout_r1_04,extraout_r2_01);
      register_opt3007_context(&s->opt3007_context);
    }
    else if (s->is_master == true) {
      power_for_imu_and_mic();
      *(undefined ***)&(s->imu_fusion_context).field_0x1c = &PTR_s_lsm6dso_6b_0008b508;
      lsm6dso_init_chip((device *)&PTR_s_lsm6dso_6b_0008b508);
    }
    register_jdb_panel_context(&s->jdb_panel_context);
    nfc_init();
    uVar14 = init_dashboard_info();
    bVar1 = getDashboardStartUpModeInfofromFlash
                      ((int)uVar14,(uint)((ulonglong)uVar14 >> 0x20),extraout_r2_02);
    bVar1 = getAppLanguageInfofromFlash((uint)bVar1,extraout_r1_05,extraout_r2_03);
    iVar11 = FUN_00025bd0((uint)bVar1,extraout_r1_06,extraout_r2_04,in_stack_ffffffcc);
    FUN_00026618(iVar11,extraout_r1_07,extraout_r2_05);
    s->field_0x10d5 = 0;
    *(undefined2 *)&(s->jdb_panel_context).field831_0x36c =
         *(undefined2 *)&(s->jdb_panel_context).field_0x372;
    s->field_0x10a4 = 0;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): exit!\n","init_context");
      }
      else {
        ble_printk("%s(): exit!\n");
      }
      goto LAB_00017458;
    }
  }
  get_settings_from_flash(s);
  iVar11 = (**(code **)&s->ble_context)(&s->ble_context);
  if ((iVar11 != 0) && (1 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): [ble_context init] fail: 0x%x\n\n","component_init",iVar11);
    }
    else {
      ble_printk("%s(): [ble_context init] fail: 0x%x\n\n");
    }
  }
  if (s->is_master == true) {
    iVar11 = (*(code *)(s->imu_fusion_context).init_cb)(&s->imu_fusion_context);
    if ((iVar11 != 0) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [imu_context init] fail: 0x%x\n\n","component_init",iVar11);
      }
      else {
        ble_printk("%s(): [imu_context init] fail: 0x%x\n\n");
      }
    }
    iVar11 = (*(code *)(s->opt3007_context).init_cb)(&s->opt3007_context);
    if ((iVar11 != 0) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [opt3007 init] fail: 0x%x\n\n","component_init",iVar11);
      }
      else {
        ble_printk("%s(): [opt3007 init] fail: 0x%x\n\n");
      }
    }
  }
  bVar2 = z_device_is_ready((device *)&PTR_s_regulators_0008b460);
  if (bVar2) {
    printk("pmic regulator %s is ready to use.\n","regulators");
    bVar2 = z_device_is_ready((device *)&PTR_s_charger_0008b520);
    if (bVar2) {
      iVar11 = fuel_gauge_init((device *)&PTR_s_charger_0008b520);
      if (iVar11 < 0) {
        pcVar12 = "Could not initialise fuel gauge.\n";
      }
      else {
        iVar11 = npm1300_charger_init((device *)&PTR_s_charger_0008b520);
        if (-1 < iVar11) {
          printk("Initialise charger.\n");
          printk("PMIC device ok\n");
          __dump_pmic_state(extraout_r0,(uint3)extraout_r1_10,extraout_r2_06);
          iVar11 = __is_old_board();
          if (iVar11 != 0) {
            printk("Old board, need to restrain Vterm to 4.2V\n");
            __change_termination_voltage();
          }
          power_for_panel();
          iVar11 = (*(code *)(s->spi_master_callbacks).init_cb)(&s->spi_master_callbacks);
          if ((iVar11 != 0) && (1 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): [spi_master init] fail: 0x%x\n\n","component_init",iVar11);
            }
            else {
              ble_printk("%s(): [spi_master init] fail: 0x%x\n\n");
            }
          }
          iVar11 = (*(code *)(s->jdb_panel_context).init_cb)(&s->jdb_panel_context);
          if ((iVar11 != 0) && (1 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): [panel_controler init] fail: 0x%x\n\n","component_init",iVar11);
            }
            else {
              ble_printk("%s(): [panel_controler init] fail: 0x%x\n\n");
            }
          }
          aw93203_init();
          app_list_init();
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): exit\n","component_init");
            }
            else {
              ble_printk("%s(): exit\n");
            }
          }
          *(undefined4 *)&s->field_0x1090 = 0;
          aw9320x_diff_get((uint32_t *)&s->field_0x1090);
          FUN_00033770(DAT_2007fc70);
          goto LAB_000174fc;
        }
        pcVar12 = "Could not initialise charger.\n";
      }
    }
    else {
      pcVar12 = "Charger device not ready.\n";
    }
  }
  else {
    pcVar12 = "pmic regulator not ready.\n";
  }
  printk(pcVar12);
LAB_000174fc:
  init_threads(s);
  sleep(2000);
  __enable_charger();
  uVar10 = extraout_r1_08;
  do {
    timeout_00.ticks._4_4_ = 0xffffffff;
    timeout_00.ticks._0_4_ = uVar10;
    z_impl_k_sem_take(sem,timeout_00);
    if (DAT_2001095c == '\x01') {
      switch_to_dfu_mode(sem);
    }
    while( true ) {
      uVar13 = (uint)(byte)s->field_0x106d;
      if (uVar13 == 0) break;
      if ((int)(uVar13 << 0x1f) < 0) {
        FUN_0007f556((int)s);
        bVar1 = s->field_0x106d & 0xfe;
        goto LAB_00017714;
      }
      if ((int)(uVar13 << 0x1e) < 0) {
        s->display_mode = 0xb;
        bVar1 = s->field_0x106d & 0xfd;
        goto LAB_00017714;
      }
      if ((int)(uVar13 << 0x1d) < 0) {
        do_pdm_transfer((device *)(uVar13 << 0x1f),(dmic_cfg *)(uVar13 << 0x1e),uVar13 << 0x1d);
        bVar1 = s->field_0x106d & 0xfb;
        goto LAB_00017714;
      }
      if ((int)(uVar13 << 0x1c) < 0) {
        erase_dfu_flash();
        bVar1 = s->field_0x106d & 0xf7;
LAB_00017714:
        s->field_0x106d = bVar1;
      }
    }
    sleep(1);
    uVar10 = extraout_r1_09;
  } while( true );
}


