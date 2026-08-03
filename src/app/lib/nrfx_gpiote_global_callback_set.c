/*
 * Function: nrfx_gpiote_global_callback_set
 * Entry:    00068b84
 * Prototype: void __stdcall nrfx_gpiote_global_callback_set(nrfx_gpiote_interrupt_handler_t handler, void * p_context)
 */


/* exclude_from_export_ai */

void nrfx_gpiote_global_callback_set(nrfx_gpiote_interrupt_handler_t handler,void *p_context)

{
  DAT_20002be8 = handler;
  DAT_20002bec = p_context;
  return;
}


