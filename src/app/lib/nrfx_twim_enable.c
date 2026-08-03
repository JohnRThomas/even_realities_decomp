/*
 * Function: nrfx_twim_enable
 * Entry:    0006ab2c
 * Prototype: void __stdcall nrfx_twim_enable(nrfx_twim_t * p_instance)
 */


/* exclude_from_export */

void nrfx_twim_enable(nrfx_twim_t *p_instance)

{
  int iVar1;
  
  iVar1 = (uint)(byte)p_instance[1] * 0x28;
  if ((&DAT_2000bdd6)[iVar1] != '\x01') {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_cb->state == NRFX_DRV_STATE_INITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",363);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(undefined4 *)(*p_instance + 0x500) = 6;
  (&DAT_2000bdd6)[iVar1] = 2;
  return;
}


