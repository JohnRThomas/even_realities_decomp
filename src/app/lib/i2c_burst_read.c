/*
 * Function: i2c_burst_read
 * Entry:    00065458
 * Prototype: int __stdcall i2c_burst_read(device * dev, uint16_t dev_addr, uint8_t start_addr, uint8_t * buf, uint32_t num_bytes)
 */


/* exclude_from_export_ai */

int i2c_burst_read(device *dev,uint16_t dev_addr,uint8_t start_addr,uint8_t *buf,uint32_t num_bytes)

{
  int iVar1;
  uint uVar2;
  size_t num_write;
  device *num_read;
  undefined4 uStack_14;
  
  uVar2 = (uint)dev_addr;
  num_read = dev;
  uStack_14 = uVar2;
  iVar1 = i2c_write_read_dt((i2c_dt_spec *)dev[1].config,&Reset,0xf,(void *)((int)&uStack_14 + 2),
                            (size_t)dev);
  if (-1 < iVar1) {
    if (((int)(uStack_14 >> 0x10 & 0xff) >> (uVar2 & 0xff)) << 0x1f < 0) {
      num_write = (uVar2 + 4) * 2 & 0xfe;
    }
    else {
      num_write = uVar2 + 0x10 & 0xff;
    }
    iVar1 = i2c_write_read_dt((i2c_dt_spec *)dev[1].config,&Reset,num_write,
                              (void *)((int)&uStack_14 + 3),(size_t)num_read);
    if (-1 < iVar1) {
      if (uStack_14 >> 0x18 < 0x18) {
        iVar1 = 0;
        *(char **)(uint)start_addr =
             "failed to set gyroscope full-scale\r\n" + (uStack_14 >> 0x18) * 100000 + 0xd;
      }
      else {
        iVar1 = -0x16;
      }
    }
  }
  return iVar1;
}


