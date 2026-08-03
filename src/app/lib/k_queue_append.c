/*
 * Function: k_queue_append
 * Entry:    00089cb2
 * Prototype: void __stdcall k_queue_append(k_queue * queue, void * data)
 */


/* exclude_from_export */

void k_queue_append(k_queue *queue,void *data)

{
  queue_insert(queue,(void *)0x0,data,false,true);
  return;
}


