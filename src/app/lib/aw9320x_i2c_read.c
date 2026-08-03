/*
 * Function: aw9320x_i2c_read
 * Entry:    00031798
 * Prototype: int8_t __stdcall aw9320x_i2c_read(uint16_t reg_addr, uint32_t * reg_data)
 */


/* exclude_from_export aw9320x.h */

int8_t aw9320x_i2c_read(uint16_t reg_addr,uint32_t *reg_data)

{
  int iVar1;
  char cnt;
  uint local_20;
  uint local_1c [2];
  
  cnt = 3;
  local_1c[0] = 0;
  local_20 = (uint)(ushort)(reg_addr << 8 | reg_addr >> 8);
  do {
    iVar1 = (**(code **)g_aw9320x_func.i2c_func.i2c_r)(&local_20,2,local_1c);
    if (iVar1 == 0) {
      *reg_data = local_1c[0] << 0x18 | (local_1c[0] >> 8 & 0xff) << 0x10 |
                  (local_1c[0] >> 0x10 & 0xff) << 8 | local_1c[0] >> 0x18;
      return '\0';
    }
    cnt = cnt + -1;
    AW_DELAY(1);
  } while (cnt != '\0');
  return -1;
}


