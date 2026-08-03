/*
 * Function: npm1300_charger_init
 * Entry:    000658ec
 * Prototype: int __stdcall npm1300_charger_init(device * dev)
 */


/* exclude_from_export */

int npm1300_charger_init(device *dev)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  uint16_t *idx;
  uint uVar4;
  undefined4 *puVar5;
  uint8_t offset;
  int *piVar6;
  uint in_fpscr;
  uint uVar7;
  uint extraout_s1;
  float fVar8;
  float fVar9;
  ulonglong uVar10;
  uint16_t *in_stack_ffffffc0;
  ushort local_32 [3];
  
  puVar5 = (undefined4 *)dev->config;
  bVar1 = z_device_is_ready((device *)*puVar5);
  if (bVar1) {
    iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000005,10);
    if (iVar2 == 0) {
      offset = '\x10';
      piVar6 = puVar5 + 5;
      uVar3 = extraout_r1;
      do {
        piVar6 = piVar6 + 1;
        if (*piVar6 != 0x7fffffff) {
          fVar8 = (float)VectorSignedToFloat(*piVar6,(byte)(in_fpscr >> 0x16) & 3);
          fVar9 = (float)VectorUnsignedToFloat
                                   ((uint)*(ushort *)(puVar5 + 0xb),(byte)(in_fpscr >> 0x16) & 3);
          uVar10 = __aeabi_f2d((uint)((1.0 / (fVar8 / 1e+06 + 273.15) - 0.0033540165) * fVar9),uVar3
                               ,0x7fffffff,(uint)*(ushort *)(puVar5 + 0xb));
          uVar4 = puVar5[10];
          uVar7 = __ieee754_logf((int)uVar10,(int)(uVar10 >> 0x20));
          uVar10 = __floatunsidf(uVar4);
          uVar10 = __muldf3((uint)uVar10,(uint)(uVar10 >> 0x20),uVar7,extraout_s1);
          uVar7 = __fixunsdfsi((uint)uVar10,(uint)(uVar10 >> 0x20));
          uVar7 = (uVar7 << 10) / (uVar4 + uVar7);
          in_stack_ffffffc0 = (uint16_t *)(uVar7 & 3);
          iVar2 = mfd_npm1300_reg_write2
                            ((device *)*puVar5,'\x03',offset,(uint8_t)((uVar7 << 0x16) >> 0x18),
                             (uint8_t)in_stack_ffffffc0);
          uVar3 = extraout_r1_00;
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        offset = offset + '\x02';
      } while (offset != '\x18');
      iVar2 = linear_range_group_get_win_index
                        ((linear_range *)&PTR_DAT_0008f624,puVar5[1],puVar5[1],(int32_t)local_32,
                         in_stack_ffffffc0);
      if (iVar2 != -0x16) {
        iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000003,0xc);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = linear_range_group_get_win_index
                          ((linear_range *)&PTR_DAT_0008f624,puVar5[2],puVar5[2],(int32_t)local_32,
                           in_stack_ffffffc0);
        if (iVar2 != -0x16) {
          iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000003,0xd);
          if (iVar2 != 0) {
            return iVar2;
          }
          iVar2 = linear_range_get_win_index
                            ((linear_range *)&PTR_DAT_0008f618,puVar5[3] + -2000,puVar5[3],local_32)
          ;
          if (iVar2 != -0x16) {
            iVar2 = mfd_npm1300_reg_write2
                              ((device *)*puVar5,'\x03','\b',
                               (uint8_t)(((uint)local_32[0] << 0x17) >> 0x18),(byte)local_32[0] & 1)
            ;
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar2 = linear_range_get_win_index
                              ((linear_range *)&PTR_LAB_0008f60c,puVar5[4] + -0xc9e,puVar5[4],
                               local_32);
            if (iVar2 != -0x16) {
              idx = (uint16_t *)(local_32[0] & 1);
              iVar2 = mfd_npm1300_reg_write2
                                ((device *)*puVar5,'\x03','\n',
                                 (uint8_t)(((uint)local_32[0] << 0x17) >> 0x18),(uint8_t)idx);
              if (iVar2 != 0) {
                return iVar2;
              }
              iVar2 = linear_range_group_get_win_index
                                ((linear_range *)&PTR_LAB_0008f5f4,puVar5[5],puVar5[5],
                                 (int32_t)local_32,idx);
              if (iVar2 != -0x16) {
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000002,2);
                if (iVar2 != 0) {
                  return iVar2;
                }
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000003,0xe);
                if (iVar2 != 0) {
                  return iVar2;
                }
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000003,0xf);
                if (iVar2 != 0) {
                  return iVar2;
                }
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000005,0x24);
                if (iVar2 != 0) {
                  return iVar2;
                }
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000005,0);
                if (iVar2 != 0) {
                  return iVar2;
                }
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000005,1);
                if (iVar2 != 0) {
                  return iVar2;
                }
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000005,0xc);
                if (iVar2 != 0) {
                  return iVar2;
                }
                if ((*(char *)((int)puVar5 + 0x32) != '\0') &&
                   (iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000003,0x50), iVar2 != 0)) {
                  return iVar2;
                }
                if ((*(char *)((int)puVar5 + 0x33) != '\0') &&
                   (iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000003,6), iVar2 != 0)) {
                  return iVar2;
                }
                if (*(char *)((int)puVar5 + 0x31) == '\0') {
                  return 0;
                }
                iVar2 = i2c_write_dt((i2c_dt_spec *)*puVar5,&DAT_00000003,4);
                return iVar2;
              }
            }
          }
        }
      }
      iVar2 = -0x16;
    }
  }
  else {
    iVar2 = -0x13;
  }
  return iVar2;
}


