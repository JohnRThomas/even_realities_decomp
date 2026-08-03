/*
 * Function: bt_att_recv
 * Entry:    0005bfa8
 * Prototype: int __stdcall bt_att_recv(bt_l2cap_chan * chan, net_buf * buf)
 */


/* exclude_from_export */

int bt_att_recv(bt_l2cap_chan *chan,net_buf *buf)

{
  char cVar1;
  bool bVar2;
  att_type_t aVar3;
  byte *pbVar4;
  net_buf *pnVar5;
  uint16_t extraout_r1;
  uint16_t err;
  int iVar6;
  uint uVar7;
  byte local_58 [4];
  char *local_54;
  uint uStack_50;
  uint local_4c;
  dword local_44;
  byte local_30 [4];
  char *local_2c;
  
  if ((buf->field6_0xc).field0.len == 0) {
    local_2c = "Too small ATT PDU received";
    local_30[0] = 2;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1040,local_30);
  }
  else {
    pbVar4 = net_buf_simple_pull_mem(&(buf->field6_0xc).b,1);
    if (chan[-1].destroy != (undefined *)0x0) {
      iVar6 = 0;
      do {
        if ((&DAT_0008ee44)[iVar6] == *pbVar4) {
          local_44 = chan[0xf].BT_L2CAP_NUM_STATUS_;
          if (local_44 != 0) goto LAB_0005c068;
          pnVar5 = net_buf_ref(buf);
          cVar1 = (&DAT_0008ee46)[iVar6 * 8];
          chan[0xf].BT_L2CAP_NUM_STATUS_ = (dword)pnVar5;
          if (cVar1 == '\x01') {
            bVar2 = atomic_test_and_set_bit((atomic_t *)(chan + 0xe),local_44);
            if (!bVar2) {
LAB_0005c0dc:
              uVar7 = (uint)(buf->field6_0xc).field0.len;
              if (uVar7 < (byte)(&DAT_0008ee45)[iVar6 * 8]) {
                local_4c = (uint)*pbVar4;
                local_54 = "Invalid len %u for code 0x%02x";
                local_58[0] = 4;
                local_58[1] = 0;
                local_58[2] = 0;
                local_58[3] = 0;
                uStack_50 = uVar7;
                LOG_WRN(&PTR_s_bt_att_0008b8b0,0x2040,local_58);
                if ((&DAT_0008ee46)[iVar6 * 8] != '\x01') goto LAB_0005c048;
              }
              else {
                iVar6 = (*(code *)(&PTR_att_mtu_req_1_0008ee48)[iVar6 * 2])(&chan[-1].destroy,buf);
                if ((cVar1 != '\x01') || (iVar6 == 0)) goto LAB_0005c048;
              }
              err = (uint16_t)*pbVar4;
              goto LAB_0005c0be;
            }
            local_2c = "Ignoring unexpected request";
          }
          else {
            if ((cVar1 != '\x05') ||
               (bVar2 = atomic_test_and_set_bit((atomic_t *)(chan + 0xe),1), !bVar2))
            goto LAB_0005c0dc;
            local_2c = "Ignoring unexpected indication";
          }
          local_30[0] = 2;
          local_30[1] = 0;
          local_30[2] = 0;
          local_30[3] = 0;
          LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1080,local_30);
          goto LAB_0005c048;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0x1e);
      if (chan[0xf].BT_L2CAP_NUM_STATUS_ != 0) {
LAB_0005c068:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!att_chan->rsp_buf",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",2900);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      pnVar5 = net_buf_ref(buf);
      chan[0xf].BT_L2CAP_NUM_STATUS_ = (dword)pnVar5;
      uStack_50 = (uint)*pbVar4;
      local_54 = "Unhandled ATT code 0x%02x";
      local_58[0] = 3;
      local_58[1] = 0;
      local_58[2] = 0;
      local_58[3] = 0;
      LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1880,local_58);
      aVar3 = att_op_get_type(*pbVar4);
      if ((aVar3 != 0) && (err = extraout_r1, aVar3 != 5)) {
LAB_0005c0be:
        send_err_rsp((bt_l2cap_chan *)&chan[-1].destroy,err,0);
      }
LAB_0005c048:
      net_buf_unref((net_buf *)chan[0xf].BT_L2CAP_NUM_STATUS_);
      chan[0xf].BT_L2CAP_NUM_STATUS_ = 0;
    }
  }
  return 0;
}


