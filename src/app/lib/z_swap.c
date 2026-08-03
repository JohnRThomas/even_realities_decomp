/*
 * Function: z_swap
 * Entry:    00053480
 * Prototype: int __stdcall z_swap(k_spinlock * lock, k_spinlock_key_t key)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

int z_swap(k_spinlock *lock,k_spinlock_key_t key)

{
  bool bVar1;
  dword dVar2;
  
  dVar2 = _current.base;
  *(k_spinlock **)(_current.base + 0x8c) = lock;
  *(undefined4 *)(dVar2 + 0x90) = 0xfffffff5;
  _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return *(int *)(_current.base + 0x90);
}


