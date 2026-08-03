/*
 * Function: notify_le_param_updated
 * Entry:    00059d8c
 * Prototype: void __stdcall notify_le_param_updated(bt_conn * conn)
 */


/* exclude_from_export */

void notify_le_param_updated(bt_conn *conn)

{
  ushort uVar1;
  char *test;
  int iVar2;
  char *file;
  int iVar3;
  int line;
  int iVar4;
  undefined **ppuVar5;
  
  iVar4 = DAT_2000b6fc;
  if (((((int)(conn->flags << 0x16) < 0) &&
       (uVar1 = (conn->le).interval, (conn->le).interval_min <= uVar1)) &&
      (uVar1 <= (conn->le).interval_max)) &&
     (iVar2._0_2_ = (conn->le).latency, iVar2._2_2_ = (conn->le).timeout,
     iVar3._0_2_ = (conn->le).pending_latency, iVar3._2_2_ = (conn->le).pending_timeout,
     iVar2 == iVar3)) {
    atomic_set_bit_to((atomic_t *)&conn->flags,-0x201,SUB21((undefined2)iVar2,0));
    iVar4 = DAT_2000b6fc;
  }
  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x20)) {
    if (*(code **)(iVar4 + 0xc) != (code *)0x0) {
      (**(code **)(iVar4 + 0xc))(conn,(conn->le).interval,(conn->le).latency,(conn->le).timeout);
    }
  }
  ppuVar5 = &PTR_ancs_connected_1_0008b79c;
  while( true ) {
    if (&DAT_0008b808 < ppuVar5) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb <= _bt_conn_cb_list_end",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1586);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_0008b804 + 3) < ppuVar5) break;
    if ((code *)ppuVar5[3] != (code *)0x0) {
      (*(code *)ppuVar5[3])(conn,(conn->le).interval,(conn->le).latency,(conn->le).timeout);
    }
    ppuVar5 = ppuVar5 + 9;
  }
  return;
}


