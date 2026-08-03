/*
 * Function: att_chan_read
 * Entry:    000855e2
 * Prototype: ssize_t __stdcall att_chan_read(bt_att_chan * chan, bt_gatt_attr * attr, net_buf * buf, uint16_t offset, attr_read_cb cb, void * user_data)
 */


/* exclude_from_export_ai */

ssize_t att_chan_read(bt_att_chan *chan,bt_gatt_attr *attr,net_buf *buf,uint16_t offset,
                     attr_read_cb cb,void *user_data)

{
  size_t sVar1;
  net_buf *frag;
  size_t sVar2;
  net_buf_pool *pool;
  size_t sVar3;
  int iVar4;
  int extraout_r1;
  uint extraout_r1_00;
  uint uVar5;
  uint uVar6;
  dword dVar7;
  uint uVar8;
  size_t sVar9;
  k_timeout_t timeout;
  
  uVar8 = (uint)offset;
  sVar1 = net_buf_frags_len(buf);
  uVar6 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
  uVar5 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
  if (uVar5 <= uVar6) {
    uVar6 = uVar5;
  }
  if (sVar1 < uVar6) {
    dVar7 = chan->ATT_NUM_FLAGS_;
    frag = net_buf_frag_last(buf);
    sVar9 = 0;
    while( true ) {
      sVar1 = net_buf_frags_len(buf);
      uVar6 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
      uVar5 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
      if (uVar5 < uVar6) {
        uVar6 = uVar5 - sVar1;
      }
      else {
        uVar6 = uVar6 - sVar1;
      }
      sVar1 = net_buf_simple_tailroom(&(frag->field6_0xc).b);
      if (uVar6 < sVar1) {
        sVar2 = net_buf_frags_len(buf);
        uVar6 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
        uVar5 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
        if (uVar5 < uVar6) {
          sVar2 = uVar5 - sVar2;
        }
        else {
          sVar2 = uVar6 - sVar2;
        }
      }
      else {
        sVar2 = net_buf_simple_tailroom(&(frag->field6_0xc).b);
      }
      if (sVar2 == 0) {
        pool = net_buf_pool_get((uint)buf->pool_id);
        timeout.ticks._4_4_ = 0;
        timeout.ticks._0_4_ = extraout_r1_00;
        frag = net_buf_alloc(pool,timeout);
        if (frag == (net_buf *)0x0) {
          return sVar9;
        }
        net_buf_frag_add(buf,frag);
        sVar1 = net_buf_frags_len(buf);
        uVar6 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
        uVar5 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
        if (uVar5 < uVar6) {
          uVar6 = uVar5 - sVar1;
        }
        else {
          uVar6 = uVar6 - sVar1;
        }
        sVar1 = net_buf_simple_tailroom(&(frag->field6_0xc).b);
        if (uVar6 < sVar1) {
          sVar2 = net_buf_frags_len(buf);
          uVar6 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
          uVar5 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
          if (uVar5 < uVar6) {
            sVar2 = uVar5 - sVar2;
          }
          else {
            sVar2 = uVar6 - sVar2;
          }
        }
        else {
          sVar2 = net_buf_simple_tailroom(&(frag->field6_0xc).b);
        }
      }
      sVar1 = (**(code **)(extraout_r1 + 4))
                        (dVar7,extraout_r1,
                         (frag->field6_0xc).field0.data + (frag->field6_0xc).field0.len,
                         sVar2 & 0xffff,uVar8);
      if ((int)sVar1 < 0) break;
      if ((cb != (attr_read_cb)0x0) && (iVar4 = (*(code *)cb)(frag,sVar1,user_data), iVar4 == 0)) {
        return sVar9;
      }
      net_buf_add((net_buf *)&(frag->field6_0xc).field0,sVar1);
      sVar3 = net_buf_frags_len(buf);
      uVar6 = (uint)*(ushort *)((int)&chan[1].ATT_NUM_FLAGS_ + 2);
      uVar5 = (uint)*(ushort *)((int)&chan->timeout_work + 2);
      if (uVar5 <= uVar6) {
        uVar6 = uVar5;
      }
      sVar9 = sVar9 + sVar1;
      uVar8 = uVar8 + sVar1 & 0xffff;
      if (uVar6 <= sVar3) {
        return sVar9;
      }
      if (sVar1 != sVar2) {
        return sVar9;
      }
    }
    if (sVar9 != 0) {
      sVar1 = sVar9;
    }
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}


