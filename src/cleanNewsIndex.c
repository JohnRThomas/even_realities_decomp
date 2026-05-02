/*
 * Function: cleanNewsIndex
 * Entry:    00038c9c
 * Prototype: undefined __stdcall cleanNewsIndex(void)
 */


void cleanNewsIndex(void)

{
  DAT_20004afd = 0;
  DAT_2001c4e4 = 0;
  if (LOG_LEVEL < 3) {
    return;
  }
  if (BLE_DEBUG != 0) {
    ble_printk("%s():  %s index = %d\n","cleanNewsIndex","cleanNewsIndex",0);
    return;
  }
  printk("%s():  %s index = %d\n","cleanNewsIndex","cleanNewsIndex",0);
  return;
}


