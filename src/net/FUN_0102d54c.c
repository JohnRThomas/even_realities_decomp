/*
 * Function: FUN_0102d54c
 * Entry:    0102d54c
 * Prototype: undefined __stdcall FUN_0102d54c(uint * param_1, byte * param_2)
 */


void FUN_0102d54c(uint *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int extraout_r1;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint *puVar4;
  undefined4 uVar5;
  
  iVar2 = (*(code *)param_1[7])(param_2);
  puVar4 = param_1 + 5;
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = FUN_010368cc(puVar4);
  if (bVar1) goto LAB_0102d58a;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_0102d58a:
    FUN_01036904(puVar4);
    *param_2 = *param_2 | 1;
    uVar3 = FUN_0103a3e0((int)param_1,param_1[1],iVar2);
    param_1[1] = uVar3;
    FUN_0103a576(param_1,extraout_r1);
    bVar1 = FUN_010368e8(puVar4);
    if (bVar1) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


