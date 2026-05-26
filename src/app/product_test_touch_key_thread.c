/*
 * Function: product_test_touch_key_thread
 * Entry:    0002ad94
 * Prototype: undefined __stdcall product_test_touch_key_thread(char * param_1, char * param_2)
 */


void product_test_touch_key_thread(char *param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  char *fmt;
  GlassesState *pGVar6;
  char *extraout_r1;
  char *extraout_r1_00;
  undefined4 extraout_r1_01;
  char *extraout_r1_02;
  undefined4 extraout_r1_03;
  char *extraout_r1_04;
  undefined4 extraout_r1_05;
  char *extraout_r1_06;
  char *extraout_r1_07;
  char *extraout_r1_08;
  char *extraout_r1_09;
  char *extraout_r1_10;
  char *extraout_r1_11;
  char *extraout_r1_12;
  char *extraout_r1_13;
  char *extraout_r1_14;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  uint32_t uVar10;
  k_timeout_t timeout;
  uint uVar5;
  
  uVar7 = 0;
  uVar9 = 0;
  uVar8 = 0;
  uVar10 = 0;
LAB_0002adaa:
  do {
    while( true ) {
      timeout.ticks._4_4_ = 0x4000;
      timeout.ticks._0_4_ = param_2;
      z_impl_k_sem_take((k_sem *)(param_1 + 0xb0),timeout);
      if ((param_1[1] != '\x01') && (param_1[1] != '\b')) break;
      k_msleep(5000);
      param_2 = extraout_r1_00;
    }
    param_2 = extraout_r1;
  } while (-1 < (int)((uint)*(ushort *)(param_1 + 0x1070) << 0x1f));
  if (GLOBAL_STATE._4_4_ != 0) {
    uVar3 = sys_clock_tick_get_32();
    FUN_00031f90(uVar3,extraout_r1_01,extraout_r2);
    sys_clock_tick_get_32();
    GLOBAL_STATE._4_4_ = 0;
  }
  if (DAT_2001aa7a == '\x01') {
    uVar3 = sys_clock_tick_get_32();
    FUN_000805b4((uint *)(param_1 + 0x1090),extraout_r1_05,extraout_r2_01);
    if (30000 < (int)(uVar3 - uVar10)) {
      uVar9 = 0;
      uVar7 = uVar9;
    }
    uVar7 = uVar7 + 1;
    DAT_2001aa7a = '\0';
  }
  else {
    uVar3 = uVar10;
    if (DAT_2001aa7a == '\x02') {
      uVar9 = sys_clock_tick_get_32();
      DAT_2001aa7a = '\0';
    }
  }
  param_2 = (char *)sys_clock_tick_get_32();
  uVar4 = sys_clock_tick_get_32();
  uVar10 = uVar3;
  if (uVar7 != 1) goto LAB_0002aeae;
  if (uVar8 == 0) {
    if ((uVar9 == 0) && (param_2 = param_2 + -uVar3, 30000 < (int)param_2)) {
      printk("########################turn on the mic and start to speak! holdtime %d\n");
      param_2 = extraout_r1_06;
      goto LAB_0002ae12;
    }
  }
  else {
LAB_0002ae12:
    uVar8 = 1;
  }
  goto LAB_0002ae14;
LAB_0002aeae:
  if (uVar7 == 0) goto LAB_0002adaa;
LAB_0002ae14:
  if (((int)uVar9 <= (int)uVar3) || ((int)(uVar4 - uVar9) < 0x2711)) goto LAB_0002adaa;
  bVar1 = FUN_00033e38();
  uVar5 = (uint)bVar1;
  if (uVar5 == 1) {
    cVar2 = FUN_00033e20();
    param_2 = extraout_r1_12;
    if ((cVar2 == '\x02') &&
       (pGVar6 = __get_dashboard_state(), param_2 = extraout_r1_13,
       (byte)pGVar6->field_0x10c8 < 0xfa)) {
      pGVar6 = __get_dashboard_state();
      pGVar6->field_0x10c8 = pGVar6->field_0x10c8 + '\x01';
      param_2 = extraout_r1_14;
    }
    goto switchD_0002aed0_caseD_6;
  }
  if ((int)(undefined *)0x249f0 < (int)(uVar9 - uVar3)) {
    printk("#############################long press################################\n");
    FUN_000805b4((uint *)(param_1 + 0x1090),extraout_r1_03,extraout_r2_00);
LAB_0002ae46:
    printk("aw9320x_diff_get: %d\n",*(undefined4 *)(param_1 + 0x1090));
    param_2 = extraout_r1_04;
    goto switchD_0002aed0_caseD_6;
  }
  if ((int)(uVar9 - uVar3) < (int)(undefined *)0x15f91) {
    param_2 = extraout_r1_02;
    switch(uVar7) {
    case 1:
      if (uVar8 == 0) {
        printk("#############################single click################################\n");
        goto LAB_0002ae46;
      }
      fmt = "turn off mic now\n";
      goto LAB_0002aebe;
    case 2:
      on_double_click(uVar5,extraout_r1_02,(undefined *)0x15f90);
      param_2 = extraout_r1_08;
      break;
    case 3:
      on_triple_click(uVar5,extraout_r1_02,(undefined *)0x15f90);
      param_2 = extraout_r1_09;
      break;
    case 4:
      goto switchD_0002aed0_caseD_4;
    case 5:
      FUN_00033e44();
      param_2 = extraout_r1_10;
      break;
    case 10:
      reset_all_usr_data(param_1,1);
      param_2 = extraout_r1_11;
    }
  }
  else {
    fmt = "#############################short press################################\n";
LAB_0002aebe:
    printk(fmt);
    param_2 = extraout_r1_07;
  }
switchD_0002aed0_caseD_6:
  uVar7 = 0;
  uVar8 = uVar7;
  goto LAB_0002adaa;
switchD_0002aed0_caseD_4:
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): sys reboot because touch event, %d click, reboot now\n\n");
    }
    else {
      ble_printk("%s(): sys reboot because touch event, %d click, reboot now\n\n",
                 "product_test_touch_key_thread",4,BLE_DEBUG);
    }
  }
  k_msleep(500);
                    /* WARNING: Subroutine does not return */
  sys_reboot(1);
}


