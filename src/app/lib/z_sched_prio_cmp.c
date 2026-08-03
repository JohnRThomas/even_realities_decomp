/*
 * Function: z_sched_prio_cmp
 * Entry:    00089dd2
 * Prototype: int32_t __stdcall z_sched_prio_cmp(k_thread * thread_1, k_thread * thread_2)
 */


/* exclude_from_export */

int32_t z_sched_prio_cmp(k_thread *thread_1,k_thread *thread_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)*(char *)((int)&thread_1->join_queue + 2);
  iVar1 = (int)*(char *)((int)&thread_2->join_queue + 2);
  if (iVar2 == iVar1) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 - iVar2;
  }
  return iVar1;
}


