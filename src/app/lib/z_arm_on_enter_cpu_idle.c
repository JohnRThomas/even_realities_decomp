/*
 * Function: z_arm_on_enter_cpu_idle
 * Entry:    0004f490
 * Prototype: bool __stdcall z_arm_on_enter_cpu_idle(void)
 */


/* exclude_from_export */

bool z_arm_on_enter_cpu_idle(void)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  uint32_t uVar4;
  uint uVar5;
  
  uVar5 = (DAT_2001e1be + 1) % 5;
  uVar4 = k_cycle_get_32();
  if ((DAT_2001e1bd == '\0') || (7 < uVar4 - *(int *)(&DAT_2000aa94 + uVar5 * 4))) {
    iVar1 = Peripherals::CLOCK_S._276_4_;
    if (iVar1 != 0) {
      Peripherals::CLOCK_S._276_4_ = 0;
      uVar2 = Peripherals::CLOCK_S._276_4_;
      DAT_2001e1be = (byte)uVar5;
      if (uVar5 == 0) {
        DAT_2001e1bd = '\x01';
      }
    }
    uVar5 = (uint)DAT_2001e1be;
    uVar4 = k_cycle_get_32();
    *(uint32_t *)(&DAT_2000aa94 + uVar5 * 4) = uVar4;
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}


