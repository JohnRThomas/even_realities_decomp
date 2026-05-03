/*
 * Function: FUN_010378f0
 * Entry:    010378f0
 * Prototype: undefined __stdcall FUN_010378f0(uint * param_1, int param_2)
 */


void FUN_010378f0(uint *param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint unaff_r5;
  
  if (param_2 == 0) {
    unaff_r5 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar1 = getCurrentExceptionNumber();
      unaff_r5 = uVar1 & 0x1f;
    }
    if ((unaff_r5 != 0) || (DAT_21004b3c == DAT_21004b30)) goto LAB_0103792e;
    bVar2 = FUN_010368e8(param_1);
    if (bVar2) goto LAB_01037924;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x111,extraout_r3);
  }
  else {
LAB_0103792e:
    bVar2 = FUN_010368e8(param_1);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(param_2);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  FUN_0103a370();
LAB_01037924:
  FUN_0102f3d0(unaff_r5);
  return;
}


