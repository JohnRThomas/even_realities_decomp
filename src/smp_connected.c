/*
 * Function: smp_connected
 * Entry:    00024088
 * Prototype: undefined __stdcall smp_connected(undefined4 param_1, int param_2)
 */


void smp_connected(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_20007f78 = 1;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): ok\n","smp_connected",&DAT_20007f78,BLE_DEBUG);
        return;
      }
      printk("%s(): ok\n");
      return;
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG != 0) {
      ble_printk("%s(): failed (err 0x%02x)\n","smp_connected",param_2,BLE_DEBUG);
      return;
    }
    printk("%s(): failed (err 0x%02x)\n");
    return;
  }
  return;
}


