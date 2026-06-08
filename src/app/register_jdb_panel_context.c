/*
 * Function: register_jdb_panel_context
 * Entry:    0004aab8
 * Prototype: undefined __stdcall register_jdb_panel_context(jdb_panel_context * panel_context)
 */


void register_jdb_panel_context(jdb_panel_context *panel_context)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  
  z_impl_k_mutex_init(&lcd_mutex);
  panel_context->init_cb = 0x4a979;
  panel_context->suspend_cb = 0x4a781;
  panel_context->resume_cb = 0x4a8ad;
  panel_context->off_cb = 0x4a721;
  panel_context->on_cb = 0x4a7cd;
  panel_context->field5_0x14 = 0x36e11;
  panel_context->field6_0x18 = 0x80b9f;
  panel_context->clear_cb = 0x80b93;
  panel_context->set_brightness_cb = 0x4a6dd;
  pvVar1 = malloc(0xfa08);
  iVar3 = (int)pvVar1 + 5;
  panel_context->field806_0x344 = iVar3;
  piVar2 = &panel_context->set_brightness_cb;
  do {
    piVar2 = piVar2 + 1;
    *piVar2 = iVar3;
    iVar3 = iVar3 + 0x140;
  } while (iVar3 != (int)pvVar1 + 0xfa05);
  panel_context->__timeout = 64000;
  return;
}


