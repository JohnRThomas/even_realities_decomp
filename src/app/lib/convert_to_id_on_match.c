/*
 * Function: convert_to_id_on_match
 * Entry:    0008699a
 * Prototype: void __stdcall convert_to_id_on_match(bt_conn * conn, void * data)
 */


/* exclude_from_export */

void convert_to_id_on_match(bt_conn *conn,void *data)

{
  int iVar1;
  
  iVar1 = memcmp(&conn->le,*(void **)data,7);
  if (iVar1 == 0) {
    bt_addr_le_copy(&(conn->le).dst,*(bt_addr_le_t **)((int)data + 4));
    return;
  }
  return;
}


