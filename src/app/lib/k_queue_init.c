/*
 * Function: k_queue_init
 * Entry:    00089c98
 * Prototype: void __stdcall k_queue_init(k_queue * queue)
 */


/* exclude_from_export */

void k_queue_init(k_queue *queue)

{
  (queue->data_q).head = (sys_sfnode_t *)0x0;
  (queue->data_q).tail = (sys_sfnode_t *)0x0;
  (queue->lock).thread_cpu = 0;
  (queue->wait_q).next = &queue->wait_q;
  (queue->wait_q).prev = &queue->wait_q;
  (queue->poll_events).next = &queue->poll_events;
  (queue->poll_events).prev = &queue->poll_events;
  return;
}


