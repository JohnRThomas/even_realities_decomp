/*
 * Function: z_arm_platform_init
 * Entry:    00067f64
 * Prototype: void __stdcall z_arm_platform_init(void)
 */


/* exclude_from_export_ai */

void z_arm_platform_init(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Peripherals::FICR_S._304_4_;
  iVar2 = Peripherals::FICR_S._308_4_;
  if ((iVar1 == 7) && (iVar2 - 2U < 4)) {
    return;
  }
  return;
}


