/*
 * Function: ?_init_serial_comm
 * Entry:    00034954
 * Prototype: undefined4 __stdcall ?_init_serial_comm(void)
 */


undefined4 __init_serial_comm(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __init_serial_port();
  if (iVar1 == 0) {
    iVar1 = FUN_00034694(&uart_dev);
    if (iVar1 == 0) {
      iVar1 = process_pt_data(0);
      uVar2 = 0;
      if (iVar1 != 0) {
        uVar2 = 0xfffffffd;
      }
    }
    else {
      printk("init_serial_comm is failed\n");
      z_impl_k_sleep((k_timeout_t)0x4000);
      uVar2 = 0xfffffffe;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


