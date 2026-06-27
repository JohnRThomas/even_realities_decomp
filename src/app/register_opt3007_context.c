/*
 * Function: register_opt3007_context
 * Entry:    0002fd84
 * Prototype: undefined __stdcall register_opt3007_context(opt3007_context * param_1)
 */


void register_opt3007_context(opt3007_context *param_1)

{
  param_1->field22_0x1c = &param_1[-0x22].read_cb;
  param_1->init_cb = (undefined4 *)0x2fb05;
  param_1->read_cb = 0x2fad1;
  return;
}


