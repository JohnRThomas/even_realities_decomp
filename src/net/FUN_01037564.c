/*
 * Function: FUN_01037564
 * Entry:    01037564
 * Prototype: undefined4 __stdcall FUN_01037564(int param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_01037564(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar2;
  undefined4 extraout_r3_01;
  undefined4 uVar3;
  
  if (param_1 != 0) goto LAB_01037582;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x2ed,param_4);
  do {
    while( true ) {
      while( true ) {
        FUN_0103a370();
LAB_01037582:
        bVar1 = FUN_0103b90a();
        if (!bVar1) break;
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x2ee,
                     extraout_r3);
      }
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar1 = FUN_010368cc((uint *)&DAT_21004b58);
      if (bVar1) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3_00);
    }
    FUN_01036904((uint *)&DAT_21004b58);
    uVar2 = *(uint *)(param_1 + 0xb0);
    if ((uVar2 & 6) != 0) {
      *(uint *)(param_1 + 0xb0) = uVar2 | 4;
      if (param_2 == 0) goto LAB_010375dc;
LAB_010375d4:
      uVar2 = uVar2 | 0xc;
LAB_010375d8:
      *(uint *)(param_1 + 0xb0) = uVar2;
LAB_010375dc:
      FUN_0103ba1a(param_1);
      uVar3 = FUN_01038668((uint *)&DAT_21004b58,uVar3,(int *)(param_1 + 0xa8),0xffffffff,0xffffffff
                           ,-1,(undefined4 *)0x0);
      return uVar3;
    }
    if (param_2 != 0) goto LAB_010375d4;
    if (*(int *)(param_1 + 0x98) != 0) {
      uVar2 = uVar2 | 4;
      goto LAB_010375d8;
    }
    bVar1 = FUN_010368e8((uint *)&DAT_21004b58);
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_01);
    param_2 = 0;
  } while( true );
}


