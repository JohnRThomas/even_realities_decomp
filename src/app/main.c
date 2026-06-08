/*
 * Function: main
 * Entry:    00016f5c
 * Prototype: undefined __stdcall main(void)
 */


/* WARNING: Unable to use type for symbol uVar8 */
/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void main(void)

{
  ushort uVar1;
  DeviceRole DVar2;
  byte bVar3;
  bool bVar4;
  app_event_header *aeh;
  GlassesState *s;
  global_state_struct_0FF0 *buf;
  global_state_struct_0FF4 *pgVar5;
  global_state_struct_1068_glasses_state *puVar4;
  void *pvVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined2 *puVar9;
  global_state_struct_1028 *pgVar10;
  uint8_t *buf_00;
  undefined4 uVar11;
  int iVar12;
  char *pcVar13;
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
  undefined4 extraout_r1_11;
  undefined4 extraout_r1_12;
  undefined4 extraout_r1_13;
  undefined4 extraout_r2;
  gpio_flags_t extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  undefined4 extraout_r2_12;
  undefined4 extraout_r2_13;
  undefined4 uVar14;
  undefined4 extraout_r2_14;
  uint uVar15;
  k_sem *sem;
  k_timeout_t duration;
  k_timeout_t timeout;
  k_timeout_t duration_00;
  k_timeout_t timeout_00;
  undefined8 uVar16;
  undefined4 in_stack_ffffffcc;
  undefined4 uVar8;
  undefined4 extraout_r2_02;
  
  FUN_0004d528();
  aeh = app_event_manager_alloc(0x10);
  if (aeh != (app_event_header *)0x0) {
    aeh->type_id = (event_type *)&DAT_000f8b8c;
  }
  aeh[1].node.next = (sys_snode_t *)&PTR_s_main_000f8c04;
  *(undefined1 *)&aeh[1].type_id = 0;
  _event_submit(aeh);
  uVar11 = extraout_r1;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Synchronization using %s driver\n");
      uVar11 = extraout_r1_01;
    }
    else {
      ble_printk("%s(): Synchronization using %s driver\n","main","mbox",BLE_DEBUG);
      uVar11 = extraout_r1_00;
    }
  }
  duration.ticks._4_4_ = 0x667;
  duration.ticks._0_4_ = uVar11;
  k_timer_start((k_timer *)&DAT_200038a0,duration,(k_timeout_t)0x66700000000);
  serialization_init();
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): [Build Info: Ver:v%d.%d.%d Commit:%s] [Build Time:%s]\n","main",1,6,3,"fcebbab6"
             ,"2025-06-28 17:28:42");
      uVar11 = extraout_r2_01;
    }
    else {
      ble_printk("%s(): [Build Info: Ver:v%d.%d.%d Commit:%s] [Build Time:%s]\n","main",1,6);
      uVar11 = extraout_r2;
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [cpuapp] global context init\n\n");
      }
      else {
        ble_printk("%s(): [cpuapp] global context init\n\n","init_context",uVar11,BLE_DEBUG);
      }
    }
  }
  s = malloc(0x1248);
  memset(s,0,0x1248);
  *(undefined4 *)&s->field_0xfde = 0xffffffff;
  *(undefined2 *)&s->field_0xfe2 = 0xffff;
  *(undefined4 *)&s->field_0xfe4 = 0xffffffff;
  *(undefined2 *)&s->field_0xfe8 = 0xffff;
  *(undefined1 *)s = 1;
  GLOBAL_STATE._0_4_ = s;
  k_sem_init(&s->sem_0,1);
  k_sem_init((k_sem *)&s->sem_1,10);
  k_sem_init(&s->sem_2,1);
  k_sem_init(&s->sem_3,1);
  sem = &s->sem_4;
  k_sem_init(&s->sem_5,1);
  k_sem_init(sem,1);
  k_sem_init(&s->sem_6,1);
  k_sem_init(&s->sem_7,1);
  k_sem_init(&s->sem_8,1);
  uVar8 = GLOBAL_STATE._0_4_;
  *(undefined1 *)(GLOBAL_STATE._0_4_ + 1) = 0xff;
  *(undefined2 *)(uVar8 + 0x1070) = 0;
  change_work_mode(0);
  buf = malloc(0x75);
  s->glasses_state_struct_0FF0 = buf;
  if (buf != (global_state_struct_0FF0 *)0x0) {
    memset(buf,0,0x75);
  }
                    /* 1704067200 = 01-01-2024 */
  __set_date(1704067200);
  pgVar5 = malloc(7);
  s->glasses_state_struct_0FF4 = pgVar5;
  puVar4 = malloc(5);
  s->___glasses_state = puVar4;
  if (puVar4 != (global_state_struct_1068_glasses_state *)0x0) {
    puVar4->___glasses_state = 0;
    puVar4->field1_0x4 = 0;
  }
  pvVar6 = malloc(0x217);
  *(void **)&s->field_0x1000 = pvVar6;
  if (pvVar6 != (void *)0x0) {
    memset(pvVar6,0,0x217);
  }
  pvVar6 = malloc(0xf5);
  *(void **)&s->field_0x1004 = pvVar6;
  pvVar6 = malloc(0x1e8);
  *(void **)&s->field_0x1008 = pvVar6;
  pvVar6 = malloc(0x1e8);
  *(void **)&s->field_0x100c = pvVar6;
  pvVar6 = malloc(0x1e9);
  *(void **)&s->field_0x1010 = pvVar6;
  pvVar6 = malloc(0x210);
  *(void **)&s->field_0x1014 = pvVar6;
  if (pvVar6 != (void *)0x0) {
    memset(pvVar6,0,0x210);
  }
  pvVar6 = malloc(0x50f);
  *(void **)&s->field_0x1030 = pvVar6;
  if (pvVar6 != (void *)0x0) {
    memset(pvVar6,0,0x50f);
  }
  pvVar6 = malloc(0x152);
  *(void **)&s->field_0x1034 = pvVar6;
  if (pvVar6 != (void *)0x0) {
    memset(pvVar6,0,0x152);
  }
  pvVar6 = malloc(0x201);
  *(void **)&s->field_0x1038 = pvVar6;
  if (pvVar6 != (void *)0x0) {
    memset(pvVar6,0,0x201);
  }
  pvVar6 = malloc(0x201);
  *(void **)&s->field_0x103c = pvVar6;
  if (pvVar6 != (void *)0x0) {
    memset(pvVar6,0,0x201);
  }
  pvVar6 = malloc(0x16a);
  *(void **)&s->field_0xff8 = pvVar6;
  if (pvVar6 != (void *)0x0) {
    *(undefined1 *)((int)pvVar6 + 0x168) = 0;
    *(undefined4 *)((int)pvVar6 + 0x164) = 0;
  }
  pvVar6 = malloc(0xaf);
  *(void **)&s->field_0xffc = pvVar6;
  puVar7 = malloc(0xb);
  *(undefined4 **)&s->field_0x1018 = puVar7;
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0;
    puVar7[1] = 0;
    *(undefined4 *)((int)puVar7 + 7) = 0;
  }
  pvVar6 = malloc(0x21);
  *(void **)&s->field_0x101c = pvVar6;
  FUN_0004280c();
  puVar8 = malloc(1);
  *(undefined1 **)&s->field_0x1020 = puVar8;
  if (puVar8 != (undefined1 *)0x0) {
    *puVar8 = 0;
  }
  puVar9 = malloc(2);
  *(undefined2 **)&s->field_0x1024 = puVar9;
  if (puVar9 != (undefined2 *)0x0) {
    *puVar9 = 0;
  }
  pgVar10 = malloc(10);
  s->field_global_state_struct_1028 = pgVar10;
  if (pgVar10 != (global_state_struct_1028 *)0x0) {
    pgVar10->field0_0x0 = 0;
    pgVar10->field1_0x4 = 0;
    pgVar10->field2_0x8 = 0;
  }
  buf_00 = malloc(0x208);
  s->___multi_packet_data_buffer = buf_00;
  if (buf_00 != (uint8_t *)0x0) {
    memset(buf_00,0,0x208);
  }
  s->field2791_0x1080[1] = 0xff;
  s->field2791_0x1080[2] = 0xff;
  s->field2791_0x1080[3] = 0xff;
  s->field2791_0x1080[4] = 0xff;
  *(undefined4 *)(s->field2791_0x1080 + 4) = 0xffffffff;
  *(undefined2 *)((int)&s->field2792_0x1087 + 1) = 0;
  register_ipc_service_context(&s->ipc_service_context,s->field2791_0x1080 + 1,0x1081);
  s->field_0x6e4 = 1;
  s->field1588_0x6e8 = "cpuapp-hw-id";
  *(undefined4 *)&s->field_0x6ec = 0x1638d;
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x6e4);
  s->field_0x6f0 = 6;
  s->field1597_0x6f4 = "cpunet-esbm-cpu-sync";
  *(undefined4 *)&s->field_0x6f8 = 0x16c6d;
  s->field_0x6fc = 4;
  s->field1606_0x700 = "cpunet-esbs";
  *(undefined4 *)&s->field_0x704 = 0x158c5;
  s->field_0x708 = 5;
  s->field1615_0x70c = "cpunet-esbs-ctrl";
  *(undefined1 **)&s->field_0x710 = &LAB_0007f2b4_1;
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x6f0);
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x6fc);
  (*(code *)(s->ipc_service_context).ipc_service_recv_cb)(&s->field_0x708);
  *(undefined4 *)&s->field_0xb24 = 0;
  *(undefined4 *)&s->field_0xb28 = 0xa090804;
  *(undefined2 *)&s->field_0xb2c = 0x200b;
  uVar16 = spi_master_register_context(&s->spi_master_callbacks);
  DEVICE_ROLE = button_init((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_00);
  uVar11 = ext_flash_api_init((undefined4 *)&s->field_0x1044,(undefined4 *)&s->field_0x1048,
                              (undefined4 *)&s->field_0x104c);
  s->field_0x10a1 = (char)uVar11;
  s->field_0x1 = 0;
  sett_init((int *)&s->field_0x1050);
  FUN_0007f6c8(s);
  DVar2 = DEVICE_ROLE;
  iVar12 = LOG_LEVEL;
  if (DEVICE_ROLE == MASTER) {
    *(undefined1 *)s = 1;
    if (0 < iVar12) {
      pcVar13 = "%s(): Master!------\n";
LAB_00017390:
      if (BLE_DEBUG == 0) {
        printk(pcVar13);
      }
      else {
        ble_printk(pcVar13,"role_init",DVar2,BLE_DEBUG);
      }
    }
  }
  else if (DEVICE_ROLE == SLAVE) {
    *(undefined1 *)s = 2;
    if (0 < LOG_LEVEL) {
      pcVar13 = "%s(): Slave!------\n";
      goto LAB_00017390;
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): error --hw_id:0x%x\n");
    }
    else {
      ble_printk("%s(): error --hw_id:0x%x\n","role_init",DEVICE_ROLE,BLE_DEBUG);
    }
  }
  runtime_info_sync((undefined2 *)s);
  if (*(char *)s == '\x01') {
    *(undefined2 *)&s->field_0xfd0 = 0x601;
    s->field_0xfd2 = 3;
    s->field_0xe4 = s->field_0xe4 | 4;
  }
  else if (*(char *)s == '\x02') {
    s->field_0xfd3 = 1;
    *(undefined2 *)&s->field_0xfd4 = 0x306;
    s->field_0x6de = s->field_0x6de | 4;
  }
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1_02;
  z_impl_k_sem_take(&s->sem_0,timeout);
  uVar11 = extraout_r2_02;
  if (s->field_0x1 == '\x01') {
LAB_00017458:
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): enter\n");
      }
      else {
        ble_printk("%s(): enter\n","component_init",uVar11,BLE_DEBUG);
      }
    }
  }
  else {
    uVar16 = FUN_0001832c((undefined4 *)&s->field_0x77c);
    if (*(char *)s == '\x01') {
      burial_point_record_info_init((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),extraout_r2_03);
      duration_00.ticks._4_4_ = 0x1e0000;
      duration_00.ticks._0_4_ = extraout_r1_03;
      k_timer_start((k_timer *)&DAT_20003868,duration_00,(k_timeout_t)0x1e000000000000);
      power_for_imu_and_mic();
      *(undefined ***)&s->field_0xf04 = &PTR_s_lsm6dso_6b_0008b508;
      lsm6dso_init_chip((device *)&PTR_s_lsm6dso_6b_0008b508);
      register_imu_funsion_context
                ((imu_fusion_context *)&(s->jdb_panel_context).field850_0x37c,extraout_r1_04,
                 extraout_r2_04);
      register_opt3007_context(&s->opt3007_context);
    }
    else if (*(char *)s == '\x02') {
      power_for_imu_and_mic();
      *(undefined ***)&s->field_0xf04 = &PTR_s_lsm6dso_6b_0008b508;
      lsm6dso_init_chip((device *)&PTR_s_lsm6dso_6b_0008b508);
    }
    register_jdb_panel_context(&s->jdb_panel_context);
    nfc_init();
    uVar16 = init_dashboard_info();
    bVar3 = getDashboardStartUpModeInfofromFlash
                      ((int)uVar16,(uint)((ulonglong)uVar16 >> 0x20),extraout_r2_05);
    bVar3 = getAppLanguageInfofromFlash((uint)bVar3,extraout_r1_05,extraout_r2_06);
    iVar12 = FUN_00025bd0((uint)bVar3,extraout_r1_06,extraout_r2_07,in_stack_ffffffcc);
    FUN_00026618(iVar12,extraout_r1_07,extraout_r2_08);
    s->field_0x10d5 = 0;
    uVar1 = *(ushort *)&(s->jdb_panel_context).field_0x372;
    *(ushort *)&(s->jdb_panel_context).field_0x36c = uVar1;
    s->field_0x10a4 = 0;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): exit!\n");
        uVar11 = extraout_r2_10;
      }
      else {
        ble_printk("%s(): exit!\n","init_context",(uint)uVar1,BLE_DEBUG);
        uVar11 = extraout_r2_09;
      }
      goto LAB_00017458;
    }
  }
  get_settings_from_flash(s);
  iVar12 = (**(code **)&s->field_0x77c)(&s->field_0x77c);
  if ((iVar12 != 0) && (1 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): [ble_context init] fail: 0x%x\n\n");
    }
    else {
      ble_printk("%s(): [ble_context init] fail: 0x%x\n\n","component_init",iVar12,BLE_DEBUG);
    }
  }
  if (*(char *)s == '\x01') {
    iVar12 = (**(code **)&s->field_0xf74)(&(s->jdb_panel_context).field850_0x37c);
    if ((iVar12 != 0) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [imu_context init] fail: 0x%x\n\n");
      }
      else {
        ble_printk("%s(): [imu_context init] fail: 0x%x\n\n","component_init",iVar12,BLE_DEBUG);
      }
    }
    iVar12 = (*(code *)(s->opt3007_context).field0_0x0)(&s->opt3007_context);
    if ((iVar12 != 0) && (1 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): [opt3007 init] fail: 0x%x\n\n");
      }
      else {
        ble_printk("%s(): [opt3007 init] fail: 0x%x\n\n","component_init",iVar12,BLE_DEBUG);
      }
    }
  }
  bVar4 = z_device_is_ready((device *)&PTR_s_regulators_0008b460);
  if (bVar4) {
    printk("pmic regulator %s is ready to use.\n","regulators");
    bVar4 = z_device_is_ready((device *)&PTR_s_charger_0008b520);
    if (bVar4) {
      iVar12 = fuel_gauge_init((device *)&PTR_s_charger_0008b520);
      if (iVar12 < 0) {
        pcVar13 = "Could not initialise fuel gauge.\n";
      }
      else {
        iVar12 = npm1300_charger_init((device *)&PTR_s_charger_0008b520);
        if (-1 < iVar12) {
          printk("Initialise charger.\n");
          printk("PMIC device ok\n");
          __dump_pmic_state(extraout_r0,(uint3)extraout_r1_10,extraout_r2_11);
          iVar12 = __is_old_board();
          if (iVar12 != 0) {
            printk("Old board, need to restrain Vterm to 4.2V\n");
            __change_termination_voltage();
          }
          power_for_panel();
          iVar12 = (*(code *)(s->spi_master_callbacks).init_cb)(&s->spi_master_callbacks);
          if ((iVar12 != 0) && (1 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): [spi_master init] fail: 0x%x\n\n");
            }
            else {
              ble_printk("%s(): [spi_master init] fail: 0x%x\n\n","component_init",iVar12,BLE_DEBUG)
              ;
            }
          }
          iVar12 = (*(code *)(s->jdb_panel_context).init_cb)(&s->jdb_panel_context);
          if ((iVar12 != 0) && (1 < LOG_LEVEL)) {
            if (BLE_DEBUG == 0) {
              printk("%s(): [panel_controler init] fail: 0x%x\n\n");
            }
            else {
              ble_printk("%s(): [panel_controler init] fail: 0x%x\n\n","component_init",iVar12,
                         BLE_DEBUG);
            }
          }
          aw93203_init();
          app_list_init();
          uVar11 = extraout_r1_11;
          uVar14 = extraout_r2_12;
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): exit\n");
              uVar11 = extraout_r1_13;
              uVar14 = extraout_r2_14;
            }
            else {
              ble_printk("%s(): exit\n","component_init",extraout_r2_12,BLE_DEBUG);
              uVar11 = extraout_r1_12;
              uVar14 = extraout_r2_13;
            }
          }
          *(undefined4 *)&s->field_0x1090 = 0;
          aw9320x_diff_get((uint *)&s->field_0x1090,uVar11,uVar14);
          FUN_00033770(DAT_2007fc70);
          goto LAB_000174fc;
        }
        pcVar13 = "Could not initialise charger.\n";
      }
    }
    else {
      pcVar13 = "Charger device not ready.\n";
    }
  }
  else {
    pcVar13 = "pmic regulator not ready.\n";
  }
  printk(pcVar13);
