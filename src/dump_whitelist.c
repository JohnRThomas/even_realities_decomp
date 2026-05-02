/*
 * Function: dump_whitelist
 * Entry:    00036c50
 * Prototype: undefined __stdcall dump_whitelist(void)
 */


void dump_whitelist(void)

{
  char *buf;
  
  buf = malloc(0x1800);
  if (buf != (char *)0x0) {
    memset(buf,0,0x15e3);
    convert_app_whitelist_to_json(buf);
    free(buf);
    return;
  }
  if (BLE_DEBUG != 0) {
    ble_printk("[%s-%d] malloc failed !!\n","dump_whitelist",0x277,BLE_DEBUG);
    return;
  }
  printk("[%s-%d] malloc failed !!\n");
  return;
}


