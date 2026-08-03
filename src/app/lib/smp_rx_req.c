/*
 * Function: smp_rx_req
 * Entry:    000559f0
 * Prototype: void __stdcall smp_rx_req(smp_transport * smtp, net_buf * nb)
 */


/* exclude_from_export_ai */

void smp_rx_req(smp_transport *smtp,net_buf *nb)

{
  net_buf_put((k_fifo *)&smtp->expected,nb);
  k_work_submit_to_queue((k_work_q *)&DAT_20005d98,(k_work *)smtp);
  return;
}


