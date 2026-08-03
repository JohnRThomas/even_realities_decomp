/*
 * Function: bt_id_del
 * Entry:    00058340
 * Prototype: void __stdcall bt_id_del(bt_keys * keys)
 */


/* exclude_from_export_ai */

void bt_id_del(bt_keys *keys)

{
  bt_conn *conn;
  int iVar1;
  net_buf *buf;
  bt_addr_le_t *dst;
  dword in_stack_ffffffa8;
  uint8_t *in_stack_ffffffac;
  void *in_stack_ffffffb0;
  undefined4 local_48;
  char *local_44;
  int iStack_40;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  
  if (keys == (bt_keys *)0x0) {
    return;
  }
  if (DAT_20002120 == 0) {
    if (DAT_20002121 == 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","bt_dev.le.rl_entries > 0",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/id.c",1075);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
  }
  else if ((uint)DAT_20002121 <= DAT_20002120 + 1) {
    conn = bt_conn_lookup_state_le('\0',(bt_addr_le_t *)0x0,6);
    if (conn != (bt_conn *)0x0) {
      DAT_200020d4 = DAT_200020d4 | 0x8000;
      keys->state = keys->state | 2;
      bt_conn_unref(conn);
      return;
    }
    bt_le_ext_adv_foreach((void *)0x84863,(void *)0x0);
    iVar1 = addr_res_enable('\0');
    if (iVar1 == 0) {
      if (DAT_20002120 < DAT_20002121) {
        DAT_20002121 = DAT_20002121 - 1;
        keys->state = keys->state & 0xfb;
        bt_keys_foreach_type(BT_KEYS_LTK,(void *)0x847ed,(void *)0x0);
      }
      else {
        buf = bt_hci_cmd_create(0x2028,'\a');
        if (buf != (net_buf *)0x0) {
          dst = net_buf_add((net_buf *)&(buf->field6_0xc).field0,7);
          bt_addr_le_copy(dst,&keys->addr);
          iVar1 = bt_hci_cmd_send_sync(0x2028,buf,(net_buf **)0x0);
          if (iVar1 == 0) {
            DAT_20002121 = DAT_20002121 - 1;
            keys->state = keys->state & 0xfb;
            goto LAB_000583ee;
          }
        }
        local_24 = "Failed to remove IRK from controller";
        local_28 = 2;
        LOG_WRN(&PTR_s_bt_id_0008b900,0x1040,&local_28,2,in_stack_ffffffc8,in_stack_ffffffcc,
                in_stack_ffffffd0);
      }
    }
    else {
      local_44 = "Disabling address resolution failed (err %d)";
      local_48 = 3;
      iStack_40 = iVar1;
      LOG_WRN(&PTR_s_bt_id_0008b900,0x1840,&local_48,3,in_stack_ffffffa8,in_stack_ffffffac,
              in_stack_ffffffb0);
    }
LAB_000583ee:
    if (DAT_20002121 != 0) {
      addr_res_enable('\x01');
    }
    bt_le_ext_adv_foreach((void *)0x84839,(void *)0x0);
    return;
  }
  DAT_20002121 = DAT_20002121 - 1;
  keys->state = keys->state & 0xfb;
  return;
}


