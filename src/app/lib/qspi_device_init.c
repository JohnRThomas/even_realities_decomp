/*
 * Function: qspi_device_init
 * Entry:    00063cb4
 * Prototype: int __stdcall qspi_device_init(device * dev)
 */


/* exclude_from_export */

int qspi_device_init(device *dev)

{
  nrfx_err_t res;
  int iVar1;
  undefined *p_context;
  
  p_context = dev->data;
  if (p_context[0x60] == '\0') {
    qspi_lock(dev);
    k_sem_give((k_sem *)(p_context + 0x48));
    iVar1 = 0;
    if (DAT_2001e2a9 == '\0') {
      res = nrfx_qspi_init((nrfx_qspi_config_t *)dev->config,(nrfx_qspi_handler_t *)0x87083,
                           p_context);
      iVar1 = qspi_get_zephyr_ret_code(res);
      DAT_2001e2a9 = iVar1 == 0;
    }
    qspi_unlock(dev);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


