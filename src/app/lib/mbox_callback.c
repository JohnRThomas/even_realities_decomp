/*
 * Function: mbox_callback
 * Entry:    0004f6b8
 * Prototype: void __stdcall mbox_callback(device * instance, uint32_t channel, void * user_data, mbox_msg * msg_data)
 */


/* exclude_from_export */

void mbox_callback(device *instance,uint32_t channel,void *user_data,mbox_msg *msg_data)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t eep;
  code *pcVar3;
  uint uVar4;
  uint chan;
  
  pcVar3 = *(code **)(instance->api + 0x10);
  if ((pcVar3 == (code *)0x0) ||
     (iVar1 = (*pcVar3)(instance,channel,0,pcVar3,instance,channel,user_data), iVar1 != 0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0",
            "WEST_TOPDIR/zephyr/soc/arm/nordic_nrf/nrf53/sync_rtc.c",203);
  }
  else {
    chan = ((uint)user_data & 0xffff) >> 8;
    uVar2 = z_nrf_rtc_timer_compare_read(chan);
    ppi_ipc_to_rtc((rtc_sync_channels)((uint)user_data & 0xff),SUB41((uint)user_data >> 8,0));
    eep = z_nrf_rtc_timer_compare_evt_address_get(chan);
    uVar4 = ((uint)user_data & 0xffffff) >> 0x10;
    if (uVar4 < 0x10) {
      (&Peripherals::IPC_S.SUBSCRIBE_SEND_0_)[uVar4 & 0x3f] = (uint)user_data & 0xff | 0x80000000;
      nrfx_gppi_event_endpoint_setup((uint8_t)user_data,eep);
      z_nrf_rtc_timer_set(chan,(ulonglong)((uVar2 + 0x32) * 2),
                          (z_nrf_rtc_timer_compare_handler_t)0x4f62d,user_data);
      return;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","index < 16",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_ipc.h",481);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


