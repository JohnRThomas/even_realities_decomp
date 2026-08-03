/*
 * Function: CC_PalInterruptInit
 * Entry:    0007d6d0
 * Prototype: undefined __stdcall CC_PalInterruptInit(void)
 */


/* exclude_from_export_ai */

void CC_PalInterruptInit(void)

{
  int iVar1;
  
  iVar1 = (*nrf_cc3xx_mutex_lock_cb)(nrf_cc3xx_platform_power_mutex);
  if (iVar1 != 0) {
    (*nrf_cc3xx_platform_abort_apis_t_20002f10.abort_fn)("Could not lock power save mutex");
  }
  DAT_2000dd94 = 0;
                    /* WARNING: Could not recover jumptable at 0x0007d6f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*nrf_cc3xx_mutex_unlock_cb)(nrf_cc3xx_platform_power_mutex);
  return;
}


