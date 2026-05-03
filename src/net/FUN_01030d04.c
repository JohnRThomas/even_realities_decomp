/*
 * Function: FUN_01030d04
 * Entry:    01030d04
 * Prototype: undefined __stdcall FUN_01030d04(byte * param_1, byte * param_2, uint param_3)
 */


void FUN_01030d04(byte *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  bVar1 = param_1[3];
  uVar4 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar4 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar8 = (uint)*param_1;
  bVar2 = param_1[1];
  uVar6 = param_1[2] - uVar8 & (uint)bVar1;
  if (uVar6 < param_3) {
    param_3 = uVar6;
  }
  *param_1 = bVar1 & *param_1 + (char)param_3;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  pbVar5 = param_2 + param_3;
  uVar7 = uVar8;
  for (; pbVar5 != param_2; param_2 = param_2 + 1) {
    *param_2 = param_1[uVar7 + 5];
    uVar7 = uVar7 + 1 & (uint)bVar1;
  }
  if (uVar8 == bVar2) {
    uVar4 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar4 = getBasePriority();
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if ((bVar3) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x40 < uVar8)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    param_1[1] = *param_1;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  if (uVar6 - param_3 <= (uint)param_1[4]) {
    Peripherals::RNG_NS.TASKS_START = 1;
  }
  return;
}


