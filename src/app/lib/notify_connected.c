/*
 * Function: notify_connected
 * Entry:    00059260
 * Prototype: void __stdcall notify_connected(bt_conn * conn)
 */


/* exclude_from_export */

void notify_connected(bt_conn *conn)

{
  char *test;
  char *file;
  int line;
  undefined **ppuVar1;
  undefined4 *puVar2;
  
  for (puVar2 = DAT_2000b6fc; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[8]) {
    if ((code *)*puVar2 != (code *)0x0) {
      (*(code *)*puVar2)(conn,conn->err);
    }
  }
  ppuVar1 = &PTR_ancs_connected_1_0008b79c;
  while( true ) {
    if (&DAT_0008b808 < ppuVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb <= _bt_conn_cb_list_end",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1517);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_0008b804 + 3) < ppuVar1) break;
    if ((code *)*ppuVar1 != (code *)0x0) {
      (*(code *)*ppuVar1)(conn,conn->err);
    }
    ppuVar1 = ppuVar1 + 9;
  }
  return;
}


