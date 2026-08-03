/*
 * Function: z_spin_lock_valid
 * Entry:    000752e8
 * Prototype: bool __stdcall z_spin_lock_valid(k_spinlock * l)
 */


/* exclude_from_export */

bool z_spin_lock_valid(k_spinlock *l)

{
  if (l->thread_cpu != 0) {
    return (l->thread_cpu & 3) != (uint)(byte)_current.init_data;
  }
  return true;
}


