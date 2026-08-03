/*
 * Function: wdt_configure
 * Entry:    0006b02c
 * Prototype: void __stdcall wdt_configure(nrfx_wdt_t * p_instance, nrfx_wdt_config_t * p_config)
 */


/* exclude_from_export */

void wdt_configure(nrfx_wdt_t *p_instance,nrfx_wdt_config_t *p_config)

{
  undefined4 extraout_r0;
  nrfx_wdt_t nVar1;
  uint uVar2;
  
  uVar2 = *(uint *)p_config[1].opaque >> 0x11;
  __aeabi_uldivmod(*(uint *)p_config[1].opaque << 0xf,uVar2,1000,0);
  if (999 < uVar2) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","ticks <= (0xffffffffUL)",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_wdt.c",63);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  nVar1 = *p_instance;
  *(undefined4 *)(nVar1 + 0x50c) = *(undefined4 *)p_config->opaque;
  *(undefined4 *)(nVar1 + 0x504) = extraout_r0;
  if ((&wdt_m_cb)[(byte)p_instance[1]].wdt_event_handler != (nrfx_wdt_event_handler_t *)0x0) {
    nVar1 = *p_instance;
    *(undefined4 *)(nVar1 + 0x100) = 0;
    arch_irq_enable((int)(nVar1 << 0xc) >> 0x18);
    *(undefined4 *)(nVar1 + 0x304) = 1;
  }
  return;
}


