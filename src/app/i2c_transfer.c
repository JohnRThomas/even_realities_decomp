/*
 * Function: $_i2c_transfer
 * Entry:    0007fae6
 * Prototype: int __stdcall $_i2c_transfer(device * dev, i2c_msg * msgs, uint8_t num_msgs, uint16_t addr)
 */


int __i2c_transfer(device *dev,i2c_msg *msgs,uint8_t num_msgs,uint16_t addr)

{
  device *pdVar1;
  int iVar2;
  int extraout_r0;
  int iVar3;
  uint32_t *output;
  device *pdVar4;
  device *local_28;
  i2c_msg *piStack_24;
  uint local_20;
  device *local_1c;
  
  local_1c = (device *)(uint)addr;
  local_20 = (uint)num_msgs;
  if ((msgs == (i2c_msg *)0x0) || (*msgs == 0)) {
    iVar2 = 7;
  }
  else {
    local_28 = dev;
    piStack_24 = msgs;
    iVar2 = __FUN_0007fabc(&dev->name,(int *)&local_28);
    pdVar1 = local_28;
    if ((iVar2 == 0) && (pdVar4 = (device *)msgs[1], local_28 <= pdVar4)) {
      iVar3 = 0;
      if (dev != (device *)0x0) {
        iVar3 = 0;
        for (output = (uint32_t *)dev->name; output != (uint32_t *)0x0;
            output = (uint32_t *)output[6]) {
          local_20 = *msgs + iVar3;
          local_1c = pdVar4;
          __data_read(output);
          if (extraout_r0 != 0) {
            msgs[1] = (i2c_msg)pdVar1;
            return extraout_r0;
          }
          iVar3 = (int)&local_1c->name + iVar3;
          pdVar4 = (device *)((int)pdVar4 - (int)local_1c);
        }
      }
      iVar2 = 0;
      msgs[1] = iVar3;
    }
    else {
      iVar2 = 1;
      msgs[1] = (i2c_msg)local_28;
    }
  }
  return iVar2;
}


