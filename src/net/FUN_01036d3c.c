/*
 * Function: FUN_01036d3c
 * Entry:    01036d3c
 * Prototype: undefined4 __stdcall FUN_01036d3c(int * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_01036d3c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar5;
  
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getCurrentExceptionNumber();
    uVar5 = uVar5 & 0x1f;
  }
  piVar3 = param_1;
  if (uVar5 == 0) goto LAB_01036d58;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/mutex.c",0xcd,param_4);
  while( true ) {
    while( true ) {
      while( true ) {
        piVar3 = (int *)FUN_0103a370();
LAB_01036d58:
        if (piVar3[2] == 0) {
          return 0xffffffea;
        }
        if (piVar3[2] != DAT_21004b30) {
          return 0xffffffff;
        }
        iVar4 = piVar3[3];
        if (iVar4 != 0) break;
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/mutex.c",0xe5,0);
      }
      if (iVar4 != 1) {
        piVar3[3] = iVar4 + -1;
        return 0;
      }
      iVar4 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        iVar4 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = FUN_010368cc((uint *)&DAT_21004b48);
      if (bVar2) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
    }
    FUN_01036904((uint *)&DAT_21004b48);
    FUN_0103b984((int *)param_1[2],param_1[4]);
    piVar3 = FUN_01038194(param_1);
    param_1[2] = (int)piVar3;
    if (piVar3 != (int *)0x0) {
      param_1[4] = (int)*(char *)((int)piVar3 + 0xe);
      piVar3[0x24] = uVar5;
      FUN_0103781c(piVar3);
      FUN_010378f0((uint *)&DAT_21004b48,iVar4);
      return 0;
    }
    param_1[3] = 0;
    bVar2 = FUN_010368e8((uint *)&DAT_21004b48);
    if (bVar2) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(iVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}


