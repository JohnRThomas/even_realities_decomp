/*
 * Function: adc_raw_to_millivolts_dt
 * Entry:    000628b8
 * Prototype: int __stdcall adc_raw_to_millivolts_dt(adc_gain gain, int32_t * value)
 */


/* exclude_from_export */

int adc_raw_to_millivolts_dt(adc_gain gain,int32_t *value)

{
  uint uVar1;
  
  uVar1 = (uint)gain;
  if (((uVar1 < 0x14) && ((byte)(&DAT_000f34ec)[uVar1] != 0)) &&
     ((byte)(&DAT_000f34ed)[uVar1 * 2] != 0)) {
    *value = (int)(*value * (uint)(byte)(&DAT_000f34ec)[uVar1]) /
             (int)(uint)(byte)(&DAT_000f34ed)[uVar1 * 2];
    return 0;
  }
  return -0x16;
}


