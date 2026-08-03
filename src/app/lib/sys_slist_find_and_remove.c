/*
 * Function: sys_slist_find_and_remove
 * Entry:    00086270
 * Prototype: bool __stdcall sys_slist_find_and_remove(sys_slist_t * list, sys_snode_t * node)
 */


/* exclude_from_export */

bool sys_slist_find_and_remove(sys_slist_t *list,sys_snode_t *node)

{
  sys_snode_t *psVar1;
  sys_snode_t *psVar2;
  
  psVar1 = (sys_snode_t *)0x0;
  psVar2 = (sys_snode_t *)list->head;
  while( true ) {
    if (psVar2 == (sys_snode_t *)0x0) {
      return false;
    }
    if (psVar2 == node) break;
    psVar1 = psVar2;
    psVar2 = psVar2->next;
  }
  psVar2 = node->next;
  if (psVar1 == (sys_snode_t *)0x0) {
    list->head = (undefined *)psVar2;
    if (node == (sys_snode_t *)list->tail) {
      list->tail = (undefined *)psVar2;
    }
  }
  else {
    psVar1->next = psVar2;
    if (node == (sys_snode_t *)list->tail) {
      list->tail = (undefined *)psVar1;
    }
  }
  node->next = (sys_snode_t *)0x0;
  return true;
}


