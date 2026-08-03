/*
 * Function: sys_slist_remove
 * Entry:    00084dae
 * Prototype: void __stdcall sys_slist_remove(sys_slist_t * list, sys_snode_t * prev_node, sys_snode_t * node)
 */


/* exclude_from_export */

void sys_slist_remove(sys_slist_t *list,sys_snode_t *prev_node,sys_snode_t *node)

{
  sys_snode_t *psVar1;
  
  psVar1 = node->next;
  if (prev_node == (sys_snode_t *)0x0) {
    list->head = (undefined *)psVar1;
    if (node == (sys_snode_t *)list->tail) {
      list->tail = (undefined *)psVar1;
    }
  }
  else {
    prev_node->next = psVar1;
    if (node == (sys_snode_t *)list->tail) {
      list->tail = (undefined *)prev_node;
    }
  }
  node->next = (sys_snode_t *)0x0;
  return;
}


