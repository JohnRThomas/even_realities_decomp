/*
 * Function: smp_bt_register
 * Entry:    00055df4
 * Prototype: int __stdcall smp_bt_register(void)
 */


/* exclude_from_export */

int smp_bt_register(void)

{
  int iVar1;
  
  iVar1 = bt_gatt_service_register((bt_gatt_service *)&DAT_200028d8);
  return iVar1;
}


