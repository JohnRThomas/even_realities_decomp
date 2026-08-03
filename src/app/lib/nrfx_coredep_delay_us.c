/*
 * Function: nrfx_coredep_delay_us
 * Entry:    00054548
 * Prototype: void __stdcall nrfx_coredep_delay_us(uint32_t time_us)
 */


/* exclude_from_export_ai */

void nrfx_coredep_delay_us(uint32_t time_us)

{
  int iVar1;
  int iVar2;
  
  Peripherals::SPU_S.EXTDOMAIN_0__PERM = 0x10;
  iVar1 = Peripherals::FICR_S._304_4_;
  iVar2 = Peripherals::FICR_S._308_4_;
  if ((iVar1 == 7) && ((3 < iVar2 - 2U || ("SRAM_0"[iVar2 + 5] != '\0')))) {
    DAT_50005618 = 1;
    DAT_50005614 = 0;
    arch_busy_wait(5);
    DAT_50005614 = 1;
    arch_busy_wait(1);
    DAT_50005614 = 0;
    DAT_50005618 = 0;
  }
  else {
    DAT_50005614 = 0;
  }
  return;
}


