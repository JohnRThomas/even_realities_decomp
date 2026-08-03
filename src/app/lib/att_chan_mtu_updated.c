/*
 * Function: att_chan_mtu_updated
 * Entry:    000853da
 * Prototype: void __stdcall att_chan_mtu_updated(bt_att_chan * updated_chan)
 */


/* exclude_from_export */

void att_chan_mtu_updated(bt_att_chan *updated_chan)

{
  ushort uVar1;
  ushort uVar2;
  ushort tx;
  ushort rx;
  int *piVar3;
  bt_att_chan *pbVar4;
  bt_att_chan *pbVar5;
  bt_att_chan *pbVar6;
  
  piVar3 = *(int **)((int)updated_chan->att + 0x30);
  if (piVar3 != (int *)0x0) {
    pbVar4 = (bt_att_chan *)0x0;
    if (*piVar3 != 0) {
      pbVar4 = (bt_att_chan *)(*piVar3 + -400);
    }
    rx = 0;
    tx = 0;
    pbVar6 = (bt_att_chan *)(piVar3 + -100);
    do {
      pbVar5 = pbVar4;
      if (pbVar6 == updated_chan) goto LAB_0008540c;
      while( true ) {
        uVar1 = *(ushort *)((int)&pbVar6[1].ATT_NUM_FLAGS_ + 2);
        uVar2 = *(ushort *)((int)&pbVar6->timeout_work + 2);
        if (tx < uVar1) {
          tx = uVar1;
        }
        pbVar5 = pbVar4;
        if (rx < uVar2) {
          rx = uVar2;
        }
LAB_0008540c:
        if (pbVar5 == (bt_att_chan *)0x0) goto LAB_0008541c;
        pbVar6 = pbVar5;
        if (pbVar5[0xb].chan != 0) break;
        pbVar4 = (bt_att_chan *)0x0;
        if (pbVar5 == updated_chan) goto LAB_0008541c;
      }
      pbVar4 = (bt_att_chan *)(pbVar5[0xb].chan - 400);
    } while( true );
  }
  tx = 0;
  rx = 0;
LAB_0008541c:
  uVar1 = *(ushort *)((int)&updated_chan[1].ATT_NUM_FLAGS_ + 2);
  uVar2 = *(ushort *)((int)&updated_chan->timeout_work + 2);
  if ((uVar1 <= tx) && (uVar2 <= rx)) {
    return;
  }
  if (rx < uVar2) {
    rx = uVar2;
  }
  if (tx < uVar1) {
    tx = uVar1;
  }
  bt_gatt_att_max_mtu_changed(*(bt_conn **)updated_chan->att,tx,rx);
  return;
}


