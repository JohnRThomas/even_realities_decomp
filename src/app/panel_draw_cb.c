/*
 * Function: panel_draw_cb
 * Entry:    00080b9e
 * Prototype: undefined __stdcall panel_draw_cb(jbd_panel_context * param_1)
 */


void panel_draw_cb(jbd_panel_context *param_1)

{
  if (param_1->init_done != 0) {
    display_image((uint16_t)param_1->current_row,(uint16_t)param_1->current_column,
                  param_1->__panel_buffer,param_1->current_buffer_size);
    return;
  }
  return;
}


