/*
 * Function: nvs_ate_crc8_update
 * Entry:    00081d60
 * Prototype: void __stdcall nvs_ate_crc8_update(nvs_ate * entry)
 */


/* exclude_from_export_ai */

void nvs_ate_crc8_update(nvs_ate *entry)

{
  byte bVar1;
  
  bVar1 = crc8_ccitt(0xff,entry,7);
  entry->crc8 = bVar1;
  return;
}


