/*
 * Function: i2c_write
 * Entry:    00087510
 * Prototype: int __stdcall i2c_write(device * dev, uint8_t * buf, uint32_t num_bytes, uint16_t addr)
 */


/* exclude_from_export */

int i2c_write(device *dev,uint8_t *buf,uint32_t num_bytes,uint16_t addr)

{
  int iVar1;
  uint8_t *local_14;
  uint32_t uStack_10;
  undefined1 local_c;
  uint3 uStack_b;
  
  _local_c = CONCAT31((uint3)(byte)(addr >> 8),2);
  local_14 = buf;
  uStack_10 = num_bytes;
  iVar1 = (**(code **)(*(int *)(dev->name + 8) + 8))
                    (dev->name,&local_14,1,*(undefined2 *)&dev->config,dev);
  return iVar1;
}


