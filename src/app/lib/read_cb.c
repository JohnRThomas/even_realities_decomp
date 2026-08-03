/*
 * Function: read_cb
 * Entry:    00085730
 * Prototype: void * __stdcall read_cb(uint16_t obj_inst_id, uint16_t res_id, uint16_t res_inst_id, size_t * data_len)
 */


/* exclude_from_export_ai */

void * read_cb(uint16_t obj_inst_id,uint16_t res_id,uint16_t res_inst_id,size_t *data_len)

{
  uint8_t uVar1;
  char cVar2;
  bt_conn *conn;
  uint uVar3;
  undefined4 *puVar4;
  bt_att_chan *chan;
  
  puVar4 = (undefined4 *)(uint)res_inst_id;
  chan = (bt_att_chan *)*puVar4;
  conn = (bt_conn *)chan->ATT_NUM_FLAGS_;
  *(undefined1 *)(puVar4 + 3) = 0;
  uVar1 = bt_gatt_check_perm(conn,(bt_gatt_attr *)(uint)obj_inst_id,0x95);
  *(uint8_t *)(puVar4 + 3) = uVar1;
  if (uVar1 == '\0') {
    uVar3 = att_chan_read(chan,(bt_gatt_attr *)(uint)obj_inst_id,(net_buf *)puVar4[2],
                          *(uint16_t *)(puVar4 + 1),(attr_read_cb)0x0,(void *)0x0);
    if (-1 < (int)uVar3) {
      return &DAT_00000001;
    }
    if (uVar3 < 0xffffff01) {
      cVar2 = '\x0e';
    }
    else {
      cVar2 = -(char)uVar3;
    }
    *(char *)(puVar4 + 3) = cVar2;
  }
  return (void *)0x0;
}


