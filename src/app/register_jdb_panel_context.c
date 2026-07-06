/*
 * Function: register_jdb_panel_context
 * Entry:    0004aab8
 * Prototype: undefined __stdcall register_jdb_panel_context(jbd_panel_context * panel_context)
 */


void register_jdb_panel_context(jbd_panel_context *panel_context)

{
  jbd_buffer *buffer_holder;
  byte **buf_ptr;
  byte (*pabVar1) [320];
  
  z_impl_k_mutex_init(&lcd_mutex);
  panel_context->init_cb = 0x4a979;
  panel_context->suspend_cb = 0x4a781;
  panel_context->resume_cb = 0x4a8ad;
  panel_context->off_cb = 0x4a721;
  panel_context->on_cb = 0x4a7cd;
  panel_context->a_unknown_panel_cb = 0x36e11;
  panel_context->draw_image_cb = 0x80b9f;
  panel_context->clear_cb = 0x80b93;
  panel_context->set_brightness_cb = 0x4a6dd;
  buffer_holder = malloc(64008);
  pabVar1 = buffer_holder->buffer;
  panel_context->current_buffer = *pabVar1;
  buf_ptr = (byte **)&panel_context->set_brightness_cb;
  do {
    buf_ptr = buf_ptr + 1;
    *buf_ptr = *pabVar1;
    pabVar1 = pabVar1 + 1;
  } while (pabVar1 != (byte (*) [320])&buffer_holder->end);
  panel_context->current_buffer_size = 64000;
  return;
}


