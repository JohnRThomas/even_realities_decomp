/*
 * Function: spim_configuration_verify
 * Entry:    0006a020
 * Prototype: nrfx_err_t __stdcall spim_configuration_verify(nrfx_spim_t * p_instance, nrfx_spim_config_t * p_config)
 */


/* exclude_from_export */

nrfx_err_t spim_configuration_verify(nrfx_spim_t *p_instance,nrfx_spim_config_t *p_config)

{
  nrfx_err_t nVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  ppuVar3 = *(undefined ***)p_config[5].opaque;
  if (ppuVar3 == (undefined **)0x1e8480) {
LAB_0006a0c0:
    if (((p_config[8].opaque[1] != 0) && (*(int *)p_config[3].opaque != -1)) ||
       (*(int *)p_config[7].opaque != -1)) goto LAB_0006a05e;
    if (p_config[8].opaque[3] == 0) {
      return NRFX_SUCCESS;
    }
  }
  else {
    if (ppuVar3 < (undefined **)0x1e8481) {
      if (ppuVar3 != (undefined **)0x7a120) {
        if (ppuVar3 < (undefined **)0x7a121) {
          if (ppuVar3 == &PTR_s_ble_process_put_req_0001e848) goto LAB_0006a0c0;
          ppuVar2 = (undefined **)0x3d090;
        }
        else {
          ppuVar2 = (undefined **)0xf4240;
        }
LAB_0006a03a:
        if (ppuVar3 != ppuVar2) {
          return NRFX_ERROR_INVALID_PARAM;
        }
      }
      goto LAB_0006a0c0;
    }
    if (ppuVar3 != (undefined **)0xf42400) {
      if (ppuVar3 < (undefined **)0xf42401) {
        if (ppuVar3 != (undefined **)&DAT_003d0900) {
          ppuVar2 = (undefined **)0x7a1200;
          goto LAB_0006a03a;
        }
        goto LAB_0006a0c0;
      }
      if (ppuVar3 != (undefined **)0x1e84800) {
        return NRFX_ERROR_INVALID_PARAM;
      }
    }
LAB_0006a05e:
    if ((char)p_instance[1] == '\0') {
      return NRFX_ERROR_NOT_SUPPORTED;
    }
    if (p_config[8].opaque[3] == 0) goto LAB_0006a072;
  }
  if (p_config[9].opaque[0] != 0) {
    return NRFX_SUCCESS;
  }
LAB_0006a072:
  if (((SPIM4_S *)*p_instance != &Peripherals::SPIM4_S) || (ppuVar3 != (undefined **)0x1e84800)) {
    return NRFX_SUCCESS;
  }
  if (((((*(int *)p_config->opaque == -1) || (*(int *)p_config->opaque == 8)) &&
       ((*(int *)p_config[1].opaque == -1 || (*(int *)p_config[1].opaque == 9)))) &&
      ((*(int *)p_config[2].opaque == -1 || (*(int *)p_config[2].opaque == 10)))) &&
     (((p_config[8].opaque[1] == 0 || (*(int *)p_config[3].opaque == -1)) ||
      (*(int *)p_config[3].opaque == 0xb)))) {
    nVar1 = NRFX_SUCCESS;
    if (*(int *)p_config[7].opaque == -1) {
      return NRFX_SUCCESS;
    }
    if (*(int *)p_config[7].opaque != 0xc) {
      nVar1 = NRFX_ERROR_INVALID_PARAM;
    }
    return nVar1;
  }
  return NRFX_ERROR_INVALID_PARAM;
}


