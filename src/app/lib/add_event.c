/*
 * Function: add_event
 * Entry:    00089f28
 * Prototype: void __stdcall add_event(sys_dlist_t * events, k_poll_event * event, z_poller * poller)
 */


/* exclude_from_export */

void add_event(sys_dlist_t *events,k_poll_event *event,z_poller *poller)

{
  int iVar1;
  k_thread *pkVar2;
  int32_t iVar3;
  undefined4 *puVar4;
  sys_dlist_t *psVar5;
  
  if ((events != (sys_dlist_t *)events->head) && (events->tail != (undefined *)0x0)) {
    iVar1 = *(int *)(events->tail + 8);
    pkVar2 = (k_thread *)0x0;
    if (iVar1 != 0) {
      pkVar2 = (k_thread *)(iVar1 + -0x60);
    }
    iVar3 = z_sched_prio_cmp(pkVar2,(k_thread *)(poller + -0x18));
    if ((iVar3 < 1) && (psVar5 = (sys_dlist_t *)events->head, events != psVar5)) {
      for (; psVar5 != (sys_dlist_t *)0x0; psVar5 = (sys_dlist_t *)psVar5->head) {
        pkVar2 = (k_thread *)0x0;
        if (psVar5[1].head != (undefined *)0x0) {
          pkVar2 = (k_thread *)(psVar5[1].head + -0x60);
        }
        iVar3 = z_sched_prio_cmp((k_thread *)(poller + -0x18),pkVar2);
        if (0 < iVar3) {
          puVar4 = (undefined4 *)psVar5->tail;
          (event->_node).next = psVar5;
          (event->_node).prev = puVar4;
          *puVar4 = event;
          psVar5->tail = (undefined *)event;
          return;
        }
        if (psVar5 == (sys_dlist_t *)events->tail) break;
      }
    }
  }
  puVar4 = (undefined4 *)events->tail;
  (event->_node).next = events;
  (event->_node).prev = puVar4;
  *puVar4 = event;
  events->tail = (undefined *)event;
  return;
}


