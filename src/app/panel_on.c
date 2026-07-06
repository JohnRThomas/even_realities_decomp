/*
 * Function: panel_on
 * Entry:    0004a7cc
 * Prototype: undefined4 __stdcall panel_on(int param_1)
 */


undefined4 panel_on(int param_1)

{
  DeviceRole DVar1;
  
  *(int *)(param_1 + 0x378) = param_1 + -0x5c;
  if (*(int *)(param_1 + -0x48) == 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): panel_on enter!\n","panel_on");
      }
      else {
        ble_printk("%s(): panel_on enter!\n");
      }
    }
    power_for_panel();
    (**(code **)(param_1 + -0x5c))(*(undefined4 *)(param_1 + 0x378));
    panel_init();
    *(undefined4 *)(param_1 + 0x35c) = 1;
    DVar1 = getDeviceRole();
    if (DVar1 == MASTER) {
      opt3007_chip_init((opt3007_context *)0x0);
    }
  }
  return 0;
}


