/*
 * Function: pm_device_state_is_locked
 * Entry:    00082706
 * Prototype: bool __stdcall pm_device_state_is_locked(device * dev)
 */


/* exclude_from_export_ai */

bool pm_device_state_is_locked(device *dev)

{
  bool bVar1;
  
  bVar1 = false;
  if (dev->pm != (undefined *)0x0) {
    bVar1 = SUB41((*(uint *)(dev->pm + 4) & 0x7f) >> 6,0);
  }
  return bVar1;
}


