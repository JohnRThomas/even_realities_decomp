/*
 * Function: touch_key_thread
 * Entry:    0002c290
 * Prototype: undefined __stdcall touch_key_thread(char * param_1, undefined4 param_2)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void touch_key_thread(char *param_1,uint32_t *param_2)

{
  GlassesState *p_irq_stat_data;
  uint32_t uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  char *fmt;
  uint32_t *extraout_r1;
  uint32_t *irq_status;
  uint32_t *extraout_r1_00;
  uint32_t *extraout_r1_01;
  undefined4 extraout_r1_02;
  uint32_t *extraout_r1_03;
  uint32_t *extraout_r1_04;
  uint32_t *extraout_r1_05;
  uint32_t *extraout_r1_06;
  uint32_t *extraout_r1_07;
  uint32_t *extraout_r1_08;
  uint32_t *extraout_r1_09;
  uint32_t *extraout_r1_10;
  uint32_t *extraout_r1_11;
  uint32_t *extraout_r1_12;
  uint32_t *extraout_r1_13;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar4;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  int iVar5;
  int iVar6;
  char cVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  int iVar13;
  int iVar14;
  k_timeout_t timeout;
  
  uVar9 = 0;
  uVar10 = 0;
  uVar2 = 0;
  uVar11 = 0;
  uVar12 = 0;
LAB_0002c2a0:
  do {
    while ((timeout.ticks._4_4_ = 0x2000, timeout.ticks._0_4_ = param_2,
           z_impl_k_sem_take((k_sem *)(param_1 + 0xb0),timeout), param_1[1] == '\x01' ||
           (p_irq_stat_data = __get_dashboard_state(), p_irq_stat_data->field_0x1 == '\b'))) {
      k_msleep(5000);
      param_2 = extraout_r1;
    }
    param_2 = irq_status;
    if (GLOBAL_STATE._4_4_ != 0) {
      aw9320x_get_irq_stat((cap_event_status *)p_irq_stat_data,irq_status);
      GLOBAL_STATE._4_4_ = 0;
      param_2 = extraout_r1_00;
    }
  } while (-1 < (int)((uint)*(ushort *)(param_1 + 0x1070) << 0x1f));
  if (aw9320x_wearing == IN_EAR) {
    uVar3 = sys_clock_tick_get_32();
    aw9320x_diff_get((uint *)(param_1 + 0x1090),extraout_r1_02,extraout_r2_00);
    if (10000 < (int)(uVar3 - uVar11)) {
      uVar10 = 0;
      uVar2 = uVar10;
    }
    uVar8 = uVar2 + 1;
    aw9320x_wearing = UNKNOWN;
  }
  else {
    uVar8 = uVar2;
    uVar3 = uVar11;
    if (aw9320x_wearing == OUT_EAR) {
      uVar10 = sys_clock_tick_get_32();
      aw9320x_wearing = UNKNOWN;
      DAT_20019a57 = 0;
    }
  }
  uVar1 = sys_clock_tick_get_32();
  uVar2 = sys_clock_tick_get_32();
  iVar13 = uVar2 - uVar10;
  iVar14 = uVar10 - uVar3;
  param_2 = extraout_r1_01;
  uVar2 = uVar8;
  uVar11 = uVar3;
  if (uVar8 != 1) goto LAB_0002c490;
  iVar5 = uVar1 - uVar3;
  if (uVar9 != 0) {
    if (uVar10 == 0) {
LAB_0002c3f0:
      if (uVar12 == 0) {
        iVar6 = 0x23;
      }
      else {
        iVar6 = 3;
      }
      if (iVar6 * 30000 < iVar5) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): #############################Long press timeout %d################################\n\n"
                  );
          }
          else {
            ble_printk("%s(): #############################Long press timeout %d################################\n\n"
                       ,"touch_key_thread",uVar12,BLE_DEBUG);
          }
        }
        uVar9 = 0;
        DAT_200084f8 = 6;
        FUN_0002c278();
        param_2 = extraout_r1_06;
        uVar2 = 0;
        uVar12 = uVar9;
        goto LAB_0002c2a0;
      }
      if ((int)uVar3 < 0) goto LAB_0002c41c;
    }
    else {
      uVar2 = uVar9;
      if ((int)uVar10 <= (int)uVar3) goto LAB_0002c2a0;
LAB_0002c41c:
      if (10000 < iVar13) {
        if (15000 < iVar14) {
          uVar9 = 1;
          goto LAB_0002c42e;
        }
        goto LAB_0002c32e;
      }
    }
    uVar9 = 1;
    uVar2 = uVar8;
    goto LAB_0002c2a0;
  }
  if (uVar10 == 0) {
    aw9320x_diff_get((uint *)(param_1 + 0x1090),extraout_r1_01,extraout_r2);
    param_2 = extraout_r1_03;
    if (((int)(undefined *)0xffffb1e0 < *(int *)(param_1 + 0x1090)) &&
       (*(int *)(param_1 + 0x1090) < 20000)) {
      uVar2 = 0;
      goto LAB_0002c2a0;
    }
    if (15000 < iVar5) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ########################turn on the mic and start to speak! holdtime %d\n\n"
                );
        }
        else {
          ble_printk("%s(): ########################turn on the mic and start to speak! holdtime %d\n\n"
                     ,"touch_key_thread",iVar5,BLE_DEBUG);
        }
      }
      DAT_200084f8 = 4;
      FUN_0002c278();
      param_2 = extraout_r1_04;
      goto LAB_0002c3f0;
    }
    if (-1 < (int)uVar3) {
      uVar9 = 0;
      goto LAB_0002c2a0;
    }
  }
  else if ((int)uVar10 <= (int)uVar3) goto LAB_0002c2a0;
  if (10000 < iVar13) {
    if (15000 < iVar14) goto LAB_0002c42e;
LAB_0002c32e:
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): #############################single click %d################################\n\n"
              );
      }
      else {
        ble_printk("%s(): #############################single click %d################################\n\n"
                   ,"touch_key_thread",*(undefined4 *)(param_1 + 0x1090),BLE_DEBUG);
      }
    }
    cVar7 = '\x04';
    while ((DAT_2001c4e8 != '\0' && (cVar7 = cVar7 + -1, cVar7 != '\0'))) {
      k_msleep(100);
    }
    DAT_200084f8 = 1;
    goto LAB_0002c452;
  }
  goto LAB_0002c2a0;
LAB_0002c490:
  if (((uVar8 == 0) || ((int)uVar10 <= (int)uVar3)) || (iVar13 < 0x2711)) goto LAB_0002c2a0;
  if (15000 < iVar14) {
LAB_0002c42e:
    if (iVar14 < 0x8ca1) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): #############################Short press end################################\n\n"
                );
          param_2 = extraout_r1_08;
        }
        else {
          ble_printk("%s(): #############################Short press end################################\n\n"
                     ,"touch_key_thread",36000,BLE_DEBUG);
          param_2 = extraout_r1_07;
        }
      }
      uVar10 = 0;
      uVar2 = uVar8;
      uVar12 = 1;
      goto LAB_0002c2a0;
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(
              "%s(): #############################Long press end################################\n\n"
              );
      }
      else {
        ble_printk("%s(): #############################Long press end################################\n\n"
                   ,"touch_key_thread",36000,BLE_DEBUG);
      }
    }
    DAT_200084f8 = 5;
    goto LAB_0002c452;
  }
  switch(uVar8) {
  case 2:
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): #############################double click################################\n\n"
              );
      }
      else {
        ble_printk("%s(): #############################double click################################\n\n"
                   ,"touch_key_thread",extraout_r2,BLE_DEBUG);
      }
    }
    DAT_200084f8 = 2;
    break;
  case 3:
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): #############################triple click################################\n\n"
              );
      }
      else {
        ble_printk("%s(): #############################triple click################################\n\n"
                   ,"touch_key_thread",extraout_r2,BLE_DEBUG);
      }
    }
    DAT_200084f8 = 3;
    break;
  default:
    goto switchD_0002c4b6_caseD_4;
  case 5:
    if (**(char **)(param_1 + 0x101c) == '\0') {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): %d click, reboot now\n\n");
        }
        else {
          ble_printk("%s(): %d click, reboot now\n\n","touch_key_thread",5,BLE_DEBUG);
        }
      }
      func_0x00017b28();
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): reset_pmic_on\n\n");
        }
        else {
          ble_printk("%s(): reset_pmic_on\n\n","touch_key_thread",extraout_r2_01,BLE_DEBUG);
        }
      }
      func_0x00017b34();
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): reset_pmic_off\n\n");
        }
        else {
          ble_printk("%s(): reset_pmic_off\n\n","touch_key_thread",extraout_r2_02,BLE_DEBUG);
        }
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): sys reboot because touch event, %d click, reboot now\n\n");
          }
          else {
            ble_printk("%s(): sys reboot because touch event, %d click, reboot now\n\n",
                       "touch_key_thread",5,BLE_DEBUG);
          }
        }
      }
      k_msleep(500);
                    /* WARNING: Subroutine does not return */
      sys_reboot(1);
    }
    goto switchD_0002c4b6_caseD_4;
  case 6:
    bt_unpair('\0',(bt_addr_le_t *)0x0);
    param_1[0x1089] = '\x02';
    param_2 = extraout_r1_09;
    if (LOG_LEVEL < 1) goto switchD_0002c4b6_caseD_4;
    uVar4 = 6;
    fmt = "%s(): #############################%d click force bind#############################\n\n";
    goto LAB_0002c5e6;
  case 10:
    iVar13 = 1;
    goto LAB_0002c69c;
  case 0xb:
    iVar13 = 0;
LAB_0002c69c:
    reset_all_usr_data(param_1,iVar13);
    param_2 = extraout_r1_13;
    goto switchD_0002c4b6_caseD_4;
  case 0xf:
    FUN_0007f300(10);
    param_2 = extraout_r1_11;
    if (LOG_LEVEL < 1) goto switchD_0002c4b6_caseD_4;
    uVar4 = 0xf;
    fmt = "%s(): %d click, use high band for ESB\n\n";
LAB_0002c5e6:
    if (BLE_DEBUG == 0) {
      printk(fmt);
      param_2 = extraout_r1_12;
    }
    else {
      ble_printk(fmt,"touch_key_thread",uVar4,BLE_DEBUG);
      param_2 = extraout_r1_10;
    }
    goto switchD_0002c4b6_caseD_4;
  }
LAB_0002c452:
  FUN_0002c278();
  param_2 = extraout_r1_05;
switchD_0002c4b6_caseD_4:
  uVar9 = 0;
  uVar2 = uVar9;
  goto LAB_0002c2a0;
}


