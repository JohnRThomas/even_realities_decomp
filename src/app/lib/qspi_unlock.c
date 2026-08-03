/*
 * Function: qspi_unlock
 * Entry:    000870e6
 * Prototype: void __stdcall qspi_unlock(device * dev)
 */


/* exclude_from_export */

void qspi_unlock(device *dev)

{
  uint *puVar1;
  
  if (dev->data[0x60] == '\0') {
    Peripherals::CLOCK_S.HFCLK192MCTRL = 2;
  }
  k_sem_give((k_sem *)(dev->data + 0x18));
  if (dev->pm != (undefined *)0x0) {
    puVar1 = (uint *)(dev->pm + 4);
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  return;
}


