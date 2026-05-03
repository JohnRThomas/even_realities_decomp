/*
 * Function: FUN_01038898
 * Entry:    01038898
 * Prototype: int * __stdcall FUN_01038898(int * param_1)
 */


int * FUN_01038898(int *param_1)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar3 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc((uint *)&DAT_21004b70);
  if (bVar2) goto LAB_010388c6;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_010388c6:
    FUN_01036904((uint *)&DAT_21004b70);
    if (*param_1 == 0) {
      param_1 = (int *)0xffffffea;
    }
    else {
      FUN_01038714(param_1);
      param_1 = (int *)0x0;
    }
    bVar2 = FUN_010368e8((uint *)&DAT_21004b70);
    if (bVar2) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return param_1;
}


