/*
 * Function: FUN_01036fe4
 * Entry:    01036fe4
 * Prototype: undefined __stdcall FUN_01036fe4(int * param_1)
 */


void FUN_01036fe4(int *param_1)

{
  uint uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 extraout_r3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar5 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc((uint *)&DAT_21004b4c);
  if (!bVar2) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3);
    FUN_0103a370();
  }
  FUN_01036904((uint *)&DAT_21004b4c);
  piVar3 = FUN_01038194(param_1);
  if (piVar3 == (int *)0x0) {
    iVar4 = param_1[2];
    if (param_1[3] != iVar4) {
      iVar4 = iVar4 + 1;
    }
    param_1[2] = iVar4;
    FUN_0103bcb6(param_1 + 4,2);
  }
  else {
    piVar3[0x24] = 0;
    FUN_0103781c(piVar3);
  }
  FUN_010378f0((uint *)&DAT_21004b4c,iVar5);
  return;
}


