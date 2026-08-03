/*
 * Function: lsm6dso_sample_fetch_accel
 * Entry:    00065528
 * Prototype: int __stdcall lsm6dso_sample_fetch_accel(device * dev)
 */


/* exclude_from_export */

int lsm6dso_sample_fetch_accel(device *dev)

{
  int32_t iVar1;
  int extraout_r0;
  
  iVar1 = lsm6dso_acceleration_raw_get((stmdev_ctx_t *)dev->config,(int16_t *)(dev->data + 4));
  if (iVar1 < 0) {
    printk("Failed to read sample\r\n");
    return extraout_r0;
  }
  return iVar1;
}


