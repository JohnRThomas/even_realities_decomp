/*
 * Function: log_backend_uart_init
 * Entry:    00051228
 * Prototype: void __stdcall log_backend_uart_init(log_backend * backend)
 */


/* exclude_from_export */

void log_backend_uart_init(log_backend *backend)

{
  bool bVar1;
  
  bVar1 = z_device_is_ready(&uart_dev);
  if (!bVar1) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","device_is_ready(uart_dev)",
            "WEST_TOPDIR/zephyr/subsys/logging/backends/log_backend_uart.c",127);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return;
}


