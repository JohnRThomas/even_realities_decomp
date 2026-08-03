/*
 * Function: z_nrf_clock_control_lf_on
 * Entry:    00063a2c
 * Prototype: void __stdcall z_nrf_clock_control_lf_on(nrf_lfclk_start_mode start_mode)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void z_nrf_clock_control_lf_on(nrf_lfclk_start_mode start_mode)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = DAT_2000ba7c;
  DAT_2000ba7c = 1;
  if (iVar4 == 0) {
    DAT_2000ba70 = iVar4;
    DAT_2000ba78 = iVar4;
    DAT_2000ba74 = 1;
    iVar4 = onoff_request((onoff_manager *)&DAT_2000baa0,(onoff_client *)&DAT_2000ba6c);
    if (iVar4 < 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err >= 0",
              "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",560);
      goto LAB_00063a68;
    }
  }
  if (start_mode != CLOCK_CONTROL_NRF_LF_START_NOWAIT) {
    if (1 < start_mode - CLOCK_CONTROL_NRF_LF_START_AVAILABLE) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
              "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",578);
LAB_00063a68:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((start_mode != CLOCK_CONTROL_NRF_LF_START_AVAILABLE) ||
       (uVar5 = Peripherals::CLOCK_S.LFCLKSRCCOPY, (uVar5 & 3) != 2)) {
      bVar3 = k_is_in_isr();
      if ((bVar3) || (slice_expired == '\0')) {
        uVar5 = 0;
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          uVar5 = getBasePriority();
        }
        bVar3 = (bool)isCurrentModePrivileged();
        if ((bVar3) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x20 < uVar1)) {
          setBasePriority(0x20);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar3 = true;
      }
      else {
        Peripherals::CLOCK_S.INTENCLR = 2;
        bVar3 = false;
        uVar5 = 0;
      }
      while( true ) {
        uVar1 = Peripherals::CLOCK_S.LFCLKSTAT;
        uVar2 = Peripherals::CLOCK_S.LFCLKSTAT;
        if (((int)(uVar1 << 0xf) < 0) &&
           (((uVar2 & 3) == 2 || (start_mode == CLOCK_CONTROL_NRF_LF_START_AVAILABLE)))) break;
        if (bVar3) {
          arch_cpu_atomic_idle(uVar5);
        }
        else {
          z_impl_k_sleep((k_timeout_t)0x21);
        }
        uVar1 = Peripherals::CLOCK_S.LFCLKSRC;
        if (((uVar1 & 0xff) == 1) && (uVar1 = Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED, uVar1 != 0))
        {
          Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED = 0;
          uVar1 = Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED;
          Peripherals::CLOCK_S.LFCLKSRC = 2;
          _DAT_e000e280 = 0x20;
          Peripherals::CLOCK_S.TASKS_LFCLKSTART = 1;
        }
      }
      if (bVar3) {
        bVar3 = (bool)isCurrentModePrivileged();
        if (bVar3) {
          setBasePriority(uVar5);
        }
        InstructionSynchronizationBarrier(0xf);
      }
      else {
        Peripherals::CLOCK_S.INTENSET = 2;
      }
    }
  }
  return;
}


