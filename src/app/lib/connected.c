/*
 * Function: connected
 * Entry:    00055c34
 * Prototype: void __stdcall connected(bt_conn * conn, uint8_t err)
 */


/* exclude_from_export_ai */

void connected(bt_conn *conn,uint8_t err)

{
  undefined4 in_r3;
  
  if (err != '\0') {
    return;
  }
  if (bt_smp != (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",s_WEST_TOPDIR_zephyr_subsys_mgmt_m_000f09cb,0x98);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  DAT_20005ef9 = DAT_2001e1c5;
  DAT_2001e1c5 = DAT_2001e1c5 + '\x01';
  if (DAT_2001e1c5 == '\0') {
    DAT_2001e1c5 = '\x01';
  }
  bt_smp = conn;
  tx_rsp((int *)&DAT_20005efc,(int *)&DAT_2001e1c5,CONCAT44(in_r3,&bt_smp));
  return;
}


