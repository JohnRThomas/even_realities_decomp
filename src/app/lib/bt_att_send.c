/*
 * Function: bt_att_send
 * Entry:    0005e92c
 * Prototype: int __stdcall bt_att_send(bt_conn * conn, net_buf * buf)
 */


/* exclude_from_export_ai */

int bt_att_send(bt_conn *conn,net_buf *buf)

{
  uint8_t uVar1;
  bool bVar2;
  bt_att *pbVar3;
  bt_att_chan *chan;
  int iVar4;
  net_buf *buf_00;
  undefined2 *puVar5;
  int in_r2;
  int *piVar6;
  bt_att_chan *pbVar7;
  char local_28 [4];
  char *local_24;
  
  uVar1 = bt_gatt_check_perm(conn,*(bt_gatt_attr **)(in_r2 + 4),0x94);
  if (uVar1 == '\0') {
    bVar2 = bt_gatt_is_subscribed(conn,*(bt_gatt_attr **)(in_r2 + 4),1);
    if (bVar2) {
      buf_00 = bt_att_create_pdu(conn,'\x1b',*(ushort *)(in_r2 + 0xc) + 2);
      if (buf_00 != (net_buf *)0x0) {
        puVar5 = net_buf_add((net_buf *)&(buf_00->field6_0xc).field0,2);
        *puVar5 = (short)buf;
        net_buf_add((net_buf *)&(buf_00->field6_0xc).field0,(uint)*(ushort *)(in_r2 + 0xc));
        memcpy(puVar5 + 1,*(void **)(in_r2 + 8),(uint)*(ushort *)(in_r2 + 0xc));
        bt_att_set_tx_meta_data
                  (buf_00,*(bt_gatt_complete_func_t *)(in_r2 + 0x10),*(void **)(in_r2 + 0x14),1);
        if (conn == (bt_conn *)0x0) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",3874);
        }
        else {
          if (buf_00 != (net_buf *)0x0) {
            pbVar3 = att_get(conn);
            if (pbVar3 == (bt_att *)0x0) {
              tx_meta_data_free((bt_att_tx_meta_data *)buf_00->user_data);
              net_buf_unref(buf_00);
              iVar4 = -0x80;
            }
            else {
              net_buf_put((k_fifo *)&pbVar3->prep_queue,buf_00);
              piVar6 = *(int **)((int)&pbVar3[1].prep_queue + 2);
              if (piVar6 != (int *)0x0) {
                chan = (bt_att_chan *)(piVar6 + -100);
                pbVar7 = (bt_att_chan *)0x0;
                if (*piVar6 != 0) {
                  pbVar7 = (bt_att_chan *)(*piVar6 + -400);
                }
                while (iVar4 = process_queue(chan,(k_fifo *)&pbVar3->prep_queue), chan = pbVar7,
                      iVar4 != 0) {
                  while( true ) {
                    if (chan == (bt_att_chan *)0x0) goto LAB_0005cd06;
                    pbVar7 = (bt_att_chan *)0x0;
                    if (chan[0xb].chan != 0) {
                      pbVar7 = (bt_att_chan *)(chan[0xb].chan - 400);
                    }
                    if (iVar4 != -2) break;
                    iVar4 = -2;
                    chan = pbVar7;
                  }
                }
              }
LAB_0005cd06:
              iVar4 = 0;
            }
            return iVar4;
          }
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",3875);
        }
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      local_24 = "No buffer available to send notification";
      local_28[0] = '\x02';
      local_28[1] = '\0';
      local_28[2] = '\0';
      local_28[3] = '\0';
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
      iVar4 = -0xc;
    }
    else {
      local_24 = "Device is not subscribed to characteristic";
      local_28[0] = '\x02';
      local_28[1] = '\0';
      local_28[2] = '\0';
      local_28[3] = '\0';
      LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
      iVar4 = -0x16;
    }
  }
  else {
    local_24 = "Link is not encrypted";
    local_28[0] = '\x02';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
    iVar4 = -1;
  }
  return iVar4;
}


