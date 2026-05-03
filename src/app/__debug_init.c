/*
 * Function: ?_debug_init
 * Entry:    00019d90
 * Prototype: int __stdcall ?_debug_init(void)
 */


int __debug_init(void)

{
  int iVar1;
  char *fmt;
  
  iVar1 = z_impl_k_msgq_alloc_init((k_msgq *)&DAT_20007ef8,200,0x14);
  if (iVar1 == 0) {
    fmt = "debug init success\r\n";
  }
  else {
    fmt = "debug init failed\r\n";
  }
  printk(fmt);
  return iVar1;
}


