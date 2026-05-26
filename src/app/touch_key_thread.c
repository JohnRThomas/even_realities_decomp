/*
 * Function: touch_key_thread
 * Entry:    0002c290
 * Prototype: undefined __stdcall touch_key_thread(char * param_1, undefined4 param_2)
 */


void touch_key_thread(char *param_1,undefined4 param_2)

{
  GlassesState *pGVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  char *fmt;
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
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar5;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  int iVar6;
  int iVar7;
  char cVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  uint32_t uVar12;
  uint32_t uVar13;
  int iVar14;
  int iVar15;
  k_timeout_t timeout;
  
  uVar10 = 0;
  uVar11 = 0;
  uVar3 = 0;
  uVar12 = 0;
  uVar13 = 0;
LAB_0002c2a0:
  do {
    while ((timeout.ticks._4_4_ = 0x2000, timeout.ticks._0_4_ = param_2,
           z_impl_k_sem_take((k_sem *)(param_1 + 0xb0),timeout), param_1[1] == '\x01' ||
           (pGVar1 = __get_dashboard_state(), pGVar1->field_0x1 == '\b'))) {
      k_msleep(5000);
      param_2 = extraout_r1;
    }
    param_2 = extraout_r1_00;
    if (GLOBAL_STATE._4_4_ != 0) {
      FUN_00031f90(pGVar1,extraout_r1_00,extraout_r2);
      GLOBAL_STATE._4_4_ = 0;
      param_2 = extraout_r1_01;
    }
  } while (-1 < (int)((uint)*(ushort *)(param_1 + 0x1070) << 0x1f));
  if (DAT_2001aa7a == '\x01') {
    uVar4 = sys_clock_tick_get_32();
    FUN_000805b4((uint *)(param_1 + 0x1090),extraout_r1_03,extraout_r2_01);
    if (10000 < (int)(uVar4 - uVar12)) {
      uVar11 = 0;
      uVar3 = uVar11;
    }
    uVar9 = uVar3 + 1;
    DAT_2001aa7a = '\0';
  }
  else {
    uVar9 = uVar3;
    uVar4 = uVar12;
    if (DAT_2001aa7a == '\x02') {
      uVar11 = sys_clock_tick_get_32();
      DAT_2001aa7a = '\0';
      DAT_20019a57 = 0;
    }
  }
  uVar2 = sys_clock_tick_get_32();
  uVar3 = sys_clock_tick_get_32();
  iVar14 = uVar3 - uVar11;
  iVar15 = uVar11 - uVar4;
  param_2 = extraout_r1_02;
  uVar3 = uVar9;
  uVar12 = uVar4;
  if (uVar9 != 1) goto LAB_0002c490;
  iVar6 = uVar2 - uVar4;
  if (uVar10 != 0) {
    if (uVar11 == 0) {
LAB_0002c3f0:
      if (uVar13 == 0) {
        iVar7 = 0x23;
      }
      else {
        iVar7 = 3;
      }
      if (iVar7 * 30000 < iVar6) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk(
                  "%s(): #############################Long press timeout %d################################\n\n"
                  );
          }
          else {
            ble_printk("%s(): #############################Long press timeout %d################################\n\n"
                       ,"touch_key_thread",uVar13,BLE_DEBUG);
          }
        }
        uVar10 = 0;
        DAT_200084f8 = 6;
        FUN_0002c278();
        param_2 = extraout_r1_07;
        uVar3 = 0;
        uVar13 = uVar10;
        goto LAB_0002c2a0;
      }
      if ((int)uVar4 < 0) goto LAB_0002c41c;
    }
    else {
      uVar3 = uVar10;
      if ((int)uVar11 <= (int)uVar4) goto LAB_0002c2a0;
LAB_0002c41c:
      if (10000 < iVar14) {
        if (15000 < iVar15) {
          uVar10 = 1;
          goto LAB_0002c42e;
        }
        goto LAB_0002c32e;
      }
    }
    uVar10 = 1;
    uVar3 = uVar9;
    goto LAB_0002c2a0;
  }
  if (uVar11 == 0) {
    FUN_000805b4((uint *)(param_1 + 0x1090),extraout_r1_02,extraout_r2_00);
    param_2 = extraout_r1_04;
    if (((int)(undefined *)0xffffb1e0 < *(int *)(param_1 + 0x1090)) &&
       (*(int *)(param_1 + 0x1090) < 20000)) {
      uVar3 = 0;
      goto LAB_0002c2a0;
    }
    if (15000 < iVar6) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ########################turn on the mic and start to speak! holdtime %d\n\n"
                );
        }
        else {
          ble_printk("%s(): ########################turn on the mic and start to speak! holdtime %d\n\n"
                     ,"touch_key_thread",iVar6,BLE_DEBUG);
        }
      }
      DAT_200084f8 = 4;
      FUN_0002c278();
      param_2 = extraout_r1_05;
      goto LAB_0002c3f0;
    }
    if (-1 < (int)uVar4) {
      uVar10 = 0;
      goto LAB_0002c2a0;
    }
  }
  else if ((int)uVar11 <= (int)uVar4) goto LAB_0002c2a0;
  if (10000 < iVar14) {
    if (15000 < iVar15) goto LAB_0002c42e;
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
    cVar8 = '\x04';
    while ((DAT_2001c4e8 != '\0' && (cVar8 = cVar8 + -1, cVar8 != '\0'))) {
      k_msleep(100);
    }
    DAT_200084f8 = 1;
    goto LAB_0002c452;
  }
  goto LAB_0002c2a0;
