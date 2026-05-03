/*
 * Function: FUN_00087cc6
 * Entry:    00087cc6
 * Prototype: undefined4 __stdcall FUN_00087cc6(int param_1, uint param_2, sensor_value * param_3)
 */


undefined4 FUN_00087cc6(int param_1,uint param_2,sensor_value *param_3)

{
  sensor_value *psVar1;
  sensor_value *psVar2;
  int iVar3;
  short *psVar4;
  uint32_t uVar5;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (param_2 < 4) {
    uVar5 = *(uint32_t *)(iVar3 + 0xc);
    if (param_2 == 2) {
      iVar3 = (int)*(short *)(iVar3 + 8);
    }
    else {
      if (param_2 == 3) {
        psVar4 = (short *)(iVar3 + 2);
        psVar2 = param_3;
        do {
          psVar4 = psVar4 + 1;
          psVar1 = psVar2 + 2;
          lsm6dso_accel_convert(psVar2,(int)*psVar4,uVar5);
          psVar2 = psVar1;
        } while (psVar1 != param_3 + 6);
        return 0;
      }
      if (param_2 == 1) {
        iVar3 = (int)*(short *)(iVar3 + 6);
      }
      else {
        iVar3 = (int)*(short *)(iVar3 + 4);
      }
    }
    lsm6dso_accel_convert(param_3,iVar3,uVar5);
  }
  else {
    if (3 < param_2 - 4) {
      return 0xffffff7a;
    }
    uVar5 = *(uint32_t *)(iVar3 + 0x18);
    if (param_2 == 6) {
      iVar3 = (int)*(short *)(iVar3 + 0x14);
    }
    else {
      if (param_2 == 7) {
        psVar4 = (short *)(iVar3 + 0xe);
        psVar2 = param_3;
        do {
          psVar4 = psVar4 + 1;
          psVar1 = psVar2 + 2;
          lsm6dso_gyro_convert(psVar2,(int)*psVar4,uVar5);
          psVar2 = psVar1;
        } while (psVar1 != param_3 + 6);
        return 0;
      }
      if (param_2 == 5) {
        iVar3 = (int)*(short *)(iVar3 + 0x12);
      }
      else {
        iVar3 = (int)*(short *)(iVar3 + 0x10);
      }
    }
    lsm6dso_gyro_convert(param_3,iVar3,uVar5);
  }
  return 0;
}


