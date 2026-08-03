/*
 * Function: bt_conn_unref
 * Entry:    00059950
 * Prototype: void __stdcall bt_conn_unref(bt_conn * conn)
 */


/* exclude_from_export */

void bt_conn_unref(bt_conn *conn)

{
  short sVar1;
  char *test;
  int iVar2;
  char *file;
  int *piVar3;
  int line;
  
  piVar3 = &conn->ref;
  iVar2 = *piVar3;
  *piVar3 = iVar2 + -1;
  if (iVar2 < 1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","old > 0",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1315);
    _ASSERT("\tConn reference counter is 0\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  sVar1._0_1_ = conn->type;
  sVar1._1_1_ = conn->role;
  if ((sVar1 == 0x101) && (*piVar3 == 0)) {
    bt_le_adv_resume();
    return;
  }
  return;
}


