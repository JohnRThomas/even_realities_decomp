/*
 * Function: bt_l2cap_init
 * Entry:    0005ac7c
 * Prototype: void __stdcall bt_l2cap_init(void)
 */


/* exclude_from_export */

void bt_l2cap_init(void)

{
  undefined *buf;
  int iVar1;
  
  k_queue_init(&free_l2cap_channs._queue);
  iVar1 = 0;
  buf = &l2cap_chan_pool;
  do {
    memset(buf,0,0x10);
    iVar1 = iVar1 + 1;
    k_queue_append(&free_l2cap_channs._queue,buf);
    buf = buf + 0x10;
  } while (iVar1 != 10);
  return;
}


