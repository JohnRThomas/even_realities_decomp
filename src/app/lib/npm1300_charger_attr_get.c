/*
 * Function: npm1300_charger_attr_get
 * Entry:    00087e14
 * Prototype: int __stdcall npm1300_charger_attr_get(device * dev, sensor_channel chan, sensor_attribute attr, sensor_value * val)
 */


/* exclude_from_export */

int npm1300_charger_attr_get
              (device *dev,sensor_channel chan,sensor_attribute attr,sensor_value *val)

{
  int ret;
  sensor_channel uStack_c;
  undefined1 local_9;
  
  if ((chan == SENSOR_CHAN_GAUGE_DESIRED_CHARGING_CURRENT) && (attr == SENSOR_ATTR_CONFIGURATION)) {
    ret = i2c_write_read_dt(*(i2c_dt_spec **)dev->config,&DAT_00000003,4,&local_9,(size_t)dev);
    if (ret == 0) {
      val->val1 = 0;
      val->val2 = 0;
    }
  }
  else {
    ret = -0x86;
  }
  return ret;
}


