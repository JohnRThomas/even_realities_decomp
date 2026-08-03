/*
 * Function: arch_irq_enable
 * Entry:    00053358
 * Prototype: void __stdcall arch_irq_enable(uint irq)
 */


/* exclude_from_export */

void arch_irq_enable(uint irq)

{
  uint uVar1;
  
  uVar1 = (uint)(char)irq;
  if (-1 < (int)uVar1) {
    *(int *)(&DAT_e000e100 + (uVar1 >> 5) * 4) = 1 << (uVar1 & 0x1f);
  }
  return;
}


