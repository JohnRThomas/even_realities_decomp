/*
 * Function: mpu_configure_static_mpu_regions
 * Entry:    00053f00
 * Prototype: int __stdcall mpu_configure_static_mpu_regions(z_arm_mpu_partition * static_regions, uint8_t regions_num, uint32_t background_area_base, uint32_t background_area_end)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

int mpu_configure_static_mpu_regions
              (z_arm_mpu_partition *static_regions,uint8_t regions_num,uint32_t background_area_base
              ,uint32_t background_area_end)

{
  log_msg_desc desc;
  int extraout_r0;
  int extraout_r0_00;
  int iVar1;
  int extraout_r0_01;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  dword in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  undefined4 uStack_50;
  char *pcStack_4c;
  int iStack_48;
  uint uStack_3c;
  uint auStack_38 [2];
  byte bStack_30;
  uint uStack_2c;
  
  uStack_3c = (uint)regions_num;
  iVar3 = 0;
  while( true ) {
    if ((int)uStack_3c <= iVar3) {
      return background_area_base;
    }
    uVar2 = static_regions[1];
    if (uVar2 != 0) break;
LAB_00053fce:
    iVar3 = iVar3 + 1;
    static_regions = static_regions + 3;
  }
  if (((uVar2 < 0x20) || ((uVar2 & 0x1f) != 0)) || (uVar4 = *static_regions, (uVar4 & 0x1f) != 0)) {
    pcStack_4c = "Partition %u: sanity check failed.";
    iStack_48 = iVar3;
    goto LAB_00053f6e;
  }
  mpu_set_rnr(uVar4);
  mpu_set_rnr((uVar2 + uVar4) - 1);
  if (extraout_r0 == extraout_r0_00) {
    iStack_48 = extraout_r0;
    if ((extraout_r0 != -0x16) && (extraout_r0 < (int)background_area_base)) {
      uVar4 = _DAT_e000eda0 | 0x1f;
      uVar2 = *static_regions;
      uVar5 = (static_regions[1] + uVar2) - 1;
      _DAT_e000ed98 = extraout_r0;
      if ((_DAT_e000ed9c & 0xffffffe0) == uVar2) {
        if (uVar4 == uVar5) {
          region_allocate_and_init((uint8_t)extraout_r0,static_regions);
          goto LAB_00053fce;
        }
        _DAT_e000ed9c = _DAT_e000ed9c & 0x1f | static_regions[1] + uVar2 & 0xffffffe0;
LAB_00053ff0:
        iVar1 = region_allocate_and_init((uint8_t)background_area_base,static_regions);
LAB_00053ff4:
        if (iVar1 == -0x16) {
          return -0x16;
        }
      }
      else {
        uVar2 = uVar2 - 1 & 0xffffffe0;
        if (uVar4 == uVar5) {
          _DAT_e000eda0 = _DAT_e000eda0 & 0x1f | uVar2;
          goto LAB_00053ff0;
        }
        _DAT_e000eda0 = uVar2 | _DAT_e000eda0 & 0x1f;
        iVar1 = region_allocate_and_init((uint8_t)background_area_base,static_regions);
        if (iVar1 == -0x16) {
          return -0x16;
        }
        bStack_30 = (byte)_DAT_e000ed9c & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5);
        auStack_38[0] = *static_regions + static_regions[1];
        uVar2 = iVar1 + 1U & 0xff;
        uStack_2c = ((auStack_38[0] & 0xffffffe0) + (uVar4 - 1)) - uVar5 & 0xffffffe0;
        if (7 < uVar2) {
          _DAT_e000ed98 = extraout_r0;
          iVar1 = region_allocate_and_init_error(uVar2);
          goto LAB_00053ff4;
        }
        _DAT_e000ed98 = extraout_r0;
        region_init(uVar2,(arm_mpu_region *)auStack_38);
        iVar1 = extraout_r0_01;
      }
      background_area_base = iVar1 + 1;
      goto LAB_00053fce;
    }
  }
  else {
    iStack_48 = -0x16;
  }
  pcStack_4c = "Invalid underlying region index %u";
LAB_00053f6e:
  uStack_50 = 3;
  desc.level = (dword)&uStack_50;
  desc.domain = 0x1840;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffa0;
  z_impl_z_log_msg_static_create(&PTR_s_mpu_0008b9d8,desc,in_stack_ffffffa4,in_stack_ffffffa8);
  return -0x16;
}


