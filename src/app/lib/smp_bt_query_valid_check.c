/*
 * Function: smp_bt_query_valid_check
 * Entry:    000843d8
 * Prototype: bool __stdcall smp_bt_query_valid_check(net_buf * nb, void * arg)
 */


/* exclude_from_export_ai */

bool smp_bt_query_valid_check(net_buf *nb,void *arg)

{
  conn_param_data *pcVar1;
  uint8_t *extraout_r1;
  bool bVar2;
  
  bVar2 = false;
  if ((arg != (void *)0x0) &&
     (pcVar1 = conn_param_data_get(arg), bVar2 = false, pcVar1 != (conn_param_data *)0x0)) {
    if (nb->user_data == extraout_r1) {
      bVar2 = *(char *)((int)&pcVar1[5].smp_notify_sem + 1) == *(char *)&nb[1].node.next;
    }
    else {
      bVar2 = true;
    }
  }
  return bVar2;
}


