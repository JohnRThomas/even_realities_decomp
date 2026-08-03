/*
 * Function: i2c_write_dt
 * Entry:    00087578
 * Prototype: int __stdcall i2c_write_dt(i2c_dt_spec * spec, uint8_t * buf, uint32_t num_bytes)
 */


/* exclude_from_export */

int i2c_write_dt(i2c_dt_spec *spec,uint8_t *buf,uint32_t num_bytes)

{
  int iVar1;
  uint16_t in_r3;
  uint8_t local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 uStack_9;
  uint32_t uStack_8;
  
  uStack_9 = (undefined1)((uint)buf >> 0x18);
  _local_c = CONCAT12((char)in_r3,CONCAT11((char)num_bytes,(char)buf));
  uStack_8 = num_bytes;
  iVar1 = i2c_write(*(device **)&spec->addr,&local_c,3,in_r3);
  return iVar1;
}


