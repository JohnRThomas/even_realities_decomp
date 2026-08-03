/*
 * Function: bt_att_req_free
 * Entry:    0005c9b4
 * Prototype: void __stdcall bt_att_req_free(bt_att_req * req)
 */


/* exclude_from_export_ai */

void bt_att_req_free(bt_att_req *req)

{
  if (req->buf != (undefined *)0x0) {
    tx_meta_data_free(*(bt_att_tx_meta_data **)(req->buf + 0x18));
    net_buf_unref((net_buf *)req->buf);
    req->buf = (undefined *)0x0;
  }
  k_mem_slab_free((k_mem_slab *)&DAT_20003938,req);
  return;
}


