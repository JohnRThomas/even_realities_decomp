/*
 * Function: nrfx_ipc_receive_event_disable
 * Entry:    000690f4
 * Prototype: void __stdcall nrfx_ipc_receive_event_disable(uint8_t event_index)
 */


/* exclude_from_export */

void nrfx_ipc_receive_event_disable(uint8_t event_index)

{
  if (DAT_2000bd10 != '\x01') {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","m_cb.state == NRFX_DRV_STATE_INITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_ipc.c",114);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  Peripherals::IPC_S.INTENCLR = 1 << event_index;
  return;
}


