/*
 * Function: k_queue_prepend
 * Entry:    00089cc8
 * Prototype: void __stdcall k_queue_prepend(k_queue * queue, void * data)
 */


/* exclude_from_export */

void k_queue_prepend(k_queue *queue,void *data)

{
  queue_insert(queue,(void *)0x0,data,false,false);
  return;
}


