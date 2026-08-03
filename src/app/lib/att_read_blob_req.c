/*
 * Function: att_read_blob_req
 * Entry:    00085b1e
 * Prototype: uint8_t __stdcall att_read_blob_req(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_read_blob_req(bt_att_chan *chan,net_buf *buf)

{
  uint8_t uVar1;
  uint16_t *puVar2;
  
  puVar2 = (uint16_t *)(buf->field6_0xc).field0.data;
  uVar1 = att_read_rsp(chan,'\f','\r',*puVar2,puVar2[1]);
  return uVar1;
}


