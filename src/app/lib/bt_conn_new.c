/*
 * Function: bt_conn_new
 * Entry:    00059550
 * Prototype: bt_conn * __stdcall bt_conn_new(bt_conn * conns, size_t size)
 */


/* exclude_from_export */

bt_conn * bt_conn_new(bt_conn *conns,size_t size)

{
  size_t sVar1;
  
  sVar1 = 0;
  while( true ) {
    if (sVar1 == size) {
      return (bt_conn *)0x0;
    }
    if (conns->ref == 0) break;
    conns = conns + 1;
    sVar1 = sVar1 + 1;
  }
  conns->ref = 1;
  if (conns == (bt_conn *)0x0) {
    return (bt_conn *)0x0;
  }
  memset(conns,0,0xd0);
  k_work_init_delayable(&conns->deferred_work,(void *)0x5a34d);
  k_work_init(&conns->tx_complete_work,&LAB_00084b88_1);
  return conns;
}


