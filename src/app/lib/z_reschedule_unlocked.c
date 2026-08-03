/*
 * Function: z_reschedule_unlocked
 * Entry:    00089dfc
 * Prototype: undefined __stdcall z_reschedule_unlocked(void)
 */


/* exclude_from_export */

void z_reschedule_unlocked(void)

{
  bool bVar1;
  uint uVar2;
  uint32_t key;
  
  key = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    key = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  z_reschedule_irqlock(key);
  return;
}


