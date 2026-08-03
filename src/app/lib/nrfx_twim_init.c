/*
 * Function: nrfx_twim_init
 * Entry:    0006aa3c
 * Prototype: nrfx_err_t __stdcall nrfx_twim_init(nrfx_twim_t * p_instance, nrfx_twim_config_t * p_config, nrfx_twim_evt_handler_t event_handler, void * p_context)
 */


/* exclude_from_export */

nrfx_err_t
nrfx_twim_init(nrfx_twim_t *p_instance,nrfx_twim_config_t *p_config,
              nrfx_twim_evt_handler_t event_handler,void *p_context)

{
  byte bVar1;
  nrfx_twim_t nVar2;
  nrfx_err_t nVar3;
  int iVar4;
  bool bVar5;
  
  if (p_config == (nrfx_twim_config_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_config",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",258);
    goto LAB_0006aa58;
  }
  nVar2 = p_instance[1];
  iVar4 = (uint)(byte)nVar2 * 0x28;
  if ((&DAT_2000bdd6)[iVar4] != '\0') {
    return NRFX_ERROR_INVALID_STATE;
  }
  *(undefined4 *)(&DAT_2000bdbc + iVar4) = 0;
  *(nrfx_twim_evt_handler_t *)(&DAT_2000bdb4 + iVar4) = event_handler;
  *(void **)(&DAT_2000bdb8 + iVar4) = p_context;
  (&DAT_2000bdd9)[iVar4] = 0;
  (&DAT_2000bdd8)[iVar4] = 0;
  bVar1 = p_config[3].opaque[2];
  (&DAT_2000bddb)[iVar4] = bVar1;
  if (*(uint *)p_config[2].opaque < 0xff00000) {
    iVar4 = 6;
LAB_0006aaa0:
    if (bVar1 == 0) {
      if (*(uint *)p_config->opaque == *(uint *)p_config[1].opaque) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_config->scl_pin != p_config->sda_pin",
                "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",243);
LAB_0006aa58:
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      TWIM_PIN_INIT(*(uint *)p_config->opaque,0,3,iVar4);
      TWIM_PIN_INIT(*(uint *)p_config[1].opaque,0,3,iVar4);
    }
    iVar4 = (uint)(byte)nVar2 * 0x28;
    (&DAT_2000bdda)[iVar4] = p_config[3].opaque[1];
    twim_configure(p_instance,p_config);
    nVar3 = NRFX_SUCCESS;
    (&DAT_2000bdd6)[iVar4] = 1;
  }
  else {
    if (*(int *)p_config->opaque == 0x22) {
      bVar5 = *(int *)p_config[1].opaque == 0x23;
LAB_0006aa9c:
      if (bVar5) {
        iVar4 = 0xb;
        goto LAB_0006aaa0;
      }
    }
    else if (*(int *)p_config->opaque == 0x23) {
      bVar5 = *(int *)p_config[1].opaque == 0x22;
      goto LAB_0006aa9c;
    }
    nVar3 = NRFX_ERROR_INVALID_PARAM;
  }
  return nVar3;
}


