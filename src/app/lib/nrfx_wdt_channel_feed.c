/*
 * Function: nrfx_wdt_channel_feed
 * Entry:    0006b1c4
 * Prototype: void __stdcall nrfx_wdt_channel_feed(nrfx_wdt_t * p_instance, nrfx_wdt_channel_id channel_id)
 */


/* exclude_from_export */

void nrfx_wdt_channel_feed(nrfx_wdt_t *p_instance,nrfx_wdt_channel_id channel_id)

{
  if ((&wdt_m_cb.state)[(byte)p_instance[1]] != NRFX_DRV_STATE_POWERED_ON) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "m_cb[p_instance->drv_inst_idx].state == NRFX_DRV_STATE_POWERED_ON",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_wdt.c",184);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(undefined4 *)(*p_instance + (channel_id + 0x180) * 4) = 0x6e524635;
  return;
}


