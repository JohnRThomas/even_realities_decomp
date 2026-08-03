/*
 * Function: gatt_write_ccc
 * Entry:    0005d7ec
 * Prototype: int __stdcall gatt_write_ccc(bt_conn * conn, bt_gatt_subscribe_params * params)
 */


/* exclude_from_export */

int gatt_write_ccc(bt_conn *conn,bt_gatt_subscribe_params *params)

{
  int iVar1;
  bt_att_chan_opt in_r2;
  
  atomic_set_bit(params + 5,8);
  iVar1 = gatt_req_send(conn,(bt_att_func_t)0x5d45d,params,(bt_att_encode_t)0x86327,'\x12',4,in_r2);
  return iVar1;
}


