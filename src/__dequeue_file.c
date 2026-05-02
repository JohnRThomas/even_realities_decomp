/*
 * Function: ?_dequeue_file
 * Entry:    0002565c
 * Prototype: int __stdcall ?_dequeue_file(void * param_1)
 */


int __dequeue_file(void *param_1)

{
  int iVar1;
  undefined1 auStack_dc [208];
  
  iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_20008380,auStack_dc,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    memcpy(param_1,auStack_dc,0xc9);
  }
  else {
    printk("dequeue_file failed\r\n");
  }
  return iVar1;
}


