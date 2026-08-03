/*
 * Function: k_fifo_peek_head
 * Entry:    00089cdc
 * Prototype: void * __stdcall k_fifo_peek_head(k_fifo * fifo)
 */


/* exclude_from_export */

void * k_fifo_peek_head(k_fifo *fifo)

{
  void *pvVar1;
  
  pvVar1 = z_queue_node_peek((fifo->_queue).data_q.head,false);
  return pvVar1;
}


