/*
 * Function: FUN_0103ac76
 * Entry:    0103ac76
 * Prototype: undefined4 __stdcall FUN_0103ac76(int param_1, byte param_2, undefined4 param_3, undefined4 param_4, uint param_5)
 */


undefined4 FUN_0103ac76(int param_1,byte param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = *(int *)(param_1 + 0x10) + (uint)param_2 * 0xc;
  if ((*(uint *)(iVar3 + 0x48) & 7) == 1) {
    *(uint *)(iVar3 + 0x48) = param_5;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    *(undefined4 *)(iVar3 + 0x40) = param_3;
    *(undefined4 *)(iVar3 + 0x44) = param_4;
    (**(code **)(*(int *)(param_1 + 4) + (uint)param_2 * 0xc))();
    uVar4 = 0;
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_5 == (*(uint *)(iVar3 + 0x48) & 0xc0)) {
      uVar4 = 0xffffff88;
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}


