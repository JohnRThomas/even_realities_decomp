/*
 * Function: z_arm_interrupt_init
 * Entry:    00053d2c
 * Prototype: void __stdcall z_arm_interrupt_init(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void z_arm_interrupt_init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _mpu_configure_regions_and_partition;
  iVar3 = 0;
  do {
    iVar2 = iVar1 + iVar3;
    iVar3 = iVar3 + 1;
    *(undefined1 *)(iVar2 + 0x300) = 0x20;
  } while (iVar3 != 0x45);
  return;
}