LAB_0002c490:
  if (((uVar9 == 0) || ((int)uVar11 <= (int)uVar4)) || (iVar14 < 0x2711)) goto LAB_0002c2a0;
  if (15000 < iVar15) {
LAB_0002c42e:
    if (iVar15 < 0x8ca1) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): #############################Short press end################################\n\n"
                );
          param_2 = extraout_r1_09;
        }
        else {
          ble_printk("%s(): #############################Short press end################################\n\n"
                     ,"touch_key_thread",36000,BLE_DEBUG);
          param_2 = extraout_r1_08;
        }
      }
      uVar11 = 0;
      uVar3 = uVar9;
      uVar13 = 1;
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
  switch(uVar9) {
  case 2:
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): #############################double click################################\n\n"
              );
      }
      else {
        ble_printk("%s(): #############################double click################################\n\n"
                   ,"touch_key_thread",extraout_r2_00,BLE_DEBUG);
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
                   ,"touch_key_thread",extraout_r2_00,BLE_DEBUG);
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
          ble_printk("%s(): reset_pmic_on\n\n","touch_key_thread",extraout_r2_02,BLE_DEBUG);
        }
      }
      func_0x00017b34();
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): reset_pmic_off\n\n");
        }
        else {
          ble_printk("%s(): reset_pmic_off\n\n","touch_key_thread",extraout_r2_03,BLE_DEBUG);
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
    param_2 = extraout_r1_10;
    if (LOG_LEVEL < 1) goto switchD_0002c4b6_caseD_4;
    uVar5 = 6;
    fmt = "%s(): #############################%d click force bind#############################\n\n";
    goto LAB_0002c5e6;
  case 10:
    iVar14 = 1;
    goto LAB_0002c69c;
  case 0xb:
    iVar14 = 0;
LAB_0002c69c:
    reset_all_usr_data(param_1,iVar14);
    param_2 = extraout_r1_14;
    goto switchD_0002c4b6_caseD_4;
  case 0xf:
    FUN_0007f300(10);
    param_2 = extraout_r1_12;
    if (LOG_LEVEL < 1) goto switchD_0002c4b6_caseD_4;
    uVar5 = 0xf;
    fmt = "%s(): %d click, use high band for ESB\n\n";
LAB_0002c5e6:
    if (BLE_DEBUG == 0) {
      printk(fmt);
      param_2 = extraout_r1_13;
    }
    else {
      ble_printk(fmt,"touch_key_thread",uVar5,BLE_DEBUG);
      param_2 = extraout_r1_11;
    }
    goto switchD_0002c4b6_caseD_4;
  }
LAB_0002c452:
  FUN_0002c278();
  param_2 = extraout_r1_06;
switchD_0002c4b6_caseD_4:
  uVar10 = 0;
  uVar3 = uVar10;
  goto LAB_0002c2a0;
}


