/*
 * Function: qspi_trans_lock
 * Entry:    000870b2
 * Prototype: void __stdcall qspi_trans_lock(device * dev)
 */


/* exclude_from_export */

void qspi_trans_lock(device *dev)

{
  undefined4 in_r1;
  k_timeout_t timeout;
  
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = in_r1;
  z_impl_k_sem_take((k_sem *)dev,timeout);
  return;
}


