/*
 * Function: opt3001_reg_read
 * Entry:    00087f88
 * Prototype: int __stdcall opt3001_reg_read(device * dev, uint8_t reg, uint16_t * val)
 */


/* exclude_from_export */

int opt3001_reg_read(device *dev,uint8_t reg,uint16_t *val)

{
  int iVar1;
  uint8_t local_2d;
  ushort local_2c [2];
  uint8_t *local_28;
  undefined4 local_24;
  undefined1 local_20;
  ushort *local_1c;
  undefined4 local_18;
  undefined1 local_14;
  
  local_28 = &local_2d;
  local_24 = 1;
  local_20 = 0;
  local_1c = local_2c;
  local_18 = 2;
  local_14 = 7;
  local_2d = reg;
  iVar1 = (**(code **)(*(int *)(dev->name + 8) + 8))
                    (dev->name,&local_28,2,*(undefined2 *)&dev->config);
  if (iVar1 == 0) {
    *val = local_2c[0] << 8 | local_2c[0] >> 8;
    iVar1 = 0;
  }
  else {
    iVar1 = -5;
  }
  return iVar1;
}


