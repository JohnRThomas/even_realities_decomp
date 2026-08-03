/*
 * Function: z_spin_lock_set_owner
 * Entry:    00075320
 * Prototype: void __stdcall z_spin_lock_set_owner(k_spinlock * l)
 */


/* exclude_from_export */

void z_spin_lock_set_owner(k_spinlock *l)

{
  l->thread_cpu = _current.base | (byte)_current.init_data;
  return;
}


