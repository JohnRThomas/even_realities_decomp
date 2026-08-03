/*
 * Function: k_work_submit
 * Entry:    00076284
 * Prototype: int __stdcall k_work_submit(k_work * work)
 */


/* exclude_from_export */

int k_work_submit(k_work *work)

{
  int iVar1;
  
  iVar1 = k_work_submit_to_queue((k_work_q *)&k_sys_work_q,work);
  return iVar1;
}


