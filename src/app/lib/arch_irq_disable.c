/*
 * Function: arch_irq_disable
 * Entry:    00053374
 * Prototype: void __stdcall arch_irq_disable(uint irq)
 */


/* exclude_from_export */

void arch_irq_disable(uint irq)

{
  uint uVar1;
  
  uVar1 = (uint)(char)irq;
  if (-1 < (int)uVar1) {
    *(int *)(&DAT_e000e100 + ((uVar1 >> 5) + 0x20) * 4) = 1 << (uVar1 & 0x1f);
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


