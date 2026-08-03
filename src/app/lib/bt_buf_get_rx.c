/*
 * Function: bt_buf_get_rx
 * Entry:    00056508
 * Prototype: net_buf * __stdcall bt_buf_get_rx(bt_buf_type type, k_timeout_t timeout)
 */


/* exclude_from_export */

net_buf * bt_buf_get_rx(bt_buf_type type,k_timeout_t timeout)

{
  net_buf *pnVar1;
  char *test;
  char *file;
  int line;
  k_timeout_t timeout_00;
  
  timeout_00.ticks._4_4_ = (undefined4)((ulonglong)timeout.ticks >> 0x20);
  if (((uint)type < 6) &&
     (timeout_00.ticks._0_4_ = (0x2aU >> (type & 0xffU)) << 0x1f, (int)timeout_00.ticks < 0)) {
    pnVar1 = net_buf_alloc((net_buf_pool *)&DAT_20003d20,timeout_00);
    if (pnVar1 != (net_buf *)0x0) {
      net_buf_reserve((net_buf *)&(pnVar1->field6_0xc).field0,1);
      *(char *)&pnVar1->user_data = (char)type;
    }
    return pnVar1;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
          "type == BT_BUF_EVT || type == BT_BUF_ACL_IN || type == BT_BUF_ISO_IN",
          "WEST_TOPDIR/zephyr/subsys/bluetooth/host/buf.c",0x3e);
  _ASSERT("\tInvalid buffer type requested\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


