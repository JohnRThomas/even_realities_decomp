/*
 * Function: conn_param_on_pref_restore
 * Entry:    00055ad4
 * Prototype: void __stdcall conn_param_on_pref_restore(k_work * work)
 */


/* exclude_from_export */

void conn_param_on_pref_restore(k_work *work)

{
  bt_le_conn_param local_10;
  
  local_10.interval_min = 0x18;
  local_10.interval_max = 0x28;
  local_10.latency = 0;
  local_10.timeout = 0x2a;
  conn_param_set(work[-1].queue,&local_10);
  *(byte *)&work[6].node.next = *(byte *)&work[6].node.next & 0xfe;
  return;
}


