/*
 * Function: __printk_hook_install
 * Entry:    0004e460
 * Prototype: void __stdcall __printk_hook_install(_char_out * fn)
 */


/* exclude_from_export_ai */

void __printk_hook_install(_char_out *fn)

{
  _char_out = fn;
  return;
}


