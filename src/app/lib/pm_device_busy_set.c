/*
 * Function: pm_device_busy_set
 * Entry:    000826d6
 * Prototype: void __stdcall pm_device_busy_set(device * dev)
 */


/* exclude_from_export */

void pm_device_busy_set(device *dev)

{
  uint *puVar1;
  
  if (dev->pm != (undefined *)0x0) {
    puVar1 = (uint *)(dev->pm + 4);
    *puVar1 = *puVar1 | 1;
  }
  return;
}


