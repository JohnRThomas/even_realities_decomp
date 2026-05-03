/*
 * Function: FUN_01037d78
 * Entry:    01037d78
 * Prototype: undefined __stdcall FUN_01037d78(uint * param_1, undefined4 param_2, int * param_3, undefined4 param_4, uint param_5, int param_6)
 */


void FUN_01037d78(uint *param_1,undefined4 param_2,int *param_3,undefined4 param_4,uint param_5,
                 int param_6)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar3;
  undefined4 extraout_r3_01;
  
  DAT_21004b5c = DAT_21004b30;
  if (param_1 != (uint *)&DAT_21004b68) goto LAB_01037dae;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x35f,
               &DAT_21004b5c);
  while( true ) {
    while( true ) {
      FUN_0103a370();
LAB_01037dae:
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
      if (bVar2) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
    }
    FUN_01036904((uint *)&DAT_21004b68);
    FUN_01037d48(DAT_21004b30,param_3,param_5,param_6);
    bVar2 = FUN_010368e8(param_1);
    uVar3 = extraout_r3_00;
    if ((bVar2) && (bVar2 = FUN_010368e8((uint *)&DAT_21004b68), uVar3 = extraout_r3_01, bVar2))
    break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x111,uVar3);
  }
  FUN_0102f3d0(param_2);
  return;
}


