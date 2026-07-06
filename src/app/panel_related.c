/*
 * Function: ?_panel_related
 * Entry:    00036e10
 * Prototype: int __stdcall ?_panel_related(jbd_panel_context * panel_context, int buffer_index, undefined4 param_3)
 */


int __panel_related(jbd_panel_context *panel_context,int buffer_index,undefined4 param_3)

{
  int iVar1;
  
  if (panel_context[1].field_0x103 == '\0') {
    iVar1 = -1;
  }
  else {
    panel_context->current_row = 0;
    panel_context->current_column = 176;
    if ((buffer_index == 7) || ((*(code *)panel_context->clear_cb)(), buffer_index - 1U < 20)) {
                    /* (index - 1) * 16 */
      iVar1 = buffer_index + 0xfffffff;
      if ((jbd_something_ARRAY_20002434[iVar1].field0_0x0 != 0) &&
         ((code *)jbd_something_ARRAY_20002434[iVar1].field2_0x8 != (code *)0x0)) {
        (*(code *)jbd_something_ARRAY_20002434[iVar1].field2_0x8)(param_3);
      }
      (*(code *)jbd_something_ARRAY_20002434[iVar1].field1_0x4)(panel_context,param_3);
    }
    if (panel_context->init_done != 0) {
      (*(code *)panel_context->draw_image_cb)(panel_context);
    }
    iVar1 = 0;
  }
  return iVar1;
}


