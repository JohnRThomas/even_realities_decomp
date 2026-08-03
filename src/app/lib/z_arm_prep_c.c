/*
 * Function: z_arm_prep_c
 * Entry:    00053dec
 * Prototype: void __stdcall z_arm_prep_c(void)
 */


/* exclude_from_export_ai */

void z_arm_prep_c(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableFIQinterrupts(0);
  }
  z_data_copy();
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 0x20;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(&DAT_e000e100 + iVar2 * 4) = 0xffffffff;
  } while (iVar3 != 0x10);
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 0x60;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(&DAT_e000e100 + iVar2 * 4) = 0xffffffff;
  } while (iVar3 != 0x10);
  enableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


