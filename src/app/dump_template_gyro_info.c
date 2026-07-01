/*
 * Function: dump_template_gyro_info
 * Entry:    000379bc
 * Prototype: undefined __stdcall dump_template_gyro_info(int param_1)
 */


void dump_template_gyro_info(int param_1)

{
  GlassesState *pGVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  uint extraout_r3;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  pGVar1 = __get_dashboard_state();
  if (2 < LOG_LEVEL) {
    uVar2 = __aeabi_f2d(*(uint *)(pGVar1->field20_0xc8 + 0x27),extraout_r1,extraout_r2,
                        (uint)(pGVar1->field20_0xc8 + 0x27));
    uVar3 = __aeabi_f2d(*(uint *)(pGVar1->field20_0xc8 + 0x2b),(int)(uVar2 >> 0x20),extraout_r2_00,
                        (uint)(pGVar1->field20_0xc8 + 0x2b));
    uVar4 = __aeabi_f2d(*(uint *)(pGVar1->field20_0xc8 + 0x2f),(int)(uVar3 >> 0x20),extraout_r2_01,
                        extraout_r3);
    if (BLE_DEBUG == 0) {
      printk("%s(): screen_id: %d, ypr: %.2f, %.2f, %.2f\n");
    }
    else {
      ble_printk("%s(): screen_id: %d, ypr: %.2f, %.2f, %.2f\n","dump_template_gyro_info",
                 (uint)*(byte *)(param_1 + 1),BLE_DEBUG,uVar2,uVar3,uVar4);
    }
  }
  return;
}


