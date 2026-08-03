/*
 * Function: lsm6dso_attr_set
 * Entry:    00012558
 * Prototype: int __stdcall lsm6dso_attr_set(device * dev, sensor_channel chan, sensor_attribute attr, sensor_value * val)
 */


/* exclude_from_export */

int lsm6dso_attr_set(device *dev,sensor_channel chan,sensor_attribute attr,sensor_value *val)

{
  char cVar1;
  ushort uVar2;
  char cVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 *puVar6;
  char *pcVar7;
  int iVar8;
  int32_t iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  ushort *puVar14;
  uint uVar15;
  undefined *puVar16;
  stmdev_ctx_t *ctx;
  undefined8 uVar17;
  
  if (chan == SENSOR_CHAN_ACCEL_XYZ) {
    if (attr == SENSOR_ATTR_SAMPLING_FREQUENCY) {
      iVar8 = 0;
      puVar14 = &DAT_0009ce0e;
      do {
        if ((ushort)val->val1 <= *puVar14) {
          puVar16 = dev->data;
          iVar9 = lsm6dso_xl_data_rate_set((stmdev_ctx_t *)dev->config,(lsm6dso_odr_xl_t)iVar8);
          if (-1 < iVar9) {
            *(undefined2 *)(puVar16 + 0x1c) = (&DAT_0009ce0e)[iVar8];
            return 0;
          }
          pcVar7 = "failed to set accelerometer sampling rate\r\n";
          goto LAB_00012612;
        }
        iVar8 = iVar8 + 1;
        puVar14 = puVar14 + 1;
      } while (iVar8 != 0xb);
    }
    else {
      if (attr != SENSOR_ATTR_FULL_SCALE) {
        pcVar7 = "Accel attribute not supported.\r\n";
        goto LAB_0001265e;
      }
      lVar5 = (longlong)val->val1 * 1000000 + (longlong)val->val2;
      if ((int)(uint)((int)lVar5 == 0) <= (int)((ulonglong)lVar5 >> 0x20)) {
        ctx = (stmdev_ctx_t *)dev->config;
        cVar1 = *(char *)((int)&ctx[1].mdelay + 2);
        uVar17 = __aeabi_ldivmod((uint)(lVar5 + 0x4ad19d),
                                 (uint)((ulonglong)(lVar5 + 0x4ad19d) >> 0x20),(uint)&DAT_0095a33a,
                                 (uint)(undefined *)0x0);
        iVar8 = (int)uVar17;
        if (cVar1 < '\0') {
          iVar11 = 4;
        }
        else {
          iVar11 = 2;
        }
        cVar3 = *(char *)((int)&ctx[1].mdelay + 2);
        if (iVar8 == iVar11) {
          iVar11 = 0;
        }
        else {
          if (cVar1 < '\0') {
            iVar11 = 0x20;
          }
          else {
            iVar11 = 0x10;
          }
          if (iVar8 == iVar11) {
            iVar11 = 1;
          }
          else {
            if (cVar1 < '\0') {
              iVar11 = 8;
            }
            else {
              iVar11 = 4;
            }
            if (iVar8 == iVar11) {
              iVar11 = 2;
            }
            else {
              if (cVar1 < '\0') {
                iVar12 = 0x10;
              }
              else {
                iVar12 = 8;
              }
              iVar11 = 3;
              if (iVar8 != iVar12) {
                return -0x16;
              }
            }
          }
        }
        puVar16 = dev->data;
        iVar9 = lsm6dso_xl_full_scale_set(ctx,iVar11);
        if (-1 < iVar9) {
          uVar2 = *(ushort *)(&DAT_0009ce06 + iVar11 * 2);
          puVar16[0x1e] = (char)iVar11;
          if (cVar3 < '\0') {
            uVar10 = (uint)uVar2 * 0x3d;
          }
          else {
            uVar10 = (uint)uVar2 * 0x3d >> 1;
          }
          *(uint *)(puVar16 + 0xc) = uVar10;
          return 0;
        }
        pcVar7 = "failed to set accelerometer full-scale\r\n";
LAB_00012612:
        printk(pcVar7);
        return -5;
      }
    }
  }
  else {
    if (chan != SENSOR_CHAN_GYRO_XYZ) {
      pcVar7 = "attr_set() not supported on this channel.\r\n";
LAB_0001265e:
      printk(pcVar7);
      return -0x86;
    }
    if (attr == SENSOR_ATTR_SAMPLING_FREQUENCY) {
      uVar10 = 0;
      puVar14 = &DAT_0009ce0e;
      do {
        if ((ushort)val->val1 <= *puVar14) {
          iVar9 = lsm6dso_gy_data_rate_set((stmdev_ctx_t *)dev->config,uVar10 & 0xff);
          if (-1 < iVar9) {
            return 0;
          }
          pcVar7 = "failed to set gyroscope sampling rate\r\n";
          goto LAB_00012612;
        }
        uVar10 = uVar10 + 1;
        puVar14 = puVar14 + 1;
      } while (uVar10 != 0xb);
    }
    else {
      if (attr != SENSOR_ATTR_FULL_SCALE) {
        pcVar7 = "Gyro attribute not supported.\r\n";
        goto LAB_0001265e;
      }
      uVar4 = (longlong)val->val1 * 1000000 + (longlong)val->val2;
      iVar8 = (int)(uVar4 >> 0x20);
      lVar5 = (uVar4 & 0xffffffff) * 0xb4;
      puVar13 = (undefined1 *)lVar5;
      if (iVar8 < (int)(uint)((int)uVar4 == 0)) {
        puVar6 = &DAT_ffe80814;
        uVar10 = -(uint)(puVar13 < &DAT_0017f7ec);
      }
      else {
        puVar6 = &DAT_0017f7ec;
        uVar10 = (uint)((undefined1 *)0xffe80813 < puVar13);
      }
      uVar15 = 0;
      uVar17 = __aeabi_ldivmod((uint)(puVar13 + (int)puVar6),
                               iVar8 * 0xb4 + (int)((ulonglong)lVar5 >> 0x20) + uVar10,
                               (uint)&DAT_002fefd8,(uint)(undefined *)0x0);
      puVar14 = &DAT_0009cdf8;
      do {
        if ((uint)uVar17 == (uint)*puVar14) {
          puVar16 = dev->data;
          iVar9 = lsm6dso_gy_full_scale_set((stmdev_ctx_t *)dev->config,uVar15 & 0xff);
          if (-1 < iVar9) {
            *(uint *)(puVar16 + 0x18) = (uint)(ushort)(&DAT_0009cdea)[uVar15] * 0x1117;
            return 0;
          }
          pcVar7 = "failed to set gyroscope full-scale\r\n";
          goto LAB_00012612;
        }
        uVar15 = uVar15 + 1;
        puVar14 = puVar14 + 1;
      } while (uVar15 != 7);
    }
  }
  return -0x16;
}


