/*
 * Function: fuel_gauge_update
 * Entry:    00010b20
 * Prototype: int __stdcall fuel_gauge_update(device * param_1)
 */


int fuel_gauge_update(device *param_1)

{
  longlong lVar1;
  char cVar2;
  float delta;
  GlassesState *pGVar3;
  undefined4 *puVar4;
  undefined4 extraout_r1;
  uint uVar5;
  undefined4 uVar6;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar7;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined1 uVar8;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  int iVar9;
  int iVar10;
  uint uVar11;
  float fVar12;
  int64_t ref_time;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  float temp;
  float voltage;
  float current;
  
  iVar10 = 0xb;
  delta = 0.0;
  while( true ) {
    cVar2 = FUN_0003214c();
    if (cVar2 != '\0') break;
    __lock_sensor_mutex(0,extraout_r1);
    iVar9 = read_sensors(param_1,&voltage,&current,&temp);
    __unlock_sensor_mutex();
    if (iVar9 < 0) {
      printk("Error: Could not read from charger device\n");
      lVar1 = CONCAT44(fuel_guage_ref_time._4_4_,(undefined4)fuel_guage_ref_time);
      goto LAB_00010b6e;
    }
    ref_time = k_uptime_get();
    lVar1 = CONCAT44(fuel_guage_ref_time._4_4_,(undefined4)fuel_guage_ref_time);
    uVar11 = (uint)(ref_time - lVar1);
    uVar5 = (uint)((ulonglong)(ref_time - lVar1) >> 0x20);
    if ((int)uVar5 < (int)(uint)(uVar11 < 1000)) {
      iVar9 = -1;
      goto LAB_00010b6e;
    }
    delta = (float)__floatdisf(uVar11,uVar5);
    fVar12 = current;
    delta = nrf_fuel_gauge_process(voltage,current,temp,delta / 1000.0,(float *)0x0);
    if ((((fVar12 != 0.0) || (iVar10 = iVar10 + -1, iVar10 == 0)) ||
        (-1 < (int)((uint)(delta < 100.0) << 0x1f))) || (delta <= 0.0)) {
      fuel_guage_ref_time = k_uptime_get();
      uVar6 = (undefined4)((ulonglong)fuel_guage_ref_time >> 0x20);
      uVar7 = extraout_r2_00;
      goto LAB_00010c08;
    }
    z_impl_k_sleep((k_timeout_t)0xa4);
  }
  uVar6 = extraout_r1;
  uVar7 = extraout_r2;
  if (delta <= 0.0) goto LAB_00010b4a;
LAB_00010c08:
  if (0 < (int)LOG_LEVEL) {
    uVar13 = __aeabi_f2d((uint)voltage,uVar6,uVar7,LOG_LEVEL);
    uVar6 = (undefined4)(uVar13 >> 0x20);
    uVar14 = __aeabi_f2d((uint)current,uVar6,extraout_r2_01,extraout_r3);
    uVar15 = __aeabi_f2d((uint)temp,(int)(uVar14 >> 0x20),extraout_r2_02,extraout_r3_00);
    if (BLE_DEBUG == 0) {
      printk("%s(): V: %.3f, I: %.3f, T: %.2f\n","fuel_gauge_update",(int)uVar13,uVar6,uVar14,uVar15
            );
    }
    else {
      ble_printk("%s(): V: %.3f, I: %.3f, T: %.2f\n","fuel_gauge_update",(int)uVar13,uVar6);
    }
  }
  ref_time = k_uptime_get();
  iVar9 = (int)ref_time;
  iVar10 = iVar9;
  fVar12 = delta;
  if (((delta == 0.0) || (DAT_20008554 == delta)) &&
     ((delta < 100.0 &&
      (iVar10 = DAT_20008550, fVar12 = DAT_20008554, 119999 < (uint)(iVar9 - DAT_20008550))))) {
    DAT_20019a5e = 1;
  }
  DAT_20008554 = fVar12;
  DAT_20008550 = iVar10;
  iVar10 = __is_old_board();
  fVar12 = delta;
  if (iVar10 != 0) {
    fVar12 = delta * 1.25;
  }
  if (0 < (int)LOG_LEVEL) {
    uVar13 = __aeabi_f2d((uint)delta,extraout_r1_00,extraout_r2_03,LOG_LEVEL);
    uVar6 = (undefined4)(uVar13 >> 0x20);
    uVar14 = __aeabi_f2d((uint)fVar12,uVar6,extraout_r2_04,extraout_r3_01);
    if (BLE_DEBUG == 0) {
      puVar4 = FUN_00025340();
      printk("%s(): Original soc %.2f, New Soc %.2f, %s\n","fuel_gauge_update",(int)uVar13,uVar6,
             uVar14,puVar4);
    }
    else {
      FUN_00025340();
      ble_printk("%s(): Original soc %.2f, New Soc %.2f, %s\n","fuel_gauge_update",(int)uVar13,uVar6
                );
    }
  }
  if (((int)((uint)(fVar12 < 0.0) << 0x1f) < 0) || (150.0 <= fVar12)) {
    fVar12 = 0.0;
LAB_00010eda:
    pGVar3 = __get_dashboard_state();
    uVar8 = 0;
  }
  else {
    if (100.0 <= fVar12) {
      fVar12 = 100.0;
      goto LAB_00010eda;
    }
    if (((fVar12 < 93.5) || (-1 < (int)((uint)(fVar12 < 94.0) << 0x1f))) &&
       ((fVar12 < 94.5 || (-1 < (int)((uint)(fVar12 < 95.0) << 0x1f))))) goto LAB_00010eda;
    pGVar3 = __get_dashboard_state();
    uVar8 = 1;
  }
  pGVar3->field_0xfc6 = uVar8;
  pGVar3 = __get_dashboard_state();
  delta = voltage * 100.0 - 200.0;
  pGVar3->field_0xfc4 = (0.0 < fVar12) * (char)(int)fVar12;
  pGVar3 = __get_dashboard_state();
  uVar11 = (uint)(0.0 < delta) * (int)delta;
  pGVar3->field_0xfc8 = (char)uVar11;
  if (current == 0.0) {
    nfc_box_status_debug_cache = nfc_box_status_debug_cache + 1;
    if (5 < nfc_box_status_debug_cache) {
      nfc_box_status_debug_cache = 0;
      uVar13 = __aeabi_f2d((uint)current,extraout_r1_01,extraout_r2_05,0);
      uVar13 = __aeabi_dadd((uint)uVar13,(uint)(uVar13 >> 0x20),0xd2f1a9fc,(uint)&DAT_3fc0624d);
      uVar13 = __muldf3((uint)uVar13,(uint)(uVar13 >> 0x20),0,0x408f4000);
      pGVar3 = __get_dashboard_state();
      uVar11 = __fixunsdfsi((uint)uVar13,(uint)(uVar13 >> 0x20));
      pGVar3->field_0xfc9 = (char)uVar11;
      pGVar3 = __get_dashboard_state();
      pGVar3->field_0xfcc = (char)(int)(current * 1000.0);
    }
  }
  else {
    uVar13 = __aeabi_f2d((uint)current,extraout_r1_01,extraout_r2_05,uVar11);
    uVar13 = __aeabi_dadd((uint)uVar13,(uint)(uVar13 >> 0x20),0xd2f1a9fc,(uint)&DAT_3fc0624d);
    uVar13 = __muldf3((uint)uVar13,(uint)(uVar13 >> 0x20),0,0x408f4000);
    pGVar3 = __get_dashboard_state();
    uVar11 = __fixunsdfsi((uint)uVar13,(uint)(uVar13 >> 0x20));
    pGVar3->field_0xfc9 = (char)uVar11;
    pGVar3 = __get_dashboard_state();
    pGVar3->field_0xfcc = (char)(int)(current * 1000.0);
    nfc_box_status_debug_cache = 0;
  }
  pGVar3 = __get_dashboard_state();
  pGVar3->field_0xfca = (0.0 < temp) * (char)(int)temp;
  pGVar3 = __get_dashboard_state();
  *(short *)&pGVar3->field_0xfce = (short)(int)(temp * 100.0);
  if (((60.0 <= temp) && ((int)((uint)(temp < 120.0) << 0x1f) < 0)) ||
     ((-50.0 <= temp && (temp <= -20.0)))) {
    pGVar3 = __get_dashboard_state();
    if (pGVar3->display_mode != '\f') {
      FUN_00029774(4,extraout_r1_02,extraout_r2_06);
      pGVar3 = __get_dashboard_state();
      if (*(char *)pGVar3 == '\x01') {
        pGVar3 = __get_dashboard_state();
        sync_to_slave((char *)pGVar3,4,(undefined4 *)0x0,0);
        pGVar3 = __get_dashboard_state();
        FUN_0007ff66((int)pGVar3,0);
      }
      else {
        pGVar3 = __get_dashboard_state();
        FUN_000294d0((int)pGVar3,8,(void *)0x0,0);
      }
      pGVar3 = __get_dashboard_state();
      pGVar3->display_mode = 0xc;
      pGVar3 = __get_dashboard_state();
      FUN_0007ff66((int)pGVar3,1);
      if (0 < (int)LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): #############################Abnormal temperature################################\n\n"
                );
        }
        else {
          ble_printk("%s(): #############################Abnormal temperature################################\n\n"
                     ,"fuel_gauge_update",extraout_r2_07,BLE_DEBUG);
        }
      }
    }
  }
LAB_00010b4a:
  iVar9 = 0;
  lVar1 = fuel_guage_ref_time;
LAB_00010b6e:
  fuel_guage_ref_time._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
  fuel_guage_ref_time._0_4_ = (undefined4)lVar1;
  return iVar9;
}


