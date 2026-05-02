/*
 * Function: cleanCalenadrIndex
 * Entry:    00038d7c
 * Prototype: undefined __stdcall cleanCalenadrIndex(void)
 */


void cleanCalenadrIndex(void)

{
  DAT_20004b00 = 0;
  DAT_2001c4e3 = 0;
  if (LOG_LEVEL < 3) {
    return;
  }
  if (BLE_DEBUG != 0) {
    ble_printk("%s():  %s index = %d\n","cleanCalenadrIndex","cleanCalenadrIndex",0);
    return;
  }
  printk("%s():  %s index = %d\n","cleanCalenadrIndex","cleanCalenadrIndex",0);
  return;
}


