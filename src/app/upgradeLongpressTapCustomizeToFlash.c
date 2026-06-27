/*
 * Function: upgradeLongpressTapCustomizeToFlash
 * Entry:    00025eb4
 * Prototype: undefined4 __stdcall upgradeLongpressTapCustomizeToFlash(uint param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 upgradeLongpressTapCustomizeToFlash(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  
  if (param_1 < 2) {
    pGVar2 = __get_dashboard_state();
    if ((byte)pGVar2->field_0x1246 != param_1) {
      pGVar2 = __get_dashboard_state();
      pGVar2->field_0x1246 = (char)param_1;
      FUN_00025b28(0,0);
    }
    uVar1 = 0;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Err:longpress_tap_customize is out of range!\n");
      }
      else {
        ble_printk("%s(): Err:longpress_tap_customize is out of range!\n",
                   "upgradeLongpressTapCustomizeToFlash",param_3,BLE_DEBUG);
      }
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


