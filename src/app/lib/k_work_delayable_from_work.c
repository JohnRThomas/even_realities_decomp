/*
 * Function: k_work_delayable_from_work
 * Entry:    00084cde
 * Prototype: k_work_delayable * __stdcall k_work_delayable_from_work(k_work * work)
 */


/* exclude_from_export */

k_work_delayable * k_work_delayable_from_work(k_work *work)

{
  return (k_work_delayable *)(work + 9);
}


