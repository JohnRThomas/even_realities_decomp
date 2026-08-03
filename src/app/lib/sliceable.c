/*
 * Function: sliceable
 * Entry:    00076994
 * Prototype: bool __stdcall sliceable(k_thread * thread)
 */


/* exclude_from_export */

bool sliceable(k_thread *thread)

{
  if (*(ushort *)((int)&thread->join_queue + 2) < 0x80) {
    if (_current._60_4_ == 0) {
      return false;
    }
    if (((int)_current._56_4_ <= (int)*(char *)((int)&thread->join_queue + 2)) &&
       (((uint)thread->join_queue & 0x1f00) == 0)) {
      if (thread == (k_thread *)&DAT_20006900) {
        return false;
      }
      return true;
    }
  }
  return false;
}


