/*
 * Function: bt_conn_security_changed
 * Entry:    0005a054
 * Prototype: void __stdcall bt_conn_security_changed(bt_conn * conn, uint8_t hci_err, bt_security_err err)
 */


/* exclude_from_export_ai */

void bt_conn_security_changed(bt_conn *conn,uint8_t hci_err,bt_security_err err)

{
  char *test;
  char *file;
  int line;
  undefined **ppuVar1;
  int iVar2;
  
  conn->required_sec_level = conn->sec_level;
  bt_l2cap_security_changed(conn,hci_err);
  for (iVar2 = DAT_2000b6fc; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
    if (*(code **)(iVar2 + 0x14) != (code *)0x0) {
      (**(code **)(iVar2 + 0x14))(conn,conn->sec_level,err);
    }
  }
  ppuVar1 = &PTR_ancs_connected_1_0008b79c;
  while( true ) {
    if (&DAT_0008b808 < ppuVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb <= _bt_conn_cb_list_end",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",2248);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)0x8b807 < ppuVar1) break;
    if ((code *)ppuVar1[5] != (code *)0x0) {
      (*(code *)ppuVar1[5])(conn,conn->sec_level,err);
    }
    ppuVar1 = ppuVar1 + 9;
  }
  return;
}


