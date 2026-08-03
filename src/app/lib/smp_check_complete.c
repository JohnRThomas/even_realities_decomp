/*
 * Function: smp_check_complete
 * Entry:    000616c8
 * Prototype: void __stdcall smp_check_complete(bt_conn * conn, uint8_t dist_complete)
 */


/* exclude_from_export */

void smp_check_complete(bt_conn *conn,uint8_t dist_complete)

{
  bt_l2cap_chan *pbVar1;
  char *test;
  int in_r2;
  char *file;
  int line;
  
  if ((in_r2 == 0) && (conn->type == BT_CONN_TYPE_LE)) {
    pbVar1 = bt_l2cap_le_lookup_tx_cid(conn,6);
    if (pbVar1 == (bt_l2cap_chan *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chan",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/smp.c",631);
      _ASSERT("\tNo SMP channel found\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    *(byte *)&pbVar1[-1].destroy = *(byte *)&pbVar1[-1].destroy & 0xfe;
    if (*(short *)&pbVar1[-1].destroy == 0) {
      smp_pairing_complete((bt_smp *)(pbVar1 + -0xc),'\0');
      return;
    }
  }
  return;
}


