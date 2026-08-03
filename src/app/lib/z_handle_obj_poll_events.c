/*
 * Function: z_handle_obj_poll_events
 * Entry:    0008a03e
 * Prototype: void __stdcall z_handle_obj_poll_events(sys_dlist_t * events, uint32_t state)
 */


/* exclude_from_export */

void z_handle_obj_poll_events(sys_dlist_t *events,uint32_t state)

{
  k_poll_event *event;
  undefined4 *puVar1;
  void *pvVar2;
  
  event = (k_poll_event *)events->head;
  if ((k_poll_event *)events != event) {
    pvVar2 = (event->_node).next;
    puVar1 = (event->_node).prev;
    *puVar1 = pvVar2;
    *(undefined4 **)((int)pvVar2 + 4) = puVar1;
    (event->_node).next = (void *)0x0;
    (event->_node).prev = (void *)0x0;
    signal_poll_event(event,state);
    return;
  }
  return;
}


