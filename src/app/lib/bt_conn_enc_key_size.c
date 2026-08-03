/*
 * Function: bt_conn_enc_key_size
 * Entry:    00084c42
 * Prototype: uint8_t __stdcall bt_conn_enc_key_size(bt_conn * conn)
 */


/* exclude_from_export */

uint8_t bt_conn_enc_key_size(bt_conn *conn)

{
  uint8_t uVar1;
  undefined *puVar2;
  
  uVar1 = '\0';
  if ((conn->encrypt != '\0') &&
     (puVar2 = (conn->le).keys, uVar1 = '\0', puVar2 != (undefined *)0x0)) {
    uVar1 = puVar2[0xc];
  }
  return uVar1;
}


