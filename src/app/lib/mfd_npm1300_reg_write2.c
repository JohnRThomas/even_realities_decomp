/*
 * Function: mfd_npm1300_reg_write2
 * Entry:    00087596
 * Prototype: int __stdcall mfd_npm1300_reg_write2(device * dev, uint8_t base, uint8_t offset, uint8_t data1, uint8_t data2)
 */


/* exclude_from_export */

int mfd_npm1300_reg_write2(device *dev,uint8_t base,uint8_t offset,uint8_t data1,uint8_t data2)

{
  int iVar1;
  undefined4 local_c;
  uint uStack_8;
  
  uStack_8 = (uint)offset;
  local_c = CONCAT13(data2,CONCAT21(CONCAT11(data1,offset),base));
  iVar1 = i2c_write((device *)dev->config,(uint8_t *)&local_c,4,(ushort)data2);
  return iVar1;
}


