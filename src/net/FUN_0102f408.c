/*
 * Function: FUN_0102f408
 * Entry:    0102f408
 * Prototype: undefined __stdcall FUN_0102f408(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0102f408(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 uVar4;
  
  uVar4 = getProcessStackPointer();
  *(undefined4 *)(DAT_21004b30 + 0x30) = unaff_r4;
  *(undefined4 *)(DAT_21004b30 + 0x34) = unaff_r5;
  *(undefined4 *)(DAT_21004b30 + 0x38) = unaff_r6;
  *(undefined4 *)(DAT_21004b30 + 0x3c) = unaff_r7;
  *(undefined4 *)(DAT_21004b30 + 0x40) = unaff_r8;
  *(undefined4 *)(DAT_21004b30 + 0x44) = unaff_r9;
  *(undefined4 *)(DAT_21004b30 + 0x48) = unaff_r10;
  *(undefined4 *)(DAT_21004b30 + 0x4c) = unaff_r11;
  *(undefined4 *)(DAT_21004b30 + 0x50) = uVar4;
  iVar3 = DAT_21004b3c;
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_21004b30 = DAT_21004b3c;
  _DAT_e000ed04 = 0x8000000;
  DAT_21004690 = *(undefined4 *)(DAT_21004b3c + 0x88);
  uVar4 = *(undefined4 *)(DAT_21004b3c + 0x8c);
  *(undefined4 *)(DAT_21004b3c + 0x8c) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  FUN_0102fda4(iVar3);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(*(undefined4 *)(iVar3 + 0x50));
  }
  FUN_0103ab8e(iVar3);
  return;
}


