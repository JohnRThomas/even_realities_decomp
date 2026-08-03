/*
 * Function: ppi_ipc_to_rtc
 * Entry:    0004f518
 * Prototype: void __stdcall ppi_ipc_to_rtc(rtc_sync_channels channels, bool setup)
 */


/* exclude_from_export */

void ppi_ipc_to_rtc(rtc_sync_channels channels,bool setup)

{
  uint32_t tep;
  uint in_r2;
  int in_r3;
  
  if (0xf < in_r2) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","index < 16",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_ipc.h",487);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  tep = z_nrf_rtc_timer_capture_task_address_get((uint)setup);
  if (in_r3 == 0) {
    nrfx_gppi_task_endpoint_clear(channels.rtc,tep);
    (&Peripherals::IPC_S.PUBLISH_RECEIVE_0_)[in_r2] = 0;
  }
  else {
    nrfx_gppi_task_endpoint_setup(channels.rtc,tep);
    (&Peripherals::IPC_S.PUBLISH_RECEIVE_0_)[in_r2] = channels.raw | 0x80000000;
  }
  return;
}


