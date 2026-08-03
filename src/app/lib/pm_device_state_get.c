/*
 * Function: pm_device_state_get
 * Entry:    000826b4
 * Prototype: int __stdcall pm_device_state_get(device * dev, pm_device_state * state)
 */


/* exclude_from_export_ai */

int pm_device_state_get(device *dev,pm_device_state *state)

{
  if (dev->pm != (undefined *)0x0) {
    *(undefined *)state = dev->pm[8];
    return 0;
  }
  return -0x58;
}


