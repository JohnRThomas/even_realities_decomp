/*
 * Function: lsm6dso_sample_fetch_gyro
 * Entry:    00065508
 * Prototype: int __stdcall lsm6dso_sample_fetch_gyro(device * dev)
 */


/* exclude_from_export */

int lsm6dso_sample_fetch_gyro(device *dev)

{
  int32_t iVar1;
  int extraout_r0;
  
  iVar1 = lsm6dso_angular_rate_raw_get((stmdev_ctx_t *)dev->config,(int16_t *)(dev->data + 0x10));
  if (iVar1 < 0) {
    printk("Failed to read sample\r\n");
    return extraout_r0;
  }
  return iVar1;
}


