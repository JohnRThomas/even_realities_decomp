/*
 * Function: FUN_0006481c
 * Entry:    0006481c
 * Prototype: undefined4 __stdcall FUN_0006481c(void)
 */


undefined4 FUN_0006481c(void)

{
  bool interrupt_priority;
  undefined1 *puVar1;
  
  interrupt_priority = nrfx_gpiote_is_init();
  if (!interrupt_priority) {
    puVar1 = (undefined1 *)nrfx_gpiote_init(interrupt_priority);
    if (puVar1 != &DAT_0bad0000) {
      return 0xfffffffb;
    }
    nrfx_gpiote_global_callback_set((nrfx_gpiote_interrupt_handler_t)0x64855,(void *)0x0);
    z_arm_irq_priority_set(0xd,5,0);
  }
  return 0;
}


