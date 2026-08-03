/*
 * Function: mfd_npm1300_reg_update
 * Entry:    000875be
 * Prototype: int __stdcall mfd_npm1300_reg_update(device * dev, uint8_t base, uint8_t offset, uint8_t data, uint8_t mask)
 */


/* exclude_from_export */

int mfd_npm1300_reg_update(device *dev,uint8_t base,uint8_t offset,uint8_t data,uint8_t mask)

{
  int iVar1;
  k_mutex *mutex;
  k_timeout_t timeout;
  device *num_read;
  undefined4 uStack_24;
  
  timeout.ticks._0_4_ = (uint8_t *)(uint)base;
  mutex = (k_mutex *)dev->data;
  timeout.ticks._4_4_ = 0xffffffff;
  num_read = dev;
  uStack_24 = (uint8_t *)timeout.ticks;
  z_impl_k_mutex_lock(mutex,timeout);
  iVar1 = i2c_write_read_dt((i2c_dt_spec *)dev,(uint8_t *)timeout.ticks,(uint)offset,
                            (void *)((int)&uStack_24 + 3),(size_t)num_read);
  if (iVar1 == 0) {
    uStack_24 = (uint8_t *)CONCAT13(uStack_24._3_1_ & ~mask | mask & data,(undefined3)uStack_24);
    iVar1 = i2c_write_dt((i2c_dt_spec *)dev,(uint8_t *)timeout.ticks,(uint)offset);
  }
  z_impl_k_mutex_unlock(mutex);
  return iVar1;
}


