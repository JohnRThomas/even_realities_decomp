/*
 * Function: le_param_req
 * Entry:    00059f24
 * Prototype: bool __stdcall le_param_req(bt_conn * conn, bt_le_conn_param * param)
 */


/* exclude_from_export */

bool le_param_req(bt_conn *conn,bt_le_conn_param *param)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *test;
  char *file;
  int line;
  undefined **ppuVar5;
  
  bVar1 = bt_le_conn_params_valid(param);
  iVar4 = DAT_2000b6fc;
  if (bVar1) {
    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x20)) {
      if ((*(code **)(iVar4 + 8) != (code *)0x0) &&
         ((iVar3 = (**(code **)(iVar4 + 8))(conn,param), iVar3 == 0 ||
          (bVar2 = bt_le_conn_params_valid(param), !bVar2)))) goto LAB_00059f36;
    }
    ppuVar5 = &PTR_ancs_connected_1_0008b79c;
    while( true ) {
      if (&DAT_0008b808 < ppuVar5) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","cb <= _bt_conn_cb_list_end",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1652);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((undefined **)0x8b807 < ppuVar5) break;
      if (((code *)ppuVar5[2] != (code *)0x0) &&
         ((iVar4 = (*(code *)ppuVar5[2])(conn,param), iVar4 == 0 ||
          (bVar2 = bt_le_conn_params_valid(param), !bVar2)))) goto LAB_00059f36;
      ppuVar5 = ppuVar5 + 9;
    }
  }
  else {
LAB_00059f36:
    bVar1 = false;
  }
  return bVar1;
}


