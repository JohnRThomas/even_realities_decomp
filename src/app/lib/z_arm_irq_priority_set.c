/*
 * Function: z_arm_irq_priority_set
 * Entry:    000533b8
 * Prototype: void __stdcall z_arm_irq_priority_set(uint irq, uint prio, uint32_t flags)
 */


/* exclude_from_export */

void z_arm_irq_priority_set(uint irq,uint prio,uint32_t flags)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (prio + 1 < 8) {
    uVar2 = (uint)(char)irq;
    bVar4 = -1 < (int)uVar2;
    if (bVar4) {
      uVar2 = uVar2 + 0xe0000000;
    }
    else {
      flags = (uint32_t)&DAT_e000ed14;
    }
    cVar1 = (char)(prio + 1) * ' ';
    if (bVar4) {
      uVar3 = uVar2 + 0xe100;
      *(char *)(uVar2 + 0xe400) = cVar1;
    }
    else {
      uVar3 = uVar2 & 0xf;
    }
    if (!bVar4) {
      *(char *)(flags + uVar3) = cVar1;
    }
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","prio <= ((1UL << (3)) - 1)",
          "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/irq_manage.c",92);
  _ASSERT("\tinvalid priority %d for %d irq! values must be less than %lu\n\n",(char *)prio,
          (char *)irq,7);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


