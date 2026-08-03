/*
 * Function: l2cap_remove_rx_cid
 * Entry:    00084e18
 * Prototype: bt_l2cap_le_chan * __stdcall l2cap_remove_rx_cid(bt_conn * conn, uint16_t cid)
 */


/* exclude_from_export */

bt_l2cap_le_chan * l2cap_remove_rx_cid(bt_conn *conn,uint16_t cid)

{
  sys_snode_t **ppsVar1;
  sys_snode_t *prev_node;
  sys_snode_t *node;
  
  if ((cid - 0x40 < 0x40) && ((sys_snode_t *)conn->channels != (sys_snode_t *)0x0)) {
    prev_node = (sys_snode_t *)0x0;
    node = (sys_snode_t *)conn->channels;
    do {
      if ((uint)*(ushort *)&node[3].next == (uint)cid) {
        sys_slist_remove((sys_slist_t *)&conn->channels,prev_node,node);
        return (bt_l2cap_le_chan *)(node + -2);
      }
      ppsVar1 = &node->next;
      prev_node = node;
      node = *ppsVar1;
    } while (*ppsVar1 != (sys_snode_t *)0x0);
  }
  return (bt_l2cap_le_chan *)0x0;
}


