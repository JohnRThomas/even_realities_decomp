/*
 * Function: adc_init
 * Entry:    00062c34
 * Prototype: undefined4 __stdcall adc_init(void)
 */


/* exclude_from_export */

undefined4 adc_init(void)

{
  uint uVar1;
  
  Peripherals::SAADC_S.EVENTS_END = 0;
  uVar1 = Peripherals::SAADC_S.EVENTS_END;
  Peripherals::SAADC_S.EVENTS_CALIBRATEDONE = 0;
  uVar1 = Peripherals::SAADC_S.EVENTS_CALIBRATEDONE;
  Peripherals::SAADC_S.INTENSET = 0x12;
  arch_irq_enable(0xe);
  z_arm_irq_priority_set(0xe,1,0);
  if (DAT_200021d8 == 0) {
    k_sem_give((k_sem *)&DAT_200021d0);
  }
  return 0;
}


