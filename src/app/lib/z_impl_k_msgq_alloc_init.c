/*
 * Function: z_impl_k_msgq_alloc_init
 * Entry:    00089bf8
 * Prototype: int __stdcall z_impl_k_msgq_alloc_init(k_msgq * msgq, size_t msg_size, uint32_t max_msgs)
 */


/* exclude_from_export */

int z_impl_k_msgq_alloc_init(k_msgq *msgq,size_t msg_size,uint32_t max_msgs)

{
  char *buffer;
  int iVar1;
  
  if ((int)((ulonglong)msg_size * (ulonglong)max_msgs >> 0x20) == 0) {
    buffer = z_thread_aligned_alloc(0,(size_t)((ulonglong)msg_size * (ulonglong)max_msgs));
    if (buffer == (char *)0x0) {
      iVar1 = -0xc;
    }
    else {
      k_msgq_init(msgq,buffer,msg_size,max_msgs);
      msgq->flags = 1;
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x16;
  }
  return iVar1;
}


