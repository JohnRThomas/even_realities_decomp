/*
 * Function: z_arm_mpu_init
 * Entry:    000541f8
 * Prototype: int __stdcall z_arm_mpu_init(void)
 */


/* WARNING: Removing unreachable block (ram,0x00054202) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

int z_arm_mpu_init(void)

{
  uint32_t extraout_r0;
  int extraout_r0_00;
  uint32_t index;
  char *test;
  char *file;
  int line;
  
  arm_core_mpu_disable();
  _DAT_e000edc0 = 0x44ffaa;
  index = extraout_r0;
  while (index != 2) {
    region_init(index,(arm_mpu_region *)(&UNK_0008ebe0 + index * 0x10));
    index = extraout_r0_00 + 1;
  }
  DAT_2001e1c4 = 2;
  arm_core_mpu_enable();
  if ((_DAT_e000ed90 & 0xffff) >> 8 != 8) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->TYPE & (0xFFUL << 8U)) >> 8U == 8",
            "WEST_TOPDIR/zephyr/arch/arm/core/aarch32/mpu/arm_mpu.c",0x1bc);
    _ASSERT("\tInvalid number of MPU regions\n\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return 0;
}


