/*
 * Function: sensor_channel_get
 * Entry:    000803ce
 * Prototype: int __stdcall sensor_channel_get(device * dev, sensor_channel chan, sensor_value * val)
 */


/* exclude_from_export */

int sensor_channel_get(device *dev,sensor_channel chan,sensor_value *val)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000803d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(dev->api + 0x10))(dev,chan);
  return iVar1;
}


