/*
 * Function: bt_gatt_att_max_mtu_changed
 * Entry:    0005fa18
 * Prototype: void __stdcall bt_gatt_att_max_mtu_changed(bt_conn * conn, uint16_t tx, uint16_t rx)
 */


/* exclude_from_export */

void bt_gatt_att_max_mtu_changed(bt_conn *conn,uint16_t tx,uint16_t rx)

{
  int *piVar1;
  
  for (piVar1 = (int *)DAT_2000b8f0; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    if ((code *)piVar1[-1] != (code *)0x0) {
      (*(code *)piVar1[-1])(conn,tx,rx);
    }
  }
  return;
}


