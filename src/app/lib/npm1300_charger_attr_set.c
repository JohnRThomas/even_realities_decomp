/*
 * Function: npm1300_charger_attr_set
 * Entry:    00087ee8
 * Prototype: int __stdcall npm1300_charger_attr_set(device * dev, sensor_channel chan, sensor_attribute attr, sensor_value * val)
 */


/* exclude_from_export */

int npm1300_charger_attr_set
              (device *dev,sensor_channel chan,sensor_attribute attr,sensor_value *val)

{
  i2c_dt_spec *spec;
  int iVar1;
  uint32_t num_bytes;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)dev->config;
  if ((chan == SENSOR_CHAN_GAUGE_DESIRED_CHARGING_CURRENT) && (attr == SENSOR_ATTR_CONFIGURATION)) {
    spec = (i2c_dt_spec *)*puVar2;
    if (val->val1 == 0) {
      num_bytes = 5;
    }
    else {
      iVar1 = i2c_write_dt(spec,&DAT_00000003,0);
      if (iVar1 != 0) {
        return iVar1;
      }
      num_bytes = 4;
      spec = (i2c_dt_spec *)*puVar2;
    }
    iVar1 = i2c_write_dt(spec,&DAT_00000003,num_bytes);
    return iVar1;
  }
  return -0x86;
}


