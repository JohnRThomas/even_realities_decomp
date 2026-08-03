/*
 * Function: arch_isr_direct_footer
 * Entry:    00053640
 * Prototype: undefined __stdcall arch_isr_direct_footer(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


/* exclude_from_export */

void arch_isr_direct_footer(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1f;
  }
  iVar3 = uVar2 - 0x10;
  (*(code *)(&PTR_z_irq_spurious_1_0008b554)[iVar3 * 2])
            ((&PTR_0008b550)[iVar3 * 2],&PTR_0008b558 + iVar3 * 2,param_3,
             (&PTR_z_irq_spurious_1_0008b554)[iVar3 * 2],param_1);
  z_arm_int_exit();
  return;
}


