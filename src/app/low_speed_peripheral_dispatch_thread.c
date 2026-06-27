/*
 * Function: low_speed_peripheral_dispatch_thread
 * Entry:    0002cb04
 * Prototype: undefined __stdcall low_speed_peripheral_dispatch_thread(char * param_1)
 */


void low_speed_peripheral_dispatch_thread(char *param_1)

{
  bool bVar1;
  bt_conn *conn;
  uint uVar2;
  uint uVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar6;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  undefined8 uVar12;
  longlong lVar13;
  
  change_work_mode(3);
  update_persist_task_status_to_idle((int)param_1,extraout_r1);
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): #enter\n");
    }
    else {
      ble_printk("%s(): #enter\n","low_speed_peripheral_dispatch_thread",extraout_r2,BLE_DEBUG);
    }
  }
  param_1[0xfc8] = '\0';
  param_1[0xfc9] = -0x80;
  param_1[0xfc4] = '\0';
  param_1[0xfc5] = '\0';
  if ((*param_1 == '\x01') && (param_1[0xfee] == '\f')) {
    sync_to_slave(param_1,4,(undefined4 *)0x0,0);
  }
  uVar9 = 0;
  cVar11 = '\0';
  do {
    uVar9 = uVar9 + 1 & 0xff;
    if (uVar9 % 5 == 0) {
      conn = (bt_conn *)FUN_00019cec();
      if ((((conn == (bt_conn *)0x0) || (param_1[0xae2] == '\0')) || (param_1[0xae3] == '\0')) ||
         (*(int *)(param_1 + 0x9b4) == 0)) {
        cVar11 = '\0';
      }
      else {
        cVar11 = cVar11 + '\x01';
        if ('\x04' < cVar11) {
          bt_conn_set_security(conn,2);
          cVar11 = -5;
        }
      }
      bVar7 = param_1[0xfc5];
      if ((byte)param_1[0xfc4] <= (byte)param_1[0xfc5]) {
        bVar7 = param_1[0xfc4];
      }
      param_1[0xde] = bVar7;
      fuel_gauge_update((device *)&PTR_s_charger_0008b520);
      bVar1 = is_in_box();
      uVar9 = (uint)bVar1;
      bVar1 = is_box_lid_closed();
      uVar2 = (uint)bVar1;
      if (((conn == (bt_conn *)0x0) || (param_1[0xae3] != '\0')) || (*(int *)(param_1 + 0x9b4) == 0)
         ) {
        check_bind_status((int)param_1,uVar9,uVar2);
        if (*param_1 != '\x01') {
          if (DAT_20019a5f == '\0') {
            param_1[0x6de] = param_1[0x6de] & 0xfe;
          }
          else {
            DAT_20019a5f = DAT_20019a5f + -1;
          }
          uVar10 = 0;
          goto LAB_0002cdc6;
        }
        runtime_info_sync((undefined2 *)param_1);
        uVar8 = 0;
LAB_0002cd92:
        uVar10 = uVar8;
        if (DAT_20019a5f == '\0') {
          param_1[0xe4] = param_1[0xe4] & 0xfc;
        }
        else {
          DAT_20019a5f = DAT_20019a5f + -1;
        }
LAB_0002cc0a:
        uVar3 = sync_to_slave(param_1,0xc,(undefined4 *)0x0,0);
        uVar6 = extraout_r2_00;
        uVar12 = CONCAT44(extraout_r1_00,uVar3);
        if (((int)uVar3 < 500) &&
           (uVar12 = CONCAT44((uint)(byte)param_1[0xe4] << 0x1d,uVar3),
           (int)((uint)(byte)param_1[0xe4] << 0x1d) < 0)) {
          uVar12 = FUN_00035270();
          uVar6 = extraout_r2_01;
LAB_0002cc28:
          param_1[0xe4] = param_1[0xe4] & 0xfb;
        }
      }
      else {
        check_bind_status((int)param_1,uVar9,uVar2);
        if (*param_1 == '\x01') {
          runtime_info_sync((undefined2 *)param_1);
          uVar8 = 1;
          if ((param_1[0x6de] & 1U) == 0) goto LAB_0002cd92;
          param_1[0xe4] = param_1[0xe4] | 3;
          DAT_20019a5f = '\x0f';
          uVar10 = (byte)param_1[0x6de] & 1;
          goto LAB_0002cc0a;
        }
        uVar10 = 1;
        DAT_20019a5f = '\x0f';
        param_1[0x6de] = param_1[0x6de] | 1;
LAB_0002cdc6:
        if ((int)((uint)(byte)(param_1[0xe4] ^ param_1[0x6de]) << 0x1f) < 0) {
          param_1[0x6df] = param_1[0x6df] + '\x01';
        }
        uVar3 = FUN_000294d0((int)param_1,1,(void *)0x0,0);
        uVar6 = extraout_r2_03;
        uVar8 = uVar10;
        uVar12 = CONCAT44(extraout_r1_02,uVar3);
        if ((uVar3 < 500) &&
           (uVar12 = CONCAT44(extraout_r1_02,uVar3), (int)((uint)(byte)param_1[0x6de] << 0x1d) < 0))
        {
          uVar12 = FUN_00035270();
          param_1[0x6de] = param_1[0x6de] & 0xfb;
          uVar6 = extraout_r2_04;
          goto LAB_0002cc28;
        }
      }
      FUN_00027744((size_t)uVar12,(uint)((ulonglong)uVar12 >> 0x20),uVar6);
      while (param_1[1] == '\x01') {
        __wdt_disable();
        if (*param_1 == '\x01') {
          FUN_000806e4((int)param_1,*(int **)(param_1 + 0xff0));
        }
        lVar13 = FUN_0007fea6();
        iVar5 = (int)((ulonglong)(lVar13 - *(longlong *)(param_1 + 0x1078)) >> 0x20);
        bVar1 = &DAT_000927bf < (undefined *)(lVar13 - *(longlong *)(param_1 + 0x1078));
        if ((int)(-(uint)bVar1 - iVar5) < 0 != (SBORROW4(0,iVar5) != SBORROW4(-iVar5,(uint)bVar1)))
        {
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): reboot because dfu exceed time\n");
            }
            else {
              ble_printk("%s(): reboot because dfu exceed time\n",
                         "low_speed_peripheral_dispatch_thread",*(undefined4 *)(param_1 + 0x107c),
                         BLE_DEBUG);
            }
          }
          k_msleep(500);
                    /* WARNING: Subroutine does not return */
          sys_reboot(1);
        }
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ********************DFU MODE********************\n");
          }
          else {
            ble_printk("%s(): ********************DFU MODE********************\n",
                       "low_speed_peripheral_dispatch_thread",*(undefined4 *)(param_1 + 0x107c),
                       BLE_DEBUG);
          }
        }
        check_work_mode(uVar9,uVar2,uVar10);
        z_impl_k_sleep((k_timeout_t)0x8000);
      }
      if (DAT_2000304f == '\0') {
        __wdt_disable();
      }
      else if (DAT_20019a5e == '\0') {
        __wdt_feed();
      }
      if (*param_1 == '\x01') {
        FUN_000806e4((int)param_1,*(int **)(param_1 + 0xff0));
      }
      bVar1 = getEraseDFU();
      if ((bVar1) &&
         (uVar12 = FUN_0007fea6(),
         (int)(uint)((uint)uVar12 < 60000) <= (int)((ulonglong)uVar12 >> 0x20))) {
        erase_dfu_flash();
        setEraseDFU(false);
      }
      if (1 < LOG_LEVEL) {
        bVar7 = param_1[0xfee];
        if (BLE_DEBUG == 0) {
          bVar1 = FUN_00028d2c();
          printk("%s(): Global Working Mode: %d get_glasses_ble_status %d ble_is_connected %d\n",
                 "low_speed_peripheral_dispatch_thread",(uint)bVar7,(uint)bVar1,uVar8);
        }
        else {
          bVar1 = FUN_00028d2c();
          ble_printk("%s(): Global Working Mode: %d get_glasses_ble_status %d ble_is_connected %d\n"
                     ,"low_speed_peripheral_dispatch_thread",(uint)bVar7,(uint)bVar1);
        }
      }
      try_enter_low_power_mode();
      check_work_mode(uVar9,uVar2,uVar10);
      check_disp_onboarding(uVar9,extraout_r1_01,extraout_r2_02);
      if ((((conn != (bt_conn *)0x0) && (param_1[0x1080] == '\0')) &&
          (uVar12 = FUN_0007fea6(), 30000 < (uint)((int)uVar12 - *(int *)(param_1 + 0xae4)))) &&
         (param_1[1] != '\x01')) {
        uVar12 = FUN_0007fea6();
        *(int *)(param_1 + 0xae4) = (int)uVar12;
        bt_conn_disconnect(conn,'\x13');
      }
      if (param_1[0x10d5] != '\0') {
        param_1[0x10d5] = '\0';
        pGVar4 = __get_dashboard_state();
        FUN_0007ff66((int)pGVar4,0);
        reset_all_usr_data(param_1,1);
      }
      check_sw0_status();
      uVar9 = 0;
    }
    FUN_0007ff16();
    if (DAT_20019a5e == '\0') {
      __wdt_feed();
    }
    z_impl_k_sleep((k_timeout_t)0x199a);
  } while( true );
}


