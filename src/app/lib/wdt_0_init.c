/*
 * Function: wdt_0_init
 * Entry:    00066db8
 * Prototype: undefined4 __stdcall wdt_0_init(int param_1)
 */


/* exclude_from_export */

undefined4 wdt_0_init(int param_1)

{
  nrfx_err_t nVar1;
  undefined4 uVar2;
  nrfx_wdt_t *p_instance;
  
  p_instance = *(nrfx_wdt_t **)(param_1 + 4);
  z_arm_irq_priority_set(0x18,1,0);
  nVar1 = nrfx_wdt_init(p_instance,(nrfx_wdt_config_t *)(p_instance + 2),
                        (nrfx_wdt_event_handler_t *)0x66de9);
  if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}


