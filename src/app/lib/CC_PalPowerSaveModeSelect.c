/*
 * Function: CC_PalPowerSaveModeSelect
 * Entry:    0007d70c
 * Prototype: CCError_t __stdcall CC_PalPowerSaveModeSelect(CCBool isPowerSaveMode)
 */


/* exclude_from_export */

CCError_t CC_PalPowerSaveModeSelect(CCBool isPowerSaveMode)

{
  int iVar1;
  
  iVar1 = (*nrf_cc3xx_mutex_lock_cb)(nrf_cc3xx_platform_power_mutex);
  if (iVar1 != 0) {
    return 0xffff8fe9;
  }
  if (isPowerSaveMode == 0) {
    if (DAT_2000dd94 == 0) {
      Peripherals::CRYPTOCELL_S.ENABLE = 1;
      do {
        iVar1 = DAT_50845910;
      } while (iVar1 != 0);
    }
    DAT_2000dd94 = DAT_2000dd94 + 1;
  }
  else if (DAT_2000dd94 != 0) {
    if (DAT_2000dd94 == 1) {
      do {
        iVar1 = DAT_50845910;
      } while (iVar1 != 0);
      Peripherals::CRYPTOCELL_S.ENABLE = 0;
      CC_HalMaskInterrupt(0x1ffffff);
    }
    DAT_2000dd94 = DAT_2000dd94 + -1;
    (*nrf_cc3xx_mutex_unlock_cb)(nrf_cc3xx_platform_power_mutex);
    return 0;
  }
  (*nrf_cc3xx_mutex_unlock_cb)(nrf_cc3xx_platform_power_mutex);
  return 0;
}


