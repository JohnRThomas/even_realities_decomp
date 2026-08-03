/*
 * Function: arm_core_mpu_disable
 * Entry:    000540b4
 * Prototype: void __stdcall arm_core_mpu_disable(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void arm_core_mpu_disable(void)

{
  DataMemoryBarrier(0x1f);
  _DAT_e000ed94 = 0;
  return;
}


