/*
 * Function: att_write_cmd
 * Entry:    00085a10
 * Prototype: uint8_t __stdcall att_write_cmd(bt_att_chan * chan, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t att_write_cmd(bt_att_chan *chan,net_buf *buf)

{
  uint8_t uVar1;
  uint16_t handle;
  
  handle = net_buf_pull_le16((net_buf *)&(buf->field6_0xc).field0);
  uVar1 = att_write_rsp(chan,'\0','\0',handle,0,(buf->field6_0xc).field0.data,
                        (buf->field6_0xc).field0.len);
  return uVar1;
}


