/*
 * Function: bt_smp_connected
 * Entry:    000604fc
 * Prototype: void __stdcall bt_smp_connected(bt_l2cap_chan * chan)
 */


/* exclude_from_export */

void bt_smp_connected(bt_l2cap_chan *chan)

{
  k_work_init_delayable((k_work_delayable *)(chan + 0xe),(void *)0x6168d);
  smp_reset((bt_smp *)(chan + -0xc));
  chan[0x10].node.next = (sys_snode_t *)&DAT_20006630;
  chan[0x10].destroy = (undefined *)0xffffffff;
  return;
}


