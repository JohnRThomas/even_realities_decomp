/*
 * Function: check_work_mode
 * Entry:    000297e0
 * Prototype: undefined __stdcall check_work_mode(int param_1, int param_2, int param_3)
 */


void check_work_mode(int param_1,int param_2,int param_3)

{
  byte bVar1;
  bool is_box_charging;
  GlassesState *pGVar2;
  char *pcVar3;
  int32_t iVar4;
  int iVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  undefined4 extraout_r1_12;
  undefined4 extraout_r1_13;
  undefined4 extraout_r1_14;
  undefined4 extraout_r1_15;
  undefined1 *puVar6;
  undefined1 *extraout_r1_16;
  undefined1 *extraout_r1_17;
  undefined4 extraout_r1_18;
  undefined1 *extraout_r1_19;
  undefined4 extraout_r1_20;
  undefined1 *extraout_r1_21;
  undefined4 extraout_r1_22;
  undefined4 extraout_r1_23;
  undefined4 uVar7;
  undefined4 extraout_r1_24;
  undefined1 *extraout_r1_25;
  undefined4 extraout_r2;
  undefined4 uVar8;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  byte *pbVar9;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  undefined1 *extraout_r2_10;
  undefined1 *extraout_r2_11;
  undefined1 *extraout_r2_12;
  undefined1 *extraout_r2_13;
  undefined1 *extraout_r2_14;
  undefined1 *puVar10;
  undefined1 *extraout_r2_15;
  undefined1 *extraout_r2_16;
  undefined1 *extraout_r2_17;
  undefined4 extraout_r2_18;
  undefined1 *extraout_r2_19;
  undefined4 extraout_r2_20;
  undefined1 *extraout_r2_21;
  undefined1 *extraout_r2_22;
  undefined1 *extraout_r2_23;
  uint uVar11;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  undefined8 uVar12;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_06;
  
  bVar1 = FUN_000169b4();
  uVar11 = (uint)bVar1;
  if ((bVar1 & 0xf7) == 0) {
    return;
  }
  if ((param_3 != 0) && (uVar11 == 1)) {
    if ((DAT_2000304d != -1) &&
       (pGVar2 = __get_dashboard_state(), (pGVar2->__work_mode_sem).count != 2)) {
      return;
    }
    pGVar2 = __get_dashboard_state();
    uVar7 = extraout_r1;
    uVar8 = extraout_r2;
    if ((pGVar2->__work_mode_sem).count == 2) {
      pGVar2 = __get_dashboard_state();
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = extraout_r1_00;
      z_impl_k_sem_take(&pGVar2->__work_mode_sem,timeout);
      uVar7 = extraout_r1_01;
      uVar8 = extraout_r2_00;
    }
    goto LAB_00029828;
  }
  uVar12 = FUN_0007fea6();
  if ((int)((ulonglong)uVar12 >> 0x20) < (int)(uint)((uint)uVar12 < 10000)) {
    return;
  }
  pGVar2 = __get_dashboard_state();
  if (((((byte)pGVar2->field_0xfc8 < 0x83) &&
       (pGVar2 = __get_dashboard_state(), 0x50 < (byte)pGVar2->field_0xfc8)) &&
      (pGVar2 = __get_dashboard_state(), '\0' < (char)pGVar2->field_0xfcc)) &&
     ((pGVar2 = __get_dashboard_state(), (byte)pGVar2->field_0xfc4 < 2 && (param_1 == 0)))) {
    pGVar2 = __get_dashboard_state();
    if (*(char *)pGVar2 == '\x01') {
      pGVar2 = __get_dashboard_state();
      sync_to_slave((char *)pGVar2,3,(undefined4 *)0x0,0);
    }
    else {
      pGVar2 = __get_dashboard_state();
      FUN_000294d0((int)pGVar2,5,(void *)0x0,0);
    }
    pGVar2 = __get_dashboard_state();
    FUN_0007ff66((int)pGVar2,1);
    change_work_mode(7);
    return;
  }
  if (DAT_20006bc8 < 0x33) {
    if (DAT_20006bc8 < 0x28) {
      DAT_20019a54 = '\0';
      pGVar2 = __get_dashboard_state();
      is_box_charging = FUN_0002da10((int)pGVar2);
      if (is_box_charging) {
        pGVar2 = __get_dashboard_state();
        if (**(char **)&pGVar2->field_0x101c == '\0') {
          bVar1 = 0x3c;
        }
        else {
          bVar1 = 10;
        }
      }
      else {
        bVar1 = 3;
      }
      DAT_20019a55 = DAT_20019a55 + 1;
      if (bVar1 <= DAT_20019a55) {
        DAT_20019a61 = 0;
        DAT_20019a60 = '\0';
        DAT_20019a55 = bVar1;
        pGVar2 = __get_dashboard_state();
        if (pGVar2->field_0x1245 != '\0') {
          pGVar2 = __get_dashboard_state();
          pGVar2->field_0x1245 = 0;
        }
        if (param_1 == 0) {
          if (uVar11 != 4) {
            pGVar2 = __get_dashboard_state();
            FUN_0007ff66((int)pGVar2,1);
            change_work_mode(4);
            if (0 < (int)LOG_LEVEL) {
              pcVar3 = "%s(): MODE_NORMAL_LOW_POWER_ID\n";
              uVar7 = extraout_r2_09;
              goto LAB_00029a46;
            }
          }
        }
        else if (param_2 == 0) {
          pGVar2 = __get_dashboard_state();
          FUN_0007ff66((int)pGVar2,1);
          change_work_mode(5);
          if (0 < (int)LOG_LEVEL) {
            pcVar3 = "%s(): MODE_CHARGING_RUN_ID\n";
            uVar7 = extraout_r2_08;
            goto LAB_00029a46;
          }
        }
        else {
          pGVar2 = __get_dashboard_state();
          FUN_0007ff66((int)pGVar2,1);
          change_work_mode(6);
          if (0 < (int)LOG_LEVEL) {
            pcVar3 = "%s(): MODE_CHARGING_LOW_POWER_ID\n";
            uVar7 = extraout_r2_07;
LAB_00029a46:
            if (BLE_DEBUG == 0) {
              printk(pcVar3);
            }
            else {
              ble_printk(pcVar3,"check_work_mode",uVar7,BLE_DEBUG);
            }
          }
        }
      }
    }
    is_box_charging = false;
LAB_000299ec:
    FUN_00081230();
  }
  else {
    DAT_20019a61 = 1;
    if (uVar11 - 2 < 2) {
      pGVar2 = __get_dashboard_state();
      is_box_charging = FUN_0002da10((int)pGVar2);
      if ((is_box_charging) && (change_work_mode(2), 0 < (int)LOG_LEVEL)) {
        pcVar3 = "%s(): MODE_NORMAL_RUN_ID\n";
        uVar7 = extraout_r2_04;
        goto LAB_00029910;
      }
    }
    else {
      pGVar2 = __get_dashboard_state();
      FUN_0007ff66((int)pGVar2,0);
      change_work_mode(3);
      if (0 < (int)LOG_LEVEL) {
        pcVar3 = "%s(): MODE_NORMAL_STANBY_ID\n";
        uVar7 = extraout_r2_03;
LAB_00029910:
        if (BLE_DEBUG == 0) {
          printk(pcVar3);
        }
        else {
          ble_printk(pcVar3,"check_work_mode",uVar7,BLE_DEBUG);
        }
      }
    }
    pbVar9 = (byte *)&DAT_20019a60;
    DAT_20019a55 = 0;
    bVar1 = DAT_20019a60 + 1;
    if (bVar1 < 2) {
LAB_00029938:
      *pbVar9 = bVar1;
    }
    else {
      DAT_20019a60 = '\x02';
      pbVar9 = (byte *)&DAT_20019a54;
      bVar1 = DAT_20019a54 + 1;
      if (bVar1 < 10) goto LAB_00029938;
      DAT_20019a54 = '\0';
      iVar4 = aw9320x_read_chipid();
      if (iVar4 != 0) {
        aw93203_init();
      }
    }
    if (param_1 != 0) {
      is_box_charging = true;
      goto LAB_000299ec;
    }
    enter_wear_burial_point();
    is_box_charging = true;
  }
  if (param_3 == 0) {
    DAT_20003048 = 0xff;
    DAT_20003049 = 0xff;
    DAT_2000304a = 0xff;
    DAT_2000304b = 0xff;
    DAT_2000304c = 0xff;
    DAT_2000304d = 0xff;
    DAT_20019a52 = 4;
    DAT_20019a53 = 4;
    return;
  }
  if ((DAT_2000304d == -1) ||
     (pGVar2 = __get_dashboard_state(), (pGVar2->__work_mode_sem).count == 2)) {
    pGVar2 = __get_dashboard_state();
    uVar7 = extraout_r1_04;
    uVar8 = extraout_r2_05;
    if ((pGVar2->__work_mode_sem).count == 2) {
      pGVar2 = __get_dashboard_state();
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = extraout_r1_05;
      z_impl_k_sem_take(&pGVar2->__work_mode_sem,timeout_00);
      uVar7 = extraout_r1_06;
      uVar8 = extraout_r2_06;
    }
LAB_00029828:
    if (0 < (int)LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): EVENT_GLASS_HAS_FINISH_BIND\n");
        uVar7 = extraout_r1_03;
        uVar8 = extraout_r2_02;
      }
      else {
        ble_printk("%s(): EVENT_GLASS_HAS_FINISH_BIND\n","check_work_mode",uVar8,BLE_DEBUG);
        uVar7 = extraout_r1_02;
        uVar8 = extraout_r2_01;
      }
    }
    FUN_00029774(0x11,uVar7,uVar8);
    DAT_2000304d = 0xfe;
    return;
  }
  uVar7 = extraout_r1_07;
  if (param_1 == 0) {
    if (is_box_charging) {
      if (0 < (int)LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): EVENT_ENTER_WARED\n");
          uVar7 = extraout_r1_13;
        }
        else {
          ble_printk("%s(): EVENT_ENTER_WARED\n","check_work_mode",extraout_r2_10,BLE_DEBUG);
          uVar7 = extraout_r1_12;
        }
      }
      uVar11 = 6;
    }
    else {
      if (0 < (int)LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): EVENT_UNWARED_OUTBOX\n");
          uVar7 = extraout_r1_15;
        }
        else {
          ble_printk("%s(): EVENT_UNWARED_OUTBOX\n","check_work_mode",extraout_r2_10,BLE_DEBUG);
          uVar7 = extraout_r1_14;
        }
      }
      uVar11 = 7;
    }
    DAT_2000304c = 0xff;
    DAT_2000304b = 0xff;
    DAT_20019a53 = '\x04';
    puVar6 = &DAT_20019a52;
    DAT_20019a52 = '\x04';
  }
  else {
    puVar6 = extraout_r2_10;
    if (param_2 == 0) {
      if (0 < (int)LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): EVENT_PUT_IN_GLASS_BOX_OPEN\n");
          uVar7 = extraout_r1_11;
          puVar6 = extraout_r2_14;
        }
        else {
          ble_printk("%s(): EVENT_PUT_IN_GLASS_BOX_OPEN\n","check_work_mode",extraout_r2_10,
                     BLE_DEBUG);
          uVar7 = extraout_r1_10;
          puVar6 = extraout_r2_13;
        }
      }
      uVar11 = 8;
    }
    else {
      if (0 < (int)LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): EVENT_PUT_IN_GLASS_BOX_CLOSE\n");
          uVar7 = extraout_r1_09;
          puVar6 = extraout_r2_12;
        }
        else {
          ble_printk("%s(): EVENT_PUT_IN_GLASS_BOX_CLOSE\n","check_work_mode",extraout_r2_10,
                     BLE_DEBUG);
          uVar7 = extraout_r1_08;
          puVar6 = extraout_r2_11;
        }
      }
      uVar11 = 0xb;
    }
  }
  if (DAT_20003050 != uVar11) {
    FUN_00029774(uVar11,uVar7,puVar6);
    DAT_20003050 = (char)uVar11;
    return;
  }
  pGVar2 = __get_dashboard_state();
  bVar1 = pGVar2->field_0xfc4;
  puVar10 = (undefined1 *)(uint)bVar1;
  puVar6 = (undefined1 *)(uint)DAT_2000304a;
  if ((puVar6 != puVar10) && (puVar10 < (undefined1 *)0x65)) {
    DAT_2000304a = bVar1;
    if (0 < (int)LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): EVENT_STATE_BATTERY_PERCENT %d\n");
        puVar6 = extraout_r1_17;
        puVar10 = extraout_r2_16;
      }
      else {
        ble_printk("%s(): EVENT_STATE_BATTERY_PERCENT %d\n","check_work_mode",puVar10,BLE_DEBUG);
        puVar6 = extraout_r1_16;
        puVar10 = extraout_r2_15;
      }
    }
    iVar5 = 10;
    goto LAB_00029bb2;
  }
  if (param_1 == 0) {
    if (DAT_20003049 != 0) {
LAB_00029c2a:
      uVar11 = 0;
LAB_00029c2c:
      if ((byte)(DAT_20019a52 + 1) < 5) {
        DAT_20019a52 = DAT_20019a52 + 1;
        return;
      }
      DAT_20019a52 = 0;
      pGVar2 = __get_dashboard_state();
      DAT_20003049 = (byte)uVar11;
      pGVar2->field_0x794 = DAT_20003049;
      FUN_00029774(9,extraout_r1_22,extraout_r2_20);
      if ((int)LOG_LEVEL < 1) {
        return;
      }
      if (BLE_DEBUG == 0) {
        printk("%s(): EVENT_STATE_CHARGING %d\n");
        return;
      }
      ble_printk("%s(): EVENT_STATE_CHARGING %d\n","check_work_mode",uVar11,BLE_DEBUG);
      return;
    }
    DAT_20019a52 = '\0';
  }
  else {
    is_box_charging = ::is_box_charging();
    uVar11 = (uint)is_box_charging;
    if (uVar11 == 0) {
      if (DAT_20003049 != 0) goto LAB_00029c2a;
    }
    else {
      DAT_20019a52 = '\x04';
      if (DAT_20003049 != uVar11) goto LAB_00029c2c;
    }
    DAT_20019a52 = '\0';
    bVar1 = FUN_00033754();
    uVar11 = (uint)bVar1;
    puVar6 = &DAT_20019a53;
    if (DAT_2000304b != uVar11) {
      DAT_20019a53 = DAT_20019a53 + 1;
      if (4 < DAT_20019a53) {
        DAT_20019a53 = 0;
        uVar7 = extraout_r1_18;
        DAT_2000304b = bVar1;
        if (0 < (int)LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): EVENT_GLASS_BOX_STATUS %d\n");
            uVar7 = extraout_r1_24;
            puVar6 = extraout_r2_22;
          }
          else {
            ble_printk("%s(): EVENT_GLASS_BOX_STATUS %d\n","check_work_mode",uVar11,BLE_DEBUG);
            uVar7 = extraout_r1_23;
            puVar6 = extraout_r2_21;
          }
        }
        FUN_00029774(0xe,uVar7,puVar6);
      }
      if ((int)LOG_LEVEL < 1) {
        return;
      }
      if (BLE_DEBUG == 0) {
        printk("%s(): last_box_charging_status is %d, box_charging_status is %d\n","check_work_mode"
               ,(uint)DAT_2000304b,uVar11);
        return;
      }
      ble_printk("%s(): last_box_charging_status is %d, box_charging_status is %d\n",
                 "check_work_mode",(uint)DAT_2000304b,uVar11);
      return;
    }
    DAT_20019a53 = '\0';
    bVar1 = FUN_00033760();
    uVar11 = (uint)bVar1;
    puVar6 = &DAT_2000304c;
    if ((DAT_2000304c != uVar11) && (uVar11 < 0x65)) {
      puVar10 = LOG_LEVEL;
      DAT_2000304c = bVar1;
      if (0 < (int)LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): EVENT_GLASS_BOX_SOC %d\n","check_work_mode",uVar11);
          puVar6 = extraout_r1_25;
          puVar10 = extraout_r2_23;
        }
        else {
          ble_printk("%s(): EVENT_GLASS_BOX_SOC %d\n","check_work_mode",uVar11,uVar11);
          puVar6 = extraout_r1_19;
          puVar10 = extraout_r2_17;
        }
      }
      iVar5 = 0xf;
      goto LAB_00029bb2;
    }
    if (0 < (int)LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): last_box_soc is %d, box_soc is %d\n","check_work_mode");
      }
      else {
        ble_printk("%s(): last_box_soc is %d, box_soc is %d\n","check_work_mode",(uint)DAT_2000304c,
                   uVar11);
      }
    }
  }
  pGVar2 = __get_dashboard_state();
  if (*(char *)pGVar2 != '\x01') {
    return;
  }
  pGVar2 = __get_dashboard_state();
  if (*(int *)&(pGVar2->opt3007_context).field_0x10 == 0) {
    return;
  }
  pGVar2 = __get_dashboard_state();
  bVar1 = FUN_00010848(&pGVar2->opt3007_context,extraout_r1_20,extraout_r2_18);
  if (bVar1 == 0xff) {
    return;
  }
  pGVar2 = __get_dashboard_state();
  if ((pGVar2->jdb_panel_context).panel_brightness_level == DAT_20003048) {
    return;
  }
  pGVar2 = __get_dashboard_state();
  DAT_20003048 = (pGVar2->jdb_panel_context).panel_brightness_level;
  iVar5 = 0x12;
  puVar6 = extraout_r1_21;
  puVar10 = extraout_r2_19;
LAB_00029bb2:
  FUN_00029774(iVar5,puVar6,puVar10);
  return;
}


