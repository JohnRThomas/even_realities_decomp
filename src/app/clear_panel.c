/*
 * Function: ?_clear_panel
 * Entry:    00080b92
 * Prototype: undefined __stdcall ?_clear_panel(int param_1)
 */


void __clear_panel(int param_1)

{
  memset(*(void **)(param_1 + 36),0,*(size_t *)(param_1 + 848));
  return;
}


