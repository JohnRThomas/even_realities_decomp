/*
 * Function: sys_dlist_init
 * Entry:    0008a05a
 * Prototype: void __stdcall sys_dlist_init(sys_dlist_t * list)
 */


/* exclude_from_export_ai */

void sys_dlist_init(sys_dlist_t *list)

{
  list->head = (undefined *)list;
  list->tail = (undefined *)list;
  list[1].head = (undefined *)0x0;
  return;
}


