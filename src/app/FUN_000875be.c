/*
 * Function: FUN_000875be
 * Entry:    000875be
 * Prototype: nrfx_err_t __stdcall FUN_000875be(nrfx_twim_t * param_1, nrfx_twim_xfer_desc_t * param_2, uint32_t param_3)
 */


nrfx_err_t FUN_000875be(nrfx_twim_t *param_1,nrfx_twim_xfer_desc_t *param_2,uint32_t param_3)

{
  nrfx_err_t nVar1;
  k_mutex *mutex;
  k_timeout_t timeout;
  
  mutex = (k_mutex *)param_1[4];
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = param_2;
  z_impl_k_mutex_lock(mutex,timeout);
  nVar1 = nrfx_twim_xfer(param_1,param_2,param_3);
  if (nVar1 == 0) {
    nVar1 = nrfx_gpiote_channel_get((nrfx_gpiote_pin_t)param_1,param_2->opaque);
  }
  z_impl_k_mutex_unlock(mutex);
  return nVar1;
}


