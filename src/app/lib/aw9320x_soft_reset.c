/*
 * Function: aw9320x_soft_reset
 * Entry:    0003165c
 * Prototype: int32_t __stdcall aw9320x_soft_reset(void)
 */


/* exclude_from_export aw9320x.c */

int32_t aw9320x_soft_reset(void)

{
  aw9320x_err_code aVar1;
  uint uVar2;
  
  aVar1 = aw9320x_i2c_write(0xff20,0x3c00f091);
  if ((int)(uint)aVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    aw9320x_i2c_write(0x4700,0x110);
    AW_DELAY(1);
    aVar1 = aw9320x_i2c_write(0x4444,0);
    uVar2 = (uint)aVar1;
    if (uVar2 == 0) {
      AW_DELAY(20);
      aw9320x_i2c_write(0xff18,0x3c);
      AW_DELAY(25);
      aw9320x_i2c_write(0x4700,0x102);
      uVar2 = 0;
    }
  }
  return uVar2;
}


