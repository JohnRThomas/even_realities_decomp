/*
 * Function: lsm6dso_sample_fetch
 * Entry:    00087d62
 * Prototype: int __stdcall lsm6dso_sample_fetch(device * dev, sensor_channel chan)
 */


/* exclude_from_export */

int lsm6dso_sample_fetch(device *dev,sensor_channel chan)

{
  if (chan != SENSOR_CHAN_GYRO_XYZ) {
    if (chan != SENSOR_CHAN_ALL) {
      if (chan == SENSOR_CHAN_ACCEL_XYZ) {
        lsm6dso_sample_fetch_accel(dev);
        return 0;
      }
      return -0x86;
    }
    lsm6dso_sample_fetch_accel(dev);
  }
  lsm6dso_sample_fetch_gyro(dev);
  return 0;
}


