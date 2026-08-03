/*
 * Function: ldo_set_voltage
 * Entry:    00087a7c
 * Prototype: int __stdcall ldo_set_voltage(device * dev, uint8_t chan, int32_t min_uv, int32_t max_uv)
 */


/* exclude_from_export */

int ldo_set_voltage(device *dev,uint8_t chan,int32_t min_uv,int32_t max_uv)

{
  int iVar1;
  undefined4 uStack_14;
  int32_t iStack_10;
  
  uStack_14 = (uint)chan;
  iStack_10 = min_uv;
  iVar1 = linear_range_get_win_index
                    ((linear_range *)min_uv,max_uv,(int)&uStack_14 + 2,(uint16_t *)max_uv);
  if (iVar1 != -0x16) {
    iVar1 = i2c_write_dt((i2c_dt_spec *)dev[1].config,&NMI,chan + 0xc & 0xff);
    return iVar1;
  }
  return -0x16;
}


