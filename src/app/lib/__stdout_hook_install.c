/*
 * Function: __stdout_hook_install
 * Entry:    000542e4
 * Prototype: void __stdcall __stdout_hook_install(_char_out * hook)
 */


/* exclude_from_export_ai */

void __stdout_hook_install(_char_out *hook)

{
  _stdout_hook = hook;
  return;
}


