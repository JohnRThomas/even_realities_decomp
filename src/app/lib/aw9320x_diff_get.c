/*
 * Function: aw9320x_diff_get
 * Entry:    000805b4
 * Prototype: int __stdcall aw9320x_diff_get(uint32_t * param_1)
 */


/* exclude_from_export aw9320x.h */

int aw9320x_diff_get(uint32_t *param_1)

{
  int8_t iVar1;
  
  iVar1 = aw9320x_i2c_read(0x1c04,param_1);
  *param_1 = (int)*param_1 >> 10;
  return (int)iVar1;
}


