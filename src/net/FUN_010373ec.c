/*
 * Function: FUN_010373ec
 * Entry:    010373ec
 * Prototype: undefined4 * __stdcall FUN_010373ec(int param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 * FUN_010373ec(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar3;
  int local_14;
  undefined4 uStack_10;
  
  local_14 = param_1;
  uStack_10 = param_3;
  if (param_2 != (undefined4 *)0x0) goto LAB_0103740a;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x174,param_4);
  while( true ) {
    while( true ) {
      FUN_0103a370();
LAB_0103740a:
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
      bVar2 = FUN_010368cc((uint *)&DAT_21004b58);
      if (bVar2) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
    }
    FUN_01036904((uint *)&DAT_21004b58);
    param_2 = (undefined4 *)FUN_010372d8(param_2,&local_14,extraout_r2,extraout_r3_00);
    bVar2 = FUN_010368e8((uint *)&DAT_21004b58);
    if (bVar2) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_01);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return param_2;
}


