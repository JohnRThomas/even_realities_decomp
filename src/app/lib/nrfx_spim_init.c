/*
 * Function: nrfx_spim_init
 * Entry:    0006a480
 * Prototype: nrfx_err_t __stdcall nrfx_spim_init(nrfx_spim_t * p_instance, nrfx_spim_config_t * p_config, nrfx_spim_evt_handler_t handler, void * p_context)
 */


/* exclude_from_export */

nrfx_err_t
nrfx_spim_init(nrfx_spim_t *p_instance,nrfx_spim_config_t *p_config,nrfx_spim_evt_handler_t handler,
              void *p_context)

{
  nrfx_err_t nVar1;
  nrfx_spim_config_t *p_config_00;
  uint uVar2;
  int iVar3;
  
  if (p_config == (nrfx_spim_config_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_config",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",511);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  uVar2 = (uint)(byte)p_instance[1];
  iVar3 = uVar2 * 0x24;
  if ((&DAT_2000bd88)[iVar3] == '\0') {
    (&DAT_2000bd6c)[uVar2 * 9] = handler;
    (&DAT_2000bd70)[uVar2 * 9] = p_context;
    nVar1 = spim_configuration_verify(p_instance,p_config);
    if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
      spim_configure(p_instance,p_config_00);
      (&DAT_2000bd89)[iVar3] = 0;
      (&DAT_2000bd88)[iVar3] = 1;
    }
  }
  else {
    nVar1 = NRFX_ERROR_INVALID_STATE;
  }
  return nVar1;
}


