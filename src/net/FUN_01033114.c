/*
 * Function: FUN_01033114
 * Entry:    01033114
 * Prototype: undefined __stdcall FUN_01033114(void)
 */


void FUN_01033114(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_21004a88 = DAT_21004a88 + -1;
  DAT_21004a84 = DAT_21004a84 + 1;
  if (7 < DAT_21004a84) {
    DAT_21004a84 = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


