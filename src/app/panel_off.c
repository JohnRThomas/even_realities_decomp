/*
 * Function: panel_off
 * Entry:    0004a720
 * Prototype: undefined4 __stdcall panel_off(int param_1)
 */


undefined4 panel_off(int param_1)

{
  DeviceRole DVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  *(int *)(param_1 + 0x378) = param_1 + -0x5c;
  if (*(int *)(param_1 + -0x48) != 0) {
    *(undefined4 *)(param_1 + 0x35c) = 0;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): panel_suspend enter!\n","panel_off");
      }
      else {
        ble_printk("%s(): panel_suspend enter!\n");
      }
    }
    DVar1 = getDeviceRole();
    if (DVar1 == MASTER) {
      opt3007_chip_deinit(0,extraout_r1,extraout_r2,extraout_r3);
    }
    (**(code **)(param_1 + -0x58))(*(undefined4 *)(param_1 + 0x378));
    power_down_panel();
  }
  return 0;
}


