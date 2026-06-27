/*
 * Function: upgradeDoubleTapCustomizeToFlash
 * Entry:    00025e10
 * Prototype: undefined4 __stdcall upgradeDoubleTapCustomizeToFlash(uint param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 upgradeDoubleTapCustomizeToFlash(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  if (param_1 < 6) {
    pGVar2 = __get_dashboard_state();
    if ((byte)pGVar2->field_0x1244 != param_1) {
      pGVar2 = __get_dashboard_state();
      pGVar2->field_0x1244 = (char)param_1;
      pGVar2 = __get_dashboard_state();
      pGVar2->field_0x1245 = 0;
      FUN_00025b28(0,0);
      pGVar2 = __get_dashboard_state();
      if (pGVar2->field_0x1244 == '\x04') {
        if (DAT_20019132 != '\x02') {
          upgradeDashboardStartupModeInfoToFlash(2,extraout_r1,extraout_r2);
        }
      }
      else {
        pGVar2 = __get_dashboard_state();
        pGVar2->field_0x1245 = 0;
      }
    }
    uVar1 = 0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Err:double_tap_customize is out of range!\n");
      }
      else {
        ble_printk("%s(): Err:double_tap_customize is out of range!\n",
                   "upgradeDoubleTapCustomizeToFlash",param_3,BLE_DEBUG);
      }
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


