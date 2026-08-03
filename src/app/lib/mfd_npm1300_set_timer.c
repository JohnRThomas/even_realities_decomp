/*
 * Function: mfd_npm1300_set_timer
 * Entry:    00087620
 * Prototype: int __stdcall mfd_npm1300_set_timer(device * dev, uint32_t time_ms)
 */


/* exclude_from_export */

int mfd_npm1300_set_timer(device *dev,uint32_t time_ms)

{
  int iVar1;
  uint uVar2;
  undefined2 local_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 local_c;
  undefined3 uStack_b;
  
  uVar2 = time_ms >> 4;
  if (time_ms < 0x10000000) {
    _local_10 = CONCAT13((char)(uVar2 >> 8),CONCAT12((char)(time_ms >> 0x14),0x807));
    _local_c = CONCAT31((int3)(time_ms >> 8),(char)uVar2);
    iVar1 = i2c_write((device *)dev->config,(uint8_t *)&local_10,5,(uint16_t)uVar2);
    if (iVar1 == 0) {
      iVar1 = i2c_write_dt((i2c_dt_spec *)dev,&DAT_00000007,3);
    }
  }
  else {
    iVar1 = -0x16;
  }
  return iVar1;
}


