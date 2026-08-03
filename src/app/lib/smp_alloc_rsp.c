/*
 * Function: smp_alloc_rsp
 * Entry:    0008429e
 * Prototype: void * __stdcall smp_alloc_rsp(void * req, void * arg)
 */


/* exclude_from_export_ai */

void * smp_alloc_rsp(void *req,void *arg)

{
  net_buf *pnVar1;
  
  pnVar1 = smp_packet_alloc();
  if (pnVar1 != (net_buf *)0x0) {
    if (*(code **)((int)arg + 0x34) == (code *)0x0) {
      memcpy(&pnVar1->user_data,(void *)((int)req + 0x18),(uint)*(byte *)((int)req + 0xb));
    }
    else {
      (**(code **)((int)arg + 0x34))(pnVar1,req);
    }
  }
  return pnVar1;
}


