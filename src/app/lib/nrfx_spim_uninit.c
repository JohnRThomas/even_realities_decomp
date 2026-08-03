/*
 * Function: nrfx_spim_uninit
 * Entry:    0006a4f0
 * Prototype: void __stdcall nrfx_spim_uninit(nrfx_spim_t * p_instance)
 */


/* exclude_from_export */

void nrfx_spim_uninit(nrfx_spim_t *p_instance)

{
  nrfx_spim_t nVar1;
  uint uVar2;
  uint32_t uVar3;
  uint32_t pin;
  
  uVar2 = (uint)(byte)p_instance[1];
  if ((&DAT_2000bd88)[uVar2 * 0x24] == '\0') {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_cb->state != NRFX_DRV_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",597);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  arch_irq_disable((int)(*p_instance << 0xc) >> 0x18);
  if ((&DAT_2000bd6c)[uVar2 * 9] != 0) {
    *(undefined4 *)(*p_instance + 0x308) = 0x80152;
    spim_abort((NRF_SPIM_Type *)*p_instance,&DAT_2000bd6c + uVar2 * 9);
  }
  nVar1 = *p_instance;
  uVar3 = *(uint32_t *)(nVar1 + 0x50c);
  pin = *(uint32_t *)(nVar1 + 0x510);
  if (-1 < (int)((uint)(byte)(&DAT_2000bd8a)[uVar2 * 0x24] << 0x1f)) {
    spim_pin_uninit(*(uint32_t *)(nVar1 + 0x508));
    spim_pin_uninit(pin);
    spim_pin_uninit(uVar3);
    spim_pin_uninit((&DAT_2000bd8c)[uVar2 * 9]);
    if ((char)p_instance[1] != '\0') {
      uVar3 = *(uint32_t *)(*p_instance + 0x514);
      spim_pin_uninit(*(uint32_t *)(*p_instance + 0x56c));
      spim_pin_uninit(uVar3);
    }
  }
  (&DAT_2000bd88)[uVar2 * 0x24] = 0;
  return;
}


