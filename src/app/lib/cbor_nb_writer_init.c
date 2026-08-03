/*
 * Function: cbor_nb_writer_init
 * Entry:    00083fe8
 * Prototype: void __stdcall cbor_nb_writer_init(cbor_nb_writer * cnw, net_buf * nb)
 */


/* exclude_from_export_ai */

void cbor_nb_writer_init(cbor_nb_writer *cnw,net_buf *nb)

{
  size_t payload_len;
  uint8_t *puVar1;
  
  net_buf_reset(nb);
  cnw->nb = (undefined *)nb;
  (nb->field6_0xc).field0.len = 8;
  puVar1 = (nb->field6_0xc).field0.data;
  payload_len = net_buf_simple_tailroom(&(nb->field6_0xc).b);
  zcbor_new_encode_state((zcbor_state_t *)&cnw->__,2,puVar1 + 8,payload_len,0);
  return;
}


