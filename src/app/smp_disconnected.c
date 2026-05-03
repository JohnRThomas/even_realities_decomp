/*
 * Function: smp_disconnected
 * Entry:    00024034
 * Prototype: undefined __stdcall smp_disconnected(undefined4 param_1, undefined4 param_2)
 */


void smp_disconnected(undefined4 param_1,undefined4 param_2)

{
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): (reason 0x%02x)\n");
    }
    else {
      ble_printk("%s(): (reason 0x%02x)\n","smp_disconnected",param_2,BLE_DEBUG);
    }
  }
  if (DAT_20007f6c != 0) {
    k_work_submit((k_work *)&DAT_20007f68);
  }
  DAT_20007f7c = 0;
  DAT_20007f78 = 0;
  return;
}


