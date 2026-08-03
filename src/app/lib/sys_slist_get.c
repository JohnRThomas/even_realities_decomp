/*
 * Function: sys_slist_get
 * Entry:    00085364
 * Prototype: sys_snode_t * __stdcall sys_slist_get(sys_slist_t * list)
 */


/* exclude_from_export */

sys_snode_t * sys_slist_get(sys_slist_t *list)

{
  sys_snode_t *psVar1;
  sys_snode_t *psVar2;
  
  psVar1 = (sys_snode_t *)list->head;
  if (psVar1 != (sys_snode_t *)0x0) {
    psVar2 = psVar1->next;
    list->head = (undefined *)psVar2;
    if (psVar1 == (sys_snode_t *)list->tail) {
      list->tail = (undefined *)psVar2;
    }
  }
  return psVar1;
}


