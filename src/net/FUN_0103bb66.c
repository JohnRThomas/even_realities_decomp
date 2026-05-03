/*
 * Function: FUN_0103bb66
 * Entry:    0103bb66
 * Prototype: undefined __stdcall FUN_0103bb66(int * param_1)
 */


void FUN_0103bb66(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = FUN_01038898(param_1);
  if (piVar3 == (int *)0x0) {
    if ((code *)param_1[9] != (code *)0x0) {
      (*(code *)param_1[9])(param_1);
    }
    piVar3 = FUN_01038120(param_1 + 6);
    if (piVar3 != (int *)0x0) {
      FUN_0103781c(piVar3);
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
      return;
    }
  }
  return;
}


