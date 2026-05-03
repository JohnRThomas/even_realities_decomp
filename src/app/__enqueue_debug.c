/*
 * Function: ?_enqueue_debug
 * Entry:    00019dbc
 * Prototype: int __stdcall ?_enqueue_debug(void * param_1)
 */


int __enqueue_debug(void *param_1)

{
  int iVar1;
  
  if (DAT_20007f1c == 0x14) {
    z_impl_k_msgq_get((k_msgq *)&DAT_20007ef8,&DAT_20010cf1,(k_timeout_t)0x0);
  }
  memcpy(&DAT_20010cf1,param_1,200);
  iVar1 = z_impl_k_msgq_put((k_msgq *)&DAT_20007ef8,&DAT_20010cf1,(k_timeout_t)0x0);
  if (iVar1 != 0) {
    printk("enqueue_debug failed\r\n");
  }
  return iVar1;
}


