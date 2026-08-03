/*
 * Function: bt_att_disconnected
 * Entry:    0005cae0
 * Prototype: void __stdcall bt_att_disconnected(bt_l2cap_chan * chan)
 */


/* exclude_from_export */

void bt_att_disconnected(bt_l2cap_chan *chan)

{
  bool bVar1;
  net_buf *pnVar2;
  bt_conn *conn;
  gatt_sub *sub;
  gatt_cf_cfg *cfg;
  uint extraout_r1;
  uint extraout_r1_00;
  uint uVar3;
  undefined4 extraout_r1_01;
  uint extraout_r1_02;
  uint extraout_r1_03;
  int bit;
  undefined *puVar4;
  undefined4 *puVar5;
  bt_gatt_subscribe_params *params;
  bt_att_req *req;
  bt_conn_le *peer_addr;
  bt_gatt_subscribe_params *pbVar6;
  bt_gatt_subscribe_params *pbVar7;
  sys_snode_t *prev;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  bt_conn *local_30;
  undefined4 local_2c;
  bt_l2cap_chan *local_20;
  
  puVar5 = (undefined4 *)chan[-1].destroy;
  if (puVar5 != (undefined4 *)0x0) {
    local_20 = chan;
    sys_slist_find_and_remove((sys_slist_t *)(puVar5 + 0xc),(sys_snode_t *)&chan[0x13].destroy);
    uVar3 = extraout_r1;
    while (timeout.ticks._4_4_ = 0, timeout.ticks._0_4_ = uVar3,
          pnVar2 = net_buf_get((k_fifo *)&chan[0xe].node,timeout), pnVar2 != (net_buf *)0x0) {
      tx_meta_data_free((bt_att_tx_meta_data *)pnVar2->user_data);
      net_buf_unref(pnVar2);
      uVar3 = extraout_r1_02;
    }
    if (chan[0xe].ops != (undefined *)0x0) {
      att_handle_rsp((bt_att_chan *)&chan[-1].destroy,(void *)0x0,0,'\x0e');
    }
    chan[-1].destroy = (undefined *)0x0;
    atomic_clear_bit((atomic_t *)(chan + 0xe),2);
    if (puVar5[0xc] == 0) {
      while (pnVar2 = net_buf_slist_get((sys_slist_t *)(puVar5 + 10)), pnVar2 != (net_buf *)0x0) {
        tx_meta_data_free((bt_att_tx_meta_data *)pnVar2->user_data);
        net_buf_unref(pnVar2);
      }
      uVar3 = extraout_r1_00;
      while (timeout_00.ticks._4_4_ = 0, timeout_00.ticks._0_4_ = uVar3,
            pnVar2 = net_buf_get((k_fifo *)(puVar5 + 3),timeout_00), pnVar2 != (net_buf *)0x0) {
        tx_meta_data_free((bt_att_tx_meta_data *)pnVar2->user_data);
        net_buf_unref(pnVar2);
        uVar3 = extraout_r1_03;
      }
      while (req = (bt_att_req *)puVar5[1], req != (bt_att_req *)0x0) {
        puVar4 = req->node;
        puVar5[1] = puVar4;
        if (req == (bt_att_req *)puVar5[2]) {
          puVar5[2] = puVar4;
        }
        if ((code *)req->func != (code *)0x0) {
          local_20 = *(bt_l2cap_chan **)((int)&req->user_data + 2);
          (*(code *)req->func)(*puVar5,0xe,0);
        }
        bt_att_req_free(req);
      }
      *puVar5 = 0;
      k_mem_slab_free((k_mem_slab *)&DAT_200038d8,puVar5);
      conn = chan->conn;
      peer_addr = &conn->le;
      local_30 = conn;
      local_2c = extraout_r1_01;
      bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5d671,conn);
      gatt_store_ccc_cf(conn->id,&peer_addr->dst);
      bVar1 = bt_addr_le_is_bonded(conn->id,&peer_addr->dst);
      if (bVar1) {
        local_2c = CONCAT31(local_2c._1_3_,conn->id);
        local_30 = (bt_conn *)peer_addr;
        bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5d581,&local_30);
      }
      sub = gatt_sub_find(conn);
      if ((sub != (gatt_sub *)0x0) &&
         (puVar5 = (undefined4 *)sub->list, puVar5 != (undefined4 *)0x0)) {
        pbVar6 = (bt_gatt_subscribe_params *)*puVar5;
        if (pbVar6 != (bt_gatt_subscribe_params *)0x0) {
          pbVar6 = pbVar6 + -6;
        }
        prev = (sys_snode_t *)0x0;
        params = puVar5 + -6;
        while( true ) {
          pbVar7 = pbVar6;
          atomic_test_and_clear_bit(params + 5,-9);
          bVar1 = bt_addr_le_is_bonded(conn->id,&peer_addr->dst);
          if ((bVar1) && (bVar1 = atomic_test_bit(params + 5,bit), -1 < (int)((uint)bVar1 << 0x1f)))
          {
            if ((sub->peer).type != '\0') {
              bt_addr_le_copy(&sub->peer,&peer_addr->dst);
            }
            prev = (sys_snode_t *)(params + 6);
          }
          else {
            *(undefined2 *)(params + 4) = 0;
            gatt_sub_remove(conn,sub,prev,params);
          }
          if (pbVar7 == (bt_gatt_subscribe_params *)0x0) break;
          pbVar6 = (bt_gatt_subscribe_params *)pbVar7[6];
          params = pbVar7;
          if (pbVar6 != (bt_gatt_subscribe_params *)0x0) {
            pbVar6 = pbVar6 + -6;
          }
        }
      }
      cfg = find_cf_cfg(conn);
      if (cfg != (gatt_cf_cfg *)0x0) {
        bVar1 = bt_addr_le_is_bonded(conn->id,&peer_addr->dst);
        if (bVar1) {
          bt_addr_le_copy(&cfg->peer,&peer_addr->dst);
          return;
        }
        clear_cf_cfg(cfg);
        return;
      }
      return;
    }
  }
  return;
}


