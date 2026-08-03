/*
 * Function: regulator_npm1300_list_voltage
 * Entry:    000652ec
 * Prototype: int __stdcall regulator_npm1300_list_voltage(device * dev, uint idx, int32_t * volt_uv)
 */


/* exclude_from_export */

int regulator_npm1300_list_voltage(device *dev,uint idx,int32_t *volt_uv)

{
  if (((byte)dev->config[0x20] < 4) && ((idx & 0xffff) < 0x18)) {
    *volt_uv = (int32_t)("failed to set gyroscope full-scale\r\n" + (idx & 0xffff) * 100000 + 0xd);
    return 0;
  }
  return -0x16;
}


