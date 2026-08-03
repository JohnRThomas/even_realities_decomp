/*
 * Function: adjust_owner_prio
 * Entry:    00089c62
 * Prototype: bool __stdcall adjust_owner_prio(k_mutex * mutex, int32_t new_prio)
 */


/* exclude_from_export */

bool adjust_owner_prio(k_mutex *mutex,int32_t new_prio)

{
  bool bVar1;
  
  if (*(char *)((int)&mutex->lock_count + 2) != new_prio) {
    bVar1 = z_set_prio((k_thread *)mutex,new_prio);
    return bVar1;
  }
  return false;
}


