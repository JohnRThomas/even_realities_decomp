/*
 * Function: bt_ancs_cp_write
 * Entry:    00052438
 * Prototype: int __stdcall bt_ancs_cp_write(bt_ancs_client * ancs_c, uint16_t len, bt_ancs_write_cb func)
 */


/* exclude_from_export_ai */

int bt_ancs_cp_write(bt_ancs_client *ancs_c,uint16_t len,bt_ancs_write_cb func)

{
  int iVar1;
  
  *(uint16_t *)(ancs_c + 0x20) = len;
  *(undefined4 *)(ancs_c + 0x14) = 0x82d89;
  *(bt_ancs_write_cb *)(ancs_c + 0x24) = func;
  *(undefined2 *)(ancs_c + 0x18) = *(undefined2 *)(ancs_c + 8);
  *(undefined2 *)(ancs_c + 0x1a) = 0;
  *(bt_ancs_client **)(ancs_c + 0x1c) = ancs_c + 0x28;
  iVar1 = bt_gatt_write(*(bt_conn **)ancs_c,(bt_gatt_write_params *)(ancs_c + 0x14));
  if (iVar1 != 0) {
    atomic_clear_bit((atomic_t *)(ancs_c + 4),2);
  }
  return iVar1;
}


