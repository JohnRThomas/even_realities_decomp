/*
 * Function: bt_smp_disconnected
 * Entry:    00086ce4
 * Prototype: void __stdcall bt_smp_disconnected(bt_l2cap_chan * chan)
 */


/* exclude_from_export_ai */

void bt_smp_disconnected(bt_l2cap_chan *chan)

{
  bool bVar1;
  undefined **target;
  bt_keys *keys;
  
  target = &chan[-0xc].ops;
  keys = (bt_keys *)(chan->conn->le).keys;
  k_work_cancel_delayable((k_work_delayable *)(chan + 0xe));
  bVar1 = atomic_test_bit((atomic_t *)target,3);
  if (((bVar1) || (bVar1 = atomic_test_bit((atomic_t *)target,1), bVar1)) ||
     (bVar1 = atomic_test_bit((atomic_t *)target,0xf), bVar1)) {
    smp_pairing_complete((bt_smp *)(chan + -0xc),'\b');
  }
  if ((keys != (bt_keys *)0x0) &&
     (((short)keys->ltk_rand0 == 0 || ((int)((uint)*(byte *)((int)&keys->keys + 1) << 0x1e) < 0))))
  {
    bt_keys_clear(keys);
  }
  memset((bt_smp *)(chan + -0xc),0,0x240);
  return;
}


