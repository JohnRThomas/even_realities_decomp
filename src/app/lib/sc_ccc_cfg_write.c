/*
 * Function: sc_ccc_cfg_write
 * Entry:    00086202
 * Prototype: ssize_t __stdcall sc_ccc_cfg_write(bt_conn * conn, bt_gatt_attr * attr, uint16_t value)
 */


/* exclude_from_export */

ssize_t sc_ccc_cfg_write(bt_conn *conn,bt_gatt_attr *attr,uint16_t value)

{
  char in_ZR;
  
  if (in_ZR == '\0') {
    sc_clear(conn);
  }
  else {
    sc_save(conn->id,&(conn->le).dst,0,0);
  }
  return 2;
}


