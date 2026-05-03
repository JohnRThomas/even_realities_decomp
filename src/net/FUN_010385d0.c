/*
 * Function: FUN_010385d0
 * Entry:    010385d0
 * Prototype: bool __stdcall FUN_010385d0(int * param_1, int param_2, int param_3)
 */


bool FUN_010385d0(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  int *piVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
  if (bVar2) goto LAB_01038606;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_01038606:
    FUN_01036904((uint *)&DAT_21004b68);
    piVar4 = (int *)*param_1;
    if (param_1 == piVar4) {
      bVar2 = false;
    }
    else if (piVar4 == (int *)0x0) {
      bVar2 = false;
    }
    else {
      piVar4[0x24] = param_2;
      piVar4[5] = param_3;
      FUN_01037fd4(piVar4,extraout_r1,extraout_r2,extraout_r3_00);
      FUN_01038898(piVar4 + 6);
      FUN_0103778c(piVar4);
    }
    bVar3 = FUN_010368e8((uint *)&DAT_21004b68);
    if (bVar3) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_01);
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return bVar2;
}


