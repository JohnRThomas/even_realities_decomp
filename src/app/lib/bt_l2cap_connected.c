/*
 * Function: bt_l2cap_connected
 * Entry:    0005abc8
 * Prototype: void __stdcall bt_l2cap_connected(bt_conn * conn)
 */


/* exclude_from_export */

void bt_l2cap_connected(bt_conn *conn)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  bt_l2cap_chan *in_r1;
  char *test;
  char *file;
  int line;
  code *pcVar4;
  undefined **ppuVar5;
  bt_conn *pbVar6;
  bt_l2cap_chan *local_14;
  
  ppuVar5 = &PTR_DAT_0008b778;
  pbVar6 = conn;
  local_14 = in_r1;
  while( true ) {
    if (&PTR_ancs_connected_1_0008b79c < ppuVar5) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","fchan <= _bt_l2cap_fixed_chan_list_end",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/l2cap.c",389);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_0008b798 + 3) < ppuVar5) break;
    iVar3 = (*(code *)ppuVar5[1])(conn,&local_14);
    if (-1 < iVar3) {
      uVar1 = *(undefined2 *)ppuVar5;
      *(undefined2 *)&local_14[1].conn = uVar1;
      *(undefined2 *)&local_14[1].BT_L2CAP_NUM_STATUS_ = uVar1;
      bVar2 = l2cap_chan_add(conn,local_14,ppuVar5[2]);
      if (!bVar2) {
        return;
      }
      if (*(code **)local_14->ops != (code *)0x0) {
        (**(code **)local_14->ops)();
      }
      local_14->BT_L2CAP_NUM_STATUS_ = local_14->BT_L2CAP_NUM_STATUS_ | 1;
      pcVar4 = *(code **)(local_14->ops + 0x1c);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(local_14,&local_14->BT_L2CAP_NUM_STATUS_,0,pcVar4,pbVar6);
      }
    }
    ppuVar5 = ppuVar5 + 3;
  }
  return;
}


