/*
 * Function: sensor_channel_get
 * Entry:    000803ce
 * Prototype: void __stdcall sensor_channel_get(device * dev, sensor_channel chan, sensor_value * val)
 */


void sensor_channel_get(device *dev,sensor_channel chan,sensor_value *val)

{
                    /* WARNING: Could not recover jumptable at 0x000803d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(dev->api + 0x10))();
  return;
}


