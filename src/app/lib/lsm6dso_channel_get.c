/*
 * Function: lsm6dso_channel_get
 * Entry:    00087cc6
 * Prototype: int __stdcall lsm6dso_channel_get(device * dev, sensor_channel chan, sensor_value * val)
 */


/* exclude_from_export */

int lsm6dso_channel_get(device *dev,sensor_channel chan,sensor_value *val)

{
  uint uVar1;
  int iVar2;
  sensor_value *psVar3;
  sensor_value *psVar4;
  undefined *puVar5;
  short *psVar6;
  uint32_t uVar7;
  
  uVar1 = (uint)chan;
  puVar5 = dev->data;
  if (uVar1 < 4) {
    uVar7 = *(uint32_t *)(puVar5 + 0xc);
    if (uVar1 == 2) {
      iVar2 = (int)*(short *)(puVar5 + 8);
    }
    else {
      if (uVar1 == 3) {
        psVar6 = (short *)(puVar5 + 2);
        psVar4 = val;
        do {
          psVar6 = psVar6 + 1;
          psVar3 = psVar4 + 1;
          lsm6dso_accel_convert(psVar4,(int)*psVar6,uVar7);
          psVar4 = psVar3;
        } while (psVar3 != val + 3);
        return 0;
      }
      if (uVar1 == 1) {
        iVar2 = (int)*(short *)(puVar5 + 6);
      }
      else {
        iVar2 = (int)*(short *)(puVar5 + 4);
      }
    }
    lsm6dso_accel_convert(val,iVar2,uVar7);
  }
  else {
    if (3 < uVar1 - 4) {
      return -0x86;
    }
    uVar7 = *(uint32_t *)(puVar5 + 0x18);
    if (uVar1 == 6) {
      iVar2 = (int)*(short *)(puVar5 + 0x14);
    }
    else {
      if (uVar1 == 7) {
        psVar6 = (short *)(puVar5 + 0xe);
        psVar4 = val;
        do {
          psVar6 = psVar6 + 1;
          psVar3 = psVar4 + 1;
          lsm6dso_gyro_convert(psVar4,(int)*psVar6,uVar7);
          psVar4 = psVar3;
        } while (psVar3 != val + 3);
        return 0;
      }
      if (uVar1 == 5) {
        iVar2 = (int)*(short *)(puVar5 + 0x12);
      }
      else {
        iVar2 = (int)*(short *)(puVar5 + 0x10);
      }
    }
    lsm6dso_gyro_convert(val,iVar2,uVar7);
  }
  return 0;
}


