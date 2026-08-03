/*
 * Function: att_handle_rsp
 * Entry:    0005c9dc
 * Prototype: uint8_t __stdcall att_handle_rsp(bt_att_chan * chan, void * pdu, uint16_t len, uint8_t err)
 */


/* exclude_from_export */

uint8_t att_handle_rsp(bt_att_chan *chan,void *pdu,uint16_t len,uint8_t err)

{
  undefined *puVar1;
  bt_att *att;
  code *pcVar2;
  undefined4 uVar3;
  byte local_28 [4];
  char *local_24;
  
  k_work_cancel_delayable((k_work_delayable *)&chan[9].timeout_work);
  puVar1 = (undefined *)chan[8].chan;
  if (puVar1 == (undefined *)0x0) {
    local_24 = "No pending ATT request";
    local_28[0] = 2;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1080,local_28);
  }
  else {
    if (puVar1 != &DAT_2000b880) {
      pcVar2 = *(code **)(puVar1 + 4);
      *(undefined4 *)(puVar1 + 4) = 0;
      uVar3 = *(undefined4 *)((int)&((bt_att_req *)chan[8].chan)->user_data + 2);
      bt_att_req_free((bt_att_req *)chan[8].chan);
      att = (bt_att *)chan->att;
      chan[8].chan = 0;
      att_req_send_process(att);
      if (pcVar2 == (code *)0x0) {
        return '\0';
      }
      (*pcVar2)(*(undefined4 *)chan->att,err,pdu,len,uVar3);
      return '\0';
    }
    chan[8].chan = 0;
  }
  att_req_send_process((bt_att *)chan->att);
  return '\0';
}


