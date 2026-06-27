/*
 * Function: ?_init_serial_port
 * Entry:    000348f0
 * Prototype: undefined4 __stdcall ?_init_serial_port(void)
 */


undefined4 __init_serial_port(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  void *extraout_r1;
  char *test;
  undefined4 extraout_r2;
  char *file;
  int line;
  
  cVar1 = DAT_2001adf6;
  if (DAT_2001adf6 == '\0') {
    bVar2 = z_device_is_ready(&uart_dev);
    if (!bVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","device_is_ready(lpuart)",
              "../src/production_test/serial_thread.c",0x2e);
      _ASSERT("\tLPUART device not ready\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    iVar3 = lpuart_async_a(0x8b370,extraout_r1,extraout_r2);
    if (iVar3 != 0) {
      DAT_2001adf6 = cVar1;
      printk("init_serial_port is failed\n");
      return 0xffffffff;
    }
    DAT_2001adf6 = '\x01';
  }
  return 0;
}


