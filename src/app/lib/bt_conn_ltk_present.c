/*
 * Function: bt_conn_ltk_present
 * Entry:    00084c14
 * Prototype: bool __stdcall bt_conn_ltk_present(bt_conn * conn)
 */


/* exclude_from_export */

bool bt_conn_ltk_present(bt_conn *conn)

{
  ushort uVar1;
  bool bVar2;
  bt_keys *pbVar3;
  
  pbVar3 = (bt_keys *)(conn->le).keys;
  if ((pbVar3 != (bt_keys *)0x0) ||
     (pbVar3 = bt_keys_find_addr(conn->id,&(conn->le).dst), bVar2 = false, pbVar3 != (bt_keys *)0x0)
     ) {
    uVar1 = (ushort)pbVar3->ltk_rand0;
    if (conn->role == '\0') {
      uVar1 = uVar1 & 0x21;
    }
    else {
      uVar1 = uVar1 & 0x24;
    }
    if (uVar1 == 0) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  }
  return bVar2;
}


