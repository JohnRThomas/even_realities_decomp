/*
 * Function: panel_on
 * Entry:    0004a7cc
 * Prototype: undefined4 __stdcall panel_on(int param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 panel_on(int param_1,undefined4 param_2,undefined4 param_3)

{
  DeviceRole DVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  *(int *)(param_1 + 0x378) = param_1 + -0x5c;
  if (*(int *)(param_1 + -0x48) == 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): panel_on enter!\n");
      }
      else {
        ble_printk("%s(): panel_on enter!\n","panel_on",param_3,BLE_DEBUG);
      }
    }
    power_for_panel();
    (**(code **)(param_1 + -0x5c))(*(undefined4 *)(param_1 + 0x378));
    panel_init();
    *(undefined4 *)(param_1 + 0x35c) = 1;
    DVar1 = getDeviceRole();
    if (DVar1 == MASTER) {
      opt3007_chip_init((opt3007_context *)0x0,extraout_r1,extraout_r2);
    }
  }
  return 0;
}


