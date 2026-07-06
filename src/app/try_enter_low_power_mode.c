/*
 * Function: try_enter_low_power_mode
 * Entry:    00028d90
 * Prototype: undefined __stdcall try_enter_low_power_mode(void)
 */


void try_enter_low_power_mode(void)

{
  bool bVar1;
  uint uVar2;
  GlassesState *pGVar3;
  undefined4 uVar4;
  size_t sVar5;
  uint uVar6;
  char *pcVar7;
  uint extraout_r1;
  uint extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  char cVar8;
  ushort uVar9;
  longlong lVar10;
  
  uVar2 = FUN_00027664();
  if (((4999 < uVar2) || (pGVar3 = __get_dashboard_state(), (byte)pGVar3->field_0xfc4 < 0x62)) ||
     (DAT_20019a62 == 0)) {
    return;
  }
  __wdt_disable();
  uVar9 = 0;
LAB_00028dc6:
  do {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        uVar4 = FUN_00027664();
        pGVar3 = __get_dashboard_state();
        printk("%s(): try to sleep chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n"
               ,"try_enter_low_power_mode",uVar4,(uint)(byte)pGVar3->field_0xfc4,(uint)DAT_20019a62)
        ;
      }
      else {
        uVar4 = FUN_00027664();
        pGVar3 = __get_dashboard_state();
        ble_printk("%s(): try to sleep chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n"
                   ,"try_enter_low_power_mode",uVar4,(uint)(byte)pGVar3->field_0xfc4,
                   (uint)DAT_20019a62);
      }
    }
    uVar2 = 0;
    do {
      sVar5 = k_msleep(1000);
      FUN_00027744(sVar5,extraout_r1,extraout_r2);
      fuel_gauge_update((device *)&PTR_s_charger_0008b520);
      uVar6 = FUN_00027664();
      if (uVar6 < 1000) {
        uVar2 = uVar2 & 0xffff;
        break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 10);
    if (DAT_20019a62 != 0) {
      uVar6 = FUN_00027664();
      if ((uVar6 < 0x3e9) && (bVar1 = is_box_lid_closed(), bVar1)) {
        DAT_20019a62 = 2;
        while ((DAT_20019a4f == '\0' &&
               (lVar10 = FUN_0007fea6(), lVar10 = lVar10 - CONCAT44(DAT_20004264,DAT_20004260),
               (uint)-(int)((ulonglong)lVar10 >> 0x20) < (uint)((uint)lVar10 < 300000)))) {
          if (DAT_20019a62 == 0) {
            return;
          }
          k_msleep(1000);
        }
        change_work_mode(8);
        DAT_50005614 = 1;
        DAT_20019a4f = '\x01';
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): enter low power mode\n","try_enter_low_power_mode");
          }
          else {
            ble_printk("%s(): enter low power mode\n");
          }
        }
        while ((pGVar3 = __get_dashboard_state(), 0x5e < (byte)pGVar3->field_0xfc4 &&
               (DAT_20019a62 != 0))) {
          uVar9 = uVar9 + 1;
          k_msleep(0x32);
          if (0x4af < uVar9) {
            fuel_gauge_update((device *)&PTR_s_charger_0008b520);
            uVar9 = 0;
          }
        }
        change_work_mode(9);
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            uVar4 = FUN_00027664();
            pGVar3 = __get_dashboard_state();
            printk("%s(): wakeup chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n"
                   ,"try_enter_low_power_mode",uVar4,(uint)(byte)pGVar3->field_0xfc4,
                   (uint)DAT_20019a62);
          }
          else {
            uVar4 = FUN_00027664();
            pGVar3 = __get_dashboard_state();
            ble_printk("%s(): wakeup chargerGetVdcRect() %d GLOBAL->battery_info[0] %d can_enter_low_power %d\n"
                       ,"try_enter_low_power_mode",uVar4,(uint)(byte)pGVar3->field_0xfc4,
                       (uint)DAT_20019a62);
          }
        }
        cVar8 = '(';
        do {
          if (DAT_20019a62 != 0) break;
          sVar5 = k_msleep(100);
          cVar8 = cVar8 + -1;
          FUN_00027744(sVar5,extraout_r1_00,extraout_r2_00);
          fuel_gauge_update((device *)&PTR_s_charger_0008b520);
        } while (cVar8 != '\0');
        bVar1 = is_box_lid_closed();
        if ((!bVar1) && (uVar2 = FUN_00027664(), uVar2 < 0x3e9)) {
          if (LOG_LEVEL < 1) goto LAB_00028e8c;
          if (BLE_DEBUG != 0) {
            uVar4 = FUN_00027664();
            pcVar7 = "%s(): force reboot becase can not get vac %d\n";
            goto LAB_00028e78;
          }
          uVar4 = FUN_00027664();
          pcVar7 = "%s(): force reboot becase can not get vac %d\n";
          goto LAB_00028e88;
        }
        k_msleep(6000);
      }
      else if (uVar2 != 10) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            uVar4 = FUN_00027664();
            printk("%s(): force exit low power mode becase can not enter low power mode %d\n",
                   "try_enter_low_power_mode",uVar4);
          }
          else {
            uVar4 = FUN_00027664();
            ble_printk("%s(): force exit low power mode becase can not enter low power mode %d\n",
                       "try_enter_low_power_mode",uVar4);
          }
        }
        change_work_mode(9);
      }
      goto LAB_00028dc6;
    }
    bVar1 = is_box_lid_closed();
    if (!bVar1) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          uVar4 = FUN_00027664();
          pcVar7 = "%s(): force reboot becase can not enter low power mode %d\n";
LAB_00028e88:
          printk(pcVar7,"try_enter_low_power_mode",uVar4);
        }
        else {
          uVar4 = FUN_00027664();
          pcVar7 = "%s(): force reboot becase can not enter low power mode %d\n";
LAB_00028e78:
          ble_printk(pcVar7,"try_enter_low_power_mode",uVar4);
        }
      }
LAB_00028e8c:
      k_msleep(500);
                    /* WARNING: Subroutine does not return */
      sys_reboot(1);
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): glass box is close, wait enter low power mode again.\n",
               "try_enter_low_power_mode");
      }
      else {
        ble_printk("%s(): glass box is close, wait enter low power mode again.\n");
      }
    }
  } while( true );
}


