/*
 * Function: gatt_delayed_store
 * Entry:    0008675e
 * Prototype: void __stdcall gatt_delayed_store(int * work)
 */


/* exclude_from_export_ai */

void gatt_delayed_store(int *work)

{
  gatt_store_ccc_cf((uint8_t)work[-10],(bt_addr_le_t *)((int)work + -0x27));
  gatt_store_ccc_cf((uint8_t)work[-7],(bt_addr_le_t *)((int)work + -0x1b));
  gatt_store_ccc_cf((uint8_t)work[-4],(bt_addr_le_t *)((int)work + -0xf));
  return;
}


