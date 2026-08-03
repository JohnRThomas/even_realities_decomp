/*
 * Function: notify_le_data_len_updated
 * Entry:    00059e3c
 * Prototype: void __stdcall notify_le_data_len_updated(bt_conn * conn)
 */


/* exclude_from_export */

void notify_le_data_len_updated(bt_conn *conn)

{
  char *test;
  char *file;
  int line;
  undefined **ppuVar1;
  int iVar2;
  
  for (iVar2 = DAT_2000b6fc; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x20)) {
    if (*(code **)(iVar2 + 0x1c) != (code *)0x0) {
      (**(code **)(iVar2 + 0x1c))(conn,&(conn->le)._pad4);
    }
  }
  ppuVar1 = &PTR_ancs_connected_1_0008b79c;
  while( true ) {
    if (&DAT_0008b808 < ppuVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb <= _bt_conn_cb_list_end",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1604);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_0008b804 + 3) < ppuVar1) break;
    if ((code *)ppuVar1[7] != (code *)0x0) {
      (*(code *)ppuVar1[7])(conn,&(conn->le)._pad4);
    }
    ppuVar1 = ppuVar1 + 9;
  }
  return;
}