LAB_000174fc:
  init_threads((char *)s);
  sleep(2000);
  __enable_charger();
  uVar11 = extraout_r1_08;
  do {
    timeout_00.ticks._4_4_ = 0xffffffff;
    timeout_00.ticks._0_4_ = uVar11;
    z_impl_k_sem_take(sem,timeout_00);
    if (DAT_2001095c == '\x01') {
      switch_to_dfu_mode(sem);
    }
    while( true ) {
      uVar15 = (uint)(byte)s->field_0x106d;
      if (uVar15 == 0) break;
      if ((int)(uVar15 << 0x1f) < 0) {
        FUN_0007f556((int)s);
        bVar3 = s->field_0x106d & 0xfe;
        goto LAB_00017714;
      }
      if ((int)(uVar15 << 0x1e) < 0) {
        s->field_0xfee = 0xb;
        bVar3 = s->field_0x106d & 0xfd;
        goto LAB_00017714;
      }
      if ((int)(uVar15 << 0x1d) < 0) {
        do_pdm_transfer((device *)(uVar15 << 0x1f),(dmic_cfg *)(uVar15 << 0x1e),uVar15 << 0x1d);
        bVar3 = s->field_0x106d & 0xfb;
        goto LAB_00017714;
      }
      if ((int)(uVar15 << 0x1c) < 0) {
        erase_dfu_flash();
        bVar3 = s->field_0x106d & 0xf7;
LAB_00017714:
        s->field_0x106d = bVar3;
      }
    }
    sleep(1);
    uVar11 = extraout_r1_09;
  } while( true );
}


