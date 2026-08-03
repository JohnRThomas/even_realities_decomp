/*
 * Function: k_msgq_init
 * Entry:    00089bd0
 * Prototype: void __stdcall k_msgq_init(k_msgq * msgq, char * buffer, size_t msg_size, uint32_t max_msgs)
 */


/* exclude_from_export */

void k_msgq_init(k_msgq *msgq,char *buffer,size_t msg_size,uint32_t max_msgs)

{
  msgq->msg_size = msg_size;
  msgq->max_msgs = max_msgs;
  msgq->used_msgs = 0;
  msgq->flags = 0;
  msgq->lock = 0;
  msgq->buffer_end = buffer + max_msgs * msg_size;
  msgq->read_ptr = buffer;
  (msgq->wait_q).head = (undefined *)msgq;
  (msgq->wait_q).tail = (undefined *)msgq;
  (msgq->poll_events).head = (undefined *)&msgq->poll_events;
  (msgq->poll_events).tail = (undefined *)&msgq->poll_events;
  msgq->buffer_start = buffer;
  msgq->write_ptr = buffer;
  return;
}


