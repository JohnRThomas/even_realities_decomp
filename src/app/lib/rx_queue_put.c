/*
 * Function: rx_queue_put
 * Entry:    000567dc
 * Prototype: void __stdcall rx_queue_put(net_buf * buf)
 */


/* exclude_from_export */

void rx_queue_put(net_buf *buf)

{
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 uStack_20;
  char *pcStack_1c;
  int iStack_18;
  
  net_buf_slist_put((sys_slist_t *)&DAT_20002144,buf);
  iStack_18 = k_work_submit_to_queue((k_work_q *)&DAT_200060e8,(k_work *)&DAT_200029a0);
  if (iStack_18 < 0) {
    pcStack_1c = "Could not submit rx_work: %d";
    uStack_20 = 3;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&uStack_20,3,in_stack_ffffffd0,in_stack_ffffffd4,
            in_stack_ffffffd8);
  }
  return;
}


