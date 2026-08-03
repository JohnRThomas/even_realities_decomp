/*
 * Function: z_reschedule_irqlock
 * Entry:    00089de4
 * Prototype: void __stdcall z_reschedule_irqlock(uint32_t key)
 */


/* exclude_from_export */

void z_reschedule_irqlock(uint32_t key)

{
  bool bVar1;
  k_spinlock_key_t in_r1;
  uint uVar2;
  
  if (key == 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1f;
    }
    if (uVar2 == 0) {
      z_swap((k_spinlock *)0x0,in_r1);
      return;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(key);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


