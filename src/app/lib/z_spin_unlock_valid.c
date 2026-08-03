/*
 * Function: z_spin_unlock_valid
 * Entry:    00075304
 * Prototype: bool __stdcall z_spin_unlock_valid(k_spinlock * l)
 */


/* exclude_from_export */

bool z_spin_unlock_valid(k_spinlock *l)

{
  bool bVar1;
  
  bVar1 = l->thread_cpu == (_current.base | (byte)_current.init_data);
  if (bVar1) {
    l->thread_cpu = 0;
  }
  return bVar1;
}


