/*
 * Function: uart_console_init
 * Entry:    00063b68
 * Prototype: int __stdcall uart_console_init(void)
 */


/* exclude_from_export_ai */

int uart_console_init(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = z_device_is_ready(&uart_dev);
  if (bVar1) {
    __stdout_hook_install((_char_out *)0x63b91);
    __printk_hook_install((_char_out *)0x63b91);
    iVar2 = 0;
  }
  else {
    iVar2 = -0x13;
  }
  return iVar2;
}


