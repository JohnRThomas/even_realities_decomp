/*
 * Function: bt_l2cap_chan_remove
 * Entry:    00084f40
 * Prototype: void __stdcall bt_l2cap_chan_remove(bt_conn * conn, bt_l2cap_chan * chan)
 */


/* exclude_from_export */

void bt_l2cap_chan_remove(bt_conn *conn,bt_l2cap_chan *chan)

{
  sys_snode_t **ppsVar1;
  sys_snode_t *prev_node;
  sys_snode_t *node;
  
  if ((sys_snode_t *)conn->channels != (sys_snode_t *)0x0) {
    prev_node = (sys_snode_t *)0x0;
    node = (sys_snode_t *)conn->channels;
    do {
      if (chan == (bt_l2cap_chan *)(node + -2)) {
        sys_slist_remove((sys_slist_t *)&conn->channels,prev_node,node);
        return;
      }
      ppsVar1 = &node->next;
      prev_node = node;
      node = *ppsVar1;
    } while (*ppsVar1 != (sys_snode_t *)0x0);
  }
  return;
}


