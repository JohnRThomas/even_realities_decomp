/*
 * Function: __l2cap_lookup_ident
 * Entry:    00084dde
 * Prototype: bt_l2cap_le_chan * __stdcall __l2cap_lookup_ident(bt_conn * conn, uint16_t ident, bool remove)
 */


/* exclude_from_export */

bt_l2cap_le_chan * __l2cap_lookup_ident(bt_conn *conn,uint16_t ident,bool remove)

{
  sys_snode_t **ppsVar1;
  sys_snode_t *node;
  sys_snode_t *prev_node;
  
  if ((sys_snode_t *)conn->channels != (sys_snode_t *)0x0) {
    prev_node = (sys_snode_t *)0x0;
    node = (sys_snode_t *)conn->channels;
    do {
      if (*(byte *)&node[0x2c].next == ident) {
        if (!remove) {
          return (bt_l2cap_le_chan *)(node + -2);
        }
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


