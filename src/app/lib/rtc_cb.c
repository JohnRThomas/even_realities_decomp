/*
 * Function: rtc_cb
 * Entry:    0004f62c
 * Prototype: void __stdcall rtc_cb(int32_t id, uint64_t cc_value, void * user_data)
 */


/* exclude_from_export */

void rtc_cb(int32_t id,uint64_t cc_value,void *user_data)

{
  nrfx_err_t nVar1;
  uint32_t eep;
  uint uVar2;
  uint chan;
  
  uVar2 = ((uint)user_data & 0xffffff) >> 0x10;
  chan = ((uint)user_data & 0xffff) >> 8;
  eep = z_nrf_rtc_timer_compare_evt_address_get(chan);
  if (uVar2 < 0x10) {
    nrfx_gppi_event_endpoint_clear((uint8_t)user_data,eep);
    (&Peripherals::IPC_S.SUBSCRIBE_SEND_0_)[uVar2 & 0x3f] = 0;
    nrfx_gppi_channels_disable(1 << ((uint)user_data & 0xff));
    z_nrf_rtc_timer_chan_free(chan);
    nVar1 = nrfx_dppi_channel_free((uint8_t)user_data);
    if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == NRFX_SUCCESS",
            "WEST_TOPDIR/zephyr/soc/arm/nordic_nrf/nrf53/sync_rtc.c",117);
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","index < 16",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_ipc.h",481);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


