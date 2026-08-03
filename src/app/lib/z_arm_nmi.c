/*
 * Function: z_arm_nmi
 * Entry:    00083f22
 * Prototype: void __stdcall z_arm_nmi(void)
 */


/* exclude_from_export_ai */

void z_arm_nmi(void)

{
  z_SysNmiOnReset();
  z_arm_int_exit();
  return;
}


