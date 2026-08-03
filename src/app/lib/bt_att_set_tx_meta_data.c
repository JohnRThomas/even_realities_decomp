/*
 * Function: bt_att_set_tx_meta_data
 * Entry:    00085d64
 * Prototype: void __stdcall bt_att_set_tx_meta_data(net_buf * buf, bt_gatt_complete_func_t func, void * user_data, bt_att_chan_opt chan_opt)
 */


/* exclude_from_export_ai */

void bt_att_set_tx_meta_data
               (net_buf *buf,bt_gatt_complete_func_t func,void *user_data,bt_att_chan_opt chan_opt)

{
  uint8_t *puVar1;
  
  puVar1 = buf->user_data;
  *(bt_gatt_complete_func_t *)(puVar1 + 8) = func;
  *(void **)(puVar1 + 0xc) = user_data;
  puVar1[0x10] = (uint8_t)chan_opt;
  puVar1[4] = '\x01';
  puVar1[5] = '\0';
  return;
}


