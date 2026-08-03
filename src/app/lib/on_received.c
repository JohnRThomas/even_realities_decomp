/*
 * Function: on_received
 * Entry:    00052784
 * Prototype: uint8_t __stdcall on_received(bt_conn * conn, bt_gatt_subscribe_params * params, void * data, uint16_t length)
 */


/* exclude_from_export_ai */

uint8_t on_received(bt_conn *conn,bt_gatt_subscribe_params *params,void *data,uint16_t length)

{
  if (nus_cb != (code *)0x0) {
    (*nus_cb)(conn,data,length);
  }
  return (uint8_t)length;
}


