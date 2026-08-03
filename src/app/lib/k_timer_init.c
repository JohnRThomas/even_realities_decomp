/*
 * Function: k_timer_init
 * Entry:    00089ed6
 * Prototype: void __stdcall k_timer_init(k_timer * timer, k_timer_expiry_t expiry_fn, k_timer_stop_t stop_fn)
 */


/* exclude_from_export */

void k_timer_init(k_timer *timer,k_timer_expiry_t expiry_fn,k_timer_stop_t stop_fn)

{
  timer->expiry_fn = expiry_fn;
  timer->stop_fn = stop_fn;
  (timer->wait_q).head = (undefined *)&timer->wait_q;
  (timer->wait_q).tail = (undefined *)&timer->wait_q;
  (timer->timeout).node.next = (void *)0x0;
  (timer->timeout).node.prev = (void *)0x0;
  timer->status = 0;
  timer->user_data = (undefined *)0x0;
  return;
}


