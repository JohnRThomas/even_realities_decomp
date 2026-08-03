/*
 * Function: npm1300_charger_channel_get
 * Entry:    0006577c
 * Prototype: int __stdcall npm1300_charger_channel_get(device * dev, sensor_channel chan, sensor_value * valp)
 */


/* exclude_from_export */

int npm1300_charger_channel_get(device *dev,sensor_channel chan,sensor_value *valp)

{
  byte bVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  int32_t iVar6;
  int iVar7;
  undefined *puVar8;
  uint in_fpscr;
  double dVar9;
  float fVar10;
  float fVar11;
  ulonglong uVar12;
  
  puVar8 = dev->config;
  puVar3 = (ushort *)dev->data;
  switch(chan) {
  case SENSOR_CHAN_GAUGE_VOLTAGE:
    uVar4 = (int)((uint)*puVar3 * 5000) >> 10;
    uVar2 = uVar4 / 1000;
    goto LAB_000657bc;
  case SENSOR_CHAN_GAUGE_AVG_CURRENT:
    switch((char)puVar3[4]) {
    case '\x04':
      iVar7 = *(int *)(puVar8 + 0x10);
      break;
    default:
      iVar7 = 0;
      goto LAB_0006587a;
    case '\f':
      iVar7 = 10000;
      iVar5 = *(int *)(puVar8 + 0xc);
      goto LAB_00065876;
    case '\r':
      iVar5 = *(int *)(puVar8 + 0xc);
      iVar7 = 2000;
LAB_00065876:
      iVar7 = -iVar5 / iVar7;
      goto LAB_0006587a;
    case '\x0f':
      iVar7 = -*(int *)(puVar8 + 0xc);
    }
    iVar7 = iVar7 / 1000;
LAB_0006587a:
    iVar7 = (uint)puVar3[1] * iVar7;
    if (iVar7 < 0) {
      iVar7 = iVar7 + 0x3ff;
    }
    uVar4 = iVar7 >> 10;
    uVar2 = (int)uVar4 / 1000;
LAB_000657bc:
    iVar6 = (uVar4 + uVar2 * -1000) * 1000;
    valp->val1 = uVar2;
    goto LAB_000657c4;
  default:
    return -0x86;
  case SENSOR_CHAN_GAUGE_MAX_LOAD_CURRENT:
    valp->val1 = *(int *)(puVar8 + 0x10) / 1000000;
    iVar7 = *(int *)(puVar8 + 0x10);
    break;
  case SENSOR_CHAN_GAUGE_TEMP:
    fVar10 = (float)VectorUnsignedToFloat((uint)puVar3[2],(byte)(in_fpscr >> 0x16) & 3);
    uVar12 = __aeabi_f2d((uint)(1024.0 / fVar10 - 1.0),chan - 0x28,valp,(uint)puVar3[2]);
    dVar9 = log((double)((uVar12 & 0xffffffff00000000) + (uVar12 & 0xffffffff)));
    fVar10 = (float)__truncdfsf2(SUB84(dVar9,0),(uint)((ulonglong)dVar9 >> 0x20));
    fVar11 = (float)VectorUnsignedToFloat
                              ((uint)*(ushort *)(puVar8 + 0x2c),(byte)(in_fpscr >> 0x16) & 3);
    fVar10 = 1.0 / (0.0033540165 - fVar10 / fVar11) - 273.15;
    valp->val1 = (int)fVar10;
    fVar10 = fmodf(fVar10,1.0);
    iVar6 = (int32_t)(fVar10 * 1e+06);
    goto LAB_000657c4;
  case SENSOR_CHAN_GAUGE_DESIRED_CHARGING_CURRENT:
    valp->val1 = *(int *)(puVar8 + 0xc) / 1000000;
    iVar7 = *(int *)(puVar8 + 0xc);
    break;
  case SENSOR_CHAN_COMMON_COUNT:
    bVar1 = (byte)puVar3[3];
    goto LAB_000658a4;
  case SENSOR_CHAN_PRIV_START:
    bVar1 = *(byte *)((int)puVar3 + 7);
LAB_000658a4:
    valp->val1 = (uint)bVar1;
    iVar6 = 0;
    goto LAB_000657c4;
  }
  iVar6 = iVar7 % 1000000;
LAB_000657c4:
  valp->val2 = iVar6;
  return 0;
}


