/*
 * Function: qspi_wait_for_completion
 * Entry:    00063c98
 * Prototype: void __stdcall qspi_wait_for_completion(device * dev, nrfx_err_t res)
 */


/* exclude_from_export */

void qspi_wait_for_completion(device *dev,nrfx_err_t res)

{
  if ((undefined1 *)(uint)res == &DAT_0bad0000) {
    z_impl_k_sem_take((k_sem *)(dev + 2),(k_timeout_t)0xffffffff0bad0000);
    return;
  }
  return;
}


