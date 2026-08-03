/*
 * Function: pm_device_is_busy
 * Entry:    000826c6
 * Prototype: bool __stdcall pm_device_is_busy(device * dev)
 */


/* exclude_from_export_ai */

bool pm_device_is_busy(device *dev)

{
  bool bVar1;
  
  bVar1 = false;
  if (dev->pm != (undefined *)0x0) {
    bVar1 = (bool)((byte)*(undefined4 *)(dev->pm + 4) & 1);
  }
  return bVar1;
}


