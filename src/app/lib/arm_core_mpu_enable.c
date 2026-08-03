/*
 * Function: arm_core_mpu_enable
 * Entry:    0005409c
 * Prototype: void __stdcall arm_core_mpu_enable(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void arm_core_mpu_enable(void)

{
  _DAT_e000ed94 = 5;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


