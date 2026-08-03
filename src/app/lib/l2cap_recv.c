/*
 * Function: l2cap_recv
 * Entry:    0005b05c
 * Prototype: int __stdcall l2cap_recv(bt_l2cap_chan * chan, net_buf * buf)
 */


/* WARNING: Removing unreachable block (ram,0x0005b3c6) */
/* exclude_from_export */

int l2cap_recv(bt_l2cap_chan *chan,net_buf *buf)

{
  byte bVar1;
  ushort uVar2;
  uint16_t credits;
  ushort cid;
  uint16_t len;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  bool bVar6;
  void *pvVar7;
  bt_l2cap_server *pbVar8;
  int iVar9;
  net_buf *pnVar10;
  undefined2 *puVar11;
  atomic_val_t aVar12;
  bt_l2cap_le_chan *pbVar13;
  net_buf *pnVar14;
  undefined1 *puVar15;
  bt_security_t sec;
  uint16_t uVar16;
  uint uVar17;
  uint16_t *puVar18;
  uint8_t *puVar19;
  undefined4 *puVar20;
  int extraout_r2;
  int extraout_r2_00;
  net_buf *extraout_r2_01;
  net_buf *extraout_r2_02;
  int extraout_r2_03;
  net_buf *extraout_r2_04;
  uint16_t len_00;
  uint16_t len_01;
  uint *target;
  short sVar21;
  bt_conn *pbVar22;
  byte local_60 [4];
  char *local_5c;
  bt_l2cap_le_chan *local_44;
  uint16_t local_40;
  uint16_t local_3e;
  byte local_30 [4];
  char *local_2c;
  
  if ((buf->field6_0xc).field0.len < 4) {
    local_2c = "Too small L2CAP signaling PDU";
    goto LAB_0005b070;
  }
  pvVar7 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,4);
  uVar2 = (buf->field6_0xc).field0.len;
  if (uVar2 != *(ushort *)((int)pvVar7 + 2)) {
    local_5c = "L2CAP length mismatch (%u != %u)";
LAB_0005b0b0:
    local_60[0] = 4;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 0;
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x2040,local_60);
    return 0;
  }
  bVar1 = *(byte *)((int)pvVar7 + 1);
  if (bVar1 == 0) {
    local_2c = "Invalid ident value in L2CAP PDU";
    goto LAB_0005b070;
  }
  bVar6 = *(bool *)pvVar7;
  if (bVar6 == 1) {
    pbVar13 = __l2cap_lookup_ident(chan->conn,(ushort)bVar1,bVar6);
LAB_0005b49a:
    if (pbVar13 == (bt_l2cap_le_chan *)0x0) {
      return 0;
    }
    goto LAB_0005b3e2;
  }
  uVar17 = bVar6 - 6;
  if ((uVar17 & 0xff) < 0x11) {
    switch(uVar17) {
    case 0:
      pbVar22 = chan->conn;
      puVar18 = (uint16_t *)(buf->field6_0xc).field0.data;
      if (uVar2 < 4) goto LAB_0005b11c;
      pbVar13 = l2cap_remove_rx_cid(pbVar22,*puVar18);
      if (pbVar13 == (bt_l2cap_le_chan *)0x0) {
        local_40 = puVar18[1];
        local_3e = *puVar18;
        pnVar10 = l2cap_create_le_sig_pdu((net_buf *)&DAT_00000001,bVar1,'\x06',local_3e);
        if (pnVar10 == (net_buf *)0x0) {
          return 0;
        }
        puVar15 = net_buf_add((net_buf *)&(pnVar10->field6_0xc).field0,2);
        puVar15[1] = 0;
        *puVar15 = 2;
        net_buf_add_mem((net_buf *)&(pnVar10->field6_0xc).field0,&local_40,4);
        pnVar14 = extraout_r2_01;
      }
      else {
        pnVar10 = l2cap_create_le_sig_pdu((net_buf *)&DAT_00000007,bVar1,'\x04',len_00);
        if (pnVar10 == (net_buf *)0x0) {
          return 0;
        }
        puVar11 = net_buf_add((net_buf *)&(pnVar10->field6_0xc).field0,4);
        *puVar11 = *(undefined2 *)((int)&pbVar13->tx_buf + 2);
        puVar11[1] = *(undefined2 *)((int)&pbVar13->rx_work + 2);
        bt_l2cap_chan_del((bt_l2cap_chan *)pbVar13);
        pnVar14 = extraout_r2_02;
      }
      uVar16 = (uint16_t)pnVar10;
      goto LAB_0005b458;
    case 1:
      if (3 < uVar2) {
        pbVar13 = l2cap_remove_rx_cid(chan->conn,*(uint16_t *)((buf->field6_0xc).field0.data + 2));
        goto LAB_0005b49a;
      }
      local_2c = "Too small LE disconn rsp packet size";
      break;
    default:
      goto switchD_0005b0e4_caseD_2;
    case 0xd:
      if (1 < uVar2) {
        return 0;
      }
      local_2c = "Too small LE conn param rsp";
      break;
    case 0xe:
      pbVar22 = chan->conn;
      puVar18 = (uint16_t *)(buf->field6_0xc).field0.data;
      if (9 < uVar2) {
        uVar2 = puVar18[2];
        cid = puVar18[1];
        len = puVar18[3];
        uVar16 = *puVar18;
        credits = puVar18[4];
        if ((uVar2 < 0x17) || (len < 0x17)) {
          local_5c = "Invalid LE-Conn Req params: mtu %u mps %u";
          goto LAB_0005b0b0;
        }
        pnVar14 = l2cap_create_le_sig_pdu((net_buf *)&DAT_00000015,bVar1,'\n',len);
        if (pnVar14 == (net_buf *)0x0) {
          return 0;
        }
        puVar20 = net_buf_add((net_buf *)&(pnVar14->field6_0xc).field0,10);
        *puVar20 = 0;
        puVar20[1] = 0;
        *(undefined2 *)(puVar20 + 2) = 0;
        pbVar8 = bt_l2cap_server_lookup_psm(uVar16);
        if (pbVar8 == (bt_l2cap_server *)0x0) {
LAB_0005b180:
          sVar21 = 2;
          goto LAB_0005b182;
        }
        if (pbVar22->sec_level < pbVar8->sec_level) {
          if ((pbVar22->sec_level < 2) && (bVar6 = bt_conn_ltk_present(pbVar22), bVar6)) {
            sVar21 = 8;
          }
          else {
            sVar21 = 5;
          }
          goto LAB_0005b182;
        }
        if (0x3f < cid - 0x40) {
          sVar21 = 9;
          goto LAB_0005b182;
        }
        local_44 = (bt_l2cap_le_chan *)bt_l2cap_le_lookup_tx_cid(pbVar22,cid);
        if (local_44 != (bt_l2cap_le_chan *)0x0) {
          sVar21 = 10;
          goto LAB_0005b182;
        }
        iVar9 = (*(code *)pbVar8->accept)(pbVar22,&local_44);
        pbVar13 = local_44;
        if (iVar9 < 0) {
          if (iVar9 == -0xc) {
LAB_0005b204:
            sVar21 = 4;
            goto LAB_0005b182;
          }
          if (iVar9 < -0xb) {
            if (iVar9 == -0x86) goto LAB_0005b180;
            if (iVar9 == -0xd) {
              sVar21 = 6;
              goto LAB_0005b182;
            }
          }
          else if (iVar9 == -1) {
            sVar21 = 7;
            goto LAB_0005b182;
          }
        }
        else {
          if (*(int *)(local_44->rx + 0x14) != 0) {
            *(byte *)((int)&local_44[3].chan + 2) = pbVar8->sec_level;
            bVar6 = l2cap_chan_add(pbVar22,(bt_l2cap_chan *)local_44,
                                   (bt_l2cap_chan_destroy_t)0x84e67);
            if (bVar6) {
              l2cap_chan_tx_init(pbVar13);
              *(ushort *)&pbVar13->rx_queue = uVar2;
              *(ushort *)((int)&pbVar13->rx_work + 2) = cid;
              *(uint16_t *)((int)&pbVar13->rx_queue + 2) = len;
              l2cap_chan_tx_give_credits((bt_l2cap_chan *)pbVar13,credits);
              l2cap_chan_rx_init(pbVar13);
              sVar21 = 0;
              *(word *)((int)&pbVar13[2].rtx_sync + 3) = pbVar8->psm;
              *(undefined1 *)((int)&local_44[2].rtx_sync + 1) = 3;
              *(undefined2 *)puVar20 = *(undefined2 *)((int)&local_44->tx_buf + 2);
              *(undefined2 *)(puVar20 + 1) = *(undefined2 *)((int)&local_44->tx_work + 2);
              *(short *)((int)puVar20 + 2) = (short)local_44->tx_work;
              *(short *)((int)puVar20 + 6) = (short)*(undefined4 *)((int)&local_44->_sdu + 2);
              goto LAB_0005b182;
            }
            goto LAB_0005b204;
          }
          local_2c = "Mandatory callback \'recv\' missing";
          local_30[0] = 2;
          local_30[1] = 0;
          local_30[2] = 0;
          local_30[3] = 0;
          LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1040,local_30);
        }
        sVar21 = 0xb;
LAB_0005b182:
        *(short *)(puVar20 + 2) = sVar21;
        iVar9 = bt_l2cap_send_cb(pbVar22,5,pnVar14,(bt_conn_tx_cb_t)0x0,(void *)0x0);
        if (iVar9 != 0) {
          net_buf_unref(pnVar14);
          return 0;
        }
        if (sVar21 != 0) {
          return 0;
        }
        if (*(code **)local_44->rx == (code *)0x0) {
          return 0;
        }
        (**(code **)local_44->rx)();
        return 0;
      }
LAB_0005b11c:
      local_2c = "Too small LE conn req packet size";
      break;
    case 0xf:
      pbVar22 = chan->conn;
      puVar19 = (buf->field6_0xc).field0.data;
      if (9 < uVar2) {
        uVar16 = *(uint16_t *)(puVar19 + 6);
        uVar3 = *(undefined2 *)(puVar19 + 2);
        uVar4 = *(undefined2 *)(puVar19 + 4);
        uVar2 = *(ushort *)(puVar19 + 8);
        uVar5 = *(undefined2 *)puVar19;
        if (((uVar2 & 0xfff7) == 0) || (uVar2 == 5)) {
          pbVar13 = __l2cap_lookup_ident(pbVar22,(ushort)bVar1,false);
          if (pbVar13 == (bt_l2cap_le_chan *)0x0) goto LAB_0005b2de;
          k_work_cancel_delayable((k_work_delayable *)((int)&pbVar13[3].pending_rx_mtu + 1));
          *(undefined1 *)((int)&pbVar13[3].chan + 1) = 0;
          if (uVar2 != 5) goto LAB_0005b348;
          target = (uint *)((int)&pbVar13->tx_queue + 2);
          aVar12 = atomic_get((atomic_t *)target);
          if (-1 < aVar12 << 0x1d) {
            bVar1 = *(byte *)(extraout_r2 + 9);
            if (bVar1 < 2) goto LAB_0005b3ee;
            if (bVar1 == 2) {
              sec = 3;
            }
            else {
              if (bVar1 != 3) goto LAB_0005b3d8;
              sec = 4;
            }
            goto LAB_0005b3a8;
          }
        }
        else {
          pbVar13 = __l2cap_lookup_ident(pbVar22,(ushort)bVar1,true);
          if (pbVar13 == (bt_l2cap_le_chan *)0x0) {
LAB_0005b2de:
            local_5c = "Cannot find channel for ident %u";
            local_60[0] = 3;
            local_60[1] = 0;
            local_60[2] = 0;
            local_60[3] = 0;
            LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1840,local_60);
            return 0;
          }
          k_work_cancel_delayable((k_work_delayable *)((int)&pbVar13[3].pending_rx_mtu + 1));
          *(undefined1 *)((int)&pbVar13[3].chan + 1) = 0;
LAB_0005b348:
          if (uVar2 != 8) {
            if (uVar2 == 0) {
              *(undefined1 *)((int)&pbVar13[2].rtx_sync + 1) = 3;
              puVar20 = (undefined4 *)pbVar13->rx;
              *(undefined2 *)((int)&pbVar13->rx_work + 2) = uVar5;
              *(undefined2 *)&pbVar13->rx_queue = uVar3;
              *(undefined2 *)((int)&pbVar13->rx_queue + 2) = uVar4;
              if ((code *)*puVar20 != (code *)0x0) {
                (*(code *)*puVar20)(pbVar13);
              }
              l2cap_chan_tx_give_credits((bt_l2cap_chan *)pbVar13,uVar16);
              return 0;
            }
            goto LAB_0005b3e2;
          }
          target = (uint *)((int)&pbVar13->tx_queue + 2);
          aVar12 = atomic_get((atomic_t *)target);
          if ((-1 < aVar12 << 0x1d) && (*(byte *)(extraout_r2_00 + 9) < 2)) {
LAB_0005b3ee:
            sec = 2;
LAB_0005b3a8:
            iVar9 = bt_conn_set_security((bt_conn *)pbVar13->chan,sec);
            if (-1 < iVar9) {
              *target = *target | 4;
              return 0;
            }
          }
        }
LAB_0005b3d8:
        bt_l2cap_chan_remove(pbVar22,(bt_l2cap_chan *)pbVar13);
LAB_0005b3e2:
        bt_l2cap_chan_del((bt_l2cap_chan *)pbVar13);
        return 0;
      }
      local_2c = "Too small LE conn rsp packet size";
      break;
    case 0x10:
      if (uVar2 < 4) {
        local_2c = "Too small LE Credits packet size";
      }
      else {
        pbVar13 = (bt_l2cap_le_chan *)
                  bt_l2cap_le_lookup_tx_cid(chan->conn,*(uint16_t *)(buf->field6_0xc).field0.data);
        if (pbVar13 != (bt_l2cap_le_chan *)0x0) {
          aVar12 = atomic_get((atomic_t *)((int)&pbVar13->state + 2));
          if (0xffff < aVar12 + extraout_r2_03) {
            local_2c = "Credits overflow";
            local_30[0] = 2;
            local_30[1] = 0;
            local_30[2] = 0;
            local_30[3] = 0;
            LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1040,local_30);
            bt_l2cap_chan_disconnect((bt_l2cap_chan *)pbVar13);
            return 0;
          }
          l2cap_chan_tx_give_credits((bt_l2cap_chan *)pbVar13,(uint16_t)extraout_r2_03);
          l2cap_chan_tx_resume(pbVar13);
          return 0;
        }
        local_2c = "Unable to find channel of LE Credits packet";
      }
    }
LAB_0005b070:
    local_30[0] = 2;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1040,local_30);
  }
  else {
switchD_0005b0e4_caseD_2:
    local_5c = "Rejecting unknown L2CAP PDU code 0x%02x";
    local_60[0] = 3;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 0;
    LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1880,local_60);
    pbVar22 = chan->conn;
    pnVar14 = l2cap_create_le_sig_pdu
                        ((net_buf *)&DAT_00000001,*(uint8_t *)((int)pvVar7 + 1),'\x02',len_01);
    if (pnVar14 == (net_buf *)0x0) {
      return 0;
    }
    puVar15 = net_buf_add((net_buf *)&(pnVar14->field6_0xc).field0,2);
    uVar16 = (uint16_t)pnVar14;
    *puVar15 = 0;
    puVar15[1] = 0;
    pnVar14 = extraout_r2_04;
LAB_0005b458:
    l2cap_send(pbVar22,uVar16,pnVar14);
  }
  return 0;
}


