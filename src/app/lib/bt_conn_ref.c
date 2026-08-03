/*
 * Function: bt_conn_ref
 * Entry:    00059900
 * Prototype: bt_conn * __stdcall bt_conn_ref(bt_conn * conn)
 */


/* exclude_from_export */

bt_conn * bt_conn_ref(bt_conn *conn)

{
  int *piVar1;
  int iVar2;
  
  if (conn == (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn","WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c"
            ,1287);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  piVar1 = &conn->ref;
  do {
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      return (bt_conn *)0x0;
    }
  } while (*piVar1 != iVar2);
  *piVar1 = iVar2 + 1;
  return conn;
}


