/*
 * Function: arm_core_mpu_mark_areas_for_dynamic_regions
 * Entry:    00054110
 * Prototype: void __stdcall arm_core_mpu_mark_areas_for_dynamic_regions(z_arm_mpu_partition * dyn_region_areas, uint8_t dyn_region_areas_num)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void arm_core_mpu_mark_areas_for_dynamic_regions
               (z_arm_mpu_partition *dyn_region_areas,uint8_t dyn_region_areas_num)

{
  int iVar1;
  int extraout_r0;
  int extraout_r0_00;
  uint32_t rnr;
  char *file;
  int line;
  int *piVar2;
  int iVar3;
  uint32_t uVar4;
  
  piVar2 = &DAT_2000b1d4;
  iVar3 = 0;
  do {
    if ((int)(uint)dyn_region_areas_num <= iVar3) {
      return;
    }
    uVar4 = dyn_region_areas[1];
    if (uVar4 != 0) {
      rnr = *dyn_region_areas;
      mpu_set_rnr(rnr);
      mpu_set_rnr((uVar4 + rnr) - 1);
      if (extraout_r0 != extraout_r0_00) {
        (&DAT_2000b1d4)[iVar3 * 5] = 0xffffffea;
LAB_00054164:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
                "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/mpu/arm_mpu.c",299);
        _ASSERT("\tMarking %u areas for dynamic regions failed\n\n",
                (char *)(uint)dyn_region_areas_num,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      *piVar2 = extraout_r0;
      if ((extraout_r0 == -0x16) || ((int)(uint)DAT_2001e1c4 <= extraout_r0)) goto LAB_00054164;
      iVar1 = iVar3 * 0x14;
      _DAT_e000ed98 = extraout_r0;
      (&DAT_2000b1e0)[iVar1] = (&DAT_2000b1e0)[iVar1] & 0xe0 | (byte)_DAT_e000ed9c & 0x1f;
      (&DAT_2000b1e0)[iVar1] = (&DAT_2000b1e0)[iVar1] & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5)
      ;
      piVar2[1] = _DAT_e000ed9c & 0xffffffe0;
      piVar2[4] = _DAT_e000eda0 & 0xffffffe0;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 5;
    dyn_region_areas = dyn_region_areas + 3;
  } while( true );
}


