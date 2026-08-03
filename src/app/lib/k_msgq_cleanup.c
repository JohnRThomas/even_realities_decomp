/*
 * Function: k_msgq_cleanup
 * Entry:    00089c30
 * Prototype: int __stdcall k_msgq_cleanup(k_msgq * msgq)
 */


/* exclude_from_export */

int k_msgq_cleanup(k_msgq *msgq)

{
  int iVar1;
  k_msgq *pkVar2;
  
  pkVar2 = (k_msgq *)(msgq->wait_q).head;
  if ((msgq == pkVar2) || (pkVar2 == (k_msgq *)0x0)) {
    if ((int)((uint)msgq->flags << 0x1f) < 0) {
      k_free(msgq->buffer_start);
      msgq->flags = msgq->flags & 0xfe;
    }
    iVar1 = 0;
  }
  else {
    iVar1 = -0x10;
  }
  return iVar1;
}


