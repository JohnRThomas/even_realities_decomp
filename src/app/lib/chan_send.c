/*
 * Function: chan_send
 * Entry:    0005bd00
 * Prototype: int __stdcall chan_send(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

int chan_send(bt_att_chan *chan,net_buf *buf)

{
  uint16_t uVar1;
  att_type_t aVar2;
  size_t sVar3;
  char *file;
  int line;
  int iVar4;
  bt_conn *conn;
  uint8_t *user_data;
  undefined4 uVar5;
  byte local_28 [4];
  char *local_24;
  char *test;
  
  user_data = buf->user_data;
  uVar5 = *(undefined4 *)user_data;
  if ((int)chan[8].att << 0x1d < 0) {
    if ((*(buf->field6_0xc).field0.data == 0xd2) &&
       (iVar4 = bt_smp_sign(*(bt_conn **)chan->att,buf), iVar4 != 0)) {
      local_24 = "Error signing data";
      local_28[0] = 2;
      local_28[1] = 0;
      local_28[2] = 0;
      local_28[3] = 0;
      LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1040,local_28);
      tx_meta_data_free((bt_att_tx_meta_data *)buf->user_data);
      net_buf_unref(buf);
    }
    else {
      sVar3 = net_buf_simple_headroom(&(buf->field6_0xc).b);
      uVar1 = (buf->field6_0xc).field0.len;
      *(bt_att_chan **)user_data = chan;
      conn = *(bt_conn **)chan->att;
      aVar2 = att_op_get_type(*(buf->field6_0xc).field0.data);
      test = (char *)(uint)aVar2;
      if (&DAT_00000005 < test) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c"
                ,651);
        _ASSERT("\tUnknown op type 0x%02X\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      iVar4 = bt_l2cap_send_cb(conn,4,buf,(&PTR_chan_tx_complete_1_0008ee2c)[(int)test],user_data);
      if (iVar4 != 0) {
        if (iVar4 == -0x69) {
          local_24 = "Ran out of TX buffers or contexts.";
          local_28[0] = 2;
          local_28[1] = 0;
          local_28[2] = 0;
          local_28[3] = 0;
          LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1040,local_28);
        }
        (buf->field6_0xc).field0.len = uVar1;
        (buf->field6_0xc).field0.data = (buf->field6_0xc).field0.__buf + (sVar3 & 0xffff);
        *(undefined4 *)user_data = uVar5;
      }
    }
  }
  else {
    iVar4 = -0x16;
    local_24 = "ATT channel not connected";
    local_28[0] = 2;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1040,local_28);
  }
  return iVar4;
}


