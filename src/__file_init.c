/*
 * Function: ?_file_init
 * Entry:    000255a0
 * Prototype: int __stdcall ?_file_init(void)
 */


int __file_init(void)

{
  int iVar1;
  char *fmt;
  
  iVar1 = z_impl_k_msgq_alloc_init((k_msgq *)&DAT_20008380,0xc9,0x1e);
  if (iVar1 == 0) {
    fmt = "file init success\r\n";
  }
  else {
    fmt = "file init failed\r\n";
  }
  printk(fmt);
  return iVar1;
}


