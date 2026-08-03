/*
 * Function: bt_conn_identity_resolved
 * Entry:    00059fc8
 * Prototype: void __stdcall bt_conn_identity_resolved(bt_conn * conn)
 */


/* exclude_from_export */

void bt_conn_identity_resolved(bt_conn *conn)

{
  char *test;
  char *file;
  int line;
  undefined **ppuVar1;
  int iVar2;
  bt_addr_le_t *pbVar3;
  
  if (conn->role == '\0') {
    pbVar3 = &(conn->le).resp_addr;
  }
  else {
    pbVar3 = &(conn->le).init_addr;
  }
  for (iVar2 = DAT_2000b6fc; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
    if (*(code **)(iVar2 + 0x10) != (code *)0x0) {
      (**(code **)(iVar2 + 0x10))(conn,pbVar3,&conn->le);
    }
  }
  ppuVar1 = &PTR_ancs_connected_1_0008b79c;
  while( true ) {
    if (&DAT_0008b808 < ppuVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb <= _bt_conn_cb_list_end",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",2138);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)0x8b807 < ppuVar1) break;
    if ((code *)ppuVar1[4] != (code *)0x0) {
      (*(code *)ppuVar1[4])(conn,pbVar3,&conn->le);
    }
    ppuVar1 = ppuVar1 + 9;
  }
  return;
}


