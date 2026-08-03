/*
 * Function: smp_send
 * Entry:    0005fde4
 * Prototype: void __stdcall smp_send(bt_smp * smp, net_buf * buf, bt_conn_tx_cb_t cb, void * user_data)
 */


/* exclude_from_export_ai */

void smp_send(bt_smp *smp,net_buf *buf,bt_conn_tx_cb_t cb,void *user_data)

{
  int iVar1;
  undefined4 extraout_r1;
  k_timeout_t delay;
  char local_18 [4];
  char *local_14;
  
  iVar1 = bt_l2cap_send_cb(*(bt_conn **)&smp[1].dhkey_BT_DH_KEY_LEN_,6,buf,cb,(void *)0x0);
  if (iVar1 != 0) {
    if (iVar1 == -0x69) {
      local_14 = "Ran out of TX buffers or contexts.";
      local_18[0] = '\x02';
      local_18[1] = '\0';
      local_18[2] = '\0';
      local_18[3] = '\0';
      LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_18);
    }
    net_buf_unref(buf);
    return;
  }
  delay.ticks._4_4_ = 0xf0000;
  delay.ticks._0_4_ = extraout_r1;
  k_work_reschedule((k_work_delayable *)(smp[3].rrnd + 9),delay);
  return;
}


