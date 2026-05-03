/*
 * Function: FUN_01032098
 * Entry:    01032098
 * Prototype: undefined4 * __stdcall FUN_01032098(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 *
FUN_01032098(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = FUN_010373ec(0x210042f0,(undefined4 *)&DAT_21004974,param_3,param_4);
  if (0 < (int)puVar3) {
    iVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    FUN_0103ba5c(iVar4);
  }
  return puVar3;
}


