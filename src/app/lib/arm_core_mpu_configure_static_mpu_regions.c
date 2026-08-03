/*
 * Function: arm_core_mpu_configure_static_mpu_regions
 * Entry:    000540c8
 * Prototype: void __stdcall arm_core_mpu_configure_static_mpu_regions(z_arm_mpu_partition * static_regions, uint8_t regions_num, uint32_t background_area_start, uint32_t background_area_end)
 */


/* exclude_from_export */

void arm_core_mpu_configure_static_mpu_regions
               (z_arm_mpu_partition *static_regions,uint8_t regions_num,
               uint32_t background_area_start,uint32_t background_area_end)

{
  int iVar1;
  char *file;
  int line;
  
  iVar1 = mpu_configure_static_mpu_regions
                    (static_regions,regions_num,(uint)DAT_2001e1c4,background_area_end);
  DAT_2001e1c4 = (byte)iVar1;
  if (iVar1 == -0x16) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/mpu/arm_mpu.c",283);
    _ASSERT("\tConfiguring %u static MPU regions failed\n\n",(char *)(uint)regions_num,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return;
}


