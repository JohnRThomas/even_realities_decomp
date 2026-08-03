/*
 * Function: qspi_lock
 * Entry:    000870be
 * Prototype: void __stdcall qspi_lock(device * dev)
 */


/* exclude_from_export */

void qspi_lock(device *dev)

{
  undefined4 extraout_r1;
  undefined *puVar1;
  k_timeout_t timeout;
  
  puVar1 = dev->data;
  pm_device_busy_set(dev);
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = extraout_r1;
  z_impl_k_sem_take((k_sem *)(puVar1 + 0x18),timeout);
  if (puVar1[0x60] == '\0') {
    Peripherals::CLOCK_S.HFCLK192MCTRL = 0;
  }
  return;
}


