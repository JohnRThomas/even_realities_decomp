/*
 * Function: regulator_set_voltage
 * Entry:    00087818
 * Prototype: int __stdcall regulator_set_voltage(device * dev, int32_t min_uv, int32_t max_uv)
 */


/* exclude_from_export */

int regulator_set_voltage(device *dev,int32_t min_uv,int32_t max_uv)

{
  int iVar1;
  
  if (*(code **)(dev->api + 0x10) == (code *)0x0) {
    iVar1 = -0x58;
  }
  else {
    if ((min_uv <= *(int *)((int)dev->config + 4)) && (*(int *)dev->config <= max_uv)) {
                    /* WARNING: Could not recover jumptable at 0x00087830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(dev->api + 0x10))();
      return iVar1;
    }
    iVar1 = -0x16;
  }
  return iVar1;
}


