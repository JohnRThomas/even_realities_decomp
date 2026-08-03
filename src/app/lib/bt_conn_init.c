/*
 * Function: bt_conn_init
 * Entry:    0005a604
 * Prototype: int __stdcall bt_conn_init(void)
 */


/* exclude_from_export */

int bt_conn_init(void)

{
  int iVar1;
  bt_conn_tx *pvVar3;
  
  k_queue_init(&free_tx._queue);
  iVar1 = 0;
  pvVar3 = &conn_tx;
  do {
    iVar1 = iVar1 + 1;
    k_queue_append(&free_tx._queue,pvVar3);
    pvVar3 = pvVar3 + 1;
  } while (iVar1 != 10);
  bt_gatt_init();
  iVar1 = bt_smp_init();
  if (iVar1 == 0) {
    bt_l2cap_init();
  }
  return iVar1;
}


