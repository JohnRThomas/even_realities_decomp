/*
 * Function: FUN_0103705c
 * Entry:    0103705c
 * Prototype: undefined4 __stdcall FUN_0103705c(int * param_1, undefined4 param_2, uint param_3, uint param_4)
 */


undefined4 FUN_0103705c(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar3;
  undefined4 extraout_r3_01;
  undefined4 uVar4;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1f;
  }
  if (uVar2 == 0) goto LAB_01037082;
  if ((param_3 | param_4) == 0) goto LAB_01037082;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sem.c",0x80,
               param_3 | param_4);
  do {
    while( true ) {
      FUN_0103a370();
LAB_01037082:
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
      bVar1 = FUN_010368cc((uint *)&DAT_21004b4c);
      if (bVar1) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
    }
    FUN_01036904((uint *)&DAT_21004b4c);
    if (param_1[2] == 0) {
      if ((param_3 | param_4) != 0) {
        uVar4 = FUN_01037d78((uint *)&DAT_21004b4c,uVar4,param_1,param_3 | param_4,param_3,param_4);
        return uVar4;
      }
      bVar1 = FUN_010368e8((uint *)&DAT_21004b4c);
      uVar3 = extraout_r3_01;
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0xfffffff0;
      }
    }
    else {
      param_1[2] = param_1[2] + -1;
      bVar1 = FUN_010368e8((uint *)&DAT_21004b4c);
      uVar3 = extraout_r3_00;
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,uVar3);
  } while( true );
}


