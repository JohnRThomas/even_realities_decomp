/*
 * Function: smp_bt_unregister
 * Entry:    00055cb8
 * Prototype: int __stdcall smp_bt_unregister(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export_ai */

int smp_bt_unregister(void)

{
  bt_conn *in_r0;
  conn_param_data *pcVar1;
  int extraout_r0;
  int extraout_r0_00;
  
  pcVar1 = conn_param_data_get(in_r0);
  smp_rx_remove_invalid(_smp_bt_chr_write,in_r0);
  if (pcVar1 != (conn_param_data *)0x0) {
    *(undefined1 *)((int)&pcVar1[5].smp_notify_sem + 1) = 0;
    pcVar1->conn = (undefined *)0x0;
    k_work_cancel_delayable((k_work_delayable *)&pcVar1->ework);
    k_work_cancel_delayable((k_work_delayable *)((int)&pcVar1[3].conn + 2));
    *(undefined1 *)&pcVar1[5].smp_notify_sem = 0;
    k_sem_give((k_sem *)(pcVar1 + 6));
    return extraout_r0;
  }
  bt_smp_disconnected((bt_l2cap_chan *)in_r0);
  return extraout_r0_00;
}


