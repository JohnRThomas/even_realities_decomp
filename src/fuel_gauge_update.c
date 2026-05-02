/*
 * Function: fuel_gauge_update
 * Entry:    00010b20
 * Prototype: int __stdcall fuel_gauge_update(device * param_1)
 */


int fuel_gauge_update(device *param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  GlassesState *pGVar4;
  undefined4 *puVar5;
  undefined4 extraout_r1;
  uint uVar6;
  undefined4 uVar7;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar8;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined1 uVar9;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  int iVar10;
  uint uVar11;
  float fVar12;
  float fVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  int64_t iVar17;
  float local_44;
  float local_40;
  float local_3c [2];
  
  iVar10 = 0xb;
  fVar13 = 0.0;
  while( true ) {
    cVar2 = FUN_0003214c();
    iVar17 = CONCAT44(DAT_20004934,DAT_20004930);
    if (cVar2 != '\0') break;
    __lock_sensor_mutex(0,extraout_r1);
    iVar3 = read_sensors(param_1,&local_44,&local_40,local_3c);
    __unlock_sensor_mutex();
    if (iVar3 < 0) {
      printk("Error: Could not read from charger device\n");
      return iVar3;
    }
    iVar17 = k_uptime_get();
    lVar1 = iVar17 - CONCAT44(DAT_20004934,DAT_20004930);
    uVar11 = (uint)lVar1;
    uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
    if ((int)uVar6 < (int)(uint)(uVar11 < 1000)) {
      return -1;
    }
    fVar13 = (float)__floatdisf(uVar11,uVar6);
    fVar12 = local_40;
    fVar13 = nrf_fuel_gauge_process(local_44,local_40,local_3c[0],fVar13 / 1000.0,(float *)0x0);
    if ((((fVar12 != 0.0) || (iVar10 = iVar10 + -1, iVar10 == 0)) ||
        (-1 < (int)((uint)(fVar13 < 100.0) << 0x1f))) || (fVar13 <= 0.0)) {
      iVar17 = k_uptime_get();
      uVar7 = (undefined4)((ulonglong)iVar17 >> 0x20);
      uVar8 = extraout_r2_00;
      goto LAB_00010c08;
    }
    z_impl_k_sleep((k_timeout_t)0xa4);
  }
  uVar7 = extraout_r1;
  uVar8 = extraout_r2;
  if (fVar13 <= 0.0) {
    return 0;
  }
LAB_00010c08:
  DAT_20004934 = (undefined4)((ulonglong)iVar17 >> 0x20);
  DAT_20004930 = (undefined4)iVar17;
  if (0 < (int)LOG_LEVEL) {
    uVar14 = __aeabi_f2d((uint)local_44,uVar7,uVar8,LOG_LEVEL);
    uVar7 = (undefined4)(uVar14 >> 0x20);
    uVar15 = __aeabi_f2d((uint)local_40,uVar7,extraout_r2_01,extraout_r3);
    uVar16 = __aeabi_f2d((uint)local_3c[0],(int)(uVar15 >> 0x20),extraout_r2_02,extraout_r3_00);
    if (BLE_DEBUG == 0) {
      printk("%s(): V: %.3f, I: %.3f, T: %.2f\n","fuel_gauge_update",(int)uVar14,uVar7,uVar15,uVar16
            );
      iVar17 = CONCAT44(DAT_20004934,DAT_20004930);
    }
    else {
      ble_printk("%s(): V: %.3f, I: %.3f, T: %.2f\n","fuel_gauge_update",(int)uVar14,uVar7);
      iVar17 = CONCAT44(DAT_20004934,DAT_20004930);
    }
  }
  DAT_20004934 = (undefined4)((ulonglong)iVar17 >> 0x20);
  DAT_20004930 = (undefined4)iVar17;
  iVar17 = k_uptime_get();
  iVar3 = (int)iVar17;
  iVar10 = iVar3;
  fVar12 = fVar13;
  if (((fVar13 == 0.0) || (DAT_20008554 == fVar13)) &&
     ((fVar13 < 100.0 &&
      (iVar10 = DAT_20008550, fVar12 = DAT_20008554, 119999 < (uint)(iVar3 - DAT_20008550))))) {
    DAT_20019a5e = 1;
  }
  DAT_20008554 = fVar12;
  DAT_20008550 = iVar10;
  iVar10 = __is_old_board();
  fVar12 = fVar13;
  if (iVar10 != 0) {
    fVar12 = fVar13 * 1.25;
  }
  if (0 < (int)LOG_LEVEL) {
    uVar14 = __aeabi_f2d((uint)fVar13,extraout_r1_00,extraout_r2_03,LOG_LEVEL);
    uVar7 = (undefined4)(uVar14 >> 0x20);
    uVar15 = __aeabi_f2d((uint)fVar12,uVar7,extraout_r2_04,extraout_r3_01);
    if (BLE_DEBUG == 0) {
      puVar5 = FUN_00025340();
      printk("%s(): Original soc %.2f, New Soc %.2f, %s\n","fuel_gauge_update",(int)uVar14,uVar7,
             uVar15,puVar5);
    }
    else {
      FUN_00025340();
      ble_printk("%s(): Original soc %.2f, New Soc %.2f, %s\n","fuel_gauge_update",(int)uVar14,uVar7
                );
    }
  }
  if (((int)((uint)(fVar12 < 0.0) << 0x1f) < 0) || (150.0 <= fVar12)) {
    fVar12 = 0.0;
  }
  else if (100.0 <= fVar12) {
    fVar12 = 100.0;
  }
  else if (((93.5 <= fVar12) && ((int)((uint)(fVar12 < 94.0) << 0x1f) < 0)) ||
          ((94.5 <= fVar12 && ((int)((uint)(fVar12 < 95.0) << 0x1f) < 0)))) {
    pGVar4 = __get_dashboard_state();
    uVar9 = 1;
    goto LAB_00010d4c;
  }
  pGVar4 = __get_dashboard_state();
  uVar9 = 0;
LAB_00010d4c:
  pGVar4->field_0xfc6 = uVar9;
  pGVar4 = __get_dashboard_state();
  fVar13 = local_44 * 100.0 - 200.0;
  pGVar4->field_0xfc4 = (0.0 < fVar12) * (char)(int)fVar12;
  pGVar4 = __get_dashboard_state();
  uVar11 = (uint)(0.0 < fVar13) * (int)fVar13;
  pGVar4->field_0xfc8 = (char)uVar11;
  if (local_40 == 0.0) {
    nfc_box_status_debug_cache = nfc_box_status_debug_cache + 1;
    if (5 < nfc_box_status_debug_cache) {
      nfc_box_status_debug_cache = 0;
      uVar14 = __aeabi_f2d((uint)local_40,extraout_r1_01,extraout_r2_05,0);
      uVar14 = __aeabi_dadd((uint)uVar14,(uint)(uVar14 >> 0x20),0xd2f1a9fc,(uint)&DAT_3fc0624d);
      uVar14 = __muldf3((uint)uVar14,(uint)(uVar14 >> 0x20),0,0x408f4000);
      pGVar4 = __get_dashboard_state();
      uVar11 = __fixunsdfsi((uint)uVar14,(uint)(uVar14 >> 0x20));
      pGVar4->field_0xfc9 = (char)uVar11;
      pGVar4 = __get_dashboard_state();
      pGVar4->field_0xfcc = (char)(int)(local_40 * 1000.0);
    }
  }
  else {
    uVar14 = __aeabi_f2d((uint)local_40,extraout_r1_01,extraout_r2_05,uVar11);
    uVar14 = __aeabi_dadd((uint)uVar14,(uint)(uVar14 >> 0x20),0xd2f1a9fc,(uint)&DAT_3fc0624d);
    uVar14 = __muldf3((uint)uVar14,(uint)(uVar14 >> 0x20),0,0x408f4000);
    pGVar4 = __get_dashboard_state();
    uVar11 = __fixunsdfsi((uint)uVar14,(uint)(uVar14 >> 0x20));
    pGVar4->field_0xfc9 = (char)uVar11;
    pGVar4 = __get_dashboard_state();
    pGVar4->field_0xfcc = (char)(int)(local_40 * 1000.0);
    nfc_box_status_debug_cache = 0;
  }
  pGVar4 = __get_dashboard_state();
  pGVar4->field_0xfca = (0.0 < local_3c[0]) * (char)(int)local_3c[0];
  pGVar4 = __get_dashboard_state();
  *(short *)&pGVar4->field_0xfce = (short)(int)(local_3c[0] * 100.0);
  if ((((60.0 <= local_3c[0]) && ((int)((uint)(local_3c[0] < 120.0) << 0x1f) < 0)) ||
      ((-50.0 <= local_3c[0] && (local_3c[0] <= -20.0)))) &&
     (pGVar4 = __get_dashboard_state(), pGVar4->field_0xfee != '\f')) {
    FUN_00029774(4,extraout_r1_02,extraout_r2_06);
    pGVar4 = __get_dashboard_state();
    if (*(char *)pGVar4 == '\x01') {
      pGVar4 = __get_dashboard_state();
      sync_to_slave((char *)pGVar4,4,(undefined4 *)0x0,0);
      pGVar4 = __get_dashboard_state();
      FUN_0007ff66((int)pGVar4,0);
    }
    else {
      pGVar4 = __get_dashboard_state();
      FUN_000294d0((int)pGVar4,8,(void *)0x0,0);
    }
    pGVar4 = __get_dashboard_state();
    pGVar4->field_0xfee = 0xc;
    pGVar4 = __get_dashboard_state();
    FUN_0007ff66((int)pGVar4,1);
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
  return 0;
}


