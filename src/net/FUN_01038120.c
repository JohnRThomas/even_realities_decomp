/*
 * Function: FUN_01038120
 * Entry:    01038120
 * Prototype: int * __stdcall FUN_01038120(int * param_1)
 */


int * FUN_01038120(int *param_1)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
  if (bVar2) goto LAB_0103814e;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_0103814e:
    FUN_01036904((uint *)&DAT_21004b68);
    piVar3 = (int *)*param_1;
    if (param_1 == piVar3) {
      piVar3 = (int *)0x0;
    }
    else if (piVar3 != (int *)0x0) {
      FUN_01037fd4(piVar3,extraout_r1,extraout_r2,extraout_r3_00);
    }
    bVar2 = FUN_010368e8((uint *)&DAT_21004b68);
    if (bVar2) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_01);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return piVar3;
}


